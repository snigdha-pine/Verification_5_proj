#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct movies{
char movie_name[20];
char categ[10];
char dim[4];
char timing[10];
int price_g;
int price_s;
int seats;
};

struct ticket{
long long uniq_id;
char seat_cate[10];
int no_tickets;
int total_pr;
char time[10];
char movie[20];
};

struct ticket tk;
struct movies mv;
FILE *fp=NULL;
FILE *tp=NULL;
FILE *tmpFp=NULL;
FILE *tmpFp1=NULL;

/**************************  ADMIN FUNCTIONS  ************************/
void admin();
int password();
void add_movie();
void show_movie();
void delete_movie();
void edit_movie();
void edit_audi();

/**************************  USER FUNCTIONS  *************************/
void user();
void book_ticket();
void cancel_ticket();
void show_movies();

/***************************  MAIN  ***********************************/
int main(){
 int ch,i;
 system("cls");
 printf("\n\t\t\t************************************************************");
 printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
 printf("\n\t\t\t************************************************************");

 printf("\n\n\n\t\t\t1. Admin\n\t\t\t2. User\n\t\t\t3. Exit\n\n\t\t\t");
 scanf("%d",&ch);

 switch(ch)
 {
    case 1: system("cls");
            printf("\n\t\t\tWELCOME TO ADMIN");
            Sleep(400);
            system("cls");
            enter:
            i = password();
            if (i==1){
            printf("\n\n\t\t**Password correct**");
            Sleep(400);
            system("cls");
            admin();
            }
            else{
                  printf("\n\n\t\t**Pass Incorrect!!! Please enter it again");
                  Sleep(600);
                  goto enter;
            }
            break;
    case 2: system("cls");
            printf("\n\t\t\tWELCOME TO USER");
            Sleep(400);
            user();
            break;
    case 3: exit(0);
            break;
    default: printf("Entered choice is wrong...");
 }
 return 0;
 }

/*****************************  ADMIN  ***********************************/

void admin(){
 int ch;
 system("cls");
 printf("\n\t\t\t************************************************************");
 printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
 printf("\n\t\t\t************************************************************");
 printf("\n\t\t\t********************** ADMIN PANEL *************************");

 printf("\n\n\n\t\t\t1. Add Movie\n\t\t\t2. Show List of Movies\n\t\t\t3. Delete Movie\n\t\t\t4. Edit Movie\n\t\t\t5. Exit\n\t\t\t");
 scanf("%d",&ch);

 switch(ch)
 {
    case 1: system("cls");
        printf("\n\t\t\tWELCOME TO ADD MOVIE PANEL...");
        Sleep(400);
        add_movie();
        break;
    case 2: system("cls");
        printf("\n\t\t\tWELCOME TO MOVIE[s] LIST...");
        Sleep(400);
        show_movie();
        break;
    case 3: system("cls");
        printf("\n\t\t\tWELCOME TO DELETE MOVIE PANEL...");
        Sleep(400);
        delete_movie();
        break;
    case 4: system("cls");
        printf("\n\t\t\tWELCOME TO EDIT MOVIE PANEL...");
        Sleep(400);
        edit_movie();
        break;
    case 5:
         main();
         break;
    default: printf("Entered choice is wrong...");
 }
 }

 int password(){
char pass[10],ch;
int i;
system("cls");
printf("\n\t\t\t************************************************************");
printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
printf("\n\t\t\t************************************************************");
printf("\n\n\t\t\tEnter 8 character password to Admin Panel\n\t\t\t");
for(int i=0;i<=7;i++)
{
    ch=getch();
    pass[i]=ch;
    ch='*';
    printf("%c",ch);
}

if(strcmp(pass,"aviral98")==0)
    i=1;
else
    i=0;

return i;
}

void add_movie()
{   int ch,lc,dc,tc;
    int fn=0;
    char mv_name[20];
    detail:
    system("cls");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t********************** ADD MOVIE PANEL *********************");
    printf("\n\t\t\tEnter Name:");
    fflush(stdin);
    scanf("%[^\n]*s",mv_name);
    strcat(mv_name,"\n");

    fp=fopen("Movie.txt","r");
    while(fgets(mv.movie_name,20,fp)!= NULL)
    {
      fscanf(fp,"%s %s %s %d %d %d\n",mv.categ,mv.dim,mv.timing,&mv.price_g,&mv.price_s,&mv.seats);
        if ((strcmp(mv.movie_name, mv_name) == 0)) {
			fn=1;
			break;
        }
    }
    fclose(fp);
    if(fn==1){
        printf("\n\t\t\tMovie is already present");
        Sleep(600);
        admin();
    }
    else{
    fp=fopen("Movie.txt","a");
    strcpy(mv.movie_name,mv_name);
    lcs:
    printf("\n\t\t\tSelect Language:\n\t\t\t\t1. Hindi\n\t\t\t\t2. English: ");
    scanf("%d",&lc);
    switch(lc)
    { case 1: strcpy(mv.categ,"Hindi");
                break;
      case 2: strcpy(mv.categ,"English");
                break;
      default: printf("Wrong Choice Entered...Enter again");
               goto lcs;
    }
    lcd:
    printf("\n\t\t\tSelect Dimension:\n\t\t\t\t1. 2D\n\t\t\t\t2. 3D: ");
    scanf("%d",&dc);
    switch(dc)
    { case 1: strcpy(mv.dim,"2D");
                break;
      case 2: strcpy(mv.dim,"3D");
                break;
      default: printf("Wrong Choice Entered...Enter again");
               goto lcd;
    }
    tcd:
    printf("\n\t\t\tTimings:\n\t\t\t\t1. 9am-12pm\n\t\t\t\t2. 12pm-3pm\n\t\t\t\t3. 3pm-6pm\n\t\t\t\t4. 6pm-9pm\n\t\t\t\t5. 9pm-12am:");
    scanf("%d",&tc);
    switch(tc)
    { case 1: strcpy(mv.timing,"9am-12pm");
                break;
      case 2: strcpy(mv.timing,"12pm-3pm");
                break;
      case 3: strcpy(mv.timing,"3pm-6pm");
                break;
      case 4: strcpy(mv.timing,"6pm-9pm");
                break;
      case 5: strcpy(mv.timing,"9pm-12am");
                break;
      default: printf("Wrong Choice Entered...Enter again");
               goto tcd;
    }
    printf("\n\t\t\tPricing:\n\t\t\t\tGold:");
    scanf("%d",&mv.price_g);
    printf("\n\t\t\t\tSilver:");
    scanf("%d",&mv.price_s);
    printf("\n\t\t\tSeats:");
    scanf("%d",&mv.seats);
    fprintf(fp,"%s%s %s %s %d %d %d\n",mv.movie_name,mv.categ,mv.dim,mv.timing,mv.price_g,mv.price_s,mv.seats);

    printf("\n\tEnter 1 to save 2 to enter details again:");
    scanf("%d",&ch);

    if(ch==1){
        system("cls");
        printf("\nEntered details are updated....");
        fclose(fp);
        Sleep(400);
        admin();
    }
    else if(ch==2){
        system("cls");
        printf("\nCanceled...Enter again");
        Sleep(400);
        goto detail;
    }
  }
}

void show_movie(){
    int ch;
    detail:
    system("cls");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t******************** LIST OF MOVIE[S] **********************");
    fp=fopen("Movie.txt","r");
    if(fp==NULL){
    printf("\n\n\t\tFILE IS EMPTY");
    admin();
    }
    while(fgets(mv.movie_name,20,fp)!= NULL)
   {
    fscanf(fp,"%s %s %s %d %d %d\n",mv.categ,mv.dim,mv.timing,&mv.price_g,&mv.price_s,&mv.seats);
    printf("\n\t\t\tMovie Name:%s",mv.movie_name);
    printf("\n\t\t\tCategory:%s",mv.categ);
    printf("\n\t\t\tDimension:%s",mv.dim);
    printf("\n\t\t\tTiming:%s",mv.timing);
    printf("\n\t\t\tPricing:\n\t\t\t\tGold:%d\n\t\t\t\tSilver:%d",mv.price_g,mv.price_s);
    printf("\n\t\t\tSeats:%d",mv.seats);
    printf("\n\t\t\t****************************");
    }
    fclose(fp);
    printf("\n\t\t\tEnter 1 to go back:");
    scanf("%d",&ch);
    if(ch==1){
        admin();
    }
    else{
        goto detail;
    }
}

 void delete_movie(){
 int fn=0;
 char mv_name[20];
    detail:
    system("cls");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t******************* DELETE MOVIE PANEL *********************");
    fp=fopen("Movie.txt","r+");
    tmpFp=fopen("Tmp.txt","w");
    if(fp==NULL){
            printf("\n\n\n\t\t\tFILE IS EMPTY");
            admin();
    }

    printf("\n\n\t\t\tEnter the name of movie to delete:");
    fflush(stdin);
    scanf("%[^\n]*s",mv_name);
    strcat(mv_name,"\n");
    while(fgets(mv.movie_name,20,fp)!= NULL)
   {
    fscanf(fp,"%s %s %s %d %d %d\n",mv.categ,mv.dim,mv.timing,&mv.price_g,&mv.price_s,&mv.seats);
        if ((strcmp(mv.movie_name, mv_name) == 0)) {
			fn=1;
			continue;
		}
			fprintf(tmpFp,"%s%s %s %s %d %d %d\n",mv.movie_name,mv.categ,mv.dim,mv.timing,mv.price_g,mv.price_s,mv.seats);
    }
	fclose(fp);
	fclose(tmpFp);
	remove("Movie.txt");
	rename("Tmp.txt","Movie.txt");

	if (fn==0) {
		printf("\n\n\t\tNo record found with the requested name: %s", mv_name);
		Sleep(600);
		goto detail;
	}
	else
    {   printf("\nRecord found and deleted");
        Sleep(600);
        admin();
    }
}

void edit_movie(){
 int fn=0;
 int lc,dc,tc,ch;
 char mv_name[20];
    detail:
    system("cls");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t******************* EDIT MOVIE PANEL *********************");
    fp=fopen("Movie.txt","r+");
    tmpFp=fopen("Tmp.txt","w");
    if(fp==NULL){
            printf("\n\n\n\t\t\tFILE IS EMPTY");
            admin();
    }

    printf("\n\n\t\t\tEnter the name of movie to update:");
    fflush(stdin);
    scanf("%[^\n]*s",mv_name);
    strcat(mv_name,"\n");
    while(fgets(mv.movie_name,20,fp)!= NULL)
   {
    fscanf(fp,"%s %s %s %d %d %d\n",mv.categ,mv.dim,mv.timing,&mv.price_g,&mv.price_s,&mv.seats);
        if ((strcmp(mv.movie_name, mv_name) == 0)) {
			fn=1;
			printf("\n\t\t\tEnter which of the following details you want to update");
			printf("\n\t\t\t1. Movie Name\n\t\t\t2. Language\n\t\t\t3. Dimension\n\t\t\t4. Timing\n\t\t\t5. Pricing\n\t\t\t6. Seats\n\t\t\t");
			scanf("%d",&ch);
			switch(ch)
			{
			    case 1: printf("\n\t\t\tEnter Name:");
                        fflush(stdin);
                        scanf("%[^\n]*s",mv.movie_name);
                        strcat(mv.movie_name,"\n");
                        break;
                case 2: lcs:
                        printf("\n\t\t\tSelect Language:\n\t\t\t\t1. Hindi\n\t\t\t\t2. English: ");
                        scanf("%d",&lc);
                         switch(lc)
                        { case 1: strcpy(mv.categ,"Hindi");
                           break;
                          case 2: strcpy(mv.categ,"English");
                           break;
                         default: printf("Wrong Choice Entered...Enter again");
                          goto lcs;
                        }
                        break;
                case 3: lcd:
                        printf("\n\t\t\tSelect Dimensions:\n\t\t\t\t1. 2D\n\t\t\t\t2. 3D: ");
                        scanf("%d",&dc);
                         switch(dc)
                       { case 1: strcpy(mv.dim,"2D");
                           break;
                         case 2: strcpy(mv.dim,"3D");
                           break;
                         default: printf("Wrong Choice Entered...Enter again");
                          goto lcd;
                       }
                        break;
                case 4:  tcd:
                         printf("\n\t\t\tTimings:\n\t\t\t\t1. 9am-12pm\n\t\t\t\t2. 12pm-3pm\n\t\t\t\t3. 3pm-6pm\n\t\t\t\t4. 6pm-9pm\n\t\t\t\t5. 9pm-12am:");
                         scanf("%d",&tc);
                         switch(tc)
                          { case 1: strcpy(mv.timing,"9am-12pm");
                              break;
                            case 2: strcpy(mv.timing,"12pm-3pm");
                              break;
                            case 3: strcpy(mv.timing,"3pm-6pm");
                              break;
                            case 4: strcpy(mv.timing,"6pm-9pm");
                              break;
                            case 5: strcpy(mv.timing,"9pm-12am");
                              break;
                            default: printf("Wrong Choice Entered...Enter again");
                             goto tcd;
                          }
                          break;
                case 5: printf("\n\t\t\tPricing:\n\t\t\t\tGold:");
                        scanf("%d",&mv.price_g);
                        printf("\n\t\t\t\tSilver:");
                        scanf("%d",&mv.price_s);
                        break;
                case 6: printf("\n\t\t\t\tSeats:");
                        scanf("%d",&mv.seats);
                        break;
                default: printf("\n\t\t\tWrong Choice Entered");
                         Sleep(600);
                         admin();
			}
			fprintf(tmpFp,"%s%s %s %s %d %d %d\n",mv.movie_name,mv.categ,mv.dim,mv.timing,mv.price_g,mv.price_s,mv.seats);
			continue;
		}
			fprintf(tmpFp,"%s%s %s %s %d %d %d\n",mv.movie_name,mv.categ,mv.dim,mv.timing,mv.price_g,mv.price_s,mv.seats);
   }
	fclose(fp);
	fclose(tmpFp);
	remove("Movie.txt");
	rename("Tmp.txt","Movie.txt");

	if (fn==0) {
		printf("\n\n\t\tNo record found with the requested name: %s", mv_name);
		Sleep(600);
		goto detail;
	}
        printf("\n\t\t\tDetails Updated successfully");
        Sleep(600);
        admin();
}


/***************************  USER  ***********************************/
 void user(){
 int ch;
 system("cls");
 printf("\n\t\t\t************************************************************");
 printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
 printf("\n\t\t\t************************************************************");
 printf("\n\t\t\t********************** USER PANEL *************************");

 printf("\n\n\n\t\t\t1. Book Movie Ticket\n\t\t\t2. Show List of Movies\n\t\t\t3. Cancel Movie Ticket\n\t\t\t4. Exit\n\t\t\t");
 scanf("%d",&ch);

 switch(ch)
 {
    case 1: system("cls");
        printf("\n\t\t\tWELCOME TO BOOK MOVIE TICKET PANEL...");
        Sleep(400);
        book_ticket();
        break;
    case 2: system("cls");
        printf("\n\t\t\tWELCOME TO MOVIE[s] SHOWS...");
        Sleep(400);
        show_movies();
        break;
    case 3: system("cls");
        printf("\n\t\t\tWELCOME TO CANCEL MOVIE TICKET PANEL...");
        Sleep(400);
        cancel_ticket();
        break;
    case 4:
         main();
         break;
    default: printf("Entered choice is wrong...");
 }
 }

void book_ticket(){
    int ch,pr,fn=0;
    char mname[20];
    system("cls");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t******************** BOOK MOVIE TICKET *********************");
    fp = fopen("Movie.txt","r");
    tp = fopen("Booked.txt","a");

    while(fgets(mv.movie_name,20,fp)!=NULL){
        fscanf(fp,"%s %s %s %d %d %d\n",mv.categ,mv.dim,mv.timing,&mv.price_g,&mv.price_s,&mv.seats);
        printf("\n\t\t\t%s",mv.movie_name);
    }
    fclose(fp);
    fp = fopen("Movie.txt","r");
    tmpFp= fopen("Tmp.txt","w");
    printf("\n\t\t\tEnter Name:");
    fflush(stdin);
    scanf("%[^\n]*s",mname);
    strcat(mname,"\n");

    while(fgets(mv.movie_name,20,fp)!= NULL)
    {
      fscanf(fp,"%s %s %s %d %d %d\n",mv.categ,mv.dim,mv.timing,&mv.price_g,&mv.price_s,&mv.seats);

        if((strcmp(mv.movie_name,mname) == 0)){
            fn=1;
            strcpy(tk.movie,mname);
            printf("\n\t\t\tPricing:\n\t\t\t\t1. Gold:%d\n\t\t\t\t2. Silver:%d",mv.price_g,mv.price_s);
            aao:
            printf("\n\t\t\tEnter your choice for category:");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: strcpy(tk.seat_cate,"GOLD");
                        pr = mv.price_g;
                        break;
                case 2: strcpy(tk.seat_cate,"SILVER");
                        pr = mv.price_s;
                        break;
                default: printf("\n\t\t\t Wrong choice");
                        goto aao;
            }
            strcpy(tk.time,mv.timing);
            printf("\n\t\t\tEnter no. of tickets required:");
            scanf("%d",&tk.no_tickets);
            mv.seats=mv.seats-tk.no_tickets;
            if(mv.seats<0)
            {
                printf("\n\t\t\tAudi Full");
                fclose(fp);
                fclose(tmpFp);
                remove("Tmp.txt");
                Sleep(600);
                user();
            }
            else
            {
                fprintf(tmpFp,"%s%s %s %s %d %d %d\n",mv.movie_name,mv.categ,mv.dim,mv.timing,mv.price_g,mv.price_s,mv.seats);
                continue;
            }
        }
        fprintf(tmpFp,"%s%s %s %s %d %d %d\n",mv.movie_name,mv.categ,mv.dim,mv.timing,mv.price_g,mv.price_s,mv.seats);
}
        fclose(fp);
        fclose(tmpFp);
        remove("Movie.txt");
        rename("Tmp.txt","Movie.txt");

        if (fn==0)
        {
            printf("\n\t\t\t\tMovie Not Found");
            Sleep(600);
            user();
        }
    tk.total_pr= (pr*tk.no_tickets);
    printf("\n\t\t\tPhone No. will be Ticket Unique ID");
    printf("\n\t\t\tEnter Phone No.:");
    scanf("%lld",&tk.uniq_id);
    fprintf(tp,"%s%lld %s %s %d %d\n",tk.movie,tk.uniq_id,tk.seat_cate,tk.time,tk.total_pr,tk.no_tickets);
    fclose(tp);
    printf("\n\t\t\tTicket Booked Successfully!!!");
    Sleep(600);
    user();
}

void show_movies(){
    int ch;
    detail:
    system("cls");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t******************** LIST OF MOVIE[S] **********************");
    fp=fopen("Movie.txt","r");
    if(fp==NULL){
    printf("\n\n\t\tFILE IS EMPTY");
    admin();
    }
    while(fgets(mv.movie_name,20,fp)!= NULL)
   {
    fscanf(fp,"%s %s %s %d %d %d\n",mv.categ,mv.dim,mv.timing,&mv.price_g,&mv.price_s,&mv.seats);
    printf("\n\t\t\tMovie Name:%s",mv.movie_name);
    printf("\n\t\t\tCategory:%s",mv.categ);
    printf("\n\t\t\tDimension:%s",mv.dim);
    printf("\n\t\t\tTiming:%s",mv.timing);
    printf("\n\t\t\tPricing:\n\t\t\t\tGold:%d\n\t\t\t\tSilver:%d",mv.price_g,mv.price_s);
    printf("\n\t\t\tSeats:%d",mv.seats);
    printf("\n\t\t\t****************************");
    }
    fclose(fp);
    printf("\n\t\t\tEnter 1 to go back:");
    scanf("%d",&ch);
    if(ch==1){
        user();
    }
    else{
        goto detail;
    }
}

void cancel_ticket(){
    int fn=0,fn1=0,tick;
    long long tid;
    char mname[20];
    system("cls");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t********* WELCOME TO MOVIE TICKET BOOKING SYSTEM ***********");
    printf("\n\t\t\t************************************************************");
    printf("\n\t\t\t******************** CANCEL MOVIE TICKET *********************");
    tp = fopen("Booked.txt","r");
    tmpFp1 = fopen("Temp.txt","w");
    printf("\n\t\t\tEnter Ticket ID:");
    scanf("%lld",&tid);
    fflush(stdin);
    while(fgets(tk.movie,20,tp)!= NULL)
    {
       fscanf(tp,"%lld %s %s %d %d\n",&tk.uniq_id,tk.seat_cate,tk.time,&tk.total_pr,&tk.no_tickets);
            if(tk.uniq_id==tid){
            fn=1;
            strcpy(mname,tk.movie);
            tick=tk.no_tickets;
            continue;
           }
     fprintf(tmpFp1,"%s%lld %s %s %d %d\n",tk.movie,tk.uniq_id,tk.seat_cate,tk.time,tk.total_pr,tk.no_tickets);
    }
    fclose(tp);
    fclose(tmpFp1);

    fp = fopen("Movie.txt","r");
    tmpFp = fopen("Tmp.txt","w");
    while(fgets(mv.movie_name,20,fp)!= NULL)
            {
              fscanf(fp,"%s %s %s %d %d %d\n",mv.categ,mv.dim,mv.timing,&mv.price_g,&mv.price_s,&mv.seats);
                  if((strcmp(mv.movie_name,mname) == 0)){
                        fn1=1;
                        mv.seats=mv.seats+tick;
                        fprintf(tmpFp,"%s%s %s %s %d %d %d\n",mv.movie_name,mv.categ,mv.dim,mv.timing,mv.price_g,mv.price_s,mv.seats);
                        continue;
                        }
                fprintf(tmpFp,"%s%s %s %s %d %d %d\n",mv.movie_name,mv.categ,mv.dim,mv.timing,mv.price_g,mv.price_s,mv.seats);
            }
    fclose(fp);
    fclose(tmpFp);
    remove("Movie.txt");
    rename("Tmp.txt","Movie.txt");
    remove("Booked.txt");
    rename("Temp.txt","Booked.txt");
    if(fn==0)
    {
        printf("\n\t\t\tTicket Id Not Found");
        Sleep(600);
        user();
    }
    else{
    printf("\n\t\t\tTicket Cancelled Successfully!!!");
    Sleep(600);
    user();
    }
}
