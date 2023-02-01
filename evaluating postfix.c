#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define SS 20
#define true 1
#define false 0
struct stack{
int top;
int item[SS];
}s;
int evaluate(char[]);
void push(int);
int pop();

int empty();
int operation(int,int,char);
void main()
{

    char postfix[100];
    int value;
    s.top=-1;
    printf("enter the postfix expression");
    scanf("%s",postfix);
    value=evaluate(postfix);
    if(empty())
    {
        printf("the result is %d",value);
        exit(0);
    }
}
int evaluate(char postfix[])
{
 int i;
 char symb;
 int value,op1,op2;
 for(i=0;postfix[i]!='\0';i++)
 {
     symb=postfix[i];
     if(symb>='0'&&symb<='9')
        push((int)(symb-'0'));
     else{
        op2=pop();
        op1=pop();
        value=operation(op1,op2,symb);
        push(value);
     }
 }
 return (pop());
 }
 int operation(int op1,int op2,char symb)
 {

     switch(symb)
     {
         case'+':return(op1+op2);
           case'-':return(op1-op2);
             case'*':return(op1*op2);
               case'/':return(op1/op2);
                 case'%':return(op1%op2);
                   case'^':return(pow(op1,op2));
     }
 }
 void push(int x)
{

    if(s.top==SS-1)
    {
        printf("overflow");
        exit(0);
    }
    else{
        s.top++;
        s.item[s.top]=x;
    }
}

int pop()
{

    if(s.top==-1)
    {

        printf("underflow");
        exit(0);
    }
    return s.item[(s.top)--];
}
int empty()
{
    if(s.top==-1)
        return true;
    else
        return false;
}
