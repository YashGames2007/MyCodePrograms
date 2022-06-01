#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Travel_Agency_Driver
{
    char name[20];
    char driving_License_Number[20];
    char route_Name[50];
    unsigned long travel_Distance;
} driver;

driver get_Details();
void present_Details(driver *new_Driver);
void clear(void);

int main()
{
    int total;
    char condition, not = 1;

    printf("\nEnter The Number of Drivers Working At Travel Agency: ");
    scanf("%d", &total);

    const int total_Drivers = total;
    driver drivers[total_Drivers];

    printf("\n\n*** Travel Agency Drivers Information Submission ***\n");
    printf("\nRules:");
    printf("\n1. Every Driver Will Enter His/Her Information 1 by 1 only.");
    printf("\n2. Information Should Be Entered as per The Instructions And Limits.");
    printf("\n3. After Entering Information of an Driver, his Stored Information will be Displayed to Check The Correctness.");
    printf("\nType 'Y/y' If The Information is Correct, if Some Mistakes are There then Type 'N/n' to Reenter The Details.");
    printf("\n\n");

    for (int i = 0; i < total_Drivers; i++)
    {
        not = 1;
        switch (i)
        {
        case 0:
            printf("\nEnter The Details of 1st Driver: \n");
            drivers[i] = get_Details();
            break;
        case 1:
            printf("\nEnter The Details of 2nd Driver: \n");
            drivers[i] = get_Details();
            break;
        case 2:
            printf("\nEnter The Details of 3rd Driver: \n");
            drivers[i] = get_Details();
            break;
        default:
            printf("\nEnter The Details of %dth Driver: \n", (i + 1));
            drivers[i] = get_Details();
            break;
        }
        present_Details(&drivers[i]);
        while (not )
        {
            printf("\nShould We Proceed Further (y/n): ");
            scanf("%s", &condition);
            if (condition == 'Y' || condition == 'y')
            {
                not = 0;
            }
            else if (condition == 'N' || condition == 'n')
            {
                printf("\nReinitializing The Details of The Current Driver, Please Enter Them Again: ");
                i--;
                not = 0;
            }
            else
            {
                printf("\nInvalid Entry, Please Type 'Y' or 'N' Only.");
                continue;
            }
        }
    }
    printf("\n\n");
    printf("\nSuccessfully Scanned Information Of All The Drivers!!!");

    printf("\n\n\nTravel Agency Drivers Detailed List: \n\n");

    for (int i = 0; i < total_Drivers; i++)
    {
        printf("\n\nDriver No. %d\n", (i + 1));
        present_Details(&drivers[i]);
    }
    printf("\n\n");
    return 0;
}
driver get_Details()
{
    driver new_Driver;
    char name[20];
    char dl_No[20];
    char route[50];

    printf("\n\n(Maximum No. of Characters Should be Entered: 20)");
    printf("\nEnter Your Name: ");
    clear();
    gets(name);

    printf("\n\n(Maximum No. of Characters Should be Entered: 20)");
    printf("\nEnter Your Driving License Number [DL No.]: ");
    gets(dl_No);

    printf("\n\n(Maximum No. of Characters Should be Entered: 50)");
    printf("\nEnter Your Travelling Route Name: ");
    gets(route);

    printf("\n\n(Value Should be in KiloMeters. [kms])");
    printf("\nEnter Traveled Distance: ");
    scanf("%d", &new_Driver.travel_Distance);

    strcpy(new_Driver.name, name);
    strcpy(new_Driver.driving_License_Number, dl_No);
    strcpy(new_Driver.route_Name, route);

    return new_Driver;
}
void present_Details(driver *new_Driver)
{
    printf("\nDriver's Name              : %s    ", new_Driver -> name);
    printf("\nDriver's DL No.            : %s    ", new_Driver -> driving_License_Number);
    printf("\nDriver's Route             : %s    ", new_Driver -> route_Name);
    printf("\nDriver's Traveled Distance : %d Kms", new_Driver -> travel_Distance);
    printf("\n");
}
void clear(void)
{
    while (getchar() != '\n')
        ;
}