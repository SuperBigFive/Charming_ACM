#include <bits/stdc++.h>
#define ll long long
#define len n+m+2
using namespace std;
const int maxn = 4e5 + 5;
const int maxm = 4e5 + 5;

int n, m, pow2, tot, cnt;
int sa[maxn], tmp_sa[maxn], rk[maxn<<1], tmp_rk[maxn<<1], bowl[maxn<<1];
int arr1[maxn], arr2[maxn], arr[maxn]; 

void _input () {
	cin >> n;
	cnt = 0;
	for (int i = 1; i <= n; ++i) cin >> arr1[i];
	arr1[n+1] = maxm;
	cin >> m;
	for (int i = 1; i <= m; ++i) cin >> arr2[i];
	arr2[m+1] = maxm;
	for (int i = 1; i <= n + 1; ++i) arr[i] = arr1[i];
	for (int i = n + 2; i <= n + 1 + m + 1; ++i) arr[i] = arr2[i-n-1];
}

void _output () {
	int p1 = 1, p2 = n + 2;
	while (p1 <= n && p2 < len) {
		if (rk[p1] < rk[p2]) cout << arr1[p1++] << " ";
		else cout << arr2[p2-n-1] << " ", ++p2;
	}
	while (p1 <= n) cout << arr1[p1++] << " ";
	while (p2 <= n + m + 1) cout << arr2[p2-n-1] << " ", ++p2;
}

bool _cmp (int a, int b) {
	if (rk[a] < rk[b]) return true;
	if (rk[a] > rk[b]) return false;
	if (rk[a+pow2] <= rk[b+pow2]) return true;
	return false;
}

void _updata (int num) {
	if (tmp_rk[sa[num]] == tmp_rk[sa[num-1]]&&
		tmp_rk[sa[num] + pow2] == tmp_rk[sa[num-1] + pow2] ) {
			rk[sa[num]] = tot;
			++cnt;
		}
	else rk[sa[num]] = ++tot;
}

void key2_sort () {
	int ccnt = 0;
	for (int i = len; i > len - pow2; --i) tmp_sa[++ccnt] = i;
	for (int i = 1; i <= len; ++i) {
		if (sa[i] > pow2) tmp_sa[++ccnt] = sa[i] - pow2;
	}
	for (int i = 1; i <= maxm; ++i) bowl[i] = 0;
}

void key1_sort () {
	//����tmp_sa[i]�ĺ��壺
	//���յڶ��ؼ������������Ϊi���ַ���ԭ�ִ���λ�� 
	//rk[tmp_sa[i]]��ʾ�����յڶ��ؼ������������Ϊi���ַ�
	//��������ַ�������ԭ�ִ�������
	//���ǱȽϵ�һ�ؼ��֡�һ��Ҫ��С����ö��
	//����һ��������һ�ؼ�����ͬ���ڶ��ؼ��ֲ�ͬ���ִ����ַ��ԣ���αȽϣ� 
	for (int i = 1; i <= len; ++i) ++bowl[rk[tmp_sa[i]]];
	for (int i = 1; i <= maxm; ++i) 
		bowl[i] = bowl[i] + bowl[i-1];
	//����ҲҪ������ͬ�ִ���ʼλ��Խ������������Ӧ��Խ��ǰ 
	for (int i = len; i >= 1; --i) {
		int end_pos = bowl[rk[tmp_sa[i]]]--;
		sa[end_pos] = tmp_sa[i];
	}
}

void _charming () {
	_input ();
	for (int i = 1; i <= len; ++i) sa[i] = i, rk[i] = arr[i], ++bowl[rk[i]];
	for (int i = 1; i <= maxm; ++i) bowl[i] += bowl[i-1];
	for (int i = len; i >= 1; --i) {
		int end_pos = bowl[rk[i]]--;
		sa[end_pos] = i; 
	}
	//sort (sa + 1, sa + 1 + len, _cmp);
	for (pow2 = 1; pow2 < len; pow2 = pow2 << 1) {
		key2_sort ();
		key1_sort ();
		memcpy (tmp_rk, rk, sizeof tmp_rk);
		tot = 0;
		for (int i = 1; i <= len; ++i) _updata (i);
		if (tot == len) {
			for (int i = 1; i <= n; ++i) sa[rk[i]] = i;
			break;
		}
	}
	_output();
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	_charming();
	return 0;
}
