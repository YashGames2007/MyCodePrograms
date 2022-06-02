#include <stdio.h>

int main()
{
    FILE *git = NULL;
    git = fopen("E:\\Programming files\\Code\\C\\Basic Programming\\New Beggining\\Git_Commands.txt", "r");
    char i;
    int spaces;
    fscanf(git, "%s", i);
    printf("\nEntry\n");
    while (i != EOF)
    {
        if (i == '$')
        {
            spaces = 0;
            printf("\n");
            while (spaces != 2)
            {
                if (i == ' ')
                {
                    spaces++;
                }
                else
                {
                    spaces = 0;
                }
                printf("%c", i);
                i = fgetc(git);
            }
        }
        
        i = fgetc(git);
    }
    fclose(git);
    printf("\nExit");
    return 0;
}