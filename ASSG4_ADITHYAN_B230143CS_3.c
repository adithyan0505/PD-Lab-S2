#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct TREE{
    int key;
    struct TREE * left,* right;
}* node;

/*void Preorder(node root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}*/

node new(int num)
{
    node Node = (node)malloc(sizeof(struct TREE));
    Node->key = num;
    Node->left = Node->right = NULL;
    return (Node);
}

node Search(node root,int x)
{
    if(root==NULL || root->key==x)
    return root;
    node left = Search(root->left,x);
    node right = Search(root->right,x);
    if(right!=NULL) return right;
    else return left;
}

void Print(node root,int k,int depth)
{
    if(root==NULL) return;
    if(depth==k)
    printf("%d ",root->key);

    Print(root->left,k,depth+1);
    Print(root->right,k,depth+1);
}

int main()
{
    node root = NULL;
    node stack[1000];
    int top = -1;
    char ch=getchar();
    ch=getchar();
    ch=getchar();
    do
    {
        int num=0;
        int flag = 0;
        while (isdigit(ch))
        {
            num *= 10;
            num += (ch-'0');
            ch=getchar();
            flag=1;
        }
        if(flag==1)
        {
            ch=getchar();
            if(root==NULL) root = new(num);
            else if(root->left==NULL)
            {
                node left = new(num);
                root->left = left;
                root = root->left;
            }
            else if(root->right==NULL)
            {
                node right = new(num);
                root->right = right;
                root = root->right;
            }
        }
        if(ch=='(')
        {
            top++;
            stack[top]=root;
            ch=getchar();
            ch=getchar();
        }
        else if(ch==')')
        {
            if(top>-1)root = stack[top];
            top--;
            if(top!=-2)
            { 
                ch=getchar();
                ch=getchar();
            }
        }
    } while (top!=-2);
    //Preorder(root);
    int x,k;
    scanf("%d",&x); scanf("%d",&k);
    node X = Search(root,x);
    Print(X,k,0);
    return 0;
}