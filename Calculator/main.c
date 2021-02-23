#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX  100

double powr(double num1,double num2);
double add(double num1,double num2);
double mult(double num1,double num2);
double min(double num1,double num2);

/* structure has 2 elements */
/* 1st element is a character pointer to store operation string */
/* 2nd element is a pointer to function taking 2 doubles and returning a double */
struct command
{
    char *name;
    double (*pf)(double,double);
};
/* Create and initialize an array of the above structure to hold information for the 3 operations: */
/* 1. powr */
/* 2. add  */
/* 3. mult */
/* 4. min */

struct command commands[]=
{
    {"powr", powr},{"add", add},{"mult", mult},{"min", min}
};

/* Find the size of the above array */
#define SIZE (sizeof(commands)/sizeof(commands[0]))

int main()
{
    char line[MAX];
    double int1 , int2 , result;
    int i ;
    while(1)
    {
        printf("Enter one of the following commands:\n");
        printf("1. add\n2. mult\n3. powr\n4. min\n5. quite\n");
        printf(">> ");
        gets(line);
        if(strcmp(line , "quite")== 0)
            return 0 ;

        /* Find the right command entered and perform the operation */
        for(i=0 ; i<SIZE ; i++)
        {
            if(strcmp(line , commands[i].name)== 0)
            {
                printf("enter the first argument: ");
                int1 = atof(gets(line));
                printf("enter the second argument: ");
                int2 = atof(gets(line));
                result = commands[i].pf(int1,int2);
                printf ("Answer is %f.\n", result);
                break;
            }
        }
        /* Wrong command entered */
        if( i == SIZE){
            printf("Command not found.\n");
        }
        /* Clear the screen */
        printf("Press Enter to continue.\n");
        gets(line);
        //system("clear");
		system("cls");

    }

    return 0;
}

double add(double num1,double num2)
{
    return (num1 + num2);
}

double mult(double num1,double num2)
{
    return(num1 * num2);
}

double min(double num1,double num2)
{
    return (num1 - num2);
}

double powr(double num1,double num2)
{
    /*another way to get the power without using math.h library*/
    int i ;
    double temp = num1;
    num2--;
    for(i=0 ; i<num2 ; i++)
    {
        temp = temp * num1;
    }
    return temp;
}
