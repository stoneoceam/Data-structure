//����

#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode;
typedef struct {
	QNode* front;
	QNode* rear;
}LinkQueue;

//��ʼ������
int InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	if (!Q.front) return 0;
	Q.front->next = NULL;
	return 1;
}

//��������
int DestroyQueue(LinkQueue& Q) {
	while (Q.front) {
		QNode* p = Q.front->next;
		delete Q.front;
		Q.front = p;
	}
	return 1;
}

//���
int EnQueue(LinkQueue& Q, ElemType e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 1;
}

//����
int DeQueue(LinkQueue& Q, ElemType& e) {
	QNode* p = Q.front->next;
	if (!p) return 0;
	e = p->data;
	Q.front->next = p->next;
	delete p;
	return 1;
}

//���ӵĳ���
int LengthQueue(LinkQueue Q) {
	QNode* p = Q.front->next;
	int Length = 0;
	while (p) {
		p = p->next;
		Length++;
	}
	return Length;
}

//��ͷԪ��
int GetHead(LinkQueue Q, ElemType& e) {
	if (!Q.front->next) return 0;
	e = Q.front->next->data;
	return 1;
}

int main() { 
	LinkQueue Q;
	
	return 0;
}