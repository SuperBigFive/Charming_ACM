#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	int ans = (n + k - 1) / k;
	if (k == 1) cout << n << endl;
	else cout << ans + (n % k != 1)<< endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}