// 12s22011 - Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int _argc, char **_argv)
{
    struct student_t *student = malloc(100 * sizeof(struct student_t));
    struct dorm_t *dorm = malloc(100 * sizeof(struct dorm_t));
    bool masukan = true;
    char inputan[100];
    //char id[10];
    //char name[50];
    //char year[10];
    //char dorm_name[10];
    int x = 0; 
    int a = 0;
     
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

        char *tok = strtok(inputan ,"#");

        if (strcmp (tok ,"student-add") == 0)
        {
            tok = strtok(NULL, "#");
            strcpy(student[x].id, tok);
            tok = strtok(NULL, "#");
            strcpy(student[x].name, tok);
            tok = strtok(NULL, "#");
            strcpy(student[x].year, tok);
            tok = strtok(NULL, "#");
            if(strcmp(tok, "male") == 0)
            {
                student[x].gender = 0;
            }
            else if(strcmp(tok ,"female") == 0)
            {
                student[x].gender = 1;
            }
           
            x++;
            create_student(student-> id,student -> name, student -> year, student -> gender);
        }
        else if(strcmp(inputan, "student-print-all-detail") == 0)
        {
            print_students(student, x);
        }
        else if(strcmp(inputan, "student-print-all") == 0)
        {
            print_student(student, x);
        }
        else if(strcmp(tok, "dorm-add") == 0 )
        {
            tok = strtok(NULL, "#");
            strcpy(dorm[a].name, tok);
            tok = strtok(NULL, "#");
            dorm[a].capacity = atoi(tok);
            tok = strtok(NULL, "#");
            if(strcmp(tok, "male") == 0)
            {
                dorm[a].gender = 0;
            }
            else if(strcmp(tok ,"female") == 0)
            {
                dorm[a].gender = 1;
            } 

            a++; 
            create_dorm(dorm -> name, dorm -> capacity, dorm -> gender); 
        } 
        else if(strcmp(inputan, "dorm-print-all-detail") == 0)
        { 
            print_dorm(dorm, a);
        }
        else if(strcmp(inputan, "dorm-print-all") == 0) 
        {
            print_dorms(dorm, a);
        }
        else if(strcmp(tok, "assign-student") == 0)
        {
            char *_id = strtok(NULL, "#");
            char *_dorms = strtok(NULL, "#");
            for ( int i = 0 ; i < x; i++)
            {
                if (strcmp(student[i].id, _id) == 0) 
                {
                    for(int c = 0 ; c < a ; c++)
                    { 
                        if (strcmp(dorm[c].name , _dorms) == 0)
                        {
                            assign_student(&student[i], &dorm[c], _id , _dorms);
                        }
                    }
                }
            }
            
        }
        else if(strcmp(tok, "move-student") == 0)
        {
            char *_id1 = strtok(NULL, "#"); 
            char *_dorms1 = strtok(NULL, "#");
            int c = 0;
            for (int i = 0; i < x ; i++)
            {
                if (strcmp(student[i].id , _id1) == 0 )
                {
                    if(student[i].dorm -> name == NULL)
                    {
                        for ( c = 0; c < a; c++)
                        {
                            if(strcmp(dorm[c].name, _dorms1) == 0)
                            {
                                void (*pf)(struct student_t *_student,struct dorm_t *_dorm, char *_id1, char *_dorms1) = NULL;
                                pf = assign_student;
                                pf(&student[i], &dorm[c], _id1, _dorms1);
                                
                            }
                        }
                        
                    }
                    else
                    {
                        for(int d = 0; d < a; d++)
                        { 
                            if(strcmp(dorm[d].name, _dorms1) == 0)
                            {
                                for(int e = 0; e < a; e++)
                                {
                                    if(student[i].dorm -> name == dorm[e].name)
                                    {
                                        void (*pf)(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *_id1, char *_dorms1) = NULL;
                                        pf = move_student;
                                        pf(&student[i], &dorm[d], &dorm[e], _id1, _dorms1);
                                        
                                    }
                                }
                                
                               
                            }
                        }
                    }
                }
            }
        }
        
        else if(strcmp(inputan, "---") == 0){
            masukan = false;
        }
        
        
    }
    return 0;
}



