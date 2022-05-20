#include <stdio.h>

void printBox(char *characters);
int conditionCheck(char *characters);

int main()
{
    int turn;
    char array[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    printf("\n   ***   Tic Tac Toe   ***   ");
    printf("\nPlayer1's Turn...");
    printBox(array);

    printf("\nType the number of position that you have to place your 'X' :- ");
    scanf("%d", &turn);

    array[turn - 1] = 'X';
    printBox(array);
    printf("\nPlayer1 placed his X at %d No. place.", turn);

    for (int i = 0; i < 4; i++)
    {
        printf("\nPlayer2's Turn...");
        printBox(array);
        printf("\nType the number of position that you have to place your 'O' :- ");
        scanf("%d", &turn);

        array[turn - 1] = 'O';
        printBox(array);
        printf("\nPlayer2 placed his O at %d No. place.", turn);

        if (conditionCheck(array))
        {
            printf("\n");
            printf("\nPlayer2 wins the match");
            printf("\n   *** Congratulations ***   ");
            printf("\n       - for Player2's Victory.");
            break;
        }
        else
        {
            printf("\nPlayer1's Turn...");
            printBox(array);
            printf("\nType the number of position that you have to place your 'X' :- ");
            scanf("%d", &turn);

            array[turn - 1] = 'X';
            printBox(array);
            printf("\nPlayer1 placed his X at %d No. place.", turn);

            if (conditionCheck(array))
            {
                printf("\n");
                printf("\nPlayer1 wins the match.");
                printf("\n   *** Congratulations ***   ");
                printf("\n      - for player1's Victory.");
                break;
            }
        }
    }
    if (conditionCheck(array) == 0)
    {
        printf("\n");
        printf("\nIt's a Tie match.");
        printf("\nwell played...");
        printf("\nBetter luck next time!");
    }
    return 0;
}
void printBox(char *characters)
{
    printf("\n");
    printf("\n");
    printf(" %c | %c | %c", characters[0], characters[1], characters[2]);
    printf("\n");
    printf("---+---+---");
    printf("\n");
    printf(" %c | %c | %c", characters[3], characters[4], characters[5]);
    printf("\n");
    printf("---+---+---");
    printf("\n");
    printf(" %c | %c | %c", characters[6], characters[7], characters[8]);
    printf("\n");
}
int conditionCheck(char *list)
{
    int win;
    if (list[0] == list[1] && list[1] == list[2])
    {
        win = 1;
    }
    else if (list[3] == list[4] && list[4] == list[5])
    {
        win = 1;
    }
    else if (list[6] == list[7] && list[7] == list[8])
    {
        win = 1;
    }
    else if (list[0] == list[3] && list[3] == list[6])
    {
        win = 1;
    }
    else if (list[1] == list[4] && list[4] == list[7])
    {
        win = 1;
    }
    else if (list[2] == list[5] && list[5] == list[8])
    {
        win = 1;
    }
    else if (list[0] == list[4] && list[4] == list[8])
    {
        win = 1;
    }
    else if (list[2] == list[4] && list[4] == list[6])
    {
        win = 1;
    }
    else
    {
        win = 0;
    }
    return win;
}