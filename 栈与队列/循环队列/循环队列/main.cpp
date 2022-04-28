//ѭ������

#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct Queue {
	ElemType* base;
	int front;
	int rear;
}Queue;

//����ѭ������
int InitQueue(Queue& Q) {
	Q.base = new ElemType[MAXSIZE];
	if (!Q.base) return ERROR;
	Q.front = Q.rear = 0;
	return OK;
}

//����ѭ������
int DestroyQueue(Queue& Q) {
	if (!Q.base) return ERROR;
	delete Q.base;
	Q.front = Q.rear = 0;
	Q.base = NULL;
	return OK;
}

//��ѭ���������
int ClearQueue(Queue& Q) {
	if (!Q.base) return ERROR;
	Q.front = Q.rear = 0;
	return OK;
}

//����ѭ�����е�Ԫ�ظ���
int QueueLength(Queue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//��e����Q�Ķ�ͷԪ��
int GetHead(Queue Q, ElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	return OK;
}

//����Ԫ��eΪ��βԪ��
int EnQueue(Queue& Q, ElemType e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

//ɾ��Q�Ķ�ͷԪ����e����ֵ
int DeQueue(Queue& Q, ElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}

int main() {
	Queue Q;
	
	return 0;
}