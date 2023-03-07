#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
int arr[maxn];
bool vis[maxn];

void init () {
	for (int i = 1; i <= n; ++i)
	vis[i] = false;	
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] == i) vis[i] = true;
	}
	
	//�Ƿ���ڴ��� 
	bool ok1 = true;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			ok1 = false;
			break;
		}
	}
	if (ok1) {
		cout << 0 << endl;
		return;
	}
	
	//ȷ����β[beg, endd]
	int beg = 1, endd = n;
	while (vis[beg]) ++beg;
	while (vis[endd]) --endd;
	
	//��������ȫ����һ�ξͿ�
	bool ok2 = true;
	for (int i = beg; i <= endd; ++i) {
		if (vis[i]) {
			ok2 = false;
			break;
		}
	} 
	if (ok2) {
		cout << 1 << endl;
		return;
	}//������Σ����ֻ������ 
	else cout << 2 << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
} 
