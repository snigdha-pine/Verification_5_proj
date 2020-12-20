#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include <windows.h>
#define SIZE 32

//short int checkValid(char*);
//void checkStrength(char*);
//void resetpassword();
//short int alphabetCount=0, digitCount=0;
//short int length=0;
//short int symbolCount=0;                  //to count symbols like ;'./ etc
//int count_reset=3;

void resetpassword()
{
    char pw[SIZE],c,rpw[SIZE];
    short int count,error;
    int option;

    Enter: printf("\nENETR NEW PASSWORD: ");
    int p=0,i=0;
    do
    {
        pw[p]=getch();
        if(pw[p]!='\r')
        {
            if(pw[p]=='\b' && p>0)
            {
                p=p-2;
                printf("\b");
                printf(" ");
                printf("\b");
            }
            else if(pw[p]!='\b')
            printf("*");
        }
        if(pw[p]!='\b')
        p++;
    }while(pw[p-1]!='\r');
    pw[p-1]='\0';
    FILE *fp;
        printf("\nRECONFIRM PASSWORD: ");
        while( (c=getch()) !='\r')
        {
            rpw[i]=c;
            putchar('*');
            i++;
        }
        rpw[i]='\0';
        //printf("\nComparing %s and %s.\n",pw,rpw);
        if(strcmp(pw,rpw)==0)
        {
            fp=fopen("./pswrd","wb");
            fprintf(fp, "%s", rpw);
            fclose(fp);
            printf("\n\n*******************************");
            printf("\nPASSWORD RESET SUCESSFULLY");
            printf("\n*******************************");
            Sleep(1000);
            system("cls");
        }
        else
        {
                //system("cls");
                printf("\nERROR: Password does not match");
//                resetpassword();
                goto Enter;
        }
}

//short int checkValid(char *x)
//{
//    alphabetCount=0;
//    digitCount=0;
//
//if(length<6)
//{
//printf("\n Password should be atleast 6 characters wide");
//return 0;
// }
//
//  while((*x)!='\0')
//    {
//     if( isalpha(*x))
//      alphabetCount++;       //alphabet, digits and symbol
//     else if( isdigit(*x) )  //count are made to check the
//      digitCount++;          //password strength
//     else if( isascii(*x) )
//      symbolCount++;
//     x++;
//    }
//
// if(alphabetCount==length) //this condition is true when u enter
// {                         //only alphabets, which is invalid
//  printf("\n ERROR: Password should contain both alphabets and digits");
//  return 0;
// }
// else if(digitCount==length) //this condion is true when u enter
// {                           //only digits, which is invalid
//  printf("\n ERROR: Password should contain both alphabets and digits");
//  return 0;
// }
// else
// return 1;
//}
//
//void checkStrength(char *p)
//{
//  short int strengthVar=0;
//
//  if( length>8 )
//  strengthVar++;
//  if( symbolCount >= 1 )
//  strengthVar++;
//  if( digitCount >= alphabetCount )
//  strengthVar++;
//  if( length>12 )
//  strengthVar++;
//
//  printf("\nPASSWORD STRENGTH : ");
//  switch(strengthVar)
//  {
//  case 0 :printf("low\n");
//   break;
//  case 1 :printf("medium\n");
//   break;
//  case 2 :printf("fair\n");
//   break;
//  case 3 :printf("high\n");
//   break;
//  case 4 :printf("very high\n");
//   break;
//  }
//
//}
