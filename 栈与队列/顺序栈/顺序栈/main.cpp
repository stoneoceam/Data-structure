//˳��ջ

#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

typedef struct SqStack {
	ElemType* top;//ջ��ָ��
	ElemType* base;//ջ��ָ��
	int stacksize;//ջ���������
}SqStack;

//˳��ջ�ĳ�ʼ��
int InitStack(SqStack& S) {
	S.base = new ElemType[MAXSIZE];
	if (!S.base) return 0;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 1;
}

//��˳��ջ�ĳ���
int StackLength(SqStack& S) {
	return S.top - S.base;
}

//���˳��ջ
int StackEmpty(SqStack& S) {
	if (S.base) S.top = S.base;
	return 1;
}

//����˳��ջ
int DestroyStack(SqStack& S) {
	if (S.base) {
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return 1;
}

//˳��ջ��ջ
int PushStack(SqStack& S, ElemType e) {
	if (S.top - S.base == S.stacksize)
		return 0;
	else {
		*S.top = e;
		S.top++;
		return 1;
	}
}

//˳��ջ��ջ
int PopStack(SqStack& S,ElemType& e) {
	if (S.top - S.base == 0) {
		return 0;
	}
	else {
		S.top--;
		e = *S.top;
		return 1;
	}
}


int main() {
	SqStack S;
	


	return 0;
}