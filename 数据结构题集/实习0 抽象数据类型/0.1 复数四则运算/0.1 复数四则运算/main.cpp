/*
* ����������
*	���һ���ɽ��и����������ʾ����
* 
* ����Ҫ��
*	ʵ���������ֻ������㣺
*		1.�������ʵ�����鲿����һ��������
*		2.����������ͣ�
*		3.����������
*		4.�������������
*		5.����֪�����з����ʵ����
*		6.����֪�����з�����鲿��
*	����������Ӧ�ĸ�����ʵ���ı�ʾ��ʽ��ʾ��
* ��������
* 
*	�����и�����ʵ����͡�
*		��1��0��0��Ӧ�����0��
*		��2��3.1��0��4.22.8.9��Ӧ�����7.32+i8.9��
*		��3��-1.33��2.34��0.1��-6.5��Ӧ�����-1.23-i4.16��
*		��4��0.9.7��-2.1��-9.7��Ӧ�����-2.1��
*		��5��7.7��-8��-7.7��0��Ӧ�����-i8��
* 
* ʵ����ʾ
*	���帴��Ϊ�������໥֮����ڴ����ϵ��ʵ�����ɵĳ����������ͣ����������ʵ���Ĳ�����ʵ�ָ����Ĳ�����
* 
*ѡ������
* ʵ�ָ������������㣬�磺�����������������ȡ�
*/

#include<iostream>
using namespace std;

//���帴���ṹ
typedef struct complex_number{
	double Real;
	double Imaginary;
}plural;

//��������
void output(plural n);//���
void add(plural a, plural b);//�����������
void sub(plural a, plural b);//�����������
void mul(plural a, plural b);//�����������
void div(plural a, plural b);//������������
void real(plural n);//����֪�����з����ʵ��
void imaginary(plural n);//����֪�����з�����鲿
void conjugate(plural n);//����

/***************************************************/
int main() {
	//�ֶ��������븴��

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

//���
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

//�����������
void add(plural a, plural b) {
	plural c;
	c.Real = a.Real + b.Real;
	c.Imaginary = a.Imaginary + b.Imaginary;
	output(c);
}

//�����������
void sub(plural a, plural b) {
	plural c;
	c.Real = a.Real - b.Real;
	c.Imaginary = a.Imaginary - b.Imaginary;
	output(c);
}

//�����������
void mul(plural a, plural b) {
	plural c;
	c.Real = (a.Real * b.Real - a.Imaginary * b.Imaginary);
	c.Imaginary = (a.Real * b.Imaginary + a.Imaginary * b.Real);
	output(c);
}

//������������
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

//����֪�����з����ʵ��
void real(plural n) {
	cout << n.Real << endl;
}

//����֪�����з�����鲿
void imaginary(plural n) {
	cout << n.Imaginary << endl;
}

//����
void conjugate(plural n) {
	n.Imaginary = -n.Imaginary;
	output(n);
}
