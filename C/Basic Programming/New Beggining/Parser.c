#include <stdio.h>
#include <string.h>

void parser(char *string, char *parsed_String);
int main()
{
    char string[100], parsed_String[100] = "";
    printf("\nEnter The HTML Code To Be Parsed (Maximum Characters: 100): ");
    gets(string);
    parser(string, parsed_String);
    printf("\nParsed Code: %s", parsed_String);
    return 0;
}
void parser(char *string, char *parsed_String)
{
    int i = 0, len = 0;
    while (string[i] != '\0')
    {
        while (string[i] == ' ' && string[i + 1] == ' ')
        {
            i++;
        }
        if (string[i] == '<')
        {
            while (string[i] != '>')
            {
                i++;
            }
            if (string[i + 1] == ' ')
            {
                i++;
            }
        }
        else
        {
            while (string[i] == ' ' && string[i + 1] == ' ')
            {
                i++;
            }
            // parsed_String += string[i];
            parsed_String[len] = string[i];
            len++;
        }
        i++;
    }
    if (parsed_String[len - 1] == ' ')
    {
        parsed_String[len - 1] = '\0';
    }
    else
    {
        parsed_String[len] = '\0';
    }
    
    // puts(parsed_String);
}