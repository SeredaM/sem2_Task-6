#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef struct numbers
{
    double num;
    struct numbers *next;
}numbers;

typedef struct operators
{
    char op;
    struct operators *next;
}operators;



void push_num( numbers **ptr, double x)
{
    numbers *tmp = (numbers*)malloc(sizeof(numbers));
    tmp->num=x;
    tmp->next=*ptr;
    *ptr = tmp;
}

void push_op(operators **ptr, char x)
{
    operators *tmp = (operators*)malloc(sizeof(operators));
    tmp->op=x;
    tmp->next=*ptr;
    *ptr = tmp;
}


void print_num(numbers *ptr)
{
    while (ptr->next!=NULL)
        {
          printf("%lf ",ptr->num);
          ptr = ptr -> next;
        }
        printf("%lf \n",ptr->num);
}

void print_op(operators *ptr)
{
    while(ptr->next!=NULL)
        {
          printf("%c ",ptr->op);
          ptr = ptr -> next;
        }
        printf("%c \n",ptr->op);
}


double pop_num(numbers **ptr)
{
    numbers *tmp = *ptr;
    *ptr = (*ptr)->next;
    double x = tmp->num;
    free(tmp);
    return(x);
}

char pop_op(operators **ptr)
{
    operators *tmp = *ptr;
    *ptr = (*ptr)->next;
    char x = tmp->op;
    free(tmp);
    return(x);
}


int priority(char a)
{
    if (a =='=')
        return 1;
    if (a== '(')
        return 2;
    if ((a=='-')||(a=='+'))
        return 3;
    if ((a=='*')||(a=='/'))
        return 4;
}
bool isnum(char *a)
{
    if (a=='0') return true;
    if (a=='1') return true;
    if (a=='2') return true;
    if (a=='3') return true;
    if (a=='4') return true;
    if (a=='5') return true;
    if (a=='6') return true;
    if (a=='7') return true;
    if (a=='8') return true;
    if (a=='9') return true;
    if (a=='.') return true;
    if (a=='e') return true;
    return false;
}

void make_operation (numbers **X, operators **Y)
{
    double x,y;
    y=pop_num(X);
    x=pop_num(X);
    switch(pop_op(Y))
    {
    case '+':
        push_num(X,x+y);
        break;
    case '-':
        push_num(X,x-y);
        break;
    case '*':
        push_num(X,x*y);
        break;
    case '/':
        if (abs(y)<0.0001)
        {
            printf("Error: division by 0");
            exit(2);
        }
        push_num(X,x/y);
        break;
    }
}
