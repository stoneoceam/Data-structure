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

//--------˳���Ķ�̬����洢�ṹ----------
#define LIST_MAX_SIZE 100 //˳���洢�ռ�ĳ�ʼ������

typedef struct {
	ElemType* elem;   //�洢�ռ�Ļ���ַ
	int length;       //��ǰ����
}SqList;

//˳���Ļ�������
Status InitList(SqList &L);//��ʼ������������һ���յ�˳���L
void DestroyList(SqList &L);//�����Ѵ��ڵ�˳���L
void ClearList(SqList &L);//��˳������
Status ListInsert(SqList& L, int i, int e);//��˳���L�е�i��λ�ò�����Ԫ��e
Status ListDelete(SqList& L, int i, int& e);//ɾ��˳���L�е�i��λ��Ԫ�أ���e����
Status IsEmpty(SqList L);//��˳���Ϊ�գ�����true������false
Status ListLength(SqList L);//����˳����Ԫ�ظ���
Status LocateElem(SqList L, int e);//L�в��������ֵe��ȵ�Ԫ�أ����ɹ����ظ�Ԫ���ڱ��е���ţ����򷵻�0
void GetElem(SqList L, int i, int& e);//��˳���L�еĵ�i��Ԫ�ط��ظ�e

//������
int main() {

	return 0;
}

//��ʼ������������һ���յ�˳���L
Status InitList(SqList& L) {
	L.elem = new ElemType[LIST_MAX_SIZE];
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}//InitList

//�����Ѵ��ڵ�˳���L
void DestroyList(SqList& L) {
	if (L.elem) delete L.elem;
}//DestroyList

//��˳������
void ClearList(SqList& L) {
	L.length = 0;
}//ClearLIst

//��˳���L�е�i��λ�ò�����Ԫ��e
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

//ɾ��˳���L�е�i��λ��Ԫ�أ���e����
Status ListDelete(SqList& L, int i, int& e) {
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j < L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}//ListInsert

//��˳���Ϊ�գ�����true������false
Status IsEmpty(SqList L) {
	if (!L.length)
		return TRUE;
	else
		return FALSE;
}//IsEmpty

//����˳����Ԫ�ظ���
Status ListLength(SqList L) {
	return L.length;
}//ListLength

//L�в��������ֵe��ȵ�Ԫ�أ����ɹ����ظ�Ԫ���ڱ��е���ţ����򷵻�0
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

//��˳���L�еĵ�i��Ԫ�ط��ظ�e
void GetElem(SqList L, int i, int& e) {
	for (int j = 0; j < L.length; j++) {
		if (j == i - 1)
			e = L.elem[j];
	}
}//GetElem