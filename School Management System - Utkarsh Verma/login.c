#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include <windows.h>
#define SIZE 32
//#include"adminTeacher.c"
//#include"reset_password.c"
#include"Admin.c"
void LOGIN()
{
    char pwd[SIZE],pd[SIZE],ch;
    char option;
    //Read inbuild passward
    FILE *fp;
    FILE *fp1;
    char path[100];
    fp=fopen("./pswrd","rb");

    if(fp == NULL)                                  //This section is when the password file is not created
    {                                               // i.e. when the program is run for the first time.
        fclose(fp);                                 // the file is created and the password is set to
        FILE *fptr=fopen("./pswrd","wb");           // abcd1234 by default.
        fprintf(fptr,"abcd1234");
        fclose(fptr);
    }
    fp=fopen("./pswrd","rb");
    fscanf(fp,"%s",pwd);
    fclose(fp);
    //printf("\nPwd is %s",pwd);
    //Login details
    ENTER_PASSWORD:
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\tPLEASE ENTER THE LOGIN PASSWORD: ");
    int p=0;
    while(1)
    {
        pd[p]=getch();
        if(pd[p]=='\r')
            break;
        if(pd[p]=='\b' && p>0)
        {
            p=p-2;
            printf("\b \b");
        }
        else if(pd[p]!='\b')                            //To avoid printing * while pressing backspace
            printf("*");

        if(pd[p]!='\b')
            p++;

    }
    pd[p]='\0';

    if(strcmp(pwd,pd)==0)
    {
        printf("\n\n \t\t\t\t\tWELCOME........LOGIN IN SUCESSFULLY ");
        printf("\n\n \t\t\t\t\tPLEASE WAIT . . . ");
        Sleep(1000);
        system("cls");
        admin();
    }
    else
    {
        printf("\n\n \t\t\t\t\tIncorrect Login!");
        printf("\n\n \t\t\t\t\tPLEASE WAIT . . . ");
        Sleep(1000);
        system("cls");
        goto ENTER_PASSWORD;
    }

}
