#include <stdio.h>

int main()
{
    float grade, totalPercentage, marathi, hindi, sanskrit, english, algebra, geometry, science_I, science_II, history, politicalScience, geography;

    printf("Enter your marathi marks :- ");
    scanf("%f", &marathi);

    printf("Enter your hindi marks :- ");
    scanf("%f", &hindi);

    printf("Enter your sanskrit marks :- ");
    scanf("%f", &sanskrit);

    printf("Enter your english marks :- ");
    scanf("%f", &english);

    printf("Enter your algebra marks :- ");
    scanf("%f", &algebra);

    printf("Enter your geometry marks :- ");
    scanf("%f", &geometry);

    printf("Enter your science I marks :- ");
    scanf("%f", &science_I);

    printf("Enter your science II marks :- ");
    scanf("%f", &science_II);

    printf("Enter your history marks :- ");
    scanf("%f", &history);

    printf("Enter your politicalScience marks :- ");
    scanf("%f", &politicalScience);

    printf("Enter your geography marks :- ");
    scanf("%f", &geography);

    totalPercentage = ((marathi + hindi + sanskrit + english + algebra + geometry + science_I + science_II + history + politicalScience + geography) / 1100) * 100;

    printf("Your Total Perecentage is %f\n", totalPercentage);

    if (totalPercentage <= 33)
    {
        printf("Your Total marks percentage is very low, Your are fail. ||| Beter luck next time |||");
    }
    else if (marathi <= 33)
    {
        printf("Your marks in marathi subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (hindi <= 33)
    {
        printf("Your marks in hindi subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (sanskrit <= 33)
    {
        printf("Your marks in sanskrit subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (english <= 33)
    {
        printf("Your marks in english subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (algebra <= 33)
    {
        printf("Your marks in algebra subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (geometry <= 33)
    {
        printf("Your marks in geometry subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (science_I <= 33)
    {
        printf("Your marks in science_I subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (science_II <= 33)
    {
        printf("Your marks in science_II subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (history <= 33)
    {
        printf("Your marks in history subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (politicalScience <= 33)
    {
        printf("Your marks in politicalScience subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else if (geography <= 33)
    {
        printf("Your marks in marathi geography subject is very low,You are failed. ||| Beter luck next time |||");
    }
    else
    {
        if (totalPercentage >= 90)
        {
            printf("You are passed with A grade! ||| CONGRATULATIONS |||");
        }
        else if (totalPercentage >= 80)
        {
            printf("You are passed with B grade! ||| CONGRATULATIONS |||");
        }
        else if (totalPercentage >= 70)
        {
            printf("You are passed with C grade! ||| CONGRATULATIONS |||");
        }
        else if (totalPercentage >= 60)
        {
            printf("You are passed with D grade! ||| CONGRATULATIONS |||");
        }
        else if (totalPercentage >= 50)
        {
            printf("You are passed with E grade! ||| CONGRATULATIONS |||");
        }
        else
        {
            printf("You are passed with F grade! ||| CONGRATULATIONS |||");
        }
    }

    return 0;
}