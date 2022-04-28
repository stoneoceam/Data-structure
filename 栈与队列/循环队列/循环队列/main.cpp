//循环队列

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

//创建循环队列
int InitQueue(Queue& Q) {
	Q.base = new ElemType[MAXSIZE];
	if (!Q.base) return ERROR;
	Q.front = Q.rear = 0;
	return OK;
}

//销毁循环队列
int DestroyQueue(Queue& Q) {
	if (!Q.base) return ERROR;
	delete Q.base;
	Q.front = Q.rear = 0;
	Q.base = NULL;
	return OK;
}

//将循环队列清空
int ClearQueue(Queue& Q) {
	if (!Q.base) return ERROR;
	Q.front = Q.rear = 0;
	return OK;
}

//返回循环队列的元素个数
int QueueLength(Queue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//用e返回Q的队头元素
int GetHead(Queue Q, ElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	return OK;
}

//插入元素e为队尾元素
int EnQueue(Queue& Q, ElemType e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

//删除Q的队头元素用e返回值
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