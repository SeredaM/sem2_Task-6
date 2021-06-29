#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

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

void push_num( numbers **ptr, double x);

void push_op(operators **ptr, char x);

void print_num(numbers *ptr);

void print_op(operators *ptr);

double pop_num(numbers **ptr);

char pop_op(operators **ptr);

int priority(char a);

bool isnum(char *a);

void make_operation (numbers **X, operators **Y);










#endif // STACK_H_INCLUDED
