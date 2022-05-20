#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game();

int main()
{
    int wh;
    do
    {
        game();
        printf("\nDo You Want To Play Again ?");
        printf("\nIf Yes press 1, if no press 2 :- ");
        scanf("%d", &wh);

        if (wh == 2)
        {
            printf("\n***||| Thanks For Playing |||***");
            break;
        }

    } while (1);

    return 0;
}
void game()
{
    int max, number, difficulty, guess, turns = 0;
    srand(time(0));

    printf("Choose the difficulty level.\n");
    printf("Press 1 for easy.\n");
    printf("Press 2 for normal.\n");
    printf("Press 3 for hard.\n");
    scanf("%d", &difficulty);

    if (difficulty == 1)
    {
        max = 10;
        printf("The number is between 1 to 10.\n");
    }
    else if (difficulty == 2)
    {
        max = 100;
        printf("The number is between 1 to 100.\n");
    }
    else if (difficulty == 3)
    {
        max = 1000;
        printf("The number is between 1 to 1000.\n");
    }

    number = rand() % max + 1;
    //printf("The random number generated is :- %d \n", number);

    printf("Type the guess :- ");
    do
    {
        turns++;
        scanf("%d", &guess);
        if (guess < number)
        {
            printf("Try greater one :- ");
        }
        else if (guess > number)
        {
            printf("Try Lower one :- ");
        }
        else if (guess == number)
        {
            printf("***|||***CONGRATULATIONS***|||***\n");
            printf("You guessed the correct number.\n");
            printf("Total guesses = %d\n", turns);
        }

    } while (guess != number);
}