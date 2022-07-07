#ifndef BINARY_TREE_H

#define BINARY_TREE_H

#include<iostream>
using namespace std;

#define Status int
#define OK 1
#define ERROR 0

#define ElemType char
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* rchild, * lchild;
}BiTNode,*BiTree;

Status InitBiTree(BiTree& T);//为二叉树添加元素
Status PreOrderTraverse(BiTree T);//二叉树顺序遍历
Status InOrderTraverse(BiTree T);//二叉树的中序遍历
Status PostOrderTraverse(BiTree T);//二叉树的后序遍历
Status LevelOrderTraverse(BiTree T);//二叉树的层序遍历
Status Copy(BiTree T,BiTree &New_T);//二叉树的复制
int LeadCount(BiTree T);//计算二叉树叶子节点的个数
int NodeCount(BiTree T);//计算二叉树节点的个数
int DeepTree(BiTree T);//计算二叉树的深度
#endif 


