#include<iostream>
using namespace std;

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;

//自定义数据类型
typedef int ElemType;

//单链表的存储结构
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

//链表的基本操作
Status InitList(LinkList& L);//单链表的初始化
Status ListEmpty(LinkList& L);//判断单链表是否为空表
Status DestroyLsit(LinkList& L);//销毁单链表
Status ClearList(LinkList& L);//清空链表L
Status ListLength(LinkList& L);//返回链表的元素个数
Status GetElem(LinkList& L, int i, ElemType& e);//获取单链表中的某个元素的内容，用变量e返回
Lnode* LocateElem(LinkList L, ElemType e);//在顺序表中查找值为e的数据元素，若找到则返回值为e的数据元素的地址，否则返回NULL
Status ListInsert(LinkList& L, int i, ElemType e);//在链表的第i个元素之前插入数据元素e



//主函数
int main() {
	LinkList L;
	InitList(L);
	cout << ListLength(L);
	DestroyLsit(L);
	return 0;
}

//单链表的初始化
Status InitList(LinkList& L) {
	L = new Lnode;
	L->next = NULL;
	return OK;
}//InitList

//判断单链表是否为空表
Status ListEmpty(LinkList& L) {
	if (!L->next)//空
		return TRUE;
	else
		return FALSE;
}//ListEmpty

//销毁单链表
Status DestroyLsit(LinkList& L) {
	Lnode* p;
	while (L) {
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}//DestroyLsit

//清空链表L
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

//返回链表的元素个数
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

//获取单链表中的某个元素的内容，用变量e返回
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

//在顺序表中查找值为e的数据元素，若找到则返回值为e的数据元素的地址，否则返回NULL
Lnode* LocateElem(LinkList L, ElemType e) {
	Lnode *p;
	p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}//LocateElem

//在链表的第i个元素之前插入数据元素e
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