#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define FEES 150000
unsigned long check_number(char str[30])
{
    unsigned long n;
    for(int i=0;str[i]!='\0';i++)
    {
        if(!isdigit(str[i]) || i==9)
            return 0;
    }
    n=(unsigned long)atof(str);
    return n;
}


long long int check_Contact(char str[30])
{
    long long int n;
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(!isdigit(str[i]))
            return 0;
    }
    if(i!=10)
        return 0;
    n=(long long int)atof(str);
    return n;
}



int check_Class(char c)
{
    if(c>'0' && c<='5')
        return 1;
    else
        return 0;
}

int check_input_for_fees(char s[20])
{
    int i=0;
    int dec_point = 0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')
            dec_point++;
        else
        {
            if(!isdigit(s[i]) || dec_point == 2)
                return 0;
        }
    }
    return 1;
}



double check_fees(char str[20])
{
    double num=0.0;
        int validity = check_input_for_fees(str);
        if(!validity)
            num=0;
        else
        {
            num = atof(str);
            num=(double)((int)(100*num))/100;
        }
        if(num>FEES)
            num=0;
        return num;
}

int check_input(char s[20])
{
    int i=0;
    int dec_point = 0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
            dec_point++;
        else
        {
            if(!isdigit(s[i]) || dec_point == 2)
                return 0;
        }
    }
    return 1;
}


