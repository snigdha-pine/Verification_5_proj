#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void admin();
void user();
void add_movie();
void search_movie();
void delete_movie();
void view_all_movies();
void edit_movie();
void audi();
void view_movies();
void book_ticket();
void cancel_ticket();
struct Movie
{
    char name[20];
    char code[20];
    int date;
    char cost[20];
};
struct Movie p,temp;

int main()
{
    int op;
    system("cls");
    system("color 5f");
    printf("\t\t\t\tWelcome To Movie Ticket Booking System\n");
    printf("\nPress 1 For Admin\n");
    printf("\nPress 2 For User\n");
    scanf("%d",&op);
    switch(op)
    {
 case(1):
    admin();
    break;
 case(2):
    user();
    break;
    }

}
admin()
{
    system("cls");
    system("color 4f");
    printf("\n\t*****MOVIE TICKET BOOKING SYSTEM****\n");
    printf("\t 1. Add Movie\n");
    printf("\t 2. Search Movie\n");
    printf("\t 3. Delete Movie\n");
    printf("\t 4. View All Movies\n");
    printf("\t 5. Edit Movie\n");
    printf("\t 6. Audi Details\n");
    printf("\t 7. Exit\n");
    printf("\n\n\tEnter Your Choice:- ");

    switch(getch())
    {
    case '1':
        add_movie();
        break;
    case '2':
        search_movie();
        break;
    case '3':
        delete_movie();
        break;
    case '4':
        view_all_movies();
        break;
    case '5':
        edit_movie();
        break;
    case '6':
        audi();
        break;
    case '7':
        exit(0);
    default:
        main();
    }
}

void add_movie()
{
    system("cls");
    int option;
    int a;
    FILE *fp;
    printf("\t\tEnter Category:\n");
    printf("\t\t1.2D Hindi\n\t\t2.2D English\n\t\t3.3D Hindi\n\t\t4.3D English\n");
    scanf("%d",&option);
    switch(option)
    {
        case(1):
            system("cls");
    printf("\t\t2D Hindi");
    fp=fopen("data1.txt","a+");
    system("cls");

    printf("\n\t*ADD MOVIE*");
    printf("\n\n\tENTER MOVIE NAME - ");
    fflush(stdin);
    scanf("%[^\n]%*c",p.name);
    printf("\n\tENTER MOVIE TIMING :-" );
    gets(p.code);
    printf("\n\tENTER AVAILABLE SEATS    :-");
    scanf("%d",&p.date);
    printf("\n\tENTER TICKET PRICE   :-");
    fflush(stdin);
    gets(p.cost);
         while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,p.name)==0)
        {
           printf("\n\tMOVIE ALREADY PRESENT\n\n");
           printf("\n\tPRESS ANY KEY TO CONTINUE: ");
           getch();
           main();

        }
    }
    fwrite (&p, sizeof(struct Movie), 1, fp);
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
        case(2):
            system("cls");
    printf("\t\t2D Hindi");
    fp=fopen("data2.txt","a+");
    system("cls");

    printf("\n\t*ADD MOVIE*");
    printf("\n\n\tENTER MOVIE NAME - ");
    fflush(stdin);
    scanf("%[^\n]%*c",p.name);
    printf("\n\tENTER MOVIE TIMING :-" );
    gets(p.code);
    printf("\n\tENTER AVAILABLE SEATS    :-");
    scanf("%d",&p.date);
    printf("\n\tENTER TICKET PRICE   :-");
    fflush(stdin);
    gets(p.cost);
         while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,p.name)==0)
        {
           printf("\n\tMOVIE ALREADY PRESENT\n\n");
           printf("\n\tPRESS ANY KEY TO CONTINUE: ");
           getch();
           main();

        }
    }
    fwrite (&p, sizeof(struct Movie), 1, fp);
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
        case(3):
            system("cls");
    printf("\t\t2D Hindi");
    fp=fopen("data3.txt","a+");
    system("cls");

    printf("\n\t*ADD MOVIE*");
    printf("\n\n\tENTER MOVIE NAME - ");
    fflush(stdin);
    scanf("%[^\n]%*c",p.name);
    printf("\n\tENTER MOVIE TIMING :-" );
    gets(p.code);
    printf("\n\tENTER AVAILABLE SEATS    :-");
    scanf("%d",&p.date);
    printf("\n\tENTER TICKET PRICE   :-");
    fflush(stdin);
    gets(p.cost);
         while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,p.name)==0)
        {
           printf("\n\tMOVIE ALREADY PRESENT\n\n");
           printf("\n\tPRESS ANY KEY TO CONTINUE: ");
           getch();
           main();

        }
    }
    fwrite (&p, sizeof(struct Movie), 1, fp);
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
        case(4):
            system("cls");
    printf("\t\t2D Hindi");
    fp=fopen("data4.txt","a+");
    system("cls");

    printf("\n\t*ADD MOVIE*");
    printf("\n\n\tENTER MOVIE NAME - ");
    fflush(stdin);
    scanf("%[^\n]%*c",p.name);
    printf("\n\tENTER MOVIE TIMING :-" );
    gets(p.code);
    printf("\n\tENTER AVAILABLE SEATS    :-");
    scanf("%d",&p.date);
    printf("\n\tENTER TICKET PRICE   :-");
    fflush(stdin);
    gets(p.cost);
         while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,p.name)==0)
        {
           printf("\n\tMOVIE ALREADY PRESENT\n\n");
           printf("\n\tPRESS ANY KEY TO CONTINUE: ");
           getch();
           main();

        }
    }
    fwrite (&p, sizeof(struct Movie), 1, fp);
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
    }
}
void search_movie()
{
       system("cls");
    int option;
    int a;
        FILE *fp;
    printf("\t\tEnter Category:\n");
    printf("\t\t1.2D Hindi\n\t\t2.2D English\n\t\t3.3D Hindi\n\t\t4.3D English\n");
    scanf("%d",&option);
    switch(option)
    {
        case(1):
    fp=fopen("data1.txt","r");
    int option,flag=0;
    char name1[20];
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag = 1;
            printf("\n\tMOVIE FOUND\n\n");
            printf("\n\tMOVIE NAME     :- %s\n",p.name);
            printf("\n\tMOVIE TIMING  :- %s\n",p.code);
            printf("\n\tAVAILABLE SEATS    :- %d\n",p.date);
            printf("\n\tTICKET COST  :- %s\n",p.cost);
        }
    }
    fclose(fp);
    if(flag == 0)
        printf("\n\tMOVIE NOT FOUND");
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;

        case(2):
    fp=fopen("data2.txt","r");
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag = 1;
            printf("\n\tMOVIE FOUND\n\n");
            printf("\n\tMOVIE NAME     :- %s\n",p.name);
            printf("\n\tMOVIE TIMING  :- %s\n",p.code);
            printf("\n\tAVAILABLE SEATS    :- %d\n",p.date);
            printf("\n\tTICKET COST  :- %s\n",p.cost);
        }
    }
    fclose(fp);
    if(flag == 0)
        printf("\n\tMOVIE NOT FOUND");
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;

        case(3):
    fp=fopen("data3.txt","r");
    fflush(stdin);
    system("cls");
    printf("\n\t Enter Movie Name :-");
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag = 1;
            printf("\n\tMOVIE FOUND\n\n");
            printf("\n\tMOVIE NAME     :- %s\n",p.name);
            printf("\n\tMOVIE TIMING  :- %s\n",p.code);
            printf("\n\tAVAILABLE SEATS    :- %d\n",p.date);
            printf("\n\tTICKET COST  :- %s\n",p.cost);
        }
    }
    fclose(fp);
    if(flag == 0)
        printf("\n\tMOVIE NOT FOUND");
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;

    case(4):
    fp=fopen("data4.txt","r");
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag = 1;
            printf("\n\tMOVIE FOUND\n\n");
            printf("\n\tMOVIE NAME     :- %s\n",p.name);
            printf("\n\tMOVIE TIMING  :- %s\n",p.code);
            printf("\n\tAVAILABLE SEATS    :- %d\n",p.date);
            printf("\n\tTICKET COST  :- %s\n",p.cost);
        }
    }
    fclose(fp);
    if(flag == 0)
        printf("\n\tMOVIE NOT FOUND");
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
    }
}
void delete_movie()
{
        system("cls");
    int option,flag =0;
    FILE *fp,*fp1;
    printf("\t\tEnter Category:\n");
    printf("\t\t1.2D Hindi\n\t\t2.2D English\n\t\t3.3D Hindi\n\t\t4.3D English\n");
    scanf("%d",&option);
    switch(option)
    {
        case(1):
    fp=fopen("data1.txt","r+");
    fp1=fopen("temp1.txt","w");
    system("cls");
    char name[20];
    printf("\t*DELETE MOVIE*");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name);
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(name,p.name)==0)
        {
            flag =1;
            continue;
        }
        else
            {
        fwrite (&p, sizeof(struct Movie), 1, fp1);
    }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("data1.txt","w");
    fp1=fopen("temp1.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp1))
    {

        fwrite (&p, sizeof(struct Movie), 1, fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp1.txt");
    if(flag == 0)
        printf("\n\tMOVIE NOT FOUND");
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    main();
    break;

        case (2):
    fp=fopen("data2.txt","r+");
    fp1=fopen("temp2.txt","w");
    system("cls");
    printf("\t*DELETE MOVIE*");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name);
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(name,p.name)==0)
        {
            flag =1;
            continue;
        }
        else
        {
        fwrite (&p, sizeof(struct Movie), 1, fp1);
    }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("data2.txt","w");
    fp1=fopen("temp2.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp1))
    {

        fwrite (&p, sizeof(struct Movie), 1, fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp2.txt");
    if(flag == 0)
        printf("\n\tMOVIE NOT FOUND");
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    main();
    break;
        case(3):
    fp=fopen("data3.txt","r+");
    fp1=fopen("temp3.txt","w");
    system("cls");
    printf("\t*DELETE MOVIE*");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name);
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(name,p.name)==0)
        {
            flag =1;
            continue;
        }
        else
        {
        fwrite (&p, sizeof(struct Movie), 1, fp1);
    }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("data3.txt","w");
    fp1=fopen("temp3.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp1))
    {
        fwrite (&p, sizeof(struct Movie), 1, fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp3.txt");
    if(flag == 0)
        printf("\n\tMOVIE NOT FOUND");
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    main();
    break;
        case(4):
    fp=fopen("data4.txt","r+");
    fp1=fopen("temp4.txt","w");
    system("cls");
    printf("\t*DELETE MOVIE*");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name);
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(name,p.name)==0)
        {
            flag =1;
            continue;
        }
        else
        {
        fwrite (&p, sizeof(struct Movie), 1, fp1);
    }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("data4.txt","w");
    fp1=fopen("temp4.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp1))
    {

        fwrite (&p, sizeof(struct Movie), 1, fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp4.txt");
    if(flag == 0)
        printf("\n\tMOVIE NOT FOUND");
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    main();
    break;
    }
}

void view_all_movies()
{
    FILE *fp;
    fp=fopen("data1.txt","r");
    system("cls");
    printf("\t*ALL MOVIES*\n\n\n");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
     if(p.name!=NULL)
    {
        printf("\n\t MOVIE NAME    :-  %s",p.name);
        printf("\n\t MOVIE TIMING :-  %s",p.code);
        printf("\n\t AVAILABLE SEATS :-  %d",p.date);
        printf("\n\t TICKET PRICE :-  %s\n\n",p.cost);
    }
    }
    fclose(fp);
    fp=fopen("data2.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
     if(p.name!=NULL)
    {
        printf("\n\t MOVIE NAME    :-  %s",p.name);
        printf("\n\t MOVIE TIMING :-  %s",p.code);
        printf("\n\t AVAILABLE SEATS :-  %d",p.date);
        printf("\n\t TICKET PRICE :-  %s\n\n",p.cost);
    }
    }
    fclose(fp);
    fp=fopen("data3.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
     if(p.name!=NULL)
    {
        printf("\n\t MOVIE NAME    :-  %s",p.name);
        printf("\n\t MOVIE TIMING :-  %s",p.code);
        printf("\n\t AVAILABLE SEATS :-  %d",p.date);
        printf("\n\t TICKET PRICE :-  %s\n\n",p.cost);
    }
    }
    fclose(fp);
    fp=fopen("data4.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(p.name!=NULL)
    {
        printf("\n\t MOVIE NAME    :-  %s",p.name);
        printf("\n\t MOVIE TIMING :-  %s",p.code);
        printf("\n\t AVAILABLE SEATS :-  %d",p.date);
        printf("\n\t TICKET PRICE :-  %s\n\n",p.cost);
    }
    }
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
}

void edit_movie()
{
    system("cls");
    int option,flag = 0;
    FILE *fp,*fp1;
    printf("\t\tEnter Category:\n");
    printf("\t\t1.2D Hindi\n\t\t2.2D English\n\t\t3.3D Hindi\n\t\t4.3D English\n");
    scanf("%d",&option);
    switch(option)
    {
        case(1):

    fp=fopen("data1.txt","r");
    system("cls");
    printf("\n\tEnter Movie Name - ");
    fflush(stdin);
    scanf("%[^\n]%*c",temp.name);
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,temp.name)==0)
        {
            flag = 1;
            temp = p;
            break;
        }
    }
    fclose(fp);
    ////////////////////////////////DELETE///////////////////////////////////
    if(flag)
    {
    fp=fopen("data1.txt","r+");
    fp1=fopen("temp.txt","w");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(temp.name,p.name)==0)
        {
            continue;
        }
        else
        {
        fwrite (&p, sizeof(struct Movie), 1, fp1);
    }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("data1.txt","w");
    fp1=fopen("temp.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp1))
    {
        fwrite (&p, sizeof(struct Movie), 1, fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    /////////////////////////////////////APPEND//EDITED/////////////////////////////////
    fp=fopen("data1.txt","a+");
    printf("\n\tEdit Movie Name - 1\n\tEdit Movie Timing - 2\n\tEdit Seats Available - 3\n\tEdit Ticket Price - 4\n");
    printf("\n\tEnter Your Choice - ");
    scanf("%d",&option);
    switch (option)
    {
        case 1 : printf("\n\tEnter New Name - ");
        fflush(stdin);
        scanf("%[^\n]%*c",p.name);
        break;

        case 2 : printf("\n\tEnter New Timing - ");
        scanf("%s",p.code);
        break;

        case 3 : printf("\n\tEnter New Available Seats - ");
        scanf("%d",&p.date);
        fflush(stdin);
        break;

        case 4 : printf("\n\tEnter New Price - ");
        scanf("%s",p.cost);
        break;

        default : printf("\n\tWRONG CHOICE");
        break;
    }
    fwrite (&p, sizeof(struct Movie), 1, fp);
    fclose(fp);
    }
    else
        printf("\n\tMOVIE NOT FOUND");

    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
        case(2):
            fp=fopen("data2.txt","r");
    system("cls");
    printf("\n\tEnter Movie Name - ");
    fflush(stdin);
    scanf("%[^\n]%*c",temp.name);
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,temp.name)==0)
        {
            flag = 1;
            temp = p;
            break;
        }
    }
    fclose(fp);
    ////////////////////////////////DELETE///////////////////////////////////
    if(flag)
    {
    fp=fopen("data2.txt","r+");
    fp1=fopen("temp.txt","w");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(temp.name,p.name)==0)
        {
            continue;
        }
        else
        {
        fwrite (&p, sizeof(struct Movie), 1, fp1);
        }
        }
    fclose(fp);
    fclose(fp1);
    fp=fopen("data2.txt","w");
    fp1=fopen("temp.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp1))
    {

        fwrite (&p, sizeof(struct Movie), 1, fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    /////////////////////////////////////APPEND//EDITED/////////////////////////////////
    fp=fopen("data2.txt","a+");
    printf("\n\tEdit Movie Name - 1\n\tEdit Movie Timing - 2\n\tEdit Seats Available - 3\n\tEdit Ticket Price - 4\n");
    printf("\n\tEnter Your Choice - ");
    scanf("%d",&option);
    switch (option)
    {
        case 1 : printf("\n\tEnter New Name - ");
        fflush(stdin);
        scanf("%[^\n]%*c",p.name);
        break;

        case 2 : printf("\n\tEnter New Timing - ");
        scanf("%s",p.code);
        break;

        case 3 : printf("\n\tEnter New Seats Available - ");
        scanf("%d",&p.date);
        fflush(stdin);
        break;

        case 4 : printf("\n\tEnter New Price - ");
        scanf("%s",p.cost);
        break;

        default : printf("\n\tWRONG CHOICE");
        break;
    }
    fwrite (&p, sizeof(struct Movie), 1, fp);
    fclose(fp);
    }
    else
        printf("\n\tMOVIE NOT FOUND");

    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
        case(3):
            fp=fopen("data3.txt","r");
    system("cls");
    printf("\n\tEnter Movie Name - ");
    fflush(stdin);
    scanf("%[^\n]%*c",temp.name);
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,temp.name)==0)
        {
            flag = 1;
            temp = p;
            break;
        }
    }
    fclose(fp);
    ////////////////////////////////DELETE///////////////////////////////////
    if(flag)
    {
    fp=fopen("data3.txt","r+");
    fp1=fopen("temp.txt","w");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(temp.name,p.name)==0)
        {
            continue;
        }
        else
        {
        fwrite (&p, sizeof(struct Movie), 1, fp1);
    }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("data3.txt","w");
    fp1=fopen("temp.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp1))
    {
        fwrite (&p, sizeof(struct Movie), 1, fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    /////////////////////////////////////APPEND//EDITED/////////////////////////////////
    fp=fopen("data3.txt","a+");
    printf("\n\tEdit Movie Name - 1\n\tEdit Movie Timing - 2\n\tEdit Seats Available - 3\n\tEdit Ticket Price - 4\n");
    printf("\n\tEnter Your Choice - ");
    scanf("%d",&option);
    switch (option)
    {
        case 1 : printf("\n\tEnter New Name - ");
        fflush(stdin);
        scanf("%[^\n]%*c",p.name);
        break;

        case 2 : printf("\n\tEnter New Timing - ");
        scanf("%s",p.code);
        break;

        case 3 : printf("\n\tEnter New Seats Available - ");
        scanf("%d",&p.date);
        fflush(stdin);
        break;

        case 4 : printf("\n\tEnter New Price - ");
        scanf("%s",p.cost);
        break;

        default : printf("\n\tWRONG CHOICE");
        break;
    }
    fwrite (&p, sizeof(struct Movie), 1, fp);
    fclose(fp);
    }
    else
        printf("\n\tMOVIE NOT FOUND");

    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
        case(4):
            fp=fopen("data4.txt","r");
    system("cls");
    printf("\n\tEnter Movie Name - ");
    fflush(stdin);
    scanf("%[^\n]%*c",temp.name);
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,temp.name)==0)
        {
            flag = 1;
            temp = p;
            break;
        }
    }
    fclose(fp);
    ////////////////////////////////DELETE///////////////////////////////////
    if(flag)
    {
    fp=fopen("data4.txt","r+");
    fp1=fopen("temp.txt","w");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(temp.name,p.name)==0)
        {
            continue;
        }
        else
        {
        fwrite (&p, sizeof(struct Movie), 1, fp1);
    }
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("data4.txt","w");
    fp1=fopen("temp.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp1))
    {
        fwrite (&p, sizeof(struct Movie), 1, fp);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    /////////////////////////////////////APPEND//EDITED/////////////////////////////////
    fp=fopen("data4.txt","a+");
    printf("\n\tEdit Movie Name - 1\n\tEdit Movie Timing - 2\n\tEdit Seats Available - 3\n\tEdit Ticket Price - 4\n");
    printf("\n\tEnter Your Choice - ");
    scanf("%d",&option);
    switch (option)
    {
        case 1 : printf("\n\tEnter New Name - ");
        fflush(stdin);
        scanf("%[^\n]%*c",p.name);
        break;

        case 2 : printf("\n\tEnter New Timing - ");
        scanf("%s",p.code);
        break;

        case 3 : printf("\n\tEnter New Seats Available - ");
        scanf("%d",&p.date);
        fflush(stdin);
        break;

        case 4 : printf("\n\tEnter New Price - ");
        scanf("%s",p.cost);
        break;

        default : printf("\n\tWRONG CHOICE");
        break;
    }
    fwrite (&p, sizeof(struct Movie), 1, fp);
    fclose(fp);
    }
    else
        printf("\n\tMOVIE NOT FOUND");

    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
    break;
    }
}

audi()
{
    system("cls");
struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n, int j)
{ struct Node* temp = n;
    int i = 0;
    while (n != NULL) {
            if(j == i)
            {
                printf("\n");
                i =0;
            }
        printf(" [%d]", n->data);
        n = n->next;
        i++;
    }
}

    int n,i,j,option=1;
    struct Node* head;
    struct Node* temp;
    struct Node* x;

    head = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter no. of Seats- ");
    scanf("%d",&n);

    j = sqrt(n);

    x = head;

    x->data = 1;

    for(i=1;i<n;i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i+1;
        x->next = temp;
        temp->next = NULL;
        x = x->next;
    }

    while(option)
    {
        printf("\n Press 1 to view Audi\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1: printList(head,j);
        break;
        case 2: exit(0);
        }
    }

    return 0;
}

void user()
{
    system("color 6f");
    system("cls");
    printf("\n\t\t\t\t*****MOVIE TICKET BOOKING SYSTEM****\n");
    printf("\t\t1.Book Ticket\n");
    printf("\t\t2.Cancel Ticket\n");
    printf("\t\t3.View All Movies\n");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case(1):
        book_ticket();
        break;
    case(2):
        cancel_ticket();
        break;
    case(3):
        view_movies();
        break;
    }
}
view_movies()
{
        FILE *fp;
    fp=fopen("data1.txt","r");
    system("cls");
    printf("\t*ALL MOVIES*\n\n\n");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
     if(p.name!=NULL)
    {
        printf("\n\t MOVIE NAME    :-  %s",p.name);
        printf("\n\t MOVIE TIMING :-  %s",p.code);
        printf("\n\t AVAILABLE SEATS :-  %d",p.date);
        printf("\n\t TICKET PRICE :-  %s\n\n",p.cost);
    }
    }
    fclose(fp);
    fp=fopen("data2.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
     if(p.name!=NULL)
    {
        printf("\n\t MOVIE NAME    :-  %s",p.name);
        printf("\n\t MOVIE TIMING :-  %s",p.code);
        printf("\n\t AVAILABLE SEATS :-  %d",p.date);
        printf("\n\t TICKET PRICE :-  %s\n\n",p.cost);
    }
    }
    fclose(fp);
    fp=fopen("data3.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
     if(p.name!=NULL)
    {
        printf("\n\t MOVIE NAME    :-  %s",p.name);
        printf("\n\t MOVIE TIMING :-  %s",p.code);
        printf("\n\t AVAILABLE SEATS :-  %d",p.date);
        printf("\n\t TICKET PRICE :-  %s\n\n",p.cost);
    }
    }
    fclose(fp);
    fp=fopen("data4.txt","r");
    while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(p.name!=NULL)
    {
        printf("\n\t MOVIE NAME    :-  %s",p.name);
        printf("\n\t MOVIE TIMING :-  %s",p.code);
        printf("\n\t AVAILABLE SEATS :-  %d",p.date);
        printf("\n\t TICKET PRICE :-  %s\n\n",p.cost);
    }
    }
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    getch();
    main();
}
book_ticket()
{
  system("cls");
    int option;
    int a;
    int s;
    int z;
        FILE *fp,*fp1,*fp2;
    printf("\t\tEnter Category:\n");
    printf("\t\t1.2D Hindi\n\t\t2.2D English\n\t\t3.3D Hindi\n\t\t4.3D English\n");
    scanf("%d",&option);
    switch(option)
    {
        case(1):
    fp=fopen("data1.txt","a+");
    fp1=fopen("book.txt","w");
    fp2=fopen("temp.txt","a+");
    int option,flag=0;
    char name1[20];
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag=1;
            printf("\n\t\t Enter No. of Seats to book:");
            scanf("%d",&z);
        if(p.date>z)
        {
         p.date = p.date - z;
         fwrite (&p, sizeof(struct Movie), 1, fp1);
         fwrite (&p, sizeof(struct Movie), 1, fp2);
         printf("\n\t\t\t\tTicket Booked");
        }
        else
        {
            fwrite (&p, sizeof(struct Movie), 1, fp2);
            printf("Insufficient Seats");
        }
        }
        else
        {
         fwrite (&p, sizeof(struct Movie), 1, fp2);
        }
    }
    if(flag==0)
    {
        printf("\n\tMOVIE NOT FOUND");
        printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("data1.txt");
    rename("temp.txt","data1.txt");
    getch();
    main();
    break;

        case(2):
      fp=fopen("data2.txt","a+");
    fp1=fopen("book.txt","w");
    fp2=fopen("temp.txt","a+");
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag=1;
            printf("\n\t\t Enter No. of Seats to book:");
            scanf("%d",&z);
        if(p.date>z)
        {
         p.date = p.date - z;
         fwrite (&p, sizeof(struct Movie), 1, fp1);
         fwrite (&p, sizeof(struct Movie), 1, fp2);
         printf("\n\t\t\t\tTicket Booked");
        }
        else
        {
            fwrite (&p, sizeof(struct Movie), 1, fp2);
            printf("Insufficient Seats");
        }
        }
        else
        {
         fwrite (&p, sizeof(struct Movie), 1, fp2);
        }
    }
    if(flag==0)
    {
        printf("\n\tMOVIE NOT FOUND");
        printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("data2.txt");
    rename("temp.txt","data2.txt");
    getch();
    main();
    break;

        case(3):
   fp=fopen("data3.txt","a+");
    fp1=fopen("book.txt","w");
    fp2=fopen("temp.txt","a+");
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag=1;
            printf("\n\t\t Enter No. of Seats to book:");
            scanf("%d",&z);
        if(p.date>z)
        {
         p.date = p.date - z;
         fwrite (&p, sizeof(struct Movie), 1, fp1);
         fwrite (&p, sizeof(struct Movie), 1, fp2);
         printf("\n\t\t\t\tTicket Booked");
        }
        else
        {
            fwrite (&p, sizeof(struct Movie), 1, fp2);
            printf("Insufficient Seats");
        }
        }
        else
        {
         fwrite (&p, sizeof(struct Movie), 1, fp2);
        }
    }
    if(flag==0)
    {
        printf("\n\tMOVIE NOT FOUND");
        printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("data3.txt");
    rename("temp.txt","data3.txt");
    getch();
    main();
    break;

    case(4):
       fp=fopen("data4.txt","a+");
    fp1=fopen("book.txt","w");
    fp2=fopen("temp.txt","a+");
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag=1;
            printf("\n\t\t Enter No. of Seats to book:");
            scanf("%d",&z);
        if(p.date>z)
        {
         p.date = p.date - z;
         fwrite (&p, sizeof(struct Movie), 1, fp1);
         fwrite (&p, sizeof(struct Movie), 1, fp2);
         printf("\n\t\t\t\tTicket Booked");
        }
        else
        {
            fwrite (&p, sizeof(struct Movie), 1, fp2);
            printf("Insufficient Seats");
        }
        }
        else
        {
         fwrite (&p, sizeof(struct Movie), 1, fp2);
        }
    }
    if(flag==0)
    {
        printf("\n\tMOVIE NOT FOUND");
        printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("data4.txt");
    rename("temp.txt","data4.txt");
    getch();
    main();
    break;
}
}
cancel_ticket()
{
   system("cls");
    int option;
    int a;
    int s;
    int z;
        FILE *fp,*fp1,*fp2;
    printf("\t\tEnter Category:\n");
    printf("\t\t1.2D Hindi\n\t\t2.2D English\n\t\t3.3D Hindi\n\t\t4.3D English\n");
    scanf("%d",&option);
    switch(option)
    {
        case(1):
    fp=fopen("data1.txt","a+");
    fp1=fopen("book.txt","w");
    fp2=fopen("temp.txt","a+");
    int option,flag=0;
    char name1[20];
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag=1;
            printf("\n\t\t Enter No. of Seats to cancel:");
            scanf("%d",&z);
        if(p.date>z)
        {
         p.date = p.date + z;
         fwrite (&p, sizeof(struct Movie), 1, fp1);
         fwrite (&p, sizeof(struct Movie), 1, fp2);
         printf("\n\t\t\t\tTicket Cancelled");
        }
        else
        {
            fwrite (&p, sizeof(struct Movie), 1, fp2);
            printf("Insufficient Seats");
        }
        }
        else
        {
         fwrite (&p, sizeof(struct Movie), 1, fp2);
        }
    }
    if(flag==0)
    {
        printf("\n\tMOVIE NOT FOUND");
        printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("data1.txt");
    rename("temp.txt","data1.txt");
    getch();
    main();
    break;

        case(2):
      fp=fopen("data2.txt","a+");
    fp1=fopen("book.txt","w");
    fp2=fopen("temp.txt","a+");
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag=1;
            printf("\n\t\t Enter No. of Seats to cancel:");
            scanf("%d",&z);
        if(p.date>z)
        {
         p.date = p.date + z;
         fwrite (&p, sizeof(struct Movie), 1, fp1);
         fwrite (&p, sizeof(struct Movie), 1, fp2);
         printf("\n\t\t\t\tTicket Cancelled");
        }
        else
        {
            fwrite (&p, sizeof(struct Movie), 1, fp2);
            printf("Insufficient Seats");
        }
        }
        else
        {
         fwrite (&p, sizeof(struct Movie), 1, fp2);
        }
    }
    if(flag==0)
    {
        printf("\n\tMOVIE NOT FOUND");
        printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("data2.txt");
    rename("temp.txt","data2.txt");
    getch();
    main();
    break;

        case(3):
   fp=fopen("data3.txt","a+");
    fp1=fopen("book.txt","w");
    fp2=fopen("temp.txt","a+");
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag=1;
            printf("\n\t\t Enter No. of Seats to cancel:");
            scanf("%d",&z);
        if(p.date>z)
        {
         p.date = p.date + z;
         fwrite (&p, sizeof(struct Movie), 1, fp1);
         fwrite (&p, sizeof(struct Movie), 1, fp2);
         printf("\n\t\t\t\tTicket Cancelled");
        }
        else
        {
            fwrite (&p, sizeof(struct Movie), 1, fp2);
            printf("Insufficient Seats");
        }
        }
        else
        {
         fwrite (&p, sizeof(struct Movie), 1, fp2);
        }
    }
    if(flag==0)
    {
        printf("\n\tMOVIE NOT FOUND");
        printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("data3.txt");
    rename("temp.txt","data3.txt");
    getch();
    main();
    break;

    case(4):
       fp=fopen("data4.txt","a+");
    fp1=fopen("book.txt","w");
    fp2=fopen("temp.txt","a+");
    system("cls");
    printf("\n\t Enter Movie Name :-");
    fflush(stdin);
    scanf("%[^\n]%*c",name1);
     while(fread (&p, sizeof(struct Movie), 1, fp))
    {
        if(strcmp(p.name,name1)==0)
        {
            flag=1;
            printf("\n\t\t Enter No. of Seats to cancel:");
            scanf("%d",&z);
        if(p.date>z)
        {
         p.date = p.date + z;
         fwrite (&p, sizeof(struct Movie), 1, fp1);
         fwrite (&p, sizeof(struct Movie), 1, fp2);
         printf("\n\t\t\t\tTicket Cancelled");
        }
        else
        {
            fwrite (&p, sizeof(struct Movie), 1, fp2);
            printf("Insufficient Seats");
        }
        }
        else
        {
         fwrite (&p, sizeof(struct Movie), 1, fp2);
        }
    }
    if(flag==0)
    {
        printf("\n\tMOVIE NOT FOUND");
        printf("\n\tPRESS ANY KEY TO CONTINUE: ");
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    remove("data4.txt");
    rename("temp.txt","data4.txt");
    getch();
    main();
    break;
}
}