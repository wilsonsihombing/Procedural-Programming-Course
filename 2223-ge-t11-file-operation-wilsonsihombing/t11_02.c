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
    char str1 [100];
    //str1[0] = '\0'; 
    char str2 [100];
    FILE *fs;
    FILE *fp; 
    fs = fopen("./storage/dorm-repository.txt", "r");
    fp = fopen ("./storage/student-repository.txt", "r");
    while(fgets(str1, 100, fs) != NULL){
        str1[strcspn(str1, "\n\r")] = '\0';
        char  *tok = strtok(str1, "|");
            strcpy(dorm[a].name, tok);
            tok = strtok(NULL, "|");
            dorm[a].capacity = atoi(tok);
            tok = strtok(NULL, "|");
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
    while(fgets(str2, 100, fp) != NULL){
        str2[strcspn(str2, "\n\r")] = '\0';
        char *tok = strtok(str2, "|");
            strcpy(student[x].id, tok);
           
           
            tok = strtok(NULL, "|");
            strcpy(student[x].name, tok);
            tok = strtok(NULL, "|");
            strcpy(student[x].year, tok); 
            tok = strtok(NULL, "|");
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
    fclose(fs);
    fclose(fp);
    
    FILE *inputstd;
    inputstd = fopen("./storage/student-repository.txt","a");
    FILE *inputdrm;
    inputdrm = fopen("./storage/dorm-repository.txt","a");
    
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
    
    
        /*while (masukan != false)
        {
        //fflush(stdin);
        fgets(inputan, sizeof(inputan), stdin);
        inputan[strcspn(inputan,"\r\n")] = 0;
        */ 
        char *token = strtok(inputan ,"#");
        if (strcmp (token ,"student-add") == 0)
        {
            
            token = strtok(NULL, "#");
            strcpy(student[x].id, token);
            token = strtok(NULL, "#");  
            strcpy(student[x].name, token);
            token = strtok(NULL, "#");
            strcpy(student[x].year, token);
            token = strtok(NULL, "#");
            if(strcmp(token, "male") == 0)
            {
                student[x].gender = 0;
                
                fprintf(inputstd, "%s|%s|%s|male\n", student[x].id, student[x].name, student[x].year);
                
                x++;  
            }
            else if(strcmp(token ,"female") == 0)
            {
                student[x].gender = 1;  
                
                fprintf(inputstd, "%s|%s|%s|female\n", student[x].id, student[x].name, student[x].year);
                
                x++;  
            } 
           
                        
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
        else if(strcmp(token, "dorm-add") == 0 )
        {
            token = strtok(NULL, "#");
            strcpy(dorm[a].name, token); 
            token = strtok(NULL, "#");
            dorm[a].capacity = atoi(token);
            token = strtok(NULL, "#");
            if(strcmp(token, "male") == 0) 
            {
                dorm[a].gender = 0;
                
                fprintf(inputdrm, "%s|%d|male\n", dorm[a].name, dorm[a].capacity);
                
                a++;   
            }
            else if(strcmp(token ,"female") == 0) 
            {
                dorm[a].gender = 1;
                
                fprintf(inputdrm, "%s|%d|female\n", dorm[a].name, dorm[a].capacity);
            
                a++;   
            } 

             
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
        else if(strcmp(inputan, "assign-student") == 0)
        {
            char *_id = strtok(NULL, "#");
            char *_dorms = strtok(NULL, "#");
            int index_std = count_std( x,_id, student, dorm);
            int index_drm = count_drm(a,_dorms, student, dorm);
            
            assign_student( index_std , index_drm , student , dorm);
            
        }
        else if(strcmp(inputan, "---") == 0){ 
            masukan = false;
        } 
        
          
    }
    fclose(inputstd); 
    fclose(inputdrm);
    free(student);
    free(dorm);
    
    return 0;
 
}
