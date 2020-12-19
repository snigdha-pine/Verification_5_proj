//#include "Create_Directory.c"
//#include "Check_Input.c"
//#include "concat.c"
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"teacher.c"
#include"login.c"
//#include"adminTeacher.c"
void main()
{
    char ch;
    while(1)
    {
        system("color F");
        printf("\n\n\t\t\t\t\t\tSchool Management System\n");
        printf("\t\t\t\t\t\t1. Admin   :\n");
        printf("\t\t\t\t\t\t2. Teacher :\n");
        printf("\t\t\t\t\t\t3. Student :\n");
        printf("\t\t\t\t\t\t4. Exit    :\n\t\t\t\t\t\t");
        fflush(stdin);
        ch=getchar();
        fflush(stdin);
        if(ch=='4')
            break;
        switch(ch)
        {
        case '1' :
            system("cls");
            LOGIN();
        break;

        case '2' :
            system("cls");
            Teacher();
        break;

        case '3' :
            system("cls");
            View_Student_Details();
            printf("Press any key to exit : ");
            getch();
            system("cls");
        break;

        default :
            system("cls");
            printf("Invalid Choice!\n");
        }
    }
}
