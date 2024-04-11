// 12S22011 - Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include "./libs/todo.h"
#include "./libs/repository.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int _argc, char **_argv)
{

    
    struct todo_t *todo = malloc(100 * sizeof(struct todo_t));
    bool masukan = true;
    char inputan[100];


    int x = 0;
    char str1[100];
    str1[0] = '\0'; 
    FILE *td;
    td = fopen("./storage/todo-repository.txt", "r");

    while(fgets(str1, 100, td) != NULL)
    {
        str1[strcspn(str1, "\n\r")] = '\0';
        char *tok = strtok(str1, "|");
        todo[x].id = atoi(tok);
        tok = strtok(NULL, "|");
        strcpy(todo[x].time, tok);
        tok = strtok(NULL, "|");
        strcpy(todo[x].activity, tok);
        tok = strtok(NULL,"|");
        strcpy(todo[x].status, tok);

        x++;
        


    }
    fclose(td);
   
    FILE *inputtd;
    inputtd =  fopen("./storage/todo-repository.txt", "a");
    while (masukan != false)
    {
        fflush(stdin);
        inputan[0] = '\0'; 
        int i = 0;
        while (1 == 1)
        {
            char j = getchar();
            if (j == '\n')
            {
                break;
            }else if(j == '\r')
            { 
                continue;
            }
            inputan[i] = j;
            inputan[++i] = '\0';
        }

        char *token = strtok(inputan ,"#");
        if (strcmp (inputan, "todo-print-all") == 0)
        {
            print_todo(todo, x);
        }
        else if(strcmp(token, "todo-add") == 0)
        {
            int a = x + 1;
            todo[x].id = a;
            
            //token = strtok(NULL, "#");
            //todo[x].id = atoi(token);
            token = strtok(NULL, "#");
            strcpy(todo[x].time, token);
            token = strtok(NULL, "|");
            strcpy(todo[x].activity, token);
            strcpy(todo[x].status, "none");
            fprintf(inputtd, "%d|%s|%s|%s\n", todo[x].id, todo[x].time, todo[x].activity, todo[x].status);
            x++;

            //create_todo(a, todo -> time, todo ->activity);
        }
        else if(strcmp(token, "todo-status") == 0)
        {
            token = strtok(NULL, "#"); 
            for(int a = 0; a < x; a++)
            {
                if(todo[a].id ==  atoi(token))
                {
                    token = strtok(NULL, "|"); 
                    if(strcmp(token, "canceled") == 0)
                    {
                        break;
                    }
                    else 
                    {
                        strcpy(todo[a].status, token);
                    }
                    
                } 
            }
            
            
        }
        else if(strcmp(inputan, "---") == 0)
        {
            masukan = false;
        }
    }
    fclose(inputtd);
    return 0;
}
