#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int rand_Int(int from, int to); //Returns A Random Integer Between From and To Including From. 
char rand_Alpha(int alpha_Case);
int check_Condition(char player, char computer);

int main()
{
    char computer;
    int computer_Turn;
    char player;
    int computer_Points = 0, player_Points = 0;
    char name[20];

    printf("\nEnter Your Name: ");
    gets(name);

    printf("\n\nRock Paper Scissors\n\n");
    for (int i = 0; i < 3; i++)
    {    
        computer_Turn = rand_Int(1, 4);

        switch (computer_Turn)
        {
        case 1:
            computer = 'r';
            break;
        case 2:
            computer = 'p';
            break;
        case 3:
            computer = 's';
            break;
        default:
            break;
        }

        while (1)
        {
            printf("\n%s's Turn...\n", name);
            printf("\nOptions:");
            printf("\n\t1. 'r' : Rock");
            printf("\n\t2. 'p' : Paper");
            printf("\n\t3. 's' : Scissors");
            printf("\n\nEnter A Character For Your Turn: ");
            scanf("%c", &player);
            getchar();

            if (player == 's' || player == 'p' || player == 'r')
            {
                break;
            }
            else
            {
                printf("\nInvalid Entry! Try Again...");
            }
        }

        printf("\n\nComputer's Turn...");
        printf("\nComputer Choosen '%c'.", computer);

        switch (check_Condition(player, computer))
        {
        case 0:
            printf("\n\nOops! %s Lose The Round!\n\n", name);
            printf("\nComputer Got 1 Point!\n");
            computer_Points++;
            break;
        case 1:
            printf("\n\nCongratulations! %s Won The Round!\n\n", name);
            printf("\n%s Got 1 Point!\n", name);
            player_Points++;
            break;
        case 2:
            printf("\n\nOh No! It's A Tie Round!\n\n");
            printf("\nNo One Got a Point!\n");
            break;
        default:
            break;
        }

        printf("\nCurrent Match Status:");
        printf("\n\tComputer Points : %d", computer_Points);
        printf("\n\tPlayer Points   : %d", player_Points);
        printf("\n");
    }
    if (player_Points == computer_Points)
    {
        printf("\n\nIt's A tie Match! Well Played, %s\n", name);
    }
    else if (player_Points > computer_Points)
    {
        printf("\n\nCongo! %s Wins The Match!\n", name);
    }
    else
    {
        printf("\n\nOh No! %s Lose The Match! Better Luck Next Time!\n", name);
    }
    return 0;
}
int check_Condition(char player, char computer)
{
    if (player == computer)
    {
        return 2; // Tie Match
    }
    else 
    {
        if (player == 'r')
        {
            if (computer == 'p')
            {
                return 0; // Computer Wins
            }
            else
            {
                return 1; // Player Wins
            }
        }
        else if (player == 'p')
        {
            if (computer == 's')
            {
                return 0; // Computer Wins
            }
            else
            {
                return 1; // Player Wins
            }
        }
        else
        {   
            if (computer == 'r')
            {
                return 0; // Computer Wins
            }
            else
            {
                return 1; // Player Wins
            }
        }
    }
}
int rand_Int(int from, int to) 
{       
    int random;
    srand(time(NULL));
    random = from + rand() % (to - from);
    return random;
}
char rand_Alpha(int alpha_Case)
{
    char random;
    switch (alpha_Case)
    {
    case 0:
        random = 'a' + rand_Int(0, 26);
        break;
    case 1:
        random = 'A' + rand_Int(0, 26);
        break;
    case 2:
        int return_Case = rand_Int(0, 2);
        if (return_Case)
        {
            random = 'a' + rand_Int(0, 26);
        }
        else
        {
            random = 'A' + rand_Int(0, 26);
        }
        break;
    default:
        random = '\0';
        break;
    }
    return random;
}