#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

void option();
int login();
void home();
void add();
void grade();
void preview();

typedef struct subjects
{

    int math, pps, ee, physics, softSkills;
    float percentage;

} subjects;

struct student
{
    char grade[10][2];
    int checkGrade[10];
    char name[10][20];
    int registration[10];
    char dob[10][10];
    char fname[10][20];
    char mname[10][20];
    char address[10][30];
    char course[10][10];
    char Edate[10][10];
    subjects sub[10];
} a;

int main()
{

    system("cls");
    if (login())
    {
        system("cls");
        home();
    }
    return 0;
}

int login()
{
    char id[10], pass[10];
    printf("enter your id : max limit 10 characters : ");
    scanf("%s", id);

    if (!strcmp(id, "kccitm"))
    {
        printf("\n Enter your password : ");
        scanf("%s", pass);

        if (!strcmp(pass, "admin@123"))
        {
            printf("\nSUCCESSFULLY LOGED IN\n");

            return 1;
        }
        else
        {
            printf("\n you have forgeted your passwd \n");
            return 0;
        }
    }
    else
    {
        printf("\n INVALID ID \n");
        return 0;
    }
}

void home()
{
    printf("\n-------------------Student Management System---------------------------\n");
    printf("*********************************************************************\n \t1. Add Student Details\n\t2. Preview Student Details\n\t3. Grades of the student \n\t4. Total number of students\n \t5. Exit \n\n\n*********************************************************************\n Enter your option : ");
    option();
}

void option()
{
    int op;
    scanf("%d", &op);
    while (op > 5 || op < 1)
    {
        printf("Invalid input --- Try Again \n");
        scanf("%d", &op);
    }

    switch (op)
    {
    case 1:
        add();
        break;
    case 2:
        preview();
        break;
    case 3:
        grade();
        break;
    case 4:
        printf(" Total number of students are : %d \n", i);
        printf(" ENTER YOUR CHOICE : ");
        option();
        break;

    default:
        exit(0);
        break;
    }
}

void add()
{
    char v;
    printf("enter your name : ");
    scanf("%c", &v);
    gets(a.name[i]);
    printf("Your Reg Number : %d \n ", i);
    a.registration[i] = i;
    printf("enter your DOB : ");
    scanf("%c", &v);
    gets(a.dob[i]);
    printf("enter your father name  : ");
    gets(a.fname[i]);
    printf("enter your mother name  : ");
    gets(a.mname[i]);
    printf("enter your address : ");
    gets(a.address[i]);
    printf("enter your course : ");
    gets(a.course[i]);
    printf("enter your date of enrollment : ");
    gets(a.Edate[i]);
    a.checkGrade[i] = 0;

    i++;

    system("cls");
    home();
    option();
}

void preview()
{
    int j = 0;
    char c;

    for (j = 0; j < i; j++)
    {
        printf("\n\n------------------------------------------\n");

        printf("name:%s\nregID:%d\ndob:%s\nfname : %s\nmname :%s\naddress: %s\ncourse: %s\nedate: %s\n", a.name[j], a.registration[j], a.dob[j], a.fname[j], a.mname[j], a.address[j], a.course[j], a.Edate[j]);
        if (a.checkGrade[j])
        {

            printf("\nEE :");
            printf("%d", a.sub[j].ee);
                printf("\nMATHs :");
            printf("%d", a.sub[j].math);
                printf("\nPHYSICS :");
            printf("%d", a.sub[j].physics);
                printf("\nPPS :");
            printf("%d", a.sub[j].pps);
                printf("\nSOFT SKILL :");
            printf("%d", a.sub[j].softSkills);
                printf("\n \n grade  : %s\n ", a.grade[j]);
        }
        else
        {
            printf("\n grade not available \n");
        }

        printf("\n------------------------------------------\n");
    }

    printf("PRESS TO CONTINUE : ");
    scanf("%c", &c);
    scanf("%c", &c);

    system("cls");
    home();
    option();
}

void grade()
{
    char c;

    int reg;

    printf("enter registration id of student : ");
    scanf("%d", &reg);

    a.checkGrade[reg] = 1;

    printf("ENTER MARKS OF :  {/100} \n");

    printf("EE :");
    scanf("%d", &a.sub[reg].ee);
        printf("MATHs :");
    scanf("%d", &a.sub[reg].math);
        printf("PHYSICS :");
    scanf("%d", &a.sub[reg].physics);
        printf("PPS :");
    scanf("%d", &a.sub[reg].pps);
        printf("SOFT SKILL :");
    scanf("%d", &a.sub[reg].softSkills);

        a.sub[reg]
            .percentage = (a.sub[reg].ee + a.sub[reg].math + a.sub[reg].physics + a.sub[reg].pps + a.sub[reg].softSkills) / 5.0;
    int perc = a.sub[reg].percentage;

    switch (perc)
    {
    case 0 ... 70:
        a.grade[reg][0] = 'C';
        break;
    case 71 ... 80:
        a.grade[reg][0] = 'B';
        break;
    case 81 ... 90:
        a.grade[reg][0] = 'A';
        break;
    case 91 ... 95:
        a.grade[reg][0] = 'A';
        a.grade[reg][1] = '+';
        break;
    case 96 ... 100:
        a.grade[reg][0] = 'O';
        break;
    }

    printf("Grade of student : %s \n ", a.grade[reg]);

    printf("PRESS TO CONTINUE : ");
    scanf("%c", &c);
    scanf("%c", &c);
    system("cls");
    home();
    option();
}
