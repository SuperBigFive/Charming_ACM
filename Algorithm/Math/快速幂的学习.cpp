#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e3 + 5;

//������
ll binpow (ll num, int pow) {
	ll res = 1;
	while (pow > 0) {
		if (pow & 1) res *= num;
		num *= num;
		pow >>= 1;
	}
	return res;
}

//Ӧ��1�� ģ������ȡ��
//ȡģ�����㲻�����˷�����
ll binPowMod (ll num, int pow, int mod) {
	ll res = 1;
	num = num % mod;
	while (pow > 0) {
		if (pow & 1) res = res * num % mod;
		num = num * num % mod;
		pow >>= 1;
	}
	return res;
} 

//Ӧ��2�� ���������
int n = 10;
struct matrix {
	int mat[maxm][maxm];
}mat1, mat2, tmp_mat, res;

matrix mult (matrix a, matrix b) {
	int tmp;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			tmp = 0;
			for (int k = 1; k <= n; ++k) {
				tmp += a.mat[i][k] * b.mat[k][j];
			}
			tmp_mat.mat[i][j] = tmp;
		}
	}
	return tmp_mat;
}

matrix mat_binpow (matrix mat, int pow) {
	while (pow > 0) {
		if (pow & 1) res = mult (res, mat);
		mat = mult (mat, mat);
		pow >>= 1;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	return 0;
}
