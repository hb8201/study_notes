// 统计二叉树叶子节点总个数
#include <stdio.h>
#include <stdlib.h>

int sum = 0;

typedef struct bnode
{
    int data;
    struct bnode *lchild;
    struct bnode *rchild;
} BNode, BTree;

BNode *add(BTree *t, int data);
void xianxu(BTree *t);
void GetLeafNum(BTree *t);

int main()
{
    BTree *btree = NULL;
    btree = add(btree, 12);
    btree = add(btree, 45);
    btree = add(btree, 34);
    btree = add(btree, 26);
    btree = add(btree, 54);
    btree = add(btree, 32);
    btree = add(btree, 14);
    btree = add(btree, 5);
    btree = add(btree, 10);
    btree = add(btree, 7);
    btree = add(btree, 21);
    GetLeafNum(btree);

    return 0;
}
BNode *add(BTree *t, int data)
{
    if (t == NULL)
    {
        t = malloc(sizeof(BNode));
        t->data = data;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }
    if (data < t->data)
    {
        t->lchild = add(t->lchild, data);
    }
    else
    {
        t->rchild = add(t->rchild, data);
    }
    return t;
}
void xianxu(BTree *t)
{
    if (t != NULL)
    {
        xianxu(t->lchild);
        xianxu(t->rchild);
    }
    else
        sum++;
}
void GetLeafNum(BTree *t)
{
    xianxu(t);
    printf("%d\n", sum);
}