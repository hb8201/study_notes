// bst.c        Binary Search Tree
// 二叉搜索树
#include <stdio.h>
#include <stdlib.h>

// 节点
typedef struct node
{
    int data;               // 数据域
    struct node *left;      // 左子树
    struct node *right;     // 右子树
} Node, Tree;

// 操作：插入、先序、后序、中序
Node *insert(Tree *root, int data);
void pre_order(Tree *root);
void post_order(Tree *root);
void in_order(Tree *root);
int min(Tree *root);
int max(Tree *root);
// 扩展：翻转，层序

int main()
{
    Tree *root = NULL;      // 空树
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 45);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    in_order(root);
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
    //
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

// 中序
void in_order(Tree *root)
{
    if (root != NULL)
    {
        in_order(root->left);       // 先左子树
        printf("%d,", root->data);  // 根
        in_order(root->right);      // 右子树
    }
}
void pre_order(Tree *root);
void post_order(Tree *root);
int min(Tree *root);
int max(Tree *root);