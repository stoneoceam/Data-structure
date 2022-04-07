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

//--------顺序表的动态分配存储结构----------
#define LIST_MAX_SIZE 100 //顺序表存储空间的初始分配量

typedef struct {
	ElemType* elem;   //存储空间的基地址
	int length;       //当前长度
}SqList;

//顺序表的基本操作
Status InitList(SqList &L);//初始化操作，建立一个空的顺序表L
void DestroyList(SqList &L);//销毁已存在的顺序表L
void ClearList(SqList &L);//将顺序表清空
Status ListInsert(SqList& L, int i, int e);//在顺序表L中第i个位置插入新元素e
Status ListDelete(SqList& L, int i, int& e);//删除顺序表L中第i个位置元素，用e返回
Status IsEmpty(SqList L);//若顺序表为空，返回true，否则false
Status ListLength(SqList L);//返回顺序表的元素个数
Status LocateElem(SqList L, int e);//L中查找与给定值e相等的元素，若成功返回该元素在表中的序号，否则返回0
void GetElem(SqList L, int i, int& e);//将顺序表L中的第i个元素返回给e

//主函数
int main() {

	return 0;
}

//初始化操作，建立一个空的顺序表L
Status InitList(SqList& L) {
	L.elem = new ElemType[LIST_MAX_SIZE];
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}//InitList

//销毁已存在的顺序表L
void DestroyList(SqList& L) {
	if (L.elem) delete L.elem;
}//DestroyList

//将顺序表清空
void ClearList(SqList& L) {
	L.length = 0;
}//ClearLIst

//在顺序表L中第i个位置插入新元素e
Status ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1) return ERROR;
	if (L.length >= LIST_MAX_SIZE) return ERROR;
	for (int j = L.length-1; j >= i-1; j--) {
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i-1] = e;
	L.length++;
	return OK;
}//ListInsert

//删除顺序表L中第i个位置元素，用e返回
Status ListDelete(SqList& L, int i, int& e) {
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j < L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}//ListInsert

//若顺序表为空，返回true，否则false
Status IsEmpty(SqList L) {
	if (!L.length)
		return TRUE;
	else
		return FALSE;
}//IsEmpty

//返回顺序表的元素个数
Status ListLength(SqList L) {
	return L.length;
}//ListLength

//L中查找与给定值e相等的元素，若成功返回该元素在表中的序号，否则返回0
Status LocateElem(SqList L, int e) {
	int flag = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) {
			i++;
			flag = i;
			break;
		}
	}
	if (flag)
		return flag;
	else
		return 0;
}//LocateElem

//将顺序表L中的第i个元素返回给e
void GetElem(SqList L, int i, int& e) {
	for (int j = 0; j < L.length; j++) {
		if (j == i - 1)
			e = L.elem[j];
	}
}//GetElem