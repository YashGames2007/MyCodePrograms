#include <stdio.h>

int main()
{
    int principle, rate, time;

    printf("Enter the Principal Ammount :- ");
    scanf("%d", &principle);

    printf("Enter the Rate of the Interest :- ");
    scanf("%d", &rate);

    printf("Enter the Time in Years :- ");
    scanf("%d", &time);

    float SI, CI;
    SI = (principle * rate * time) / 100;
    CI = (principle * (((100 + rate) / 100) ^ time)) - principle;

    printf("Simple Interest :- %f \n", SI);
    printf("Compound Interest :- %f", CI);
    return 0;
}