#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
    int key;
    struct bst * left,* right;
}* node;

node InsertKey(node,int);
void SearchKey(node,int);
node DeleteKey(node,int);
void Inorder(node);
void Preorder(node);
void Postorder(node);

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
        else if (ch=='p')
        {
            if(root==NULL)
            {
                printf("NULL\n");
                continue;
            }
            Inorder(root);
            printf("\n");
        }
        else if (ch=='t')
        {
            if(root==NULL)
            {
                printf("NULL\n");
                continue;
            }
            Preorder(root);
            printf("\n");
        }
        else if (ch=='b')
        {
            if(root==NULL)
            {
                printf("NULL\n");
                continue;
            }
            Postorder(root);
            printf("\n");
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

void Inorder(node root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d ",root->key);
        Inorder(root->right);
    }
}

void Preorder(node root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(node root)
{
    if(root!=NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->key);
    }
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
    if(root == NULL) return root;

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
        while(temp && temp->left != NULL)
            temp = temp->left;
        root->key = temp->key;
        root->right = DeleteKey(root->right,temp->key);
    }
    return root;
}