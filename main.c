#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

int main()
{
  numbers *X = NULL;
  operators *Y =NULL;
  char s[100],polsk[100]="",num[50];
  char pr_op='=';
  int i=0,k=0,j,l;
  FILE *input=fopen("input.txt","r");
  fgets(s,100,input);
  while (s[i]!='=')
  {
    if ((isnum(s[i])==true)||(X==NULL))
    {
       j=i;
       do
       {
           if (s[j]=='e')
            j+=4;
           else
            j++;
       }while (isnum(s[j])==true);
       l=0;
       if (s[i]=='-')
       {
           i++;
       while (i<j)
       {
           num[l]=s[i];
           l++;
           i++;
       }
       num[l]='\0';
       strcat(polsk,num);
       k+=l;
       push_num(&X,atof(num));
       strcat(polsk," ");
       push_op(&Y,'-');
       pr_op='-';
       k+=1;
       }
       else
        {
       while (i<j)
       {
           num[l]=s[i];
           l++;
           i++;
       }
       num[l]='\0';
       strcat(polsk,num);
       k+=l;
       push_num(&X,atof(num));
       strcat(polsk," ");
       k++;
       }


    }
    else
    {
        if((s[i]!=')')&&(s[i]!='('))
      {
          if (priority(pr_op)<priority(s[i]))
            {
               pr_op=s[i];
               push_op(&Y,s[i]);
               i++;
            }
            else
            {
              while((Y!=NULL)&&(priority(Y->op)>=priority(s[i])))
              {
                polsk[k]=Y->op;
                strcat(polsk," ");
                k++;
                k++;
                make_operation(&X,&Y);
              }
              push_op(&Y,s[i]);
              i++;
            }
      }
     if (s[i]==')')
      {
          while (Y->op!='(')
          {
              polsk[k]=Y->op;
              strcat(polsk," ");
              k++;
              k++;
              make_operation(&X,&Y);
          }
          pop_op(&Y);
          i++;
      }
      if (s[i]=='(')
      {
            push_op(&Y,s[i]);
            i++;
            if (s[i]=='-')
            {
               push_num(&X,0);
               i++;
               j=i;
               do
               {
                 if (s[j]=='e')
                 j+=4;
                 else
                 j++;
               }
                while (isnum(s[j])==true);
                l=0;
                while (i<j)
                {
                  num[l]=s[i];
                  l++;
                  i++;
                }
       num[l]='\0';
       strcat(polsk,num);
       strcat(polsk," ");
       push_op(&Y,'-');
       k+=1;
       k+=l;
       push_num(&X,atof(num));
            }

      }

    }

  }
  while (Y!=NULL)
  {
    polsk[k]=Y->op;
    strcat(polsk," ");
    k++;
    k++;
    make_operation(&X,&Y);
  }
  polsk[k]='=';
  polsk[k+1]='\0';
  printf("Expression:");
  puts(s);
  printf("\nAnswer: ");
  print_num(X);
  printf("\nPN: ");
  puts(polsk);
  return 0;
}

