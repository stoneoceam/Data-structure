/*
* 问题描述：
*	设计一个可进行复数运算的演示程序。
* 
* 基本要求：
*	实现下列六种基本运算：
*		1.由输入的实部和虚部生成一个复数；
*		2.两个复数求和；
*		3.两个复数求差；
*		4.两个复数求积；
*		5.从已知复数中分离出实部；
*		6.从已知复数中分离出虚部；
*	运算结果以相应的复数或实数的表示形式显示。
* 测试数据
* 
*	对下列各数据实现求和。
*		（1）0；0；应输出“0”
*		（2）3.1，0；4.22.8.9；应输出“7.32+i8.9”
*		（3）-1.33，2.34；0.1，-6.5；应输出“-1.23-i4.16”
*		（4）0.9.7；-2.1，-9.7；应输出“-2.1”
*		（5）7.7，-8；-7.7，0；应输出“-i8”
* 
* 实现提示
*	定义复数为由两个相互之间存在次序关系的实数构成的抽象数据类型，则可以利用实数的操作来实现复数的操作。
* 
*选做内容
* 实现复数的其他运算，如：两个复数相除、求共轭等。
*/

#include<iostream>
using namespace std;

//定义复数结构
typedef struct complex_number{
	double Real;
	double Imaginary;
}plural;

//基本操作
void output(plural n);//输出
void add(plural a, plural b);//两个复数求和
void sub(plural a, plural b);//两个复数求差
void mul(plural a, plural b);//两个复数求积
void div(plural a, plural b);//两个复数求商
void real(plural n);//从已知复数中分离出实部
void imaginary(plural n);//从已知复数中分离出虚部
void conjugate(plural n);//求共轭

/***************************************************/
int main() {
	//手动创建输入复数

	plural a,b;
	a.Real = -1.33;
	a.Imaginary = 2.34;
	b.Real = 0.1;
	b.Imaginary = -6.5;
	div(a, b);
	conjugate(a);
	imaginary(a);

	return 0;
}
/*******************************************************/

//输出
void output(plural n) {
	if (n.Real == 0 && n.Imaginary == 0) {
		cout << "0";
	}
	else {
		if (n.Real != 0)
			cout << n.Real;
		if (n.Imaginary != 0) {
			if (n.Imaginary > 0) {
				cout << "+i" << n.Imaginary;
			}
			else {
				cout << "-i" << -n.Imaginary;
			}
		}
	}
	cout << endl;
}

//两个复数求和
void add(plural a, plural b) {
	plural c;
	c.Real = a.Real + b.Real;
	c.Imaginary = a.Imaginary + b.Imaginary;
	output(c);
}

//两个复数求差
void sub(plural a, plural b) {
	plural c;
	c.Real = a.Real - b.Real;
	c.Imaginary = a.Imaginary - b.Imaginary;
	output(c);
}

//两个复数求积
void mul(plural a, plural b) {
	plural c;
	c.Real = (a.Real * b.Real - a.Imaginary * b.Imaginary);
	c.Imaginary = (a.Real * b.Imaginary + a.Imaginary * b.Real);
	output(c);
}

//两个复数求商
void div(plural a, plural b) {
	plural c;
	double i;
	i = b.Real * b.Real + b.Imaginary * b.Imaginary;
	if (i) {
		c.Real = (a.Real * b.Real + a.Imaginary * b.Imaginary) / i;
		c.Imaginary = (a.Imaginary * b.Real - a.Real * b.Imaginary) / i;
		output(c);
	}

}

//从已知复数中分离出实部
void real(plural n) {
	cout << n.Real << endl;
}

//从已知复数中分离出虚部
void imaginary(plural n) {
	cout << n.Imaginary << endl;
}

//求共轭
void conjugate(plural n) {
	n.Imaginary = -n.Imaginary;
	output(n);
}
