#include <stdio.h>

void GoodMorning();
void GoodAfternoon();
void GoodNight();

int main()
{

    printf("\nInitializing GoodMorning function");
    GoodMorning();

    printf("\nAll Done!");
    return 0;
}

void GoodMorning()
{
    printf("\nGood Morning!.");
    printf("\nInitializing GoodAfternoon function");
    GoodAfternoon();
    printf("\nInitializing GoodNight function");
    GoodNight();
}
void GoodAfternoon()
{
    printf("\nGood Afternoon!.");
}
void GoodNight()
{
    printf("\nGood Night!.");
}