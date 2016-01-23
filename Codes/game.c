//	Connect 4 ( or four in a row ) game
/*	
	This file contains the C code for the conenct 4 game... the definitions for the bot1() and bot2() function are missing which has to be filled by the programmers... All they have to do is write one function to complete the program... 
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>		//	graphics header file

//	Detailed description of these function is given at lines after 27rd line
int bot1(int[][7],int);		//	This is the function which is written by you
int bot2(int[][7],int);		//	This is the function which is written by your opponent (or vice-versa)


//	The following function are not important for the participants... They can skip these functions if they want to
void drawGrid(int[][7]);
void checkForErrors(int,int,int[][7]);
int updateGrid(int,int[][7],int);
void animateGrid(int,int[][7],int);
int checkWinOrLose(int [][7],int,int);
int checkDraw(int [][7]);
void copyGrid(int [][7],int [][7]);
int equalGrid(int [][7],int [][7]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef C4_DEFINED
#define C4_DEFINED

#include <time.h>

#ifndef Boolean
#define Boolean char
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define C4_NONE      2
#define C4_MAX_LEVEL 20



extern void    c4_poll(void (*poll_func)(void), clock_t interval);
extern void    c4_new_game(int width, int height, int num);
extern Boolean c4_make_move(int player, int column, int *row);
extern int tech_fest_bot_move(int player, int level, int *column, int *row);
//extern Boolean bot1(char **grid, int player);
extern Boolean tech_fest_bot_update_state(int grid[6][7]);
extern char ** c4_board(void);
extern int     c4_score_of_player(int player);
extern Boolean c4_is_winner(int player);
extern Boolean c4_is_tie(void);
extern void    c4_win_coords(int *x1, int *y1, int *x2, int *y2);
extern void    c4_end_game(void);
extern void    c4_reset(void);

extern const char *c4_get_version(void);

#endif /* C4_DEFINED */


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
//#include "connect_four.h"
#define other(x)        ((x) ^ 1)
#define real_player(x)  ((x) & 1)

#define pop_state() \
(current_state = &state_stack[--depth])
#define goodness_of(player) \
(current_state->score[player] - current_state->score[other(player)])

typedef struct {
    
    char **board;                              
    
    int *(score_array[2]);      
    int score[2];           
    short int winner;      
    int num_of_pieces;
    
} Game_state;

static int size_x, size_y, num_to_connect;
static int win_places;

static int ***map;  

static int magic_win_number;
static Boolean game_in_progress = FALSE, move_in_progress = FALSE;
static Boolean seed_chosen = FALSE;
static void (*poll_function)(void) = NULL;
static clock_t poll_interval, next_poll;
static Game_state state_stack[C4_MAX_LEVEL+1];
static Game_state *current_state;
static int depth;
static int states_allocated = 0;
static int *drop_order;


static int num_of_win_places(int x, int y, int n);
static void update_score(int player, int x, int y);
static int drop_piece(int player, int column);
static void push_state(void);
static int evaluate(int player, int level, int alpha, int beta);
static void *emalloc(unsigned int n);




void
c4_poll(void (*poll_func)(void), clock_t interval)
{
    poll_function = NULL;
    poll_interval = interval;
}



void
c4_new_game(int width, int height, int num)
{
    register int i, j, k, x;
    int win_index, column;
    int *win_indices;
    
    assert(!game_in_progress);
    assert(width >= 1 && height >= 1 && num >= 1);
    
    size_x = width;
    size_y = height;
    num_to_connect = num;
    magic_win_number = 1 << num_to_connect;
    win_places = num_of_win_places(size_x, size_y, num_to_connect);
    
   
    if (!seed_chosen) {
        srand((unsigned int) time((time_t *) 0));
        seed_chosen = TRUE;
    }
    
       depth = 0;
    current_state = &state_stack[0];
    
    current_state->board = (char **) emalloc(size_x * sizeof(char *));
    for (i=0; i<size_x; i++) {
        current_state->board[i] = (char *) emalloc(size_y);
        for (j=0; j<size_y; j++)
            current_state->board[i][j] = C4_NONE;
    }
   
    current_state->score_array[0] = (int *) emalloc(win_places * sizeof(int));
    current_state->score_array[1] = (int *) emalloc(win_places * sizeof(int));
    for (i=0; i<win_places; i++) {
        current_state->score_array[0][i] = 1;
        current_state->score_array[1][i] = 1;
    }
    
    current_state->score[0] = current_state->score[1] = win_places;
    current_state->winner = C4_NONE;
    current_state->num_of_pieces = 0;
    
    states_allocated = 1;
    
  
    
    map = (int ***) emalloc(size_x * sizeof(int **));
    for (i=0; i<size_x; i++) {
        map[i] = (int **) emalloc(size_y * sizeof(int *));
        for (j=0; j<size_y; j++) {
            map[i][j] = (int *) emalloc((num_to_connect*4 + 1) * sizeof(int));
            map[i][j][0] = -1;
        }
    }
    
    win_index = 0;
    
   
    for (i=0; i<size_y; i++)
        for (j=0; j<size_x-num_to_connect+1; j++) {
            for (k=0; k<num_to_connect; k++) {
                win_indices = map[j+k][i];
                for (x=0; win_indices[x] != -1; x++)
                    ;
                win_indices[x++] = win_index;
                win_indices[x] = -1;
            }
            win_index++;
        }
    
       for (i=0; i<size_x; i++)
        for (j=0; j<size_y-num_to_connect+1; j++) {
            for (k=0; k<num_to_connect; k++) {
                win_indices = map[i][j+k];
                for (x=0; win_indices[x] != -1; x++)
                    ;
                win_indices[x++] = win_index;
                win_indices[x] = -1;
            }
            win_index++;
        }
    
    
    for (i=0; i<size_y-num_to_connect+1; i++)
        for (j=0; j<size_x-num_to_connect+1; j++) {
            for (k=0; k<num_to_connect; k++) {
                win_indices = map[j+k][i+k];
                for (x=0; win_indices[x] != -1; x++)
                    ;
                win_indices[x++] = win_index;
                win_indices[x] = -1;
            }
            win_index++;
        }
    
   
    for (i=0; i<size_y-num_to_connect+1; i++)
        for (j=size_x-1; j>=num_to_connect-1; j--) {
            for (k=0; k<num_to_connect; k++) {
                win_indices = map[j-k][i+k];
                for (x=0; win_indices[x] != -1; x++)
                    ;
                win_indices[x++] = win_index;
                win_indices[x] = -1;
            }
            win_index++;
        }
    
   
    
    drop_order = (int *) emalloc(size_x * sizeof(int));
    column = (size_x-1) / 2;
    for (i=1; i<=size_x; i++) {
        drop_order[i-1] = column;
        column += ((i%2)? i : -i);
    }
    
    game_in_progress = TRUE;
}



Boolean
c4_make_move(int player, int column, int *row)
{
    int result; 
    
    assert(game_in_progress);
    assert(!move_in_progress);
    
    if (column >= size_x || column < 0)
        return FALSE;
    
    result = drop_piece(real_player(player), column);
    if (row && result >= 0)
        *row = result;
    return (result >= 0);
}


Boolean first_time=TRUE;
/*Boolean bot1(char **grid, int player){
    int column=3;
    first_time=FALSE;
    int i,j;

    //c4_auto_move(player, 10, &column, NULL);
    return TRUE;
}*/
Boolean tech_fest_bot_update_state(int grid[6][7]){
    int i,j,temp_rw;
    if(first_time){
        first_time=FALSE;
        c4_new_game(7,6,4);
        return TRUE;
    }
    for (i=0; i<6; i++) {
        for (j=0; j<7; j++) {
            if(grid[i][j]!=0){
                if (grid[i][j]==1) {
                    current_state->board[j][i]=1;                    
                }
                else if(grid[i][j]==-1 && current_state->board[j][i]==C4_NONE){
                    //grid[i][j]=0;
                    c4_make_move(0,j,&temp_rw);
                }
                
                //    current_state->board[j][i]=0;
            }
        }
    }
    return TRUE;
}

int
tech_fest_bot_move(int player, int level, int *column, int *row)
{
    if (first_time) {
        first_time=FALSE;
       
    }
    int i, best_column = -1, goodness = 0, best_worst = -(INT_MAX);
    int num_of_equal = 0, real_player, current_column, result;
    
    assert(game_in_progress);
    assert(!move_in_progress);
    assert(level >= 1 && level <= C4_MAX_LEVEL);
    
    real_player = real_player(player);
        if (current_state->num_of_pieces < 2 &&
        size_x == 7 && size_y == 6 && num_to_connect == 4 &&
        (current_state->num_of_pieces == 0 ||
         current_state->board[3][0] != C4_NONE)) {
            if (column){
                *column = 3;
               
            }
            if (row)
                *row = current_state->num_of_pieces;
            drop_piece(real_player, 3);
            return 3;
        }
    
    move_in_progress = TRUE;
    
    
    
    for (i=0; i<size_x; i++) {
        push_state();
        current_column = drop_order[i];
        
        
        if (drop_piece(real_player, current_column) < 0) {
            pop_state();
            continue;
        }
        
        
        else if (current_state->winner == real_player) {
            best_column = current_column;
            pop_state();
            break;
        }
        
        else {
            next_poll = clock() + poll_interval;
            goodness = evaluate(real_player, level, -(INT_MAX), -best_worst);
        }
        
        
        if (goodness > best_worst) {
            best_worst = goodness;
            best_column = current_column;
            num_of_equal = 1;
        }
        
       
        else if (goodness == best_worst) {
            num_of_equal++;
            if (rand()%10000 < ((float)1/(float)num_of_equal) * 10000)
                best_column = current_column;
        }
        
        pop_state();
    }
    
    move_in_progress = FALSE;
    printf("%d", best_column);
    
    
    if (best_column >= 0) {
        result = drop_piece(real_player, best_column);
        if (column)
            *column = best_column;
        if (row)
            *row = result;
        return best_column;
    }
    else
        return best_column;
}


char **
c4_board(void)
{
    assert(game_in_progress);
    return current_state->board;
}



int
c4_score_of_player(int player)
{
    assert(game_in_progress);
    return current_state->score[real_player(player)];
}



Boolean
c4_is_winner(int player)
{
    assert(game_in_progress);
    return (current_state->winner == real_player(player));
}



Boolean
c4_is_tie()
{
    assert(game_in_progress);
    return (current_state->num_of_pieces == size_x * size_y);
}



void
c4_win_coords(int *x1, int *y1, int *x2, int *y2)
{
    register int i, j, k;
    int winner, win_pos = 0;
    Boolean found;
    
    assert(game_in_progress);
    
    winner = current_state->winner;
    assert(winner != C4_NONE);
    
    while (current_state->score_array[winner][win_pos] != magic_win_number)
        win_pos++;
    
   
    
    found = FALSE;
    for (j=0; j<size_y && !found; j++)
        for (i=0; i<size_x; i++)
            for (k=0; map[i][j][k] != -1; k++)
                if (map[i][j][k] == win_pos) {
                    *x1 = i;
                    *y1 = j;
                    found = TRUE;
                    break;
                }
    
  
    
    found = FALSE;
    for (j=size_y-1; j>=0 && !found; j--)
        for (i=size_x-1; i>=0; i--)
            for (k=0; map[i][j][k] != -1; k++)
                if (map[i][j][k] == win_pos) {
                    *x2 = i;
                    *y2 = j;
                    found = TRUE;
                    break;
                }
}



void
c4_end_game(void)
{
    int i, j;
    
    assert(game_in_progress);
    assert(!move_in_progress);
    
    
    
    for (i=0; i<size_x; i++) {
        for (j=0; j<size_y; j++)
            free(map[i][j]);
        free(map[i]);
    }
    free(map);
    
    
    
    for (i=0; i<states_allocated; i++) {
        for (j=0; j<size_x; j++)
            free(state_stack[i].board[j]);
        free(state_stack[i].board);
        free(state_stack[i].score_array[0]);
        free(state_stack[i].score_array[1]);
    }
    states_allocated = 0;
    
    
    
    free(drop_order);
    
    game_in_progress = FALSE;
}



void
c4_reset(void)
{
    assert(!move_in_progress);
    if (game_in_progress)
        c4_end_game();
    poll_function = NULL;
}


const char *
c4_get_version(void)
{
    return "$Id: c4.c,v 3.7 2000/05/19 16:49:46 pomakis Exp pomakis $";
}


static int
num_of_win_places(int x, int y, int n)
{
    if (x < n && y < n)
        return 0;
    else if (x < n)
        return x * ((y-n)+1);
    else if (y < n)
        return y * ((x-n)+1);
    else
        return 4*x*y - 3*x*n - 3*y*n + 3*x + 3*y - 4*n + 2*n*n + 2;
}



static void
update_score(int player, int x, int y)
{
    register int i;
    int win_index;
    int this_difference = 0, other_difference = 0;
    int **current_score_array = current_state->score_array;
    int other_player = other(player);
    
    for (i=0; map[x][y][i] != -1; i++) {
        win_index = map[x][y][i];
        this_difference += current_score_array[player][win_index];
        other_difference += current_score_array[other_player][win_index];
        
        current_score_array[player][win_index] <<= 1;
        current_score_array[other_player][win_index] = 0;
        
        if (current_score_array[player][win_index] == magic_win_number)
            if (current_state->winner == C4_NONE)
                current_state->winner = player;
    }
    
    current_state->score[player] += this_difference;
    current_state->score[other_player] -= other_difference;
}



static int
drop_piece(int player, int column)
{
    int y = 0;
    
    while (current_state->board[column][y] != C4_NONE && ++y < size_y)
        ;
    
    if (y == size_y)
        return -1;
    
    current_state->board[column][y] = player;
    current_state->num_of_pieces++;
    update_score(player, column, y);
    
    return y;
}



static void
push_state(void)
{
    register int i, win_places_array_size;
    Game_state *old_state, *new_state;
    
    win_places_array_size = win_places * sizeof(int);
    old_state = &state_stack[depth++];
    new_state = &state_stack[depth];
    
    if (depth == states_allocated) {
        
       
        
        new_state->board = (char **) emalloc(size_x * sizeof(char *));
        for (i=0; i<size_x; i++)
            new_state->board[i] = (char *) emalloc(size_y);
        
        
        
        new_state->score_array[0] = (int *) emalloc(win_places_array_size);
        new_state->score_array[1] = (int *) emalloc(win_places_array_size);
        
        states_allocated++;
    }
    
    
    
    for (i=0; i<size_x; i++)
        memcpy(new_state->board[i], old_state->board[i], size_y);
    
   
    
    memcpy(new_state->score_array[0], old_state->score_array[0],
           win_places_array_size);
    memcpy(new_state->score_array[1], old_state->score_array[1],
           win_places_array_size);
    
    new_state->score[0] = old_state->score[0];
    new_state->score[1] = old_state->score[1];
    new_state->winner = old_state->winner;
    
    current_state = new_state;
}



static int
evaluate(int player, int level, int alpha, int beta)
{
    int i, goodness, best, maxab;
    
    if (poll_function && next_poll <= clock()) {
        next_poll += poll_interval;
        (*poll_function)();
    }
    
    if (level == depth)
        return goodness_of(player);
    else {
       
        best = -(INT_MAX);
        maxab = alpha;
        for(i=0; i<size_x; i++) {
            push_state();
            if (drop_piece(other(player), drop_order[i]) < 0) {
                pop_state();
                continue;
            }
            else if (current_state->winner == other(player))
                goodness = INT_MAX - depth;
            else
                goodness = evaluate(other(player), level, -beta, -maxab);
            if (goodness > best) {
                best = goodness;
                if (best > maxab)
                    maxab = best;
            }
            pop_state();
            if (best > beta)
                break;
        }
        
        
        return -best;
    }
}



static void *
emalloc(unsigned int n)
{
    void *ptr;
    
    ptr = (void *) malloc(n);
    if (ptr == NULL) {
        fprintf(stderr, "c4: emalloc() - Can't allocate %d bytes.\n", n);
        exit(1);
    }
    return ptr;
}

char bot1Name[50]="Sandhya";
int bot1(int grid[6][7],int move) {
    int column_to_return=0;
    int temp=3;
    tech_fest_bot_update_state(grid);
	if(move==1)
    column_to_return=tech_fest_bot_move(1,7,&temp, NULL);
	if(move==-1)
    column_to_return=tech_fest_bot_move(0,7,&temp, NULL);
    return column_to_return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//	Works for both bot1 and bot2... but has column full error... 

int pot_moves[7];                                                   //1
int results[7];                                                     //2
int isValidMove(int grid[6][7],int column);                         //3
int isBoardFull(int grid[6][7]);                                    //4
void makeMove(int dupe[6][7],int move,int i);                       //5
int getLowestEmptySpace(int grid[6][7],int column);                 //6
int isWinner(int dupe[6][7],int move);                              //7
void compute_pot_moves(int grid[6][7],int move,int lookahead);      //8
void compute_results(int grid[6][7],int move,int lookahead);        //9

char bot2Name[50]="Ajith_Ashwin";
int bot2(int grid[6][7],int move)
{
        int b_m_fittness=-1;
        int bestmoves[7];
        int j=0;
        int r;
	int i;

        compute_pot_moves(grid,move,2);

        for(i=0;i<7;i++)
            if(pot_moves[i]>b_m_fittness&&isValidMove(grid,i))
                b_m_fittness=pot_moves[i];

        for(i=0;i<7;i++)
            if(pot_moves[i]==b_m_fittness&&isValidMove(grid,i))
                bestmoves[j++]=i;

        r=rand()%j;

        return bestmoves[r];
}





void compute_results(int grid[6][7],int move,int lookahead)
{
    int results[7]={0};                //global
    int dupe[6][7],dupe1[6][7];
    int enemy;
	int i,j,k,l;

    if(move==1)
        enemy=-1;
    else
        enemy=1;

    if(lookahead==0||!(isBoardFull(grid)))
    {
        for(i=0;i<7;i++)        //i=1st move
        {

            for(l=0;l<6;l++)
                for(k=0;k<7;k++)
                    dupe[l][k]=grid[l][k];

            if(!(isValidMove(dupe,i)))
                continue;

            makeMove(dupe,move,i);

            if(isWinner(dupe,move))
            {
                results[i]=1;
                break;
            }

            else
            {
                if(isBoardFull(dupe))
                    results[i]=0;

                else
                {
                    for(j=0;j<7;j++)    //j=counter move by enemy
                    {
                        for(l=0;l<6;l++)
                            for(k=0;k<7;k++)
                                dupe1[l][k]=dupe[l][k];

                        if(!(isValidMove(dupe1,j)))
                            continue;

                         makeMove(dupe1,enemy,j);

                        if(isWinner(dupe1,enemy))
                        {
                            results[i]=-1;
                            break;
                        }
                        else
                        {
                            results[i]=0;
                        }

                    }
                }
            }
        }
    }

}









void compute_pot_moves(int grid[6][7],int move,int lookahead)
{
    int pot_moves[7]={0};                //global
    int res=0;
    int dupe[6][7],dupe1[6][7];
    int enemy;
	int i,j,k,l;

    if(move==1)
        enemy=-1;
    else
        enemy=1;

    if(lookahead==0||!(isBoardFull(grid)))
    {
        for(i=0;i<7;i++)        //i=1st move
        {

            for(l=0;l<6;l++)
                for(k=0;k<7;k++)
                    dupe[l][k]=grid[l][k];

            if(!(isValidMove(dupe,i)))
                continue;

            makeMove(dupe,move,i);
            if(isWinner(dupe,move))
            {
                pot_moves[i]=1;
                break;
            }

            else
            {
                if(isBoardFull(dupe))
                    pot_moves[i]=0;

                else
                {
                    for(j=0;j<7;j++)    //j=counter move by enemy
                    {
                        for(l=0;l<6;l++)
                            for(k=0;k<7;k++)
                                dupe1[l][k]=dupe[l][k];

                        if(!(isValidMove(dupe1,j)))
                            continue;

                         makeMove(dupe1,enemy,j);

                        if(isWinner(dupe1,enemy))
                        {
                            pot_moves[i]=-1;
                            break;
                        }
                        else
                        {
                            compute_results(dupe1,move,1);
                            for(l=0;l<7;l++)
                                res+=results[l];
                            pot_moves[i]+=(res/7)/7;
                        }

                    }
                }
            }
        }
    }

}


int isValidMove(int grid[6][7],int column)
{
    if(column<0||column>=7||grid[0][column]!='\0')
        return -1;

    return 1;
}


int isBoardFull(int grid[6][7])
{
	int i,j;
    for(i=0;i<6;i++)
        for(j=0;j<7;j++)
            if(grid[i][j]==0)
                return -1;

    return 1;
}


void makeMove(int grid[6][7],int move,int column)
{
    int lowest;
    lowest=getLowestEmptySpace(grid,column);
    if(lowest!=-1)
        grid[lowest][column]=move;
}


int getLowestEmptySpace(int grid[6][7],int column)
{
	int i;
    for(i=0;i<6;i++)
        if(grid[i][column]==0)
            return i;
    return -1;
}


int isWinner(int grid[6][7],int move)
{
	int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<7-3;j++)
        {
            if(grid[i][j]==move&&grid[i][j+1]==move&&grid[i][j+2]==move&&grid[i][j+3]==move)
                return 1;
        }
    }

    for(i=0;i<6-3;i++)
    {
        for(j=0;j<7;j++)
        {
            if(grid[i][j]==move&&grid[i+1][j]==move&&grid[i+2][j]==move&&grid[i+3][j]==move)
                return 1;
        }
    }

    for(i=3;i<6;i++)
    {
        for(j=0;j<7-3;j++)
        {
            if(grid[i][j]==move&&grid[i-1][j+1]==move&&grid[i-2][j+2]==move&&grid[i-3][j+3]==move)
                return 1;
        }
    }

    for(i=0;i<6-3;i++)
    {
        for(j=0;j<7-3;j++)
        {
            if(grid[i][j]==move&&grid[i+1][j+1]==move&&grid[i+2][j+2]==move&&grid[i+3][j+3]==move)
                return 1;
        }
    }
    return -1;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[]) {
/*	Variables important for the participants : 
		grid[6][7] : this stores the current state of the game. 
			grid[i][j]==0 means that particular place is not occupied by any piece
			grid[i][j]==1 means that particular place is occupied by player 1 (or bot 1) piece
			grid[i][j]==-1 means that particular place is occupied by player 2 (or bot 2) piece
		move : this variables content decides which player's turn it is to play
			move==1 means it is player 1 (or bot1) to play
			move==-1 means it is player 2 (or bot2) to play
*/

/*	rest of the variables used and rest of the main() function code is not important for the participants... They can skip going through it...	*/

/*	result : contains which column the player has made the move in
	win : contains which player has won the game (possible values 1, -1 or 0 for draw)
*/

	int grid[6][7],move=1,result,win=0,i,j,gridDup[6][7],moveDup,rowNum;
	char displayStr[50];

	int gd,gm=VGAMAX; gd=DETECT;
	initgraph(&gd,&gm,NULL);		//	Initialize the graph

	srand(time(NULL));			//	If any bot uses rand() function

	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			grid[i][j]=0;		//	Initialize grid to 0 implying it is empty

	outtextxy(500,150,"Bot 1 : ");
	outtextxy(500,180,bot1Name);
	outtextxy(500,300,"Bot 2 : ");
	outtextxy(500,330,bot2Name);
	drawGrid(grid);
	while(1) {
		copyGrid(grid,gridDup);		//	gridDup=grid
		moveDup=move;
		if(move>0) {			//	player 1 chance to play... so call bot1()
//			printf("\nPlayer 1 to play... ");
			result=bot1(grid,move);
//			printf("\nPlayer 1 returned successfully");
		}
		else {				//	player 2 chance to play... so call bot2()
//			printf("\nPlayer 2 to play... ");
			result=bot2(grid,move);
//			printf("\nPlayer 2 returned successfully");
		}
		if(!(equalGrid(grid,gridDup) && move==moveDup)) {	//	grid() and move variables should not be changed
			printf("Bot %d error : Grid or move is modified!!!",move);
			delay(3000);
			exit(1);
		}
		checkForErrors(result,move,grid);			//	errors like result should be within the 0 to 6 range, etc...
//		animateGrid(move,grid,result);				//	make the piece to move
		rowNum=updateGrid(move,grid,result);			//	update the grid implying the move has been made
		drawGrid(grid);
		if(checkWinOrLose(grid,result,rowNum)) {		//	check for win condition
			win=move;					//	win will contain which bot has won
			break;
		}
		else if(checkDraw(grid)) {				//	check for draw condition
			win=0;						//	win=0 implies draw
			break;
		}
		move*=-1;						//	toggle between plaper 1 and player 2
		srand(time(NULL));			//	If any bot uses rand() function
	}

	if(win>0)				//	player 1 wins
		strcpy(displayStr,"Bot 1 wins!!!");
	else if(win<0)				//	player 2 wins
		strcpy(displayStr,"Bot 2 wins!!!");
	else					//	draw 
		strcpy(displayStr,"Game drawn!!!");

	outtextxy(100,430,displayStr);
	delay(15000);
	closegraph();

	// following code displays the game status after the game is played
	printf("\n\n\t%s\n\n\t\tgrid content : \n\n",displayStr);
	for(i=0;i<6;i++) {
		for(j=0;j<7;j++)
			printf("\t%d",grid[i][j]);
		printf("\n\n");
	}
	printf("\n\n");
	return 0;
}

/*	The rest of the program is not important for the participants... They can skip going through the rest of the code...	*/



int checkWinOrLose(int grid[][7],int result,int rowNum) {
//	For checking whether any win or lose condition is reached. Returns 1 if win or lose is reached. else returns 0
	int move=grid[rowNum][result];
	if(rowNum<=2 && grid[rowNum+1][result]==move && grid[rowNum+2][result]==move && grid[rowNum+3][result]==move)
		return 1;
	else {
		int count=1,i,j;
		for(i=result+1;i<7;i++) {
			if(grid[rowNum][i]!=move)
				break;
			count++;
		}
		for(i=result-1;i>=0;i--) {
			if(grid[rowNum][i]!=move)
				break;
			count++;
		}
		if(count>=4)
			return 1;
		count=1;
		for(i=result+1,j=rowNum+1;i<7 && j<6;i++,j++) {
			if(grid[j][i]!=move)
				break;
			count++;
		}
		for(i=result-1,j=rowNum-1;i>=0 && j>=0;i--,j--) {
			if(grid[j][i]!=move)
				break;
			count++;
		}
		if(count>=4)
			return 1;
		count=1;
		for(i=result+1,j=rowNum-1;i<7 && j>=0;i++,j--) {
			if(grid[j][i]!=move)
				break;
			count++;
		}
		for(i=result-1,j=rowNum+1;i>=0 && j<6;i--,j++) {
			if(grid[j][i]!=move)
				break;
			count++;
		}
		if(count>=4)
			return 1;
	}
	return 0;
}

int checkDraw(int grid[][7]) {
//	Checking for draw condition. Returns 1 if draw is reached. else returns 0
	int i;
	for(i=0;i<7;i++)
		if(grid[0][i]==0)
			return 0;
	return 1;
}

void copyGrid(int grid[6][7],int gridDup[6][7]) {
//	does dridDup=grid
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			gridDup[i][j]=grid[i][j];
}

int equalGrid(int grid[][7],int gridDup[][7]) {
//	return 1 if grid==gridDup... else returns 0
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			if(gridDup[i][j]!=grid[i][j])
				return 0;
	return 1;
}

void animateGrid(int move,int grid[6][7],int result) {
//	Function to make the pieces fall from the top
	int startX=100,startY=100,len=50,i,j,r=len/2,p=startX+r+len*result,n;
	for(i=0;i<6;i++)
		if(grid[i][result]!=0)
			break;
	i--;
	n=startY+r+len*i;
	r-=10;
	if(move>0) {	//	player 1
		for(j=startY-len;j<n;j+=4) {
//			drawGrid(grid);
			setcolor(RED);
			circle(p,j,r);
			floodfill(p,j,RED);
			setcolor(BLACK);
			circle(p,j,r);
			floodfill(p,j,BLACK);
		}
	}
	else if(move<0) {	//	player 2
		for(j=startY-len;j<n;j+=4) {
//			drawGrid(grid);
			setcolor(BLUE);
			circle(p,j,r);
			floodfill(p,j,BLUE);
			setcolor(BLACK);
			circle(p,j,r);
			floodfill(p,j,BLACK);
		}
	}
}

int updateGrid(int move,int grid[6][7],int result) {
//	Updates the grid with the next move
	int i;
	for(i=0;i<6;i++)
		if(grid[i][result]!=0)
			break;
	grid[i-1][result]=move;
	return i-1;
}

void checkForErrors(int result,int move,int grid[6][7]) {
//	error checks
	int err=0;
	char displayStr[50];
	if(move>0) {
		if(result<0 || result>6)	//	result should be within 0 to 6 range
			err=1;
		if(grid[0][result]!=0)		//	the result column should not be full
			err=2;
	}
	else {
		if(result<0 || result>6)
			err=-1;
		if(grid[0][result]!=0)
			err=-2;
	}
	if(err) {
//		closegraph();
		switch(err) {
			case 1 : strcpy(displayStr,"Bot 1 error : Result is out of bounds!!!"); break;
			case 2 : strcpy(displayStr,"Bot 1 error : Column is full!!!"); break;
			case -1 : strcpy(displayStr,"Bot 2 error : Result is out of bounds"); break;
			case -2 : strcpy(displayStr,"Bot 2 error : Column is full!!!"); break;
		}
		outtextxy(100,430,displayStr);
		delay(15000);
		printf("\n\n\t%s\n\n",displayStr);
		exit(1);
	}
}

void drawGrid(int grid[6][7]) {
//	Function to draw the grid and the pieces
//	Player 1 is red piece and player 2 is blue piece

	int startX=100,startY=100,len=50,i,j,r=len/2;

	outtextxy(200,50,"CONNECT 4");
//	cleardevice();
	setcolor(WHITE);
	for(i=0;i<7;i++)
		line(startX,startY+len*i,startX+len*7,startY+len*i);
	for(i=0;i<8;i++)
		line(startX+len*i,startY,startX+len*i,startY+len*6);
	for(i=0;i<6;i++)
		for(j=0;j<7;j++) {
			if(grid[i][j]>0) {	//	player 1
				setcolor(RED);
				circle(startY+r+len*j,startX+r+len*i,r-10);
				floodfill(startY+r+len*j,startX+r+len*i,RED);
			}
			else if(grid[i][j]<0) {	//	player 2
				setcolor(BLUE);
				circle(startY+r+len*j,startX+r+len*i,r-10);
				floodfill(startY+r+len*j,startX+r+len*i,BLUE);
			}
		}
}

