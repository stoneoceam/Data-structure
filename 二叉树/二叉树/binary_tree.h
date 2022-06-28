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

Status InitBiTree(BiTree& T);//Ϊ���������Ԫ��
Status PreOrderTraverse(BiTree T);//������˳�����
Status InOrderTraverse(BiTree T);//���������������
Status PostOrderTraverse(BiTree T);//�������ĺ������
Status LevelOrderTraverse(BiTree T);//�������Ĳ������
Status Copy(BiTree T,BiTree &New_T);//�������ĸ���
int LeadCount(BiTree T);//���������Ҷ�ӽڵ�ĸ���
int NodeCount(BiTree T);//����������ڵ�ĸ���
int DeepTree(BiTree T);//��������������
#endif 


