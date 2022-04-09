#include<iostream>
using namespace std;

//�������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;

//�Զ�����������
typedef int ElemType;

//������Ĵ洢�ṹ
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

//����Ļ�������
Status InitList(LinkList& L);//������ĳ�ʼ��
Status ListEmpty(LinkList& L);//�жϵ������Ƿ�Ϊ�ձ�
Status DestroyLsit(LinkList& L);//���ٵ�����
Status ClearList(LinkList& L);//�������L
Status ListLength(LinkList& L);//���������Ԫ�ظ���
Status GetElem(LinkList& L, int i, ElemType& e);//��ȡ�������е�ĳ��Ԫ�ص����ݣ��ñ���e����
Lnode* LocateElem(LinkList L, ElemType e);//��˳����в���ֵΪe������Ԫ�أ����ҵ��򷵻�ֵΪe������Ԫ�صĵ�ַ�����򷵻�NULL
Status ListInsert(LinkList& L, int i, ElemType e);//������ĵ�i��Ԫ��֮ǰ��������Ԫ��e



//������
int main() {
	LinkList L;
	InitList(L);
	cout << ListLength(L);
	DestroyLsit(L);
	return 0;
}

//������ĳ�ʼ��
Status InitList(LinkList& L) {
	L = new Lnode;
	L->next = NULL;
	return OK;
}//InitList

//�жϵ������Ƿ�Ϊ�ձ�
Status ListEmpty(LinkList& L) {
	if (!L->next)//��
		return TRUE;
	else
		return FALSE;
}//ListEmpty

//���ٵ�����
Status DestroyLsit(LinkList& L) {
	Lnode* p;
	while (L) {
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}//DestroyLsit

//�������L
Status ClearList(LinkList& L) {
	Lnode* p, * q;
	p = L->next;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}//ClearList

//���������Ԫ�ظ���
Status ListLength(LinkList& L) {
	Lnode* p;
	int length = 0;
	p = L->next;
	if (p) {
		length++;
		p = p->next;
	}
	return length;
}//LinkLength

//��ȡ�������е�ĳ��Ԫ�ص����ݣ��ñ���e����
Status GetElem(LinkList& L, int i, ElemType& e) {
	Lnode* p;
	int j;
	p = L->next;
	j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}//GetElem

//��˳����в���ֵΪe������Ԫ�أ����ҵ��򷵻�ֵΪe������Ԫ�صĵ�ַ�����򷵻�NULL
Lnode* LocateElem(LinkList L, ElemType e) {
	Lnode *p;
	p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}//LocateElem

//������ĵ�i��Ԫ��֮ǰ��������Ԫ��e
Status ListInsert(LinkList& L, int i, ElemType e) {
	Lnode* p = L->next;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	Lnode* q = new Lnode;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return OK;
}//ListInsert