#include"binary_tree.h"
#include<iostream>
#include<queue>
using namespace std;

//为二叉树添加元素
Status InitBiTree(BiTree& T) {
	char ch;
	cin >> ch;
	if (ch != '\n') {
		if (ch == '#') T = NULL;
		else {
			if (T = new BiTNode) {
				T->data = ch;
				InitBiTree(T->lchild);
				InitBiTree(T->rchild);
				return OK;
			}
			else
				return ERROR;
		}
	}
	return OK;
}
//二叉树顺序遍历
Status PreOrderTraverse(BiTree T) {
	if (T == NULL) return OK;//空树
	else {
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		return OK;
	}
}
//二叉树的中序遍历
Status InOrderTraverse(BiTree T) {
	if (T == NULL) return OK;//空树
	else {
		PreOrderTraverse(T->lchild);
		cout << T->data;
		PreOrderTraverse(T->rchild);
		return OK;
	}
}
//二叉树的后序遍历
Status PostOrderTraverse(BiTree T) {
	if (T == NULL) return OK;//空树
	else {
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		cout << T->data;
		return OK;
	}
}
//二叉树的层序遍历
Status LevelOrderTraverse(BiTree T) {
	queue<BiTNode*> q;
	q.push(T);
	while (q.size() != 0) {
		cout << q.front()->data;
		if (q.front()->lchild != NULL) q.push(q.front()->lchild);
		if (q.front()->rchild != NULL) q.push(q.front()->rchild);
		q.pop();
	}
	return OK;
}
//二叉树的复制
Status Copy(BiTree T, BiTree &New_T) {
	if (T == NULL) {
		New_T = NULL;
		return OK;
	}
	else {
		New_T = new BiTNode;
		New_T->data = T->data;
		Copy(T->lchild, New_T->lchild);
		Copy(T->rchild, New_T->rchild);
		return OK;
	}
}
//计算二叉树叶子节点的个数
int LeadCount(BiTree T) {
	if (T == NULL) return 0;
	else {
		if (T->lchild == NULL && T->rchild == NULL)
			return 1;
		else
			return LeadCount(T->lchild) + LeadCount(T->rchild);
	}
}
//计算二叉树节点的个数
int NodeCount(BiTree T) {
	if (T == NULL) return 0;
	else {
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}
//计算二叉树的深度
int DeepTree(BiTree T) {
	if (T == NULL) return 0;
	else {
		int m = DeepTree(T->lchild);
		int n = DeepTree(T->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}
