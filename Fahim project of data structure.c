//Arifuzzaman Fahim
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define TOTAL_user 100
typedef struct
{
    char name[50];
    int age;
    char address[20];
    double balance;
} User;

int i = 0, n = 0;
char choice;
int read = 0, record = 0;
FILE *file1, *file2;
User user[TOTAL_user];
void fileload(User user[])
{
    file2 = fopen("hasan.txt", "w+");
    if (file2 == NULL)
    {
        printf("Error opening file2\n");
        exit(1);
    }

    do
    {
        read = fscanf(file2, "%39[^,],%d,%19[^,],%lf\n", user[record].name, &user[record].age, user[record].address, &user[record].balance);

        if (read == 4)
            record++;
        if (read != 4 && !feof(file2))
        {
            printf("File format error\n");
            exit(1);
        }
        if (ferror(file2))
        {
            printf("Error reading from file2\n");
            exit(1);
        }
    } while (!feof(file2));
    fclose(file2);
}

void add_User(User user[])
{
    file1 = fopen("file.txt", "w+");
    char another = 'y';
    while (another == 'y')
    {
        printf("\nUser %d info:\n", record + 1);
        fflush(stdin);
        printf("Enter Name: ");
        scanf("%[^\n]%*c", user[record].name);
        fflush(stdin);
        printf("Enter age: ");
        scanf("%d", &user[record].age);
        fflush(stdin);
        printf("Enter Address: ");
        scanf("%[^\n]%*c", user[record].address);
        fflush(stdin);
        printf("Enter Blance: ");
        fflush(stdin);
        scanf("%lf", &user[record].balance);
        printf("\n");
        printf("Do you want to Add another user? (y/n): ");
        fflush(stdin);
        another = getchar();
        record++;
    }
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", user[i].name, user[i].age, user[i].address, user[i].balance);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("\n%d User added to file1\n", record);
}
void list_User(User Users[])
{
    printf("%-7s %-20s %-7s %-20s %-10s\n", "Serial", "Name", "age", "Address", "Balance");
    for (i = 0; i < record; i++)
    {
        printf("%-7d %-20s %-7d %-20s %-10.2lf\n", i, user[i].name, user[i].age, user[i].address, user[i].balance);
    }
    system("pause");
}
void modify_User(User user[])
{
    printf("Enter the serial number of the User you want to modify: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("\nUser %d info:\n", n);
    fflush(stdin);
    printf("Name: ");
    scanf("%[^\n]%*c", user[n].name);
    fflush(stdin);
    printf("age: ");
    scanf("%d", &user[n].age);
    fflush(stdin);
    printf("Address: ");
    scanf("%[^\n]%*c", user[n].address);
    fflush(stdin);
    printf("Balance: ");
    fflush(stdin);
    scanf("%lf", &user[n].balance);
    printf("\n");
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%lf\n", user[i].name, user[i].age, user[i].address, user[i].balance);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    printf("User %d modified\n", n);
    fclose(file1);
    system("pause");
}

void delete_User(User user[])
{
    printf("Enter the User serial number : ");
    fflush(stdin);
    scanf("%d", &n);
    for (i = n; i < record; i++)
    {
        strcpy(user[i].name, user[i + 1].name);
        user[i].age = user[i + 1].age;
        strcpy(user[i].address, user[i + 1].address);
        user[i].balance = user[i + 1].balance;
    }
    record--;
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", user[i].name, user[i].age, user[i].address, user[i].balance);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("User %d is deleted\n", n);
    system("pause");
}
void search_User(User user[])
{

    printf("Enter the name of the User you want to search: ");
    fflush(stdin);
    char name[40];
    scanf("%[^\n]%*c", name);
    for (i = 0; i < record; i++)
    {
        if (strcmp(user[i].name, name) == 0)
        {
            printf("%-7s %-20s %-7s %-20s %-10s\n", "Serial", "Name", "age", "Address", "Balance");
            printf("%-7d %-20s %-7d %-20s %-10.2lf\n", i, user[i].name, user[i].age, user[i].address, user[i].balance);
            system("pause");
        }
    }
}
void sort_User_name(User user[])
{
    int i, j;
    User tuser;
    for (i = 0; i < record; i++)
    {
        for (j = 0; j < record - 1; j++)
        {
            if (strcmp(user[j].name, user[j + 1].name) > 0)
            {
                strcpy(tuser.name, user[j].name);
                tuser.age = user[j].age;
                strcpy(tuser.address, user[j].address);
                tuser.balance = user[j].balance;
                strcpy(user[j].name, user[j + 1].name);
                user[j].age = user[j + 1].age;
                strcpy(user[j].address, user[j + 1].address);
                user[j].balance = user[j + 1].balance;
                strcpy(user[j + 1].name, tuser.name);
                user[j + 1].age = tuser.age;
                strcpy(user[j + 1].address, tuser.address);
                user[j + 1].balance = tuser.balance;
            }
        }
    }
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", user[i].name, user[i].age, user[i].address, user[i].balance);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("User sorted by name done successfully\n");
    system("pause");
}
void sort_User_age(User user[])
{
    int i, j;
    User tuser;
    for (i = 0; i < record; i++)
    {
        for (j = 0; j < record - 1; j++)
        {
            if (user[j].age > user[j + 1].age)
            {
                strcpy(tuser.name, user[j].name);
                tuser.age = user[j].age;
                strcpy(tuser.address, user[j].address);
                tuser.balance = user[j].balance;
                strcpy(user[j].name, user[j + 1].name);
                user[j].age = user[j + 1].age;
                strcpy(user[j].address, user[j + 1].address);
                user[j].balance = user[j + 1].balance;
                strcpy(user[j + 1].name, tuser.name);
                user[j + 1].age = tuser.age;
                strcpy(user[j + 1].address, tuser.address);
                user[j + 1].balance = tuser.balance;
            }
        }
    }
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", user[i].name, user[i].age, user[i].address, user[i].balance);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("User sorted by age successfully\n");
    system("pause");
}

void sort_User_address(User user[])
{
    int i, j;
    User tuser;
    for (i = 0; i < record; i++)
    {
        for (j = 0; j < record - 1; j++)
        {
            if (strcmp(user[j].address, user[j + 1].address) > 0)
            {
                strcpy(tuser.name, user[j].name);
                tuser.age = user[j].age;
                strcpy(tuser.address, user[j].address);
                tuser.balance = user[j].balance;
                strcpy(user[j].name, user[j + 1].name);
                user[j].age = user[j + 1].age;
                strcpy(user[j].address, user[j + 1].address);
                user[j].balance = user[j + 1].balance;
                strcpy(user[j + 1].name, tuser.name);
                user[j + 1].age = tuser.age;
                strcpy(user[j + 1].address, tuser.address);
                user[j + 1].balance = tuser.balance;
            }
        }
    }
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%.2lf\n", user[i].name, user[i].age, user[i].address, user[i].balance);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("User is sorted by address successfully\n");
    system("pause");
}
void sort_user_age(User user[])
{
    int i, j;
    User tuser;
    for (i = 0; i < record; i++)
    {
        for (j = 0; j < record - 1; j++)
        {
            if (user[j].balance > user[j + 1].balance)
            {
                strcpy(tuser.name, user[j].name);
                tuser.age = user[j].age;
                strcpy(tuser.address, user[j].address);
                tuser.balance = user[j].balance;
                strcpy(user[j].name, user[j + 1].name);
                user[j].age = user[j + 1].age;
                strcpy(user[j].address, user[j + 1].address);
                user[j].balance = user[j + 1].balance;
                strcpy(user[j + 1].name, tuser.name);
                user[j + 1].age = tuser.age;
                strcpy(user[j + 1].address, tuser.address);
                user[j + 1].balance = tuser.balance;
            }
        }
    }
    file1 = fopen("CCsvf.csv", "w+");
    for (i = 0; i < record; i++)
    {
        fprintf(file1, "%s,%d,%s,%lf\n", user[i].name, user[i].age, user[i].address, user[i].balance);
        if (ferror(file1))
        {
            printf("Error writing to file1\n");
            exit(1);
        }
    }
    fclose(file1);
    printf("User sorted by balance successfully\n");
    system("pause");
}
int main()
{

    fileload(user);

    while (1)
    {
        printf(" \n\t\t\tWELLCOME TO Fahim BANK MANAGEMENT SYSTEM \n");
        printf("  \t\t\t\t 1. Add User Records \n");
        printf("  \t\t\t\t 2. List User Records \n");
        printf("  \t\t\t\t 3. Modify User Records\n");
        printf("  \t\t\t\t 4. Delete User Records\n");
        printf("  \t\t\t\t 5. Search User Records\n");
        printf("  \t\t\t\t 6. Sort User Records\n");
        printf("  \t\t\t\t 7. Exit System\n");
        printf("  __________________________________________________________________________________\n");
        printf("  __________________________________________________________________________________");
        printf(" \n \n Your Choice: ");
        fflush(stdin);
        choice = getchar();
        switch (choice)
        {
        case '1':
            system("cls");
            add_User(user);
            break;
        case '2':
            system("cls");
            list_User(user);
            break;
        case '3':
            system("cls");
            modify_User(user);
            break;
        case '4':
            system("cls");
            delete_User(user);
            break;
        case '5':
            system("cls");
            search_User(user);

            break;
        case '6':
            system("cls");

            printf(" \n\t\t\tBANK MANageMENT SYSTEM\n");
            printf("1. Sort by Name \n");
            printf("2. Sort by age \n");
            printf("3. Sort by Address \n");
            printf("4. Sort by Basic age \n");
            printf("5. Return Back \n");
            printf(" \n \n Your Choice: ");
            fflush(stdin);
            choice = getchar();
            switch (choice)
            {
            case '1':
                system("cls");
                sort_User_name(user);
                break;
            case '2':
                system("cls");
                sort_User_age(user);
                break;
            case '3':
                system("cls");
                sort_User_address(user);
                break;
            case '4':
                system("cls");
                sort_User_age(user);
                break;
            case '5':
                system("cls");
                break;
            default:
                system("cls");
                printf("\nInvalid choice & returning back ...\n");
                system("pause");
            }
            break;
        case '7':
            system("cls");
            exit(0);
            break;
        default:
            system("cls");
            printf("Invalid Choice");
            break;
        }
    }
    return 0;
}
