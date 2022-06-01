#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int ulli;

typedef struct Travel_Agency_Driver
{
    char *name;
    char *driving_License_Number;
    char *route_Name;
    ulli *travel_Distance;
} driver;

void *get_Details(driver *new_Driver);
void present_Details(driver *new_Driver);

int main()
{
    int total = 3;
    char condition, not = 1;

    // printf("\nEnter The Number of Drivers Working At Travel Agency: ");
    // scanf("%d", &total);

    const int total_Drivers = total;
    driver *drivers = (driver *)malloc(total_Drivers * sizeof(driver));

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
            get_Details(&drivers[i]);
            break;
        case 1:
            printf("\nEnter The Details of 2nd Driver: \n");
            get_Details(&drivers[i]);
            break;
        case 2:
            printf("\nEnter The Details of 3rd Driver: \n");
            get_Details(&drivers[i]);
            break;
        default:
            printf("\nEnter The Details of %dth Driver: \n", (i + 1));
            get_Details(&drivers[i]);
            break;
        }
        present_Details(&drivers[i]);
        while (not )
        {
            printf("\nShould We Proceed Further (y/n): ");
            condition = 'Y';
            // scanf("%s", &condition);
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

    for (int i = 0; i < total_Drivers; i++)
    {
        free(drivers[i].name);
        free(drivers[i].driving_License_Number);
        free(drivers[i].route_Name);
        free(drivers[i].travel_Distance);
    }
    free(drivers);
    return 0;
}
void *get_Details(driver *new_Driver)
{
    char *name  = (char *)malloc(100 * sizeof(char));
    char *dl_No = (char *)malloc(100 * sizeof(char));
    char *route = (char *)malloc(1000 * sizeof(char));
    ulli *travel_Dist = (ulli *)malloc(sizeof(ulli));

    printf("\n\n(Maximum No. of Characters Should be Entered: 100)");
    printf("\nEnter Your Name: ");
    // getchar();
    // gets(name);
    strcpy(name, "name");

    printf("\n\n(Maximum No. of Characters Should be Entered: 100)");
    printf("\nEnter Your Driving License Number [DL No.]: ");
    // gets(dl_No);
    strcpy(dl_No, "dl_No");

    printf("\n\n(Maximum No. of Characters Should be Entered: 1000)");
    printf("\nEnter Your Travelling Route Name: ");
    // gets(route);
    strcpy(route, "route");

    printf("\n\n(Value Should be in KiloMeters. [kms])");
    printf("\nEnter Traveled Distance: ");
    // scanf("%llu", travel_Dist);
    *travel_Dist = 500;

    new_Driver -> name                   = (char *)malloc((strlen(name) + 1)  * sizeof(char));
    new_Driver -> driving_License_Number = (char *)malloc((strlen(dl_No) + 1) * sizeof(char));
    new_Driver -> route_Name             = (char *)malloc((strlen(route) + 1) * sizeof(char));
    new_Driver -> travel_Distance        = (ulli *)malloc(sizeof(ulli));


    strcpy(new_Driver -> name, name);
    strcpy(new_Driver -> driving_License_Number, dl_No);
    strcpy(new_Driver -> route_Name, route);
    *new_Driver -> travel_Distance = *travel_Dist;

    free(name);
    free(dl_No);
    free(route);
    free(travel_Dist);
}
void present_Details(driver *new_Driver)
{
    printf("\nDriver's Name              : %s      ", new_Driver -> name);
    printf("\nDriver's DL No.            : %s      ", new_Driver -> driving_License_Number);
    printf("\nDriver's Route             : %s      ", new_Driver -> route_Name);
    printf("\nDriver's Traveled Distance : %llu Kms", *new_Driver -> travel_Distance);
    printf("\n");
}