#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node, Tree;

Node *insert(Tree *root, int data);
void preorder(Tree *root);      // 先序
void inorder(Tree *root);       // 中序
void postorder(Tree *root);     // 后序
void tierorder(Tree *root);     // 层序
int min(Tree *root);
int max(Tree *root);
void reverse(Tree *root);

int main()
{
    Tree *root = NULL;
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 11);
    root = insert(root, 9);
    root = insert(root, 3);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("%d\n", min(root));
    printf("%d\n", max(root));
    tierorder(root);
    printf("\n");
    reverse(root);
    inorder(root);
    printf("\n");

    return 0;
}

Node *insert(Tree *root, int data)
{
    if (root == NULL)
    {
        root = malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void preorder(Tree *root)
{
    if (root != NULL)
    {
        printf("%d,", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d,", root->data);
        inorder(root->right);
    }
}
void postorder(Tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d,", root->data);
    }
}
void tierorder(Tree *root)
{
    if (root == NULL)
        return;

    Node *node[100];
    int head = 0, tail = 0;
    node[tail++] = root;
    while (head != tail)
    {
        Node *node1 = node[head++];
        printf("%d,", node1->data);
        if (node1->left != NULL)
        {
            node[tail++] = node1->left;
        }
        if (node1->right != NULL)
        {
            node[tail++] = node1->right;
        }
    }
}
int min(Tree *root)
{
    if (root->left == NULL)
    {
        return root->data;
    }
    min(root->left);
}
int max(Tree *root)
{
    if (root->right == NULL)
    {
        return root->data;
    }
    max(root->right);
}
void reverse(Tree *root)
{
    Node *node;
    if (root != NULL)
    {
        reverse(root->left);
        reverse(root->right);
        node = root->left;
        root->left = root->right;
        root->right = node;
    }
}
