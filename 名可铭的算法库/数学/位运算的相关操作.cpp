#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

bool isPowerOf2 (int num) {
	//�ж�һ�����Ƿ���2�ķǸ��������� 
	return (num > 0) && !(num & (num - 1));
}

bool modPowerOf2 (int num, int mod) {
	//��2�ķǸ���������ȡģ 
	return num & (mod - 1);
} 

bool Abs (int num) {
	//���ܻ����Ŀ���� 
	return (num ^ (num >> 31) - (num >> 31));
}

bool isSameSign (int x, int y) {
	//���ܻ����Ŀ���� 
	return (x ^ y) >= 0;
} 

int Bigger (int a, int b) {
	//���ܻ����Ŀ���� 
	return b & ((a - b) >> 31) | a & (~(a - b) >> 31);
}

int Smaller (int a, int b) {
	//���ܻ����Ŀ����
	return a & ((a - b) >> 31) + b & (~(a - b) >> 31);
} 

int getBit (int num, int digit) {
	//��ȡ num �ĵ� digit ��λ 
	return (num >> (digit - 1)) & 1;
}

int set0 (int num, int digit) {
	//�� num �ĵ� digit ��λ����Ϊ0 
	return num & ~(1 << (digit - 1)); 
}

int set1 (int num, int digit) {
	//�� num �ĵ� digit ��λ����Ϊ1 
	return num | (1 << (digit - 1));
} 

int flapBit (int num, int digit) {
	//�� num �ĵ� digit ��λȡ��
	return num ^ (1 << (digit - 1)); 
} 

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cout << ~0 << endl;
	return 0;
}
