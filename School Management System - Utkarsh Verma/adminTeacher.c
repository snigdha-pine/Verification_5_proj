#include<stdio.h>
#include<windows.h>
#include"Check_Input.c"
struct teacher
{
    char id[20];
    char name[50];
    char sub[20];
    char pwd[20];
    double salary;
    double salary_paid;
    long long int contact_no;
    struct teacher *next;
};
struct teacher *start=NULL;
void add_Teacher(struct teacher **);
int search_teacher(char [],struct teacher *);
void List_Teachers(struct teacher *);
void write_to_master(struct teacher *);
struct teacher* get_from_master();
void view_teachers_details();
void modify_teacher_details();
void change_Details(char* ,struct teacher **);
void list_salary_pending();
void update_Student_Details(int);
void delete_teacher_record(struct teacher *);
struct teacher* check_teacher(struct teacher* st);

void admin_Teacher()
{
    start = NULL;
    start=get_from_master();
    while(1)
    {
        system("cls");
        char ch;
        printf("1. Add Teacher Record :\n");
        printf("2. Delete Teacher Record :\n");
        printf("3. View Teacher Details :\n");
        printf("4. Edit Teacher Details :\n");
        printf("5. List All Teachers :\n");
        printf("6. List Teachers(Salary Pending) :\n");
        printf("0. Exit :\n");
        fflush(stdin);
        ch=getchar();
        if(ch=='0')
        {
            system("cls");
            break;
        }
        switch(ch)
        {
            case '1' :
                system("cls");
                add_Teacher(&start);
            break;

            case '2' :
                system("cls");
                if(start == NULL)
                {
                    printf("No Teachers.\n");
                    printf("Press any key to exit : ");
                    getch();
                    break;
                }
                struct teacher *t;
                t=check_teacher(start);
                if(t!=NULL)
                    delete_teacher_record(t);
            break;

            case '3' :
                system("cls");
                if(start == NULL)
                {
                    printf("No Teachers.\n");
                    printf("Press any key to exit.\n");
                    getch();
                    break;
                }

                view_teachers_details();
            break;

            case '4' :
                system("cls");
                if(start == NULL)
                {
                    printf("No Teacher Found.\n");
                    printf("Press any key to exit.\n");
                    getch();
                    break;
                }
                modify_teacher_details();
            break;

            case '5' :
                system("cls");
                if(start == NULL)
                {
                    printf("No Teacher Found.\n");
                    printf("Press any key to exit.\n");
                    getch();
                    break;
                }
                List_Teachers(start);
            break;

            case '6' :
                system("cls");
                if(start == NULL)
                {
                    printf("No Teacher Found.\n");
                    printf("Press any key to exit.\n");
                    getch();
                    break;
                }
                list_salary_pending();
            break;

            default :
                system("cls");
                printf("Invalid Choice!\n");
            break;
        }

    }
}

void add_Teacher(struct teacher **start)
{
    printf("Enter ID :");
    while(1)
    {
        char id[11];
        fflush(stdin);
        scanf("%s",id);
        fflush(stdin);
        if(id[0]=='0')
        {
            break;
        }
        if(search_teacher(id,*start)!=0)
        {
            system("cls");
            printf("ID already exists.\n");
            printf("Enter ID(0 to exit) : ");
            continue;
        }
        else
        {
            char sal[9],cnt[30];
            struct teacher *new_node = (struct teacher *)malloc(sizeof(struct teacher));
            new_node->next=NULL;
            strcpy(new_node->id,id);
            printf("Enter Password : ");
            scanf("%s",new_node->pwd);
            fflush(stdin);
            printf("Enter Name :");
            scanf("%[^\n]%*c",new_node->name);
            printf("Enter contact no. : ");
            while(1)
            {
                scanf("%s",cnt);
                long long int n = check_Contact(cnt);
                if(n!=0)
                {
                    new_node->contact_no=n;
                    fflush(stdin);
                    break;
                }
                else
                {
                    printf("\nInvalid Number!\nPlease enter a valid Number : ");
                    fflush(stdin);
                }
            }
            printf("Enter Subject : ");
            scanf("%[^\n]%*c",new_node->sub);
            printf("Enter Salary : ");
            while(1)
            {
                fflush(stdin);
                scanf("%s",sal);
                new_node->salary = check_fees(sal);                          //Same as that of checking fees.
                if(new_node->salary == 0)
                {
                    system("cls");
                    printf("Invalid Input!\n");
                    printf("Enter Salary : ");
                }
                else
                    break;
            }
            new_node->salary_paid=0;
            if(*start == NULL)
            {
                *start = new_node;
            }
            else
            {
                struct teacher *ptr;
                ptr = *start;
                while(ptr->next != NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
            }
            printf("\nTeacher added.\n");
            char file[50]="../Directories/Teachers/";
            concat(file,file,new_node->id);
            concat(file,file,".txt");
            FILE *fptr=fopen(file,"w");
            {
                fprintf(fptr,"%s\n",new_node->id);
                fprintf(fptr,"%s\n",new_node->name);
                fprintf(fptr,"%s\n",new_node->pwd);
                fprintf(fptr,"%s\n",new_node->sub);
                fprintf(fptr,"%lld\n",new_node->contact_no);
                fprintf(fptr,"%lf\n",new_node->salary);
                fprintf(fptr,"%lf\n",new_node->salary_paid);
            }
            fclose(fptr);
            printf("Press any key to exit : ");
            getch();
            break;
        }
    }
    write_to_master(*start);
}

int search_teacher(char t_id[],struct teacher *start)
{
//    if(start == NULL)
//        return 0;
//    else
//    {
//        struct teacher *temp;
//        temp = start;
//        while(temp!=NULL)
//        {
//            if(strcmp(temp->id,t_id)==0)
//                return 1;
//            temp=temp->next;
//        }
//    }
//    return 0;
    if(start == NULL)
        return 0;
    else
    {
        char f_name[50];
        concat(f_name,"../Directories/Teachers/",t_id);
        concat(f_name,f_name,".txt");
        FILE *fptr = fopen(f_name,"r");
        if(fptr == NULL)
            return 0;
        else
        {
            fclose(fptr);
            return 1;
        }
    }
}

void List_Teachers(struct teacher *start)
{
    int i=0;
    struct teacher *temp;
    temp=start;
    if(start == NULL)
    {
        printf("No Teachers.\n");
    }
    else
    {
        printf("%-10s %-15s %-15s %-15s %-15s %-15s\n\n","ID","NAME","SUBJECT","NUMBER","SALARY","SALARY PAID");
        while(temp!=NULL)
        {
            printf("%-10s %-15s %-15s %-15lld %-15.2lf %-15.2lf\n\n",temp->id,temp->name,temp->sub,temp->contact_no,temp->salary,temp->salary_paid);
            temp=temp->next;
        }
    }
    printf("\nPress any key to exit : ");
    getch();
}


void write_to_master(struct teacher *st)
{
    FILE *fptr=fopen("../Directories/Teachers/Master.txt","w");
    struct teacher *ptr;
    ptr=st;
    while(ptr!=NULL)
    {
        fprintf(fptr,"%s\n",ptr->id);
        fprintf(fptr,"%s\n",ptr->name);
        fprintf(fptr,"%s\n",ptr->pwd);
        fprintf(fptr,"%s\n",ptr->sub);
        fprintf(fptr,"%lld\n",ptr->contact_no);
        fprintf(fptr,"%lf\n",ptr->salary);
        fprintf(fptr,"%lf\n",ptr->salary_paid);
        ptr=ptr->next;
    }
    fclose(fptr);
}

struct teacher* get_from_master()
{
    FILE *fptr=fopen("../Directories/Teachers/Master.txt","r");
    if(fptr == NULL)
    {
        return NULL;
    }
    struct teacher *ptr;
    ptr=NULL;
    int i=0;
    while(!feof(fptr))
    {
        struct teacher *new_node = (struct teacher *)malloc(sizeof(struct teacher));
        new_node->next=NULL;
        fscanf(fptr,"%[^\n]%*c",new_node->id);
        fscanf(fptr,"%[^\n]%*c",new_node->name);
        fscanf(fptr,"%[^\n]%*c",new_node->pwd);
        fscanf(fptr,"%[^\n]%*c",new_node->sub);
        fscanf(fptr,"%lld\n",&new_node->contact_no);
        fscanf(fptr,"%lf\n",&new_node->salary);
        fscanf(fptr,"%lf\n",&new_node->salary_paid);

        if(start == NULL)
        {
            start=new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next= new_node;
        }
    }
    return start;
    fclose(fptr);
}

void view_teachers_details()
{
    char t_id[10],f_nam[50];
    printf("Enter ID : ");
    scanf("%s",t_id);
    concat(f_nam,"../Directories/Teachers/",t_id);
    concat(f_nam,f_nam,".txt");
    FILE *fptr = fopen(f_nam,"r");
    if(fptr == NULL)
    {
        printf("Teacher not found.\n");
    }
    else
    {
        char id[20],name[50],sub[20],pwd[20];
        long long int contact_no;
        double salary,salary_paid;
        fscanf(fptr,"%[^\n]%*c",id);
        fscanf(fptr,"%[^\n]%*c",name);
        fscanf(fptr,"%[^\n]%*c",pwd);
        fscanf(fptr,"%[^\n]%*c",sub);
        fscanf(fptr,"%lld\n",&contact_no);
        fscanf(fptr,"%lf\n",&salary);
        fscanf(fptr,"%lf\n",&salary_paid);
        printf("%-10s %-15s %-15s %-15s %-15s %-15s\n\n","ID","NAME","SUBJECT","NUMBER","SALARY","SALARY PAID");
        printf("%-10s %-15s %-15s %-15lld %-15.2lf %-15.2lf\n\n",id,name,sub,contact_no,salary,salary_paid);
        fclose(fptr);
    }
    printf("Press any key to exit : ");
    getch();
}


void modify_teacher_details()
{
    char t_id[10],f_nam[50];
    enter_id : printf("Enter ID : ");
    scanf("%s",t_id);
    concat(f_nam,"../Directories/Teachers/",t_id);
    concat(f_nam,f_nam,".txt");
    FILE *fptr = fopen(f_nam,"r");
    if(fptr == NULL)
    {
        printf("Teacher not found.\n");
        printf("Press any key to exit (1 to continue):\n");
        fflush(stdin);
        char ch=getch();
        fflush(stdin);
        if(ch == '1')
            goto enter_id;
    }
    else
    {
        fclose(fptr);
        struct teacher *temp;
        temp = start;
        while(temp!=NULL)
        {
            if(strcmp(t_id,temp->id)==0)
            {
                change_Details(f_nam,&temp);
                fclose(fptr);
                break;
            }
            temp=temp->next;
        }
    }
}

void change_Details(char f_nam[50], struct teacher **temp)
{
    system("cls");
    char ch;
    while(1)
    {
        printf("%-10s %-15s %-15s %-15s %-15s %-15s\n\n","ID","NAME","SUBJECT","NUMBER","SALARY","SALARY PAID");
        printf("%-10s %-15s %-15s %-15lld %-15.2lf %-15.2lf\n\n",(*temp)->id,(*temp)->name,(*temp)->sub,(*temp)->contact_no,(*temp)->salary,(*temp)->salary_paid);
        printf("1. Change Name :\n");
        printf("2. Change Subject :\n");
        printf("3. Contact Number :\n");
        printf("4. Change Salary :\n");
        printf("5. Change Salary Paid :\n");
        printf("0. Exit :\n");
        fflush(stdin);
        ch = getchar();
        fflush(stdin);
        if(ch == '0')
        {
            break;
        }
        switch(ch)
        {
        case '1' :
            printf("Enter new name : ");
            scanf("%[^\n]%*c",(*temp)->name);
            system("cls");
        break;

        case '2' :
            printf("Enter new Subject : ");
            scanf("%[^\n]%*c",(*temp)->sub);
            system("cls");
        break;

        case '3' :
            enter_no : printf("Enter new Number : ");
            char n[20];
            scanf("%s",n);
            long long int no = check_Contact(n);
            if(no == 0)
            {
                printf("Invalid Number!\n");
                goto enter_no;
            }
            else
                (*temp)->contact_no=no;
            system("cls");
        break;

        case '4' :
            enter_s : printf("Enter new Salary : ");
            char s[9];
            scanf("%s",s);
            double sal=check_fees(s);
            if(sal == 0)
            {
                system("cls");
                printf("Invalid Input!\n");
                goto enter_s;
            }
            else
                (*temp)->salary=sal;
            system("cls");
        break;

        case '5' :
            enter_sp : printf("\nEnter Total Salary Paid : ");
            char sp[9];
            scanf("%s",sp);
            sal=check_fees(sp);
            if(sal == 0 || sal > (*temp)->salary)
            {
                printf("Invalid Input!\n");
                goto enter_sp;
            }
            else
                (*temp)->salary_paid=sal;
            system("cls");
        break;

        default :
            system("cls");
            printf("Invalid Choice!");
        }
        FILE *fptr = fopen(f_nam,"w");
        fprintf(fptr,"%s\n",(*temp)->id);
        fprintf(fptr,"%s\n",(*temp)->name);
        fprintf(fptr,"%s\n",(*temp)->pwd);
        fprintf(fptr,"%s\n",(*temp)->sub);
        fprintf(fptr,"%lld\n",(*temp)->contact_no);
        fprintf(fptr,"%lf\n",(*temp)->salary);
        fprintf(fptr,"%lf\n",(*temp)->salary_paid);
        fclose(fptr);
    }
    write_to_master(start);
}


void list_salary_pending()
{
    int count = 0;
    struct teacher *temp;
    temp=start;
    while(temp!=NULL)
    {
        if(temp->salary_paid < temp->salary)
        {
            if(count == 0)
            {
                count = 1;
                printf("%-10s %-15s %-15s %-15s %-15s %-15s\n\n","ID","NAME","SUBJECT","NUMBER","SALARY","SALARY PAID");
            }
            printf("%-10s %-15s %-15s %-15lld %-15.2lf %-15.2lf\n\n",temp->id,temp->name,temp->sub,temp->contact_no,temp->salary,temp->salary_paid);
        }
        temp=temp->next;
    }
    if(count == 0)
        printf("No Teachers found.\n");
    printf("Press any key to exit : ");
    getch();
}




// Teachers section

void Teacher()
{
    start=NULL;
    start = get_from_master();
    struct teacher *temp;
    temp=check_teacher(start);
    if(temp== NULL)
        return;

    char pass[20];
    enter_pass : printf("Enter password (0 to exit) : \n");
    scanf("%[^\n]%*c",pass);
    if(pass[0] == '0')
    {
        system("cls");
        fflush(stdin);
        return;
    }
    if(strcmp(pass,temp->pwd) != 0)
    {
        system("cls");
        printf("Wrong password.\n");
        goto enter_pass;
    }

    while(1)
    {
        system("cls");
        char ch;
        printf("1. View Details :\n");
        printf("2. Change Password :\n");
        printf("3. Change Marks :\n");
        printf("0. Exit :\n");
        fflush(stdin);
        ch=getchar();
        if(ch=='0')
        {
            system("cls");
            break;
        }
        switch(ch)
        {
        case '1' :
            system("cls");
            printf("%-10s %-15s %-15s %-15s %-15s %-15s\n\n","ID","NAME","SUBJECT","NUMBER","SALARY","SALARY PAID");
            printf("%-10s %-15s %-15s %-15lld %-15.2lf %-15.2lf\n\n",temp->id,temp->name,temp->sub,temp->contact_no,temp->salary,temp->salary_paid);
            printf("Press any key to exit :");
            getch();
        break;
        case '2' :
            system("cls");
            new_pass : printf("Enter new password(0 to exit) : ");
            fflush(stdin);
            scanf("%[^\n]%*c",pass);
            if(pass[0] == '0')
                break;
            char cnfrm[30];
            printf("Confirm password : ");
            scanf("%[^\n]%*c",cnfrm);

            if(strcmp(cnfrm,pass) == 0)
                concat(temp->pwd,"",cnfrm);
            else
            {
                system("cls");
                printf("Password does not match.\n");
                goto new_pass;
            }
            printf("Password Changed.\n");
            char file[50]="../Directories/Teachers/";
            concat(file,file,temp->id);
            concat(file,file,".txt");
            FILE *fptr=fopen(file,"w");
            {
                fprintf(fptr,"%s\n",temp->id);
                fprintf(fptr,"%s\n",temp->name);
                fprintf(fptr,"%s\n",temp->pwd);
                fprintf(fptr,"%s\n",temp->sub);
                fprintf(fptr,"%lld\n",temp->contact_no);
                fprintf(fptr,"%lf\n",temp->salary);
                fprintf(fptr,"%lf\n",temp->salary_paid);
            }
            fclose(fptr);
            write_to_master(start);
            printf("Press any key to exit : \n");
            getch();
            system("cls");
        break;


        case '3' :
            update_Student_Details(1);
        break;

        default :
            printf("Invalid Choice.\n");
            system("cls");
        }
    }
}

struct teacher* check_teacher(struct teacher* st)
{
    struct teacher* temp;
    temp=st;
    char t_id[30];
    enter_id : printf("Enter ID :");
    fflush(stdin);
    scanf("%[^\n]%*c",t_id);
    while(temp!=NULL)
    {
        if(strcmp(t_id,temp->id)==0)
            return temp;
        temp=temp->next;
    }
    if(temp == NULL)
    {
        printf("No Teacher found.\n");
        printf("Press any key to exit (1 to continue) :");
        fflush(stdin);
        char ch = getch();
        system("cls");
        if(ch == 1)
            goto enter_id;
        else
            return NULL;
    }
}


void delete_teacher_record(struct teacher *tmp)
{
    char f_name[50],m[50];
    concat(f_name,"../Directories/Teachers/",tmp->id);
    concat(f_name,f_name,".txt");
    if(start->next == NULL)
    {
        //printf("coming1");
        start = NULL;
        printf("Record Deleted.\n");
        remove(f_name);
        printf("Deleting Master file.\n");
        printf("Press any key to exit : ");
        concat(m,"../Directories/Teachers/","Master.txt");
        remove(m);
        getch();
    }
    else
    {
        if(strcmp(start->id,tmp->id)==0)
        {
            start=start->next;
            remove(f_name);
            write_to_master(start);
            printf("Record Deleted.\n");
            printf("Press any key to exit :\n");
            getch();
            return;
        }
        struct teacher *ptr,*prev;
        prev=start;
        ptr= start;
        while(ptr!=NULL && (strcmp(ptr->id,tmp->id) != 0))
        {
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next = ptr->next;

        printf("Record Deleted.\n");
        printf("Press any key to exit : ");
        remove(f_name);
        write_to_master(start);
        getch();
    }
}
