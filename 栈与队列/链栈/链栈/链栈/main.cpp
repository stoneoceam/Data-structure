#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

//创建链栈
int InitStack(LinkStack& S) {
	S = NULL;
	return 1;
}

//判断链栈是否为空
int StackEmpty(LinkStack S) {
	if (S == NULL)
		return 1;
	else
		return 0;
}

//链栈的入栈
void Push(LinkStack& S,ElemType e) {
	StackNode* p = new StackNode;//创建新的节点
	p->data = e;
	p->next = S;
	S = p;
}

//链栈的出栈
int Pop(LinkStack& S, ElemType& e) {
	if (S == NULL) return 0;
	StackNode* p;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	p = NULL;
	return 1;
}

//求链栈的长度
int StackLength(LinkStack S) {
	int length = 0;
	StackNode* p = S;
	while (p != NULL) {
		p = p->next;
		length++;
	}
	p = NULL;
	return length;
}

//清空链栈
int ClearStack(LinkStack& S) {
	StackNode* p;
	while (S != NULL) {
		p = S;
		S = S->next;
		delete p;
	}
	p = NULL;
	return 1;
}



//取栈顶元素
ElemType Get(LinkStack S, ElemType& e) {
	if (S == NULL) return 0;
	e = S->data;
	return 1;
}

int main() {
	LinkStack S;
	
	return 0;
}