#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#define MS 20
#define true 1
#define false 0
struct stack{
int top;
char item[MS];
}s;
char infix[100],postfix[100];
void convert();
void push(char );
char pop();

int precedence(char);
int empty();
void main(){
s.top=-1;
printf("enter the infix ");
scanf("%s",infix);
convert();
printf("the postfix is %s",postfix);

}
void push(char x){
if(s.top==MS-1)
    {
        printf("overflow");
        exit(0);
    }else{
    s.top++;
    s.item[s.top]=x;
    }
    }
char pop(){
if(s.top==-1)
{
    printf("underflow");
    exit(0);

}
return (s.item[(s.top)--]);
}
void convert()
{

    int pos=0,i;
    char temp,symb;
    for(i=0;infix[i]!='\0';i++)
    {
        symb=infix[i];
        switch(symb)
        {
            case'(':push(symb);
            break;
            case')':while((temp=pop())!='(')
                          {
                              postfix[pos++]=temp;
                          }
                          break;
            case'+':
                case'-':
                    case'*':
                        case'/':
                            case'%':
                                case'^':
                                    while(!empty()&&precedence(s.item[s.top])>=precedence(symb))







                                    {
                                        postfix[pos++]=pop();
                                    }

                                    push(symb);
                                    break;
                                    default:postfix[pos++]=symb;
                                    break;
        }
    }
    while(!empty())
    {
        temp=pop();
        postfix[pos++]=temp;
    }
}
int precedence(char symb)
{
 switch(symb)
 {
     case'^':return(3);
     case'%':
     case'*':
        case'/':return(2);
         case'+':
        case'-':return(1);

        case'(':return(0);
 }
 return (symb);
}
int empty()
{

    if(s.top==-1)



        return true;
        else
            return false;
}
