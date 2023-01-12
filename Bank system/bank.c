#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
int top = -1;

typedef struct acc
{
    long int cust_id;
    char name[40];
    char type;
    int balance;
} acc;

void create(acc *arr[])
{
    arr[++top] = (acc *)malloc(sizeof(acc));
    acc *temp = arr[top];
    char s;
    printf("ENTER CUSTOMER NAME : ");
    scanf("%c", &s);
    gets(temp->name);
    temp->cust_id = 10000 + top;
    printf("PRESS    {S} = SAVING A/C \n\t {C} = CURRENT \n\t DEFAULT {SAVING A/C} \n");
    scanf("%c", &temp->type);
    if (temp->type != 'C')
        temp->type = 'S';
    printf("ENTER BALANCE : ");
    scanf("%d", &temp->balance);
}

void print(acc *arr[])
{
    printf("________________________________\n");
    printf(" NAME       \t CUST_ID   ACC_TYPE   BAL.\n\n");
    for (int i = 0; i <= top; i++)
    {
        printf(" %-15s %-9d %-10c %d\n", arr[i]->name, arr[i]->cust_id, arr[i]->type, arr[i]->balance);
    }

    printf("________________________________\n");
}

void deposit(acc *arr[], int op)
{
    int select;
    int amt;
B:
    printf("Enter CUST_ID : ");
    scanf("%d", &select);
    if (select > (10000 + top) || select < (10000))
    {
        printf("\nINVALID ID\n");
        goto B;
    }
    select -= 10000;

    if (op == 2)
    {
        printf("ENTER AMOUNT TO DEPOSIT : ");
        scanf("%d", &amt);
        arr[select]->balance += amt;
    }
    else
    {
    A:
        printf("ENTER AMOUNT TO WITHDRAW : ");
        scanf("%d", &amt);
        if (amt > arr[select]->balance)
        {
            printf("\nINSUFFICIENT CASH TO WITHDRAW\n");
            goto A;
        }
        arr[select]->balance -= amt;
    }
}

void load_data(FILE *ptr, acc *arr[])
{
    fprintf(ptr, " NAME       \t CUST_ID   ACC_TYPE   BAL.\n\n");
    for (int i = 0; i <= top; i++)
    {
        fprintf(ptr, " %-15s %-9d %-10c %d\n", arr[i]->name, arr[i]->cust_id, arr[i]->type, arr[i]->balance);
    }
}

int main()
{
    system("cls");
    acc *arr[20];
    int op;

    FILE *ptr = fopen("Bank.txt", "w");

    do
    {
        printf("1. NEW ACCOUNT \n2. DEPOSIT \n3. WITHDRAWL \n0. EXIT \n");
        
        printf("\nENTER CHOICE : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            create(arr);
            system("cls");

            break;

        case 2:
            deposit(arr, 2);
            system("cls");

            break;

        case 3:
            deposit(arr, 3);
            system("cls");

            break;

        case 0:
            break;
        default:
            printf("\n INVALID OPERATION \n");
            Sleep(500);
            system("cls");
            break;
        }
        print(arr);
        printf("\n\n");

    } while (op);

    load_data(ptr, arr);

    return 0;
}