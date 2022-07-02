#pragma once
#ifndef HUFFMANTREE_H
#include<iostream>
#include<string>
using namespace std;

typedef struct HTNode{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode,*HuffmanTree;

typedef struct HCNode {
	string Code="";
}HCNode,*HuffmanCode;


void Select(HuffmanTree HT, int n, int& flag1, int& flag2);
void CreatHuffmanTree(HuffmanTree& HT, int n);
void CreatHuffmanCode(HuffmanTree& HT, HuffmanCode& HC, int n);


#endif // !HUFFMANTREE_H

