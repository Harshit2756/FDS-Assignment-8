/*Harshit Khandelwal
SYITA169
Assignment 8
Department maintains student information. The file contains roll, name, division, and address. To create a sequential file to store and maintain student data. add, delete information of the student.*/
#include <stdio.h>
#include <stdlib.h>

struct stud
{
    int roll;
    char name[20];
    float per;
} s[10];

void accept(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of student %d :- ", i + 1);
        printf("\n\nEnter the Name :-");
        scanf("%s", s[i].name);
        printf("Enter Roll Number :- ");
        scanf("%d", &s[i].roll);
        printf("Enter Percentage :- ");
        scanf("%f", &s[i].per);
    }
}

void write_to_file(int n)
{
    int i;
    FILE *fp;
    fp = fopen("data.txt", "a");
    if (fp == NULL)
        printf("\nError");
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%d %s %f\n", s[i].roll, s[i].name, s[i].per);
        }
    }
    fclose(fp);
}

void disp(int n)
{
    int roll;
    char nm[100];
    float p;
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL)
        printf("\nError");
    else
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%d %s %f", &roll, nm, &p);
            printf("%d %s %f\n", roll, nm, p);
        }
    fclose(fp);
}

void search(int n, int rn)
{
    int c = 0;
    int roll;
    char nm[100];
    float p;
    FILE *fp;
    fp = fopen("data.txt", "r+");
    if (fp == NULL)
        printf("\nError");
    else
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%d %s %f", &roll, nm, &p);
            if (roll == rn)
            {
                c = 1;
                printf("\n\n%d %s %f\n", roll, nm, p);
                break;
            }
        }
    if (c == 0)
        printf("\nStudent not found");
    fclose(fp);
}

void delete (int n, int rn)
{
    int roll;
    char nm[100];
    int t = 0;
    float p;
    FILE *fp;
    fp = fopen("data.txt", "r");
    FILE *f;
    f = fopen("data1.txt", "w");
    if (fp == NULL)
        printf("\nError");
    else
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%d %s %f", &roll, nm, &p);
            if (roll != rn)
            {
                t++;
                fprintf(f, "%d %s %f\n", roll, nm, p);
            }
        }
    }
    fclose(f);
    fclose(fp);
    f = fopen("data1.txt", "r");
    fp = fopen("data.txt", "w");
    if (f == NULL)
        printf("\nError");
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            fscanf(f, "%d %s %f", &roll, nm, &p);
            fprintf(fp, "%d %s %f\n", roll, nm, p);
        }
    }
    FILE *f1;

    fclose(f);
    fclose(fp);
    f1 = fopen("data.txt", "r");
    if (f1 == NULL)
        printf("\nError");
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            fscanf(f1, "%d %s %f", &roll, nm, &p);
            printf("%d %s %f\n", roll, nm, p);
        }
    }
}
int main()
{
    int n;
    int ch;
    int rn;
    printf("\nEnter the number of students :- ");
    scanf("%d", &n);
    accept(n);
    write_to_file(n);
    while (1)
    {
        printf("\nEnter 1 - to display all the records ");
        printf("\nEnter 2 - to search for a particular student ");
        printf("\nEnter 3 - to delete information of a particular student ");
        printf("\nEnter 0 - to exit ");
        printf("\n\nEnter the choice :- \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            disp(n);
            break;
        case 2:
            printf("\nEnter the roll no of student to display record :- ");
            scanf("%d", &rn);
            search(n, rn);
            break;
        case 3:
            printf("\nEnter the roll no of student to delete record :- ");
            scanf("%d", &rn);
            delete (n, rn);
            break;
        case 0:
            exit(0);
            return 0;
        default:
            printf("\nEnter valid choice ");
        }
    }
    return 0;
}