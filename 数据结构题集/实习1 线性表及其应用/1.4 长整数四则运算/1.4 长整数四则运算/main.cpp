/*
【问题描述】
	设计一个实现任意长的整数进行加法运算的演示程序。
【基本要求】
	利用双向循环链表实现长整数的存储，每个结点含一个整型变量。任何整型变量的范
	围是-(2^15-1)~(2^15-1)。输入和输出形式：按中国对于长整数的表示习惯，每四位一
	组，组间用逗号隔开。
【测试数据】
	（1）0；0；应输出“0”。
	（2）-2345，6789；-7654，3211；应输出“-1，0000，0000”。
	（3）-9999，9999；1，0000，0000，0000；应输出“9999，0000，0001”。
	（4）1，0001，0001；一1，0001，0001；应输出“0”。
	（5）1，0001，0001；-1，0001，0000；应输出“1”。
	（6）-9999，9999，9999；-9999，9999，9999；应输出“一1，9999，9999，9998”。
	（7）1，0000，9999，9999；1；应输出“1，0001，0000，0000”。
【实现提示】
	（1）每个结点中可以存放的最大整数为215-1=32767，才能保证两数相加不会溢
	出。但若这样存放，即相当于按32768进制数存放，在十进制数与32768进制数之间的转
	换十分不方便。故可以在每个结点中仅存十进制数的4位，即不超过9999的非负整数，整
	个链表表示为万进制数。
	（2)可以利用头结点数据域的符号代表长整数的符号。相加过程中不要破坏两个操
	作数链表。不能给长整数位数规定上限。
【选作内容】
	（1）实现长整数的四则运算；
	（2）实现长整数的乘方和阶乘运算；
	（3）整型量范围是-(2^n-1)～(2^n-1)，其中，n是由程序读入的参量。输人数据的分
	组方法可以另行规定。
*/

//目前只完成了加法


#include<iostream>
using namespace std;
#define MAX_SIZE 10000


typedef struct SqList{
	char symbol;//符号
	char* data = new char[MAX_SIZE];//数
	int len;//数的长度
}SqList;


void CreatList(SqList& k) {//创建大整数
	cout << "输入一个大整数" << endl;
	char d[MAX_SIZE] = { 0 };
	cin >> d;
	if (d[0] == '-') {//去除数的符号
		k.symbol = '-';
		for (int i = 1,j=0; i < strlen(d); i++,j++) {
			k.data[j] = d[i];
		}
		k.len = strlen(d)-1;
	}
	else {
		k.symbol = '+';
		for (int i = 0, j = 0; i < strlen(d); i++, j++) {
			k.data[j] = d[i];
		}
		k.len = strlen(d);
	}
}

void swap(SqList& k1, SqList& k2) {//k1为较大的数，k2为较小的数(不看符号)
	SqList temp;
	if (k1.len < k2.len) {
		temp = k1;
		k1 = k2;
		k2 = temp;
	}
	if (k1.len == k2.len) {//长度相同，逐级比较
		for (int i = 0; i < k2.len; i++) {
			if (k1.data[i] < k2.data[i]) {
				temp = k1;
				k1 = k2;
				k2 = temp;
				break;
			}
		}
	}
}



void Add_Unsigned(SqList k1, SqList k2, SqList& k3) {

	int i = 0, j= 0;
	int result = 0;//结果数
	int carry = 0;//进位数
	int k = MAX_SIZE-1;
	for (i = k1.len - 1,j = k2.len-1; j >= 0; i--,j--) {
		int a = k1.data[i] - '0';
		int b = k2.data[j] - '0';

		result = (carry + a + b);//该位的结果
		carry = 0;//进位置0
		k3.data[k--] = result % 10 + '0';
		carry = result / 10;//产生的进位
	}

	for (i; i >= 0; i--) {//处理余项
		int a = k1.data[i] - '0';
		int b = 0;
		
		result = (carry + a + b);//该位的结果
		carry = 0;//进位置0
		k3.data[k--] = result % 10 + '0';
		carry = result / 10;//产生的进位
	}


	while (carry != 0) {//处理余项产生的进位
		k3.data[k--] = carry % 10 + '0';
		carry = carry / 10;
	}
	k++;
	k3.len = k;
}

void Sub_Unsigned(SqList k1, SqList k2, SqList& k3) {

	int i = 0, j = 0;
	int result = 0;//结果数
	int carry = 0;//借位数
	int k = MAX_SIZE - 1;
	for (i = k1.len - 1, j = k2.len - 1; j >= 0; i--, j--) {
		int a = k1.data[i] - '0';
		int b = k2.data[j] - '0';

		result = (a - b - carry);//该位的结果

		if (result < 0) {
			result = (10 + a - b - carry);
			carry = 1;
		}
		else
			carry = 0;//借位置0

		k3.data[k--] = result + '0';
	}

	for (i; i >= 0; i--) {//处理余项
		int a = k1.data[i] - '0';
		int b = 0;

		result = (a - b - carry);//该位的结果

		if (result < 0) {
			result = (10 + a - b - carry);
			carry = 1;
		}
		else
			carry = 0;//借位置0

		k3.data[k--] = result + '0';
	}

	k++;
	
	//去掉多余的零位
	for (k; k < MAX_SIZE - 1; k++) {
		if (k3.data[k] != '0')
			break;
	}

	k3.len = k;
}

void Add(SqList k1, SqList k2, SqList& k3) {
	swap(k1, k2);
	if (k1.symbol == k2.symbol) {
		k3.symbol = k1.symbol;
		Add_Unsigned(k1, k2, k3);
	}
	else {
		k3.symbol = k1.symbol;
		Sub_Unsigned(k1, k2, k3);
	}
}


void Output(SqList k) {//结果输出
	if (k.symbol == '-')
		cout << k.symbol;
	for (int i = k.len; i < MAX_SIZE; i++) {
		cout << k.data[i] - '0';
	}
}

int main() {
	SqList k1,k2,k3;//k3为结果数
	CreatList(k1);
	CreatList(k2);
	Add(k1, k2, k3);
	Output(k3);
	return 0;
}