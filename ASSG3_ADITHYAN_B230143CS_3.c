#include <stdio.h>

int main()
{
    int n,count=0,top; char ch,temp;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char stack[20];
        top=-1;
        while((ch=getchar())!='\n')
        {
            if(ch=='(') 
            {
                top++;
                stack[top]=ch;
            }
            else if(ch==')')
            {
                top--;
            }
            temp=ch;
        }
        if((top==-1)&&(temp!='(')) count++;
    }
    printf("%d",count);
    return 0;
}