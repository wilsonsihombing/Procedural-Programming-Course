// 12S22011 - Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include "academic.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

char *grade_to_text(enum grade_t _grade)
{

    char *value = (char *)malloc(20 * sizeof(char *));
    if (_grade == GRADE_NONE)
    {
        strcpy(value, "None");
    }
    else if (_grade == GRADE_T)
    {
        strcpy(value, "T");
    }
    else if (_grade == GRADE_E)
    {
        strcpy(value, "E");
    }
    else if (_grade == GRADE_D)
    {
        strcpy(value, "D");
    }
    else if (_grade == GRADE_C)
    {
        strcpy(value, "C");
    }
    else if (_grade == GRADE_BC)
    {
        strcpy(value, "BC");
    }
    else if (_grade == GRADE_B)
    {
        strcpy(value, "B");
    }
    else if (_grade == GRADE_AB)
    {
        strcpy(value, "AB");
    }
    else if (_grade == GRADE_A)
    {
        strcpy(value, "A");
    }
    else
    {
        strcpy(value, "None");
    }

    return value;
}

float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
    float performa;
    if (_grade == GRADE_A)
    {
        performa = _credit * 4.0;
    }
    else if (_grade == GRADE_AB)
    {
        performa = _credit * 3.5;
    }
    else if (_grade == GRADE_B)
    {
        performa = _credit * 3.0;
    }
    else if (_grade == GRADE_BC)
    {
        performa = _credit * 2.5;
    }
    else if (_grade == GRADE_C)
    {
        performa = _credit * 2.0;
    }
    else if (_grade == GRADE_D)
    {
        performa = _credit * 1.0;
    }
    else if (_grade == GRADE_E)
    {
        performa = _credit * 0.0;
    }
    else if (_grade == GRADE_T)
    {
        performa = _credit * 0.0;
    }
    else if (_grade == GRADE_NONE)
    {
        performa = 0.0 * _credit;
    }
    else
    {
        performa = 0.0;
    }

    return performa;
}

void print_course(struct course_t _course)
{
    // t07, write your code here
    char *nilai = grade_to_text(_course.passing_grade);

    printf("%s|", _course.code);
    printf("%s|", _course.name);
    printf("%d|", _course.credit);  
    printf("%s\n", nilai);
}

void print_student(struct student_t _student)
{
    printf("%s|", _student.id);
    printf("%s|", _student.name);
    printf("%s|", _student.year);
    printf("%s\n", _student.study_program);
}

void print_enrollment(struct enrollment_t _enrollment)
{
    char *nilai = grade_to_text(_enrollment.grade);
    float perfor = calculate_performance(_enrollment.grade, _enrollment.course.credit);
    printf("%s|", _enrollment.course.code);
    printf("%s|", _enrollment.student.id);
    printf("%s|", nilai);
    printf("%.2f\n", perfor);
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade)
{
    struct course_t crs;

    strcpy(crs.code, _code);
    strcpy(crs.name, _name);
    crs.credit = _credit;
    crs.passing_grade = _passing_grade;

    return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program)
{
    struct student_t std;

    strcpy(std.id, _id);
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    strcpy(std.study_program, _study_program);

    return std;
}

struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester)
{

    struct enrollment_t emt;

    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year, _year);
    emt.semester = _semester;

    return emt;
}
