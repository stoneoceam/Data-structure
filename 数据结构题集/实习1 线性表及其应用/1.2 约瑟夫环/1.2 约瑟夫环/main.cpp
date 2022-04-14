/*
*【问题描述】
*	约瑟夫(Joseph)问题的一种描述是：编号为1，2，…，n的n个人按顺时针方向围坐一
*	圈，每人持有一个密码(正整数)。一开始任选一个正整数作为报数上限值m，从第一个人
*	开始按顺时针方向自1开始顺序报数，报到m时停止报数。报m的人出列，将他的密码作
*	为新的m值，从他在顺时针方向上的下一个人开始重新从1报数，如此下去，直至所有人
*	全部出列为止。试设计一个程序求出出列顺序。
*【基本要求】
*	利用单向循环链表存储结构模拟此过程，按照出列的顺序印出各人的编号。
*【测试数据】
*	m的初值为20；n=7，7个人的密码依次为：3，1，7，2，4，8，4，首先m值为6(正确的出
*	列顺序应为6，1，4，7，2，3，5)。
*【实现提示】
*	程序运行后，首先要求用户指定初始报数上限值，然后读取各人的密码。可设n≤30。
*	此题所用的循环链表中不需要“头结点”，请注意空表和非空表的界限。
*【选作内容】
*	向上述程序中添加在顺序结构上实现的部分。
*/

#include<iostream>
using namespace std;

//定义数据元素
typedef struct LNode {
	int number;
	int password;
	struct LNode *next;
}Lnode,*LinkList;


//创建无头结点链表
void CreatList(LinkList& L, int* k, int n) {
	LNode* temp=NULL;//上一个节点的地址
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

void deleteList(LinkList& L, LNode* p, LNode*& start, int& m) {//删除地址为p的结点
	LNode* q;//迭代器q
	LNode* h;//目标结点的地址

	q = L;
	while (q->next != p) {
		q = q->next;
	}//找到目标结点的前驱
	h = q->next;
	if (h == L)//若删除的结点为头指针指向的结点
		L = h->next;
	cout << h->number << " ";
	m = h->password;
	q->next = h->next;
	delete h;
	start = q->next;//下一元素
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
		deleteList(L, p, start, m);//删除报m的人
		n--;
	}
}

void input(int& m, int& n, int*& k) {
	cout << "请输入m (m>=1)" << endl;
	cin >> m;
	cout << "请输入n（n>=1）" << endl;
	cin >> n;
	cout << "请输入每个人的password" << endl;
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