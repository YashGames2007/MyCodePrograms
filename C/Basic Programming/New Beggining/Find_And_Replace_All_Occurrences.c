#include <stdio.h>
#include <string.h>

void find_And_Replace_All_Occurrences(char *path, char *finder, char *replacer); 

int main()
{
    char *file_Path;
    file_Path = "E:\\Programming files\\Code\\C\\Basic Programming\\New Beggining\\git_Commands2.txt";

    find_And_Replace_All_Occurrences(file_Path, "{{git}}", "git");
    find_And_Replace_All_Occurrences(file_Path, "{{Used To Show}}", "shows");
    // fclose(git);
    return 0;
}
void find_And_Replace_All_Occurrences(char *path, char *finder, char *replacer)
{
    FILE *file = NULL;
    FILE *temp = NULL;

    file = fopen(path, "r");
    // temp = fopen("temp.txt", "w");
    temp = fopen("temp.txt", "a+");
    char tempFinder[strlen(finder) + 1];

    char character = fgetc(file);

    while (character != EOF)
    {
        if (character == finder[0])
        {
            int i = 0;
            while (character  == finder[i])
            {
                tempFinder[i] = character;
                character = fgetc(file);
                i++;
            }
            tempFinder[i] = '\0';
            if (strlen(tempFinder) == strlen(finder))
            {
                fputs(replacer, temp);
            }
            else
            {
                fputs(tempFinder, temp);
            }
            fputc(character, temp);
        }
        else
        {
            fprintf(temp, "%c", character);
        }
        character = fgetc(file);
    }
    fclose(temp);
    temp = fopen("temp.txt", "a+");
    character = fgetc(temp);
    printf("\nCharacter: %c.", character);
    file = freopen(path, "w", file);
    file = freopen(path, "a", file);
    while (character != EOF)
    {
        fputc(character, file);
        character = fgetc(temp);
    }
    fclose(file);
    fclose(temp);
    remove("temp.txt");
}