/*
������������
	���һ��ʵ�����ⳤ���������мӷ��������ʾ����
������Ҫ��
	����˫��ѭ������ʵ�ֳ������Ĵ洢��ÿ����㺬һ�����ͱ������κ����ͱ����ķ�
	Χ��-(2^15-1)~(2^15-1)������������ʽ�����й����ڳ������ı�ʾϰ�ߣ�ÿ��λһ
	�飬����ö��Ÿ�����
���������ݡ�
	��1��0��0��Ӧ�����0����
	��2��-2345��6789��-7654��3211��Ӧ�����-1��0000��0000����
	��3��-9999��9999��1��0000��0000��0000��Ӧ�����9999��0000��0001����
	��4��1��0001��0001��һ1��0001��0001��Ӧ�����0����
	��5��1��0001��0001��-1��0001��0000��Ӧ�����1����
	��6��-9999��9999��9999��-9999��9999��9999��Ӧ�����һ1��9999��9999��9998����
	��7��1��0000��9999��9999��1��Ӧ�����1��0001��0000��0000����
��ʵ����ʾ��
	��1��ÿ������п��Դ�ŵ��������Ϊ215-1=32767�����ܱ�֤������Ӳ�����
	��������������ţ����൱�ڰ�32768��������ţ���ʮ��������32768������֮���ת
	��ʮ�ֲ����㡣�ʿ�����ÿ������н���ʮ��������4λ����������9999�ķǸ���������
	�������ʾΪ���������
	��2)��������ͷ���������ķ��Ŵ��������ķ��š���ӹ����в�Ҫ�ƻ�������
	�����������ܸ�������λ���涨���ޡ�
��ѡ�����ݡ�
	��1��ʵ�ֳ��������������㣻
	��2��ʵ�ֳ������ĳ˷��ͽ׳����㣻
	��3����������Χ��-(2^n-1)��(2^n-1)�����У�n���ɳ������Ĳ������������ݵķ�
	�鷽���������й涨��
*/

//Ŀǰֻ����˼ӷ�


#include<iostream>
using namespace std;
#define MAX_SIZE 10000


typedef struct SqList{
	char symbol;//����
	char* data = new char[MAX_SIZE];//��
	int len;//���ĳ���
}SqList;


void CreatList(SqList& k) {//����������
	cout << "����һ��������" << endl;
	char d[MAX_SIZE] = { 0 };
	cin >> d;
	if (d[0] == '-') {//ȥ�����ķ���
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

void swap(SqList& k1, SqList& k2) {//k1Ϊ�ϴ������k2Ϊ��С����(��������)
	SqList temp;
	if (k1.len < k2.len) {
		temp = k1;
		k1 = k2;
		k2 = temp;
	}
	if (k1.len == k2.len) {//������ͬ���𼶱Ƚ�
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
	int result = 0;//�����
	int carry = 0;//��λ��
	int k = MAX_SIZE-1;
	for (i = k1.len - 1,j = k2.len-1; j >= 0; i--,j--) {
		int a = k1.data[i] - '0';
		int b = k2.data[j] - '0';

		result = (carry + a + b);//��λ�Ľ��
		carry = 0;//��λ��0
		k3.data[k--] = result % 10 + '0';
		carry = result / 10;//�����Ľ�λ
	}

	for (i; i >= 0; i--) {//��������
		int a = k1.data[i] - '0';
		int b = 0;
		
		result = (carry + a + b);//��λ�Ľ��
		carry = 0;//��λ��0
		k3.data[k--] = result % 10 + '0';
		carry = result / 10;//�����Ľ�λ
	}


	while (carry != 0) {//������������Ľ�λ
		k3.data[k--] = carry % 10 + '0';
		carry = carry / 10;
	}
	k++;
	k3.len = k;
}

void Sub_Unsigned(SqList k1, SqList k2, SqList& k3) {

	int i = 0, j = 0;
	int result = 0;//�����
	int carry = 0;//��λ��
	int k = MAX_SIZE - 1;
	for (i = k1.len - 1, j = k2.len - 1; j >= 0; i--, j--) {
		int a = k1.data[i] - '0';
		int b = k2.data[j] - '0';

		result = (a - b - carry);//��λ�Ľ��

		if (result < 0) {
			result = (10 + a - b - carry);
			carry = 1;
		}
		else
			carry = 0;//��λ��0

		k3.data[k--] = result + '0';
	}

	for (i; i >= 0; i--) {//��������
		int a = k1.data[i] - '0';
		int b = 0;

		result = (a - b - carry);//��λ�Ľ��

		if (result < 0) {
			result = (10 + a - b - carry);
			carry = 1;
		}
		else
			carry = 0;//��λ��0

		k3.data[k--] = result + '0';
	}

	k++;
	
	//ȥ���������λ
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


void Output(SqList k) {//������
	if (k.symbol == '-')
		cout << k.symbol;
	for (int i = k.len; i < MAX_SIZE; i++) {
		cout << k.data[i] - '0';
	}
}

int main() {
	SqList k1,k2,k3;//k3Ϊ�����
	CreatList(k1);
	CreatList(k2);
	Add(k1, k2, k3);
	Output(k3);
	return 0;
}