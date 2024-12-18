#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
    int key;
    struct bst * left,* right;
}* node;

node InsertKey(node,int);
void SearchKey(node,int);
node DeleteKey(node,int);
void KthSmallest(node,int*);
void Maximum(node);
void Successor(node,int);

int main()
{
    node root = NULL;
    char ch; int num;
    do
    {
        scanf("%c",&ch);
        if(ch=='i')
        {
            scanf("%d",&num);
            root = InsertKey(root,num);
        }
        else if(ch=='s')
        {
            scanf("%d",&num);
            SearchKey(root,num);
        }
        else if(ch=='d')
        {
            scanf("%d",&num);
            root = DeleteKey(root,num);
        }
        else if (ch=='k')
        {
            if(root==NULL)
            {
                printf("NULL\n");
                continue;
            }
            int k;
            scanf("%d",&k);
            KthSmallest(root,&k);
        }
        else if (ch=='m')
        {
            if(root==NULL)
            {
                printf("NULL\n");
                continue;
            }
            Maximum(root);
        }
        else if (ch=='n')
        {
            if(root==NULL)
            {
                printf("NULL\n");
                continue;
            }
            scanf("%d",&num);
            Successor(root,num);
        }
    } while (ch!='e');
    return 0;
}

node InsertKey(node Node,int num)
{
    if(Node == NULL)
    {
        node temp = (node)malloc(sizeof(struct bst));
        temp->key = num;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (num < Node->key)
        Node->left = InsertKey(Node->left,num);
    else if(num > Node->key)
        Node->right = InsertKey(Node->right,num);
    return Node;
}

void SearchKey(node root,int num)
{
    int flag = 0;
    while(root!=NULL)
    {
        if(root->key == num)
        {
            printf("PRESENT\n");
            flag=1;
            break;
        }
        if(root->key > num)
            root = root->left;
        else if(root->key < num)
            root = root->right;
    }
    if(flag==0) printf("NOT PRESENT\n");

}

node DeleteKey(node root,int num)
{
    if(root == NULL)
    {
        printf("NOT PRESENT\n");
        return root;
    }
    if (num < root->key) 
        root->left = DeleteKey(root->left,num);
    else if(num > root->key)
        root->right = DeleteKey(root->right,num);
    else
    {
        if(root->left==NULL)
        {
            node temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node temp = root->left;
            free(root);
            return temp;
        }
        
        node temp = root->right;
        while(temp->left != NULL)
            temp = temp->left;
        root->key = temp->key;
        root->right = DeleteKey(root->right,temp->key);
    }
    return root;
}

void KthSmallest(node root,int * count)
{
    if(root!=NULL)
    {
        KthSmallest(root->left,count);
        (*count)--;
        if(*count==0)
        {
            printf("%d\n",root->key);
            return;
        }
        KthSmallest(root->right,count);
    }
}

void Maximum(node root)
{

    while(root->right!=NULL)
        root = root->right;
    printf("%d\n",root->key);
}

void Successor(node root,int num)
{
    node succ = NULL;
    while(root!=NULL)
    {
        if(root->key == num)
        {
            if(root->right!=NULL)
            {
                node temp = root->right;
                while(temp && temp->left != NULL)
                    temp = temp->left;
                printf("%d\n",temp->key);
                break;
            }
            else
            {
                if(succ==NULL)
                {
                    printf("NULL\n");
                    break;
                }
                printf("%d\n",succ->key);
                break;
            }
        }
        if(root->key > num)
        {
            succ = root;
            root = root->left;
        }
        else if(root->key < num)
            root = root->right;
        //else    break;
    }
}