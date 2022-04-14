/*
*������������
*	Լɪ��(Joseph)�����һ�������ǣ����Ϊ1��2������n��n���˰�˳ʱ�뷽��Χ��һ
*	Ȧ��ÿ�˳���һ������(������)��һ��ʼ��ѡһ����������Ϊ��������ֵm���ӵ�һ����
*	��ʼ��˳ʱ�뷽����1��ʼ˳����������mʱֹͣ��������m���˳��У�������������
*	Ϊ�µ�mֵ��������˳ʱ�뷽���ϵ���һ���˿�ʼ���´�1�����������ȥ��ֱ��������
*	ȫ������Ϊֹ�������һ�������������˳��
*������Ҫ��
*	���õ���ѭ������洢�ṹģ��˹��̣����ճ��е�˳��ӡ�����˵ı�š�
*���������ݡ�
*	m�ĳ�ֵΪ20��n=7��7���˵���������Ϊ��3��1��7��2��4��8��4������mֵΪ6(��ȷ�ĳ�
*	��˳��ӦΪ6��1��4��7��2��3��5)��
*��ʵ����ʾ��
*	�������к�����Ҫ���û�ָ����ʼ��������ֵ��Ȼ���ȡ���˵����롣����n��30��
*	�������õ�ѭ�������в���Ҫ��ͷ��㡱����ע��ձ�ͷǿձ�Ľ��ޡ�
*��ѡ�����ݡ�
*	�����������������˳��ṹ��ʵ�ֵĲ��֡�
*/

#include<iostream>
using namespace std;

//��������Ԫ��
typedef struct LNode {
	int number;
	int password;
	struct LNode *next;
}Lnode,*LinkList;


//������ͷ�������
void CreatList(LinkList& L, int* k, int n) {
	LNode* temp=NULL;//��һ���ڵ�ĵ�ַ
	for (int i = 1; i <= n; i++) {
		LNode* p;
		p = new LNode;
		if (i == 1)
			L = p;
		else
			temp->next = p;
		p->next = NULL;
		p->number = i;
		p->password = *k++;
		temp = p;
		if (i == n)
			p->next = L;
	}
}

void deleteList(LinkList& L, LNode* p, LNode*& start, int& m) {//ɾ����ַΪp�Ľ��
	LNode* q;//������q
	LNode* h;//Ŀ����ĵ�ַ

	q = L;
	while (q->next != p) {
		q = q->next;
	}//�ҵ�Ŀ�����ǰ��
	h = q->next;
	if (h == L)//��ɾ���Ľ��Ϊͷָ��ָ��Ľ��
		L = h->next;
	cout << h->number << " ";
	m = h->password;
	q->next = h->next;
	delete h;
	start = q->next;//��һԪ��
}

void joseph(LinkList& L, int m,int n) {
	LNode* start;
	start = L;
	while (n != 0) {
		LNode* p;
		p = start;
		for (int i = 1; i < m; i++) {
			p = p->next;
		}
		deleteList(L, p, start, m);//ɾ����m����
		n--;
	}
}

void input(int& m, int& n, int*& k) {
	cout << "������m (m>=1)" << endl;
	cin >> m;
	cout << "������n��n>=1��" << endl;
	cin >> n;
	cout << "������ÿ���˵�password" << endl;
	k = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
}


int main() {
	LinkList L;
	int m, n;
	int* k;
	input(m, n, k);
	CreatList(L, k, n);
	joseph(L, m, n);
	return 0;
}