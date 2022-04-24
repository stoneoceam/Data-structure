//顺序栈

#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

typedef struct SqStack {
	ElemType* top;//栈顶指针
	ElemType* base;//栈底指针
	int stacksize;//栈的最大容量
}SqStack;

//顺序栈的初始化
int InitStack(SqStack& S) {
	S.base = new ElemType[MAXSIZE];
	if (!S.base) return 0;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 1;
}

//求顺序栈的长度
int StackLength(SqStack& S) {
	return S.top - S.base;
}

//清空顺序栈
int StackEmpty(SqStack& S) {
	if (S.base) S.top = S.base;
	return 1;
}

//销毁顺序栈
int DestroyStack(SqStack& S) {
	if (S.base) {
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return 1;
}

//顺序栈入栈
int PushStack(SqStack& S, ElemType e) {
	if (S.top - S.base == S.stacksize)
		return 0;
	else {
		*S.top = e;
		S.top++;
		return 1;
	}
}

//顺序栈出栈
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