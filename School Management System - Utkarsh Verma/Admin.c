#include "concat.c"
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<dirent.h>
#include<string.h>
#define PATH "C:/Users/Utkarsh Verma/Desktop/Projects/"
#include"adminTeacher.c"
#include"reset_password.c"

struct student
{
    char name[3][30];
    char adrs[50];
    char cls;
    unsigned long roll_no;
    long long int contact_no;
    double fees;
    double marks[3];
}st;
void admin_Student();
void write_to_file(struct student, char []);
void display_student_details(struct student );
void Add_Student();
void update_Student_Details(int);
int  search_roll_no(char roll_txt[]);                                                           //With Dirent
void View_Student_Details();
void read_From_File(char file_name[]);
void change_Name();
void change_Marks();
void check_fee_status();
void delete_student_record();
void get_file_name_(int, char [], char*);
int search_for_student(char []);                                                                //Without Dirent
void display_by_class();
void display_specific();
void display_by_fees();
void admin()
{
    char ch;
    char pth[50];
    while(1)
    {
        printf("1. Teacher        :\n");
        printf("2. Student        :\n");
        printf("3. Reset Password :\n");
        printf("4. Exit           :\n");
        fflush(stdin);
        ch=getchar();
        fflush(stdin);
        if(ch=='4')
        {
            system("cls");
            return;
        }
        switch(ch)
        {

        case '1' :
            admin_Teacher();
        break;

        case '2' :
            admin_Student();
            system("cls");
        break;

        case '3' :
            system("cls");
            resetpassword();
        break;

        default :
            system("cls");
            printf("Invalid Choice!\n");
        }
    }
}

void admin_Student()
{
    char ch;
    system("cls");
    while(1)
    {
        printf("1. Add Student                 :\n");
        printf("2. Update Student Details      :\n");
        printf("3. Delete Student Records      :\n");
        printf("4. Check Payment Status        :\n");
        printf("5. View Student Details        :\n");
        printf("6. List Students               :\n");
        printf("7. List Students(Fees Pending) :\n");
        printf("8. Change Fees Status          :\n");
        printf("0. Exit                        :\n");
        ch = getchar();
        fflush(stdin);
        if(ch=='0')
            break;
        switch(ch)
        {
        case '1' :
            Add_Student();
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            fflush(stdin);
        break;

        case '2' :
            system("cls");
            update_Student_Details(0);
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            fflush(stdin);
        break;

        case '3' :
            delete_student_record();
            printf("Student record deleted.\n");
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            fflush(stdin);
        break;
        case '4' :
            check_fee_status();
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            fflush(stdin);
        break;

        case '5' :
            View_Student_Details();
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            fflush(stdin);
        break;

        case '6' :
            display_by_class();
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            fflush(stdin);
        break;

        case '7' :
            display_by_fees();
            printf("Press any key to exit : ");
            getch();
            system("cls");
            fflush(stdin);
        break;

        case '8' :
            system("cls");
            update_Student_Details(3);
            system("cls");
            fflush(stdin);
        break;

        default :
            system("cls");
            printf("Invalid Choice!\n");
        }
    }

}


void Add_Student()
{
    system("cls");
    char check[30];
    unsigned long r_no=0;
    int i;
    while(1)
    {
        loop  : printf("Enter the Roll Number :\n");
        loop1 : printf("Press 0 to exit :\n");
        scanf("%s",check);
        if(check[0] == '0')
            return;
        r_no=check_number(check);
        if(r_no != 0)
        {
            st.roll_no=r_no;
            break;
        }
        else
        {
            printf("Invalid Input!\n");
            continue;
        }
    }
    char file_name[15];
    concat(file_name,check,".txt");
    int c=search_roll_no(file_name);
//    int c=search_for_student(check,file_name);
//    printf("Returned : %d.\n",c);
    if(c!=0)
    {
        printf("Roll No. Already Exixts!\n");
        printf("Please Enter a Unique Roll No. :\n");
        fflush(stdin);
        goto loop1;
    }
    else
    {
        fflush(stdin);
        printf("Enter Student's Name :");
        scanf("%[^\n]%*c",st.name[0]);

        printf("Enter Father's Name :");
        scanf("%[^\n]%*c",st.name[1]);

        printf("Enter Mother's Name :");
        scanf("%[^\n]%*c",st.name[2]);

        printf("Enter address :");
        scanf("%[^\n]%*c",st.adrs);

        cl : printf("Enter Class :");
        char c=getchar();
        fflush(stdin);
        if(check_Class(c) == 0)
        {
            printf("Invalid Input!\n");
            goto cl;
        }
        else
            st.cls=c;

        char cno[30];
        cntct : printf("Enter Contact Number :");
        scanf("%s",cno);
        long long int c_no=check_Contact(cno);
        if(c_no != 0)
            st.contact_no=c_no;
        else
        {
            printf("Invalid Input!\n");
            fflush(stdin);
            goto cntct;
        }

        printf("Enter Fees Paid :");
        fee : scanf("%s",cno);
        double f = check_fees(cno);
        if(f == 0)
        {
            printf("Invalid Input!\nEnter valid input : ");
            fflush(stdin);
            goto fee;
        }
        st.fees=f;
        st.marks[0]=0.0;
        st.marks[1]=0.0;
        st.marks[2]=0.0;
        display_student_details(st);
        write_to_file(st,check);
    }
}

void display_student_details(struct student st)
{
    printf("Roll No.         : %u\n",st.roll_no);
    printf("Name             : %s\n",st.name[0]);
    printf("Class            : %c\n",st.cls);
    printf("Father's Name    : %s\n",st.name[1]);
    printf("Mother's Name    : %s\n",st.name[2]);
    printf("Address          : %s\n",st.adrs);
    printf("Fees Paid        : %.2f\n",st.fees);
    printf("Contact No.      : %lld\n",st.contact_no);
    printf("Marks in Hindi   : %.2f\n",st.marks[0]);
    printf("Marks in English : %.2f\n",st.marks[1]);
    printf("Marks in Maths   : %.2f\n",st.marks[2]);
}

void write_to_file(struct student st,char roll[11])
{
    char path_name[100];
    char temp[3]={st.cls,'/'};
    concat(path_name,PATH,"Directories/Students/Class");
    concat(path_name,path_name,temp);
    concat(path_name,path_name,roll);
    concat(path_name,path_name,".txt");
    FILE *fptr=fopen(path_name,"w");
//    fwrite(&st, sizeof(struct student), 1, fptr);
    fprintf(fptr,"%s\n",st.name[0]);
    fprintf(fptr,"%s\n",st.name[1]);
    fprintf(fptr,"%s\n",st.name[2]);
    fprintf(fptr,"%u\n",st.roll_no);
    fprintf(fptr,"%s\n",st.adrs);
    fprintf(fptr,"%c\n",st.cls);
    fprintf(fptr,"%lld\n",st.contact_no);
    fprintf(fptr,"%lf\n",st.fees);
    fprintf(fptr,"%lf\n",st.marks[0]);
    fprintf(fptr,"%lf\n",st.marks[1]);
    fprintf(fptr,"%lf\n",st.marks[2]);
    fclose(fptr);
}


int search_for_student(char check[30])                                                  //Without Dirent Structure
{
    FILE *fptr;
    int i;
    char path_name[100];
    for(i=0;i<5;i++)
    {
        get_file_name_(i+1,check,path_name);
        fptr=fopen(path_name,"r");
        if(fptr!=NULL)
        {
            fclose(fptr);
            return i+1;                                                                 //Returning class of student
        }
        fclose(fptr);
    }
    return 0;
}

int search_roll_no(char roll_txt[15])                                                   //With Dirent Structure
{
    DIR *dir_stu = NULL,*dir_class;
    char p[100];
    struct dirent *list1,*list2;
    int c=0;
    concat(p,PATH,"Directories/Students/");
    dir_stu = opendir(p);
    if(dir_stu == NULL)
        printf("Cannot Open DIrectory.\n");
    else
    {
        while((list1 = readdir(dir_stu)) !=NULL)
        {
            c++;
            concat(p,PATH,"Directories/Students/");
            concat(p,p,list1->d_name);
            dir_class = opendir(p);
            while((list2 = readdir(dir_class)) != NULL)
            {
                if(strcmp(list2->d_name,roll_txt) == 0)
                {
                    closedir(dir_class);
                    closedir(dir_stu);
                    return (int)(list1->d_name[5] - '0');                               //Returning the class of student.
                }
            }
        }
        closedir(dir_class);
        closedir(dir_stu);
        return 0;
    }
}

void View_Student_Details()
{
    system("cls");
    char roll[30];
    unsigned long r_no=0;
    int i;
    while(1)
    {
        loop  : printf("Enter the Roll Number :\n");
        scanf("%s",roll);
        r_no=check_number(roll);
        if(r_no == 0)
        {
            printf("Invalid Input!\n");
            continue;
        }
        else
        {
            int c = search_for_student(roll);
            if(c==0)
            {
                printf("Roll No. not found!\n");
                break;
            }
            else
            {
                char path_name[100];
                get_file_name_(c,roll,path_name);
                read_From_File(path_name);
                display_student_details(st);
                break;
            }
        }
    }
}


void read_From_File(char file_name[100])
{
    FILE *fptr=fopen(file_name,"r");
    if(fptr==NULL)
    {
        printf("File not found!\n");
    }
    else
    {
        fscanf(fptr,"%[^\n]%*c",st.name[0]);
        fscanf(fptr,"%[^\n]%*c",st.name[1]);
        fscanf(fptr,"%[^\n]%*c",st.name[2]);
        fscanf(fptr,"%u\n",&st.roll_no);
        fscanf(fptr,"%[^\n]%*c",st.adrs);
        fscanf(fptr,"%c",&st.cls);
        fscanf(fptr,"%lld\n",&st.contact_no);
        fscanf(fptr,"%lf\n",&st.fees);
        fscanf(fptr,"%lf\n",&st.marks[0]);
        fscanf(fptr,"%lf\n",&st.marks[1]);
        fscanf(fptr,"%lf\n",&st.marks[2]);
//        fread(&st, sizeof(struct student), 1, fptr);
        fclose(fptr);
    }
}

void update_Student_Details(int found)
{
    system("cls");
    char roll[11];
    unsigned long r_no=0;
    int i;
    while(1)
    {
        printf("Enter the Roll Number :\n");
        fflush(stdin);
        scanf("%s",roll);
        r_no=check_number(roll);
        if(r_no == 0)
        {
            printf("Invalid Input!\n");
            continue;
        }
        else
        {
            int c = search_for_student(roll);
            if(c==0)
            {
                system("cls");
                printf("Roll No. not found!\n");
                break;
            }
            else
            {
                char path_name[100];
                get_file_name_(c,roll,path_name);
                read_From_File(path_name);
                display_student_details(st);
                char name[50];
                printf("Enter student's name to verify :\n");
                fflush(stdin);
                scanf("%[^\n]%*c",name);
                if(strcmp(st.name[0],name)!=0)
                {
                    printf("Invalid Details!\n");
                    break;
                }
                system("cls");
                while(1)
                {
                    char ch;
                    if(found == 1)
                    {
                        found = 2;
                        ch = '4';
                        goto f;
                    }
                    if(found == 2)
                        return;
                    if(found == 3)
                    {
                        found = 2;
                        ch = '5';
                        goto f;
                    }
                    printf("Press 1 to change Name :\n");
                    printf("Press 2 to change Address       :\n");
                    printf("Press 3 to change Contact No.   :\n");
                    printf("Press 4 to change Marks         :\n");
                    printf("Press 0 to exit                 :\n");
                    fflush(stdin);
                    ch=getchar();
                    f : fflush(stdin);
                    if(ch=='0')
                        break;
                    switch(ch)
                    {
                    case '1' :
                        change_Name();
                        system("cls");
                    break;
                    case '2' :
                        system("cls");
                        printf("Enter Address : ");
                        scanf("%[^\n]%*c",st.adrs);
                        printf("Address Changed.\n");
                        printf("Press any key to exit : ");
                        getch();
                        system("cls");
                    break;

                    case '3' :
                        system("cls");
                        cnt : printf("Enter Contact Number :");
                        char cno[20];
                        scanf("%s",cno);
                        long long int c_no=check_Contact(cno);
                        if(c_no != 0)
                        {
                            st.contact_no=c_no;
                            printf("Contact No. Changed.\n");
                            printf("Press any key to exit : ");
                            getch();
                        }
                        else
                        {
                            printf("Invalid Input!\n");
                            fflush(stdin);
                            goto cnt;
                        }
                        system("cls");
                    break;

                    case '4' :
                            change_Marks();
                            if(found == 2)
                                write_to_file(st,roll);
                    break;

                    case '5' :
                        system("cls");
                        char fee[10];
                        printf("Enter fees paid till date : ");
                        fe : scanf("%s",fee);
                        double f = (int)check_fees(fee);
                        if(f == 0)
                        {
                            printf("Invalid Input!\nEnter valid input : ");
                            goto fe;
                        }

                        st.fees=f;
                        if(found == 2)
                            write_to_file(st,roll);
                        printf("Total amount paid is now changed to %.2f.\n",st.fees);
                        printf("Press any key to exit : ");
                        getch();
                        system("cls");
                    break;

                    default :
                        system("cls");
                        printf("Invalid Choice123.\n");
                    break;
                    }
                }
                write_to_file(st,roll);
                break;
            }
        }
    }
}



void change_Name()
{
    system("cls");
    while(1)
    {
        printf("Press 1 to change Student's Name :\n");
        printf("Press 2 to change Father's Name  :\n");
        printf("Press 3 to change Mother's Name  :\n");
        printf("Press 4 to exit                  :\n");
        fflush(stdin);
        char ch = getchar();
        if(ch == '4')
            break;
        switch(ch)
        {

        case '1' :
            system("cls");
            printf("Enter Name : ");
            fflush(stdin);
            scanf("%[^\n]%*c",st.name[0]);
            printf("Student's Name Changed.\n");
            printf("Press any key to exit : ");
            getch();
            system("cls");
        break;

        case '2' :
            system("cls");
            printf("Enter Father's Name : ");
            fflush(stdin);
            scanf("%[^\n]%*c",st.name[1]);
            printf("Father's Name Changed.\n");
            printf("Press any key to exit : ");
            getch();
            system("cls");
        break;

        case '3' :
            system("cls");
            printf("Enter Mother's Name : ");
            fflush(stdin);
            scanf("%[^\n]%*c",st.name[2]);
            printf("Mother's Name Changed.\n");
            printf("Press any key to exit : ");
            getch();
            system("cls");
        break;

        default :
            system("cls");
            printf("Invalid Choice!\n");
        break;
        }
    }
}



void change_Marks()
{
    system("cls");
    double mark=0;
    char mrk[10];
    while(1)
    {
        printf("Press 1 to change Marks in Hindi   :\n");
        printf("Press 2 to change Marks in English :\n");
        printf("Press 3 to change Marks in Maths   :\n");
        printf("Press 4 to exit                    :\n");
        fflush(stdin);
        char ch = getchar();
        if(ch == '4')
        {
             break;
        }
        switch(ch)
        {
        case '1' :
            system("cls");
            m1 : printf("Enter the Marks : ");
            fflush(stdin);
            scanf("%s",mrk);
            mark=check_fees(mrk);
            if(mark == 0 || mark >100)
            {
                printf("Invalid Input!\n");
                goto m1;
            }
            else
                st.marks[0]=mark;
            printf("Marks changed.\n");
            printf("Press any key to exit :\n");
            getch();
            system("cls");
        break;

        case '2' :
            system("cls");
            m2 : printf("Enter the Marks : ");
            fflush(stdin);
            scanf("%s",mrk);
            mark=check_fees(mrk);
            if(mark == 0 || mark > 100)
            {
                printf("Invalid Input!\n");
                goto m2;
            }
            else
                st.marks[1]=mark;
            printf("Marks changed.\n");
            printf("Press any key to exit :\n");
            getch();
            system("cls");
        break;

        case '3' :
            system("cls");
            m3 : printf("Enter the Marks : ");
            fflush(stdin);
            scanf("%s",mrk);
            mark=check_fees(mrk);
            if(mark == 0 || mark >100)
            {
                printf("Invalid Input!\n");
                goto m3;
            }
            else
                st.marks[2]=mark;
            printf("Marks changed.\n");
            printf("Press any key to exit :\n");
            getch();
            system("cls");
        break;

        default :
            system("cls");
            printf("Invalid Choice.\n");
        break;
        }
    }
}


void check_fee_status()
{
    system("cls");
    char roll[11];
    unsigned long r_no=0;
    int i;
    while(1)
    {
        loop  : printf("Enter the Roll Number :\n");
        fflush(stdin);
        scanf("%s",roll);
        fflush(stdin);
        r_no=check_number(roll);
        if(r_no == 0)
        {
            printf("Invalid Input!\n");
            continue;
        }
        else
        {
            int c = search_for_student(roll);
            if(c==0)
            {
                system("cls");
                printf("Roll No. not found!\n");
                break;
            }
            else
            {
                char path_name[100];
                get_file_name_(c,roll,path_name);
                read_From_File(path_name);
                printf("Student Name : %s\n",st.name[0]);
                printf("Fees paid    : %.2lf\n",st.fees);
                printf("Pending fees : %.2lf\n",FEES-st.fees);
                break;
            }
        }
    }
}


void delete_student_record()
{
     system("cls");
    char roll[11];
    unsigned long r_no=0;
    int i;
    while(1)
    {
        loop  : printf("Enter the Roll Number :\n");
        fflush(stdin);
        scanf("%s",roll);
        r_no=check_number(roll);
        if(r_no == 0)
        {
            printf("Invalid Input!\n");
            continue;
        }
        else
        {
            int c = search_for_student(roll);
            if(c==0)
            {
                system("cls");
                printf("Roll No. not found!\n");
                break;
            }
            else
            {
                char path_name[100];
                get_file_name_(c,roll,path_name);
                remove(path_name);
                break;
            }
        }
    }
}

void get_file_name_(int c,char r_no[11],char *p)
{
    concat(p,PATH,"Directories/Students/Class");
    char s[3] = {c+48,'/'};
    concat(p,p,s);
    concat(p,p,r_no);
    concat(p,p,".txt");
}


void display_by_class()
{
    system("cls");
    char c;
    while(1)
    {
        printf("Enter class (0 to exit):");
        fflush(stdin);
        scanf("%c",&c);
        if(c == '0')
            return;
        else
        {
            if(check_Class(c) == 0)
            {
                printf("Invalid Input.\n");
                continue;
            }
            else
                break;
        }
    }
    DIR *dirptr=NULL;
    char path_name[100];
    char s[3]={c,'/'};
    concat(path_name,PATH,"Directories/Students/Class");
    concat(path_name,path_name,s);
    struct dirent *list;
    dirptr=opendir(path_name);
    char pth[100];
    int count =0;

    while((list = readdir(dirptr)) !=NULL )
    {
        count++;
        if(count<3)                                             //Just to avoid PWD(.) and PD(..)
            continue;
        if(count == 3)
            printf("%-10s\t%s\n","Roll No.","Name");
        concat(pth,path_name,list->d_name);
        read_From_File(pth);

        printf("%-10u\t%s\n",st.roll_no,st.name[0]);
    }
    if(count==2)
        printf("No Students Present in class.\n");
    closedir(dirptr);
}


void display_by_fees()
{
    int flag = 0;
    DIR *dirptr=NULL;
    char path_name[100];
    for(int i=1;i<=5;i++)
    {
        char s[3]={i+48,'/'};
        concat(path_name,"../Directories/Students/Class",s);
        struct dirent *list;
        dirptr=opendir(path_name);
        char pth[100];
        int count =0;

        while((list = readdir(dirptr)) !=NULL )
        {
            count++;
            if(count<3)
                continue;
            if(count == 3 && flag == 0)
            {
                flag=1;
                printf("%-10s%-15s%-15s%-15s%-15s\n","Roll No.","Name","CLass","Fees Paid","Fees Pending");
            }
            concat(pth,path_name,list->d_name);
            read_From_File(pth);
            if(st.fees < FEES)
                printf("%-10u%-15s%-15d%-15.2lf%-15.2lf\n",st.roll_no,st.name[0],i,st.fees,FEES-st.fees);
        }
        closedir(dirptr);
    }
    if(flag == 0)
        printf("All the students have submitted their fees.\n");
}
