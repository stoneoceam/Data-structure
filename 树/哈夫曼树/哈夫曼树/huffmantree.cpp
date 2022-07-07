#include<iostream>
#include<string>
#include"huffmantree.h"
using namespace std;

void Select(HuffmanTree HT, int n, int& flag1, int& flag2){
	int MIN1 = 10000000, MIN2 = 10000000;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && HT[i].weight < MIN1) {
			MIN1 = HT[i].weight;
			flag1 = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && HT[i].weight < MIN2 && i != flag1) {
			MIN2 = HT[i].weight;
			flag2 = i;
		}
	}	
}

void CreatHuffmanTree(HuffmanTree& HT, int n){
	if (n <= 1) return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];//0号位置不用
	for (int i = 1; i <= n; i++) {
		cin >> HT[i].weight;//输入每个数据的权值
	}
	for (int i = 1; i <= m; i++) {
		HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
	}
	/*------------初始化完成---------------------*/
	for (int i = n + 1; i <= m; i++) {
		int flag1, flag2;
		Select(HT, i - 1, flag1, flag2);
		HT[flag1].parent = HT[flag2].parent = i;
		HT[i].lchild = flag1;
		HT[i].rchild = flag2;
		HT[i].weight = HT[flag1].weight + HT[flag2].weight;
	}
}

void CreatHuffmanCode(HuffmanTree& HT, HuffmanCode& HC, int n) {
	CreatHuffmanTree(HT, n);
	HC = new HCNode[n + 1];
	for (int i = 1; i <= n; i++) {
		int f = HT[i].parent;
		int child = i;
		while (f != 0) {
			if (HT[f].lchild == child) { HC[i].Code.insert(0, 1, '0'); }
			else { HC[i].Code.insert(0, 1, '1'); }
			child = f;
			f = HT[f].parent;
		}
	}
}