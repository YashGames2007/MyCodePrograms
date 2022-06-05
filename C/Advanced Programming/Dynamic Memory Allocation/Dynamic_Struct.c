#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct person {
    int id;
    char *name;
} Person;


Person * create_human(const char *new_name, int id) 
{
    Person *human = malloc(sizeof(Person));       // memory for the  human

    human->name = malloc(strlen(new_name) + 1);   // memory for the string
    strcpy(human->name, new_name);                // copy the name

    human->id = id;                               // assign the id 

    return human; 
}

int main()
{
    Person *human = create_human("John Smith", 666);

    printf("Human= %s, with id= %d.\n", human->name, human->id);

    // Do not forget to free his name, id and human 
    free(human->name);
    free(human->id);
    free(human);

    return 0;
}