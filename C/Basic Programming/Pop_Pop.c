#include <stdio.h>

void print_Array(char *array, int size);
void printBox_PopPop(char *tokenArray);
void place_Tokens(char *tokenArray, int player, int place);
int conditionChecker_PopPop(char *tokenArray);

int main()
{
    char tokens[72];
    char *token = &tokens[0];

    char j = '0';
    for (char i = '1'; i <= '9'; i++)
    {
        *token = j;
        token++;
        *token = i;
        token++;

        if (i == '9')
        {
            j++;
            *token = j;
            token++;
            *token = '0';
            token++;
            i = '0';
        }
        if (j == '3' && i == '6')
        {
            break;
        }
    }


    unsigned short place, player, p1_Points, p2_Points, total_Points, game_Over;

    // print_Array(&tokens[0], 72);
    // printBox_PopPop(&tokens[0]);

    // place_Tokens(&tokens[0], player, place);
    // printBox_PopPop(&tokens[0]);

    do
    {
        game_Over = 0;
        p1_Points = 0;
        p2_Points = 0;
        char *token = &tokens[0];

        for (short i = 36; i > 0; i--)
        {
            total_Points = p1_Points + p2_Points;
            
            if (i % 2 == 0)
            {
                player = 1;
                printf("\nPlayer 1 Turn...");
                printBox_PopPop(&tokens[0]);
                print_Array(&tokens[0], 72);
                printf("\nType The Number Of The Position Where You Want To Place Your P : ");
                scanf("%d", &place);
                printf("\n%p", &tokens[0]);
                place_Tokens(token, player, place);
                printf("\n%p", &tokens[0]);
                printf("\nSuccesfully Placed.");
                printBox_PopPop(&tokens[0]);
                print_Array(&tokens[0], 72);

                if (total_Points != conditionChecker_PopPop(&tokens[0]))
                {
                    p1_Points += conditionChecker_PopPop(&tokens[0]) - total_Points;
                }
                printf("\nPlayer 1 Points: %d", p1_Points);
                printf("\nPlayer 2 Points: %d", p2_Points);
            }
            else
            {
                player = 2;
                printf("\nPlayer 2 Turn...");
                printBox_PopPop(&tokens[0]);
                print_Array(&tokens[0], 72);
                printf("\nType The Number Of The Position Where You Want To Place Your O : ");
                scanf("%d", &place);
                place_Tokens(token, player, place);
                printf("\nSuccesfully Placed.");
                printBox_PopPop(&tokens[0]);
                print_Array(&tokens[0], 72);

                if (total_Points != conditionChecker_PopPop(&tokens[0]))
                {
                    p2_Points += conditionChecker_PopPop(&tokens[0]) - total_Points;
                }
                printf("\nPlayer 1 Points: %d", p1_Points);
                printf("\nPlayer 2 Points: %d", p2_Points);
            }
            if (i > 36 || i < 0)
            {
                break;
            }
        }
        printf("\nDo You Want To Play Again?\n1) Yes\t0) No\n");
        scanf("%d", &game_Over);

    } while (game_Over);

    return 0;
}

void print_Array(char *array, int size)
{
    printf("\n{");
    for (int i = 0; i < size - 1; i++)
    {
        printf("'%c', ", *array++);
    }
    printf("'%c'}", *array);
}

void printBox_PopPop(char *tokens)
{
    printf("\n\n#-----------------------------#\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("| %c", *tokens);
            tokens++;
            printf("%c ", *tokens);
            tokens++;
        }
        if (i < 5)
        {
            printf("|\n|----+----+----+----+----+----|\n");
        }
    }
    printf("|\n#-----------------------------#\n\n");
}

void place_Tokens(char *tokenArray, int player, int place)
{
    /*
    place = 1 : tA[0] = ' ', tA[1] = 'P'
    place = 2 : tA[2] = ' ', tA[3] = 'P'
    */
    // Formula : place = n : tokenArray[(n * 2) -2] = ' ', tokenArray[(n * 2) - 1] = 'P'.
    if (tokenArray[1] == ' ')
    {
        printf("\nGliched Before");
    }
    if (player == 1)
    {
        tokenArray[(place * 2) - 2] = ' ';
        tokenArray[(place * 2) - 1] = 'P';
    }
    else
    {
        tokenArray[(place * 2) - 2] = ' ';
        tokenArray[(place * 2) - 1] = 'O';
    }
    if (tokenArray[1] == ' ')
    {
        printf("\nGliched After");
    }
}

int conditionChecker_PopPop(char *tokenArray)
{
    int points = 0;
    /*
    Vertical Checks : t1 = P, t3 = O, t5 = P.
                      t3 = P, t5 = O, t7 = P. 
                      t5 = P, t7 = O, t9 = P. 
                      t7 = P, t9 = O, t11 = P. 

                      t13 = P, t15 = O, t17 = P. 
                      t15 = P, t17 = O, t19 = P. 
                      t17 = P, t19 = O, t21 = P. 
                      t19 = P, t21 = O, t23 = P. 
                    
                    ...

                      t67 = P, t69 = O, t71 = P.

    for(int i = 1, i <= 67, i+=2)
    */

    // For Loop for Vertical Checks :
    for (int i = 1; i <= 67; i+=2)
    {
        if (i == 9 || i == 11 || i == 21 || i == 23 || i == 33 || i == 35 || i == 45 || i == 47 || i == 57 || i == 59)
        {
            /* Nothing To Do. */
        }
        else
        {
            // printf("\nt%d = P, t%d = O, t%d = P.", i, i + 2, i + 4);
            if (tokenArray[i] == 'P' && tokenArray[i + 2] == 'O' && tokenArray[i + 4] == 'P')
            {
                points++;
            } 
        }
    }
    return points;
}