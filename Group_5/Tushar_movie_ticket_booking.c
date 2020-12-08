#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct {
    char name[55];
    char language[8];
    char type[3];
    char time[6];
    int price;
    int ticket_booked;
}mov;

struct Node {
    int data;
    struct Node *next;
};

int main(void);
void password();
void admin();
void add_movie();
void show_movie();
void delete_movie();
void audi();
void edit_movie();
void show_movie_user();
void book_ticket();
//void bubbleSort(struct Node *);
void show_seats(struct Node*, int );
void cancel_ticket();


///////////////////////////////////////////////////ADMIN FUNCTIONS///////////////////////////////////////////////////

void admin()
{
    int op;
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    printf("\n\n\tpress 1 to add movie\n\tpress 2 to show movie list\n\tpress 3 to Delete movie\n\tpress 4 for Audi Details\n\tPress 5 to Edit Movie Details\n\tpress 0 to exit\n\n\tEnter your choise - ");
    scanf("%d",&op);
    switch(op)
    {
        case 1: add_movie();
        break;
        case 2: show_movie();
        break;
        case 3: delete_movie();
        break;
        case 4: audi();
        break;
        case 5: edit_movie();
        break;
        case 0: main();
        break;
    }
}

void add_movie()
{
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    int temp,i=1,flag;
    char file_name[55],temp_naam[55],mov_name[55];
    FILE *fptr;
    while(i)
    {
        fptr = fopen("movie.txt","r");
    printf("\n\n\tEnter Movie Name - ");
    fflush(stdin);
    gets(mov.name);
    strcpy(temp_naam,mov.name);
    strcat(temp_naam,"\n");
    flag = 0;
    while(fgets(mov_name,55,fptr)!= NULL)
    {
        if(strcmp(mov_name,temp_naam) == 0)
        {
            printf("\n\n\t\tMovie Name Already Present!!!\n");
            flag =1;
        }
        if(flag)
        {
            printf("\n\tPress 1 to Enter again\n\tPress 0 exit\n\n\tEnter your choise - ");
            scanf("%d",&i);
            if(i == 0)
                admin();
        }
        else
            i =0;
    }
    fclose(fptr);
    }

    strcpy(file_name,mov.name);
    strcat(file_name,".txt");
    fptr = fopen(file_name,"a+");
    fputs(mov.name,fptr);
    printf("\n\tSelect Language\n\t\tpress 0 for English\n\t\tpress 1 for Hindi\n\n\t\tEnter your choice - ");
    scanf("%d",&temp);
    if(temp)
        strcpy(mov.language,"Hindi");
    else
        strcpy(mov.language,"English");

    printf("\n\n\tSelect Viewing Type\n\t\tpress 0 for 2D\n\t\tpress 1 for 3D\n\n\t\tEnter your choice - ");
    scanf("%d",&temp);
    if(temp)
        strcpy(mov.type,"3D");
    else
        strcpy(mov.type,"2D");

    printf("\n\n\tEnter Movie time - ");
    scanf("%s",mov.time);

    printf("\n\n\tEnter Normal Ticket Price - ");
    scanf("%d",&mov.price);

    mov.ticket_booked = 0;

    fprintf(fptr,"\n%s %s %s %d %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
    fclose(fptr);
    fptr = fopen("movie.txt","a+");
    fputs(mov.name,fptr);
    fputs("\n",fptr);
    fclose(fptr);
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    printf("\n\n\t\tMOVIE ADDED!!!\n\n\tPress any key to continue...");
    getch();
    admin();
}

void show_movie()
{
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    int op = 1;
    char mov_name[55];
    FILE *fptr;
    fptr = fopen("movie.txt","r");
    printf("\n\n\tMOVIE NAMES :-\n\n");

    while(fgets(mov_name,55,fptr)!= NULL){
            printf("\t");
        puts(mov_name);
    }
    fclose(fptr);
        printf("\n\tPress 1 for Detailed list\n\tPress 0 exit\n\n\tEnter option - ");
        scanf("%d",&op);

        switch(op)
        {
            case 1: printf("\n\n\tEnter movie name - ");
                    fflush(stdin);
                    gets(mov_name);
                    strcat(mov_name,".txt");
                    fptr = fopen(mov_name,"r");
                    if(fptr == NULL)
                        printf("\n\n\t\tWRONG MOVIE NAME!!!\n\n");
                    else
                    {
                    fflush(stdin);
                    fgets(mov.name,55,fptr);
                    fscanf(fptr,"%s %s %s %d %d",mov.language,mov.type,mov.time,&mov.price,&mov.ticket_booked);
                    system("cls");
                    printf("\n\t\t\tMOVIE TICKET BOOKING");
                    printf("\n\n\tName\t-\t");
                    puts(mov.name);
                    printf("\tAudio\t-\t%s\n\tType\t-\t%s\n\tTiming\t-\t%s\n\tPrice\t-\t%d\n\tBooked\t-\t%d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
                    fclose(fptr);
                    }
                    printf("\n\tPress any key continue...");
                    getch();
                    break;
        }
        admin();
}

void delete_movie()
{
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    printf("\n");
    int flag =0;
    char mov_name[55],temp[55],temp2[55];
    FILE *fptr,*p;
    fptr = fopen("movie.txt","r");
    while(fgets(mov_name,55,fptr)!= NULL){

            printf("\t");
        puts(mov_name);

    }


    fclose(fptr);

    fptr = fopen("movie.txt","r+");
    p = fopen("movie_temp.txt","w");
    printf("\n\n\tEnter Movie name to Delete - ");
    fflush(stdin);
    gets(temp);
    strcpy(temp2,temp);
    strcat(temp,"\n");

    while(fgets(mov_name,55,fptr)!= NULL)
    {
        if(strcmp(temp,mov_name) == 0)
            {
                strcat(temp2,".txt");
                remove(temp2);
                flag++;
            }
        else
            fputs(mov_name,p);
    }
    fclose(fptr);
    fclose(p);

    remove("movie.txt");
    rename("movie_temp.txt","movie.txt");

    if(flag)
        printf("\n\tMOVIE DELETED!!!");
    else
        printf("\n\tWRONG MOVIE NAME!!!");

    printf("\n\n\tPress any key continue...");
    getch();
    admin();
}


void audi()
{
    FILE *fptr;
    int option,seats,len,silver,gold;
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    printf("\n\n\tPress 1 To See Audi details\n\tPress 2 to Edit Details\n\tPress 0 to Exit\n\n\tEnter choice :- ");
    scanf("%d",&option);
    switch(option)
    {
        case 1: system("cls");
                printf("\n\t\t\tMOVIE TICKET BOOKING");
                fptr = fopen("audi.txt","r");
                fscanf(fptr,"%d %d %d %d",&seats,&len,&silver,&gold);
                printf("\n\n\tTotal seats\t-\t%d\n\tSeats in a Row\t-\t%d\n\n\tPrice\n\tSilver seats\t-\t%d\n\tGold seats\t-\t%d",seats,len,silver,gold);
                fclose(fptr);
                printf("\n\n\tPress any key to continue...");
                getch();
                break;
        case 2:system("cls");
               printf("\n\t\t\tMOVIE TICKET BOOKING");
               while(1)
               {
                   printf("\n\n\tEnter Total seats :- ");
                   scanf("%d",&seats);
                   len = sqrt(seats);
                   if(len*len == seats)
                   {
                       break;
                   }
                   else
                   {
                       system("cls");
                       printf("\n\t\t\tMOVIE TICKET BOOKING");
                       printf("\n\n\t\tEnter a Perfect Square Number!!!");
                   }
               }

               printf("\n\n\tEnter Price for Silver seat - ");
               scanf("%d",&silver);
               printf("\n\n\tEnter Price for Gold seat- ");
               scanf("%d",&gold);
               fptr = fopen("audi.txt","w");
               fprintf(fptr,"%d %d %d %d",seats,len,silver,gold);
               fclose(fptr);
               printf("\n\n\tPress any key to continue...");
               getch();
               break;

        case 3: option = 0;

    }
    admin();
}


void edit_movie()
{
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    char mov_name[55],temp[55],file_name[55],p_name[55];
    int op,temp_data,i;
    FILE *fptr,*p;
    struct Node *head, *tem, *x;
    head = (struct Node*)malloc(sizeof(struct Node));
    x = head;
    fptr = fopen("movie.txt","r");
    printf("\n\t MOVIE NAMES\n\n");
    while(fgets(mov_name,55,fptr)!= NULL)
    {
        printf("\t");
        puts(mov_name);
    }

    fclose(fptr);

    printf("\tEnter movie name to Edit Data - ");
    fflush(stdin);
    gets(mov_name);
    strcpy(file_name,mov_name);
    strcat(file_name,".txt");
    fptr = fopen(file_name,"r");
    fflush(stdin);
    fgets(mov.name,55,fptr);
    fscanf(fptr,"%s %s %s %d %d",mov.language,mov.type,mov.time,&mov.price,&mov.ticket_booked);
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    printf("\n\n\tName\t-\t");
    puts(mov.name);
    printf("\n\tAudio\t-\t%s\n\tType\t-\t%s\n\tTiming\t-\t%s\n\tPrice\t-\t%d\n\tBooked\t-\t%d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
    if(mov.ticket_booked)
    {
        fscanf(fptr,"%d",&temp_data);
       // printf("%d",temp_data);
        x->data = temp_data;
        x->next = NULL;
        for(i=1;i<mov.ticket_booked;i++)
        {
            tem = (struct Node*)malloc(sizeof(struct Node));
            fscanf(fptr,"%d",&temp_data);
            tem->data = temp_data;
            tem->next = NULL;
            x->next = tem;
            x = x->next;
        }
    }
    fclose(fptr);


    printf("\n\tEdit name\t-\t1\n\tEdit Language\t-\t2\n\tEdit type\t-\t3\n\tEdit Timing\t-\t4\n\tEdit Price\t-\t5\n\tLeave Edit\t-\t6\n\n\tEnter your choice\t-\t");
    scanf("%d",&op);
    switch(op)
    {
        case 1: printf("\n\tEnter new Name - ");
                fflush(stdin);
                gets(mov.name);
                strcpy(temp,mov.name);
                strcat(temp,".txt");
                fptr = fopen(temp,"w");
                fputs(mov.name,fptr);
                fprintf(fptr,"\n%s %s %s %d %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
                if(mov.ticket_booked)
                {

                    x = head;
                    while(x != NULL)
                    {
                        fprintf(fptr,"%d ",x->data);
                        x = x->next;
                    }
                }
                fclose(fptr);
                p = fopen("rename.txt","w");
                fptr = fopen("movie.txt","r");
                strcat(mov_name,"\n");
                while(fgets(p_name,55,fptr)!= NULL)
                {
                    if(strcmp(p_name,mov_name) == 0)
                    {
                        remove(file_name);
                        strcat(mov.name,"\n");
                        fputs(mov.name,p);
                    }
                    else
                        fputs(p_name,p);
                }
                fclose(p);
                fclose(fptr);
                remove("movie.txt");
                rename("rename.txt","movie.txt");
                printf("\n\n\tNAME CHANGED!!!");
                printf("\n\n\t\tPress any key to continue...");
                getch();
                break;

        case 2: if(strcmp(mov.language,"English") == 0)
                   strcpy(mov.language,"Hindi");
                else
                   strcpy(mov.language,"English");

                fptr = fopen(file_name,"w");
                fputs(mov.name,fptr);
                fprintf(fptr,"\n%s %s %s %d %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
                if(mov.ticket_booked)
                {

                    x = head;
                    while(x != NULL)
                    {
                        fprintf(fptr,"%d ",x->data);
                        x = x->next;
                    }
                }
                fclose(fptr);
                printf("\n\n\t\tLANGUAGE CHANGED\n\n\tPress any key to continue...");
                getch();
                break;

        case 3: if(strcmp(mov.type ,"2D") == 0)
                   strcpy(mov.type,"3D");
                else
                   strcpy(mov.type,"2D");

                fptr = fopen(file_name,"w");
                fputs(mov.name,fptr);
                fprintf(fptr,"\n%s %s %s %d %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
                if(mov.ticket_booked)
                {

                    x = head;
                    while(x != NULL)
                    {
                        fprintf(fptr,"%d ",x->data);
                        x = x->next;
                    }
                }
                fclose(fptr);
                printf("\n\n\t\tTYPE CHANGED\n\n\tPress any key to continue...");
                getch();
                break;

        case 4: printf("\n\n\tEnter New timing - ");
                scanf("%s",mov.time);
                fptr = fopen(file_name,"w");
                fputs(mov.name,fptr);
                fprintf(fptr,"\n%s %s %s %d %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
                if(mov.ticket_booked)
                {

                    x = head;
                    while(x != NULL)
                    {
                        fprintf(fptr,"%d ",x->data);
                        x = x->next;
                    }
                }
                fclose(fptr);
                printf("\n\n\t\tTIMING CHANGED\n\n\tPress any key to continue...");
                getch();
                break;

        case 5: printf("\n\n\t Enter New Price - ");
                scanf("%d",&mov.price);
                fptr = fopen(file_name,"w");
                fputs(mov.name,fptr);
                fprintf(fptr,"\n%s %s %s %d %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
                if(mov.ticket_booked)
                {

                    x = head;
                    while(x != NULL)
                    {
                        fprintf(fptr,"%d ",x->data);
                        x = x->next;
                    }
                }
                fclose(fptr);
                printf("\n\n\t\tPRICE CHANGED\n\n\tPress any key to continue...");
                getch();
                break;

        default: printf("\n\n\tNOTHING CHANGED\n\n\t Press any key to continue...");
                 getch();
                 break;

    }

    admin();
}

void password()
{
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    char p[9],temp[9];
    int i,flag = 1;
    //FILE *fptr;
    //fptr = fopen("pass.txt","r");
    //fgets(temp,9,fptr);
    strcpy(temp,"hell-007");
    while(flag)
    {
    printf("\n\n\tEnter Password - ");
    for(i =0;i<8;i++)
    {
        p[i] = getch();
        printf("*");
    }

    if(!strcmp(p,temp))
    {
        admin();

    }
    else
    {
        system("cls");
        printf("\n\t\t\tMOVIE TICKET BOOKING");
        flag++;
        printf("\n\n\tWRONG PASSWORD!!!");
        if(flag == 4)
            main();
    }
   // fclose(fptr);
    }
}

/////////////////////////////////////////////////////////USER FUNCTIONS////////////////////////////////////////////////////


void show_movie_user()
{
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    int op = 1;
    char mov_name[55];
    FILE *fptr;
    fptr = fopen("movie.txt","r");
    printf("\n\n\tMOVIE NAMES :-\n\n");

    while(fgets(mov_name,55,fptr)!= NULL){
            printf("\t");
        puts(mov_name);
    }

    fclose(fptr);
        printf("\n\tPress 1 for Detailed list\n\tPress 2 exit\n\n\tEnter option - ");
        scanf("%d",&op);
        while(op)
        {
        switch(op)
        {
            case 1: printf("\n\n\tEnter movie name - ");
                    fflush(stdin);
                    gets(mov_name);
                    strcat(mov_name,".txt");
                    fptr = fopen(mov_name,"r");
                    if(fptr == NULL)
                        printf("\n\n\t\tWRONG MOVIE NAME\n\n");
                    else
                    {
                    fflush(stdin);
                    fgets(mov.name,55,fptr);
                    fscanf(fptr,"%s %s %s %d %d",mov.language,mov.type,mov.time,&mov.price,&mov.ticket_booked);
                    system("cls");
                    printf("\n\t\t\tMOVIE TICKET BOOKING");
                    printf("\n\n\tName         - ");
                    puts(mov.name);
                    printf("\tLanguage     - %s\n\tType         - %s\n\tTiming       - %s\n\tPrice        - %d\n\tBooked Seats - %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
                    fclose(fptr);
                    }
                    printf("\n\tPress 1 to check another\n\tPress 0 to exit\n\n\tEnter your choice - ");
                    scanf("%d",&op);
                    if(op == 1)
                        op = 2;
                    else
                        op =3;
                    break;

            case 2: system("cls");
                    printf("\n\t\t\tMOVIE TICKET BOOKING");
                    fptr = fopen("movie.txt","r");
                    printf("\n\n\tMOVIE NAMES :-\n\n");

                    while(fgets(mov_name,55,fptr)!= NULL){
                    printf("\t");
                    puts(mov_name);
                    }
                    fclose(fptr);
                    printf("\n\n\tEnter movie name - ");
                    fflush(stdin);
                    gets(mov_name);
                    strcat(mov_name,".txt");
                    fptr = fopen(mov_name,"r");
                    if(fptr == NULL)
                        printf("\n\n\t\tWRONG MOVIE NAME\n\n");
                    else
                    {
                    fflush(stdin);
                    fgets(mov.name,55,fptr);
                    fscanf(fptr,"%s %s %s %d %d",mov.language,mov.type,mov.time,&mov.price,&mov.ticket_booked);
                    system("cls");
                    printf("\n\t\t\tMOVIE TICKET BOOKING");
                    printf("\n\n\tName         - ");
                    puts(mov.name);
                    printf("\tLanguage     - %s\n\tType         - %s\n\tTiming       - %s\n\tPrice        - %d\n\tBooked Seats - %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
                    fclose(fptr);
                    }
                    printf("\n\tPress 1 to check another\n\tPress 0 to exit\n\n\tEnter your choice - ");
                    scanf("%d",&op);
                    if(op == 1)
                        op = 2;
                    else
                        op =3;
                    break;


            case 3: op = 0;
                    printf("\n\t\tPress any key to continue");
                    getch();
        }
        }
        main();
}


void book_ticket()
{
    FILE *fptr;
    struct Node *head, *temp, *x;
    head = (struct Node*)malloc(sizeof(struct Node));
    x = head;
    head->data = -1;
    head->next = NULL;
    char mov_name[55],bkp_name[55];
    int seats_book,i,temp_data,seats,len,silver,gold,n,uniq,sum =0;
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    printf("\n\n\tEnter movie name - ");
    fflush(stdin);
    gets(mov_name);
    strcpy(bkp_name,mov_name);
    strcat(mov_name,".txt");
    fptr = fopen(mov_name,"r");
    if(fptr == NULL)
    {
                 printf("\n\n\t\tWRONG MOVIE NAME\n\n\tPress any key to continue...");
                 getch();
                 main();

    }
    fflush(stdin);
    fgets(mov.name,55,fptr);
    fscanf(fptr,"%s %s %s %d %d",mov.language,mov.type,mov.time,&mov.price,&mov.ticket_booked);
    if(mov.ticket_booked)
    {
        fscanf(fptr,"%d",&temp_data);
        x->data = temp_data;
        x->next = NULL;
        for(i=1;i<mov.ticket_booked;i++)
        {
            temp = (struct Node*)malloc(sizeof(struct Node));
            fscanf(fptr,"%d",&temp_data);
            temp->data = temp_data;
            temp->next = NULL;
            x->next = temp;
            x = x->next;
        }

    }
    fclose(fptr);

    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    fptr = fopen("audi.txt","r");
    fscanf(fptr,"%d %d %d %d",&seats,&len,&silver,&gold);
    printf("\n\n\tName         - ");
    puts(mov.name);
    printf("\tAudio\t-\t%s\n\tType\t-\t%s\n\tTiming\t-\t%s\n\tPrice\t-\t%d\n\tSeats\n\tTotal\t-\t%d\n\tLeft\t-\t%d\n",mov.language,mov.type,mov.time,mov.price,seats,seats-mov.ticket_booked);
    fclose(fptr);
    if(seats == mov.ticket_booked){
        printf("\n\n\t\tHOUSE FULL");
        printf("\n\n\tPress any key to continue....");
        getch();
        main();
    }


    printf("\n\n\tEnter tickets to book - ");
    scanf("%d",&seats_book);

    if(seats_book > seats - mov.ticket_booked)
    {
        printf("\n\n\tSorry Only %d seats are left\n\nPress any key to continue...",seats - mov.ticket_booked);
        getch();
        main();
    }

    show_seats(head,mov.price);

    fptr = fopen("booked.txt","a+");

    for(i=0;i<seats_book;)
    {
        uniq = 0;
        printf("\n\tEnter seat Number - ");
        scanf("%d",&n);
        if(n>0 && n<=seats)
        {
        temp = head;
        while(temp != NULL)
        {
            if(temp->data == n)
            {
                uniq = 1;
                printf("\n\tSeat is allready booked, Enter another seat number...");
                break;
            }

            temp = temp->next;
        }

        if(uniq == 0)
        {
            if(i == 0)
            {
                fputs(bkp_name,fptr);
                fprintf(fptr,"\n%d %d ",seats_book,n);
            }
            else{
                fprintf(fptr,"%d ",n);
            }
        if(x->data == -1)
            x->data = n;
        else{
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = n;
            temp->next = NULL;
            x->next = temp;
            x = x->next;
        }

        if(n<seats/2)
            sum = sum + mov.price;
        else if(seats/2 < n && n < seats/4*3)
            sum = sum + mov.price + silver;
        else
            sum = sum + mov.price + gold;

        i++;
        }
        }
        else
        printf("\n\t\tWrong seat Number!!!");
    }
    fprintf(fptr,"\n");
    fclose(fptr);

    mov.ticket_booked = mov.ticket_booked + seats_book;
    fptr = fopen(mov_name,"w");
    fputs(mov.name,fptr);
    fprintf(fptr,"\n%s %s %s %d %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
    if(mov.ticket_booked)
        {
            x = head;
            while(x != NULL)
            {
                fprintf(fptr,"%d ",x->data);
                x = x->next;
            }
        }
    fclose(fptr);

    printf("\n\n\tTotal Cost - %d \n\n\t\tTickets Booked\n\n\t\tEnjoy the movie!!!",sum);
    /*printf("\n\n\tNew List - ");
    x = head;
    while(x != NULL)
    {
       printf("%d ",x->data);
       x = x->next;
    }*/
    getch();
   main();
}


void show_seats(struct Node *n, int price)
{
    system("cls");
    printf("\n\t\t\t\t  MOVIE TICKET BOOKING\n\n");
    struct Node *x;
    int seats,len,silver,gold,i,flag;
    FILE *fptr;
    fptr = fopen("audi.txt","r");
    fscanf(fptr,"%d %d %d %d",&seats,&len,&silver,&gold);
    fclose(fptr);
    printf("\n\t");
    printf("\n\t-----------\tS\tC\tR\tE\tE\tN\t--------------");
    printf("\n\n\t");
    for(i =1;i<=seats;i++)
    {
        flag =1;
        x = n;
        while(x != NULL)
        {
            if(i == x->data){
                flag = 0;
                break;
            }
            x = x->next;
        }
        if(flag)
            printf("[%d]\t",i);
        else
            printf("[0]\t");

        if(i%len == 0)
            printf("\n\t");
    }

    printf("\n\tPrice for seat Number 0 to %d - %d",seats/2,price);
    printf("\n\tPrice for seat Number %d to %d - %d",seats/2+1,(seats*3)/4,price+silver);
    printf("\n\tPrice for seat Number %d to %d - %d\n",(seats*3)/4+1,seats,price+gold);
}

void cancel_ticket()
{
    FILE *fptr, *tptr;
    char mov_name[55],mov_file[55];
    int seat_num,a[10],n,i,flag =0,temp_data;
    struct Node *head, *temp, *x;
    head = (struct Node*)malloc(sizeof(struct Node));
    x = head;
    head->data = -1;
    head->next = NULL;
    system("cls");
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    printf("\n\n\tEnter movie name - ");
    fflush(stdin);
    gets(mov_name);
    strcpy(mov_file,mov_name);
    strcat(mov_file,".txt");
    strcat(mov_name,"\n");
    printf("\n\tEnter First seat number - ");
    scanf("%d",&seat_num);
    fptr = fopen("booked.txt","r");

    while(fgets(mov.name,55,fptr)!= NULL)
    {
        fscanf(fptr,"%d",&n);
        for(i=0;i<n;i++)
            fscanf(fptr,"%d",&a[i]);
        if( strcmp(mov.name,mov_name)== 0 && seat_num == a[0])
        {
            flag =1;
            break;
        }
    }
    fclose(fptr);
    if(flag)
    {
    fptr = fopen(mov_file,"r");
    fflush(stdin);
    fgets(mov.name,55,fptr);
    fscanf(fptr,"%s %s %s %d %d",mov.language,mov.type,mov.time,&mov.price,&mov.ticket_booked);

    fscanf(fptr,"%d",&temp_data);
    x->data = temp_data;
    x->next = NULL;
    for(i=1;i<mov.ticket_booked;i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        fscanf(fptr,"%d",&temp_data);
        temp->data = temp_data;
        temp->next = NULL;
        x->next = temp;
        x = x->next;
    }
    fclose(fptr);

    for(i=0;i<n;i++)
    {
        x = head;

        if(head->data == a[i])
        {
            head = head->next;
        }
        else
        {
            while(x->next!= NULL)
            {
                if(x->next->data == a[i])
                {
                    x->next = x->next->next;
                    break;
                }

                x = x->next;

            }
        }
    }
    mov.ticket_booked = mov.ticket_booked - n;
    fptr = fopen(mov_file,"w");
    fputs(mov.name,fptr);
    fprintf(fptr,"\n%s %s %s %d %d\n",mov.language,mov.type,mov.time,mov.price,mov.ticket_booked);
    if(mov.ticket_booked)
        {
            x = head;
            while(x != NULL)
                {
                    fprintf(fptr,"%d ",x->data);
                    x = x->next;
                }
        }
    fclose(fptr);

    fptr = fopen("booked.txt","r");
    tptr = fopen("temp_booked.txt","w");

    while(fgets(mov.name,55,fptr)!= NULL)
    {
        if(strcmp(mov.name," \n") == 0)
        {
            puts(mov.name);
        }
        else
        {
        fscanf(fptr,"%d",&n);
        for(i=0;i<n;i++)
            fscanf(fptr,"%d",&a[i]);
        if( strcmp(mov.name,mov_name)== 0 && seat_num == a[0])
        {
            flag =1;
        }
        else
        {
            fputs(mov.name,tptr);
            fprintf(tptr,"%d ",n);
            for(i=0;i<n;i++)
                fprintf(tptr,"%d ",a[i]);
            fprintf(tptr,"\n");
        }
        }
    }
    fclose(fptr);
    fclose(tptr);
    remove("booked.txt");
    rename("temp_booked.txt","booked.txt");
    printf("\n\n\tTicket Canceled");
    }
    else
        printf("\n\n\tTicket Not Found");

    getch();
    main();

}

//////////////////////////////////////////////////////////MAIN FUNCTION/////////////////////////////////////////////////////

int main(void)
{
    system("cls");
    int option1;
    printf("\n\t\t\tMOVIE TICKET BOOKING");
    printf("\n\n\tPress 1 for Admin\n\tPress 2 to see movies\n\tPress 3 to Book Ticket\n\tPress 4 to Cancel Ticket\n\tPress 5 to Exit\n\n\tEnter your choice - ");
    fflush(stdin);
    scanf("%d",&option1);
    switch (option1)
    {
        case 1: password();
        break;

        case 2: show_movie_user();
        break;

        case 3: book_ticket();
        break;

        case 4: cancel_ticket();
        break;

        case 5: exit(0);
        default : printf("\n\t\t WRONG INPUT");
        getch();
        main();

    }
}
