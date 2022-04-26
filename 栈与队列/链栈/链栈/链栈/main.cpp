#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

//������ջ
int InitStack(LinkStack& S) {
	S = NULL;
	return 1;
}

//�ж���ջ�Ƿ�Ϊ��
int StackEmpty(LinkStack S) {
	if (S == NULL)
		return 1;
	else
		return 0;
}

//��ջ����ջ
void Push(LinkStack& S,ElemType e) {
	StackNode* p = new StackNode;//�����µĽڵ�
	p->data = e;
	p->next = S;
	S = p;
}

//��ջ�ĳ�ջ
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

//����ջ�ĳ���
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

//�����ջ
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



//ȡջ��Ԫ��
ElemType Get(LinkStack S, ElemType& e) {
	if (S == NULL) return 0;
	e = S->data;
	return 1;
}

int main() {
	LinkStack S;
	
	return 0;
}