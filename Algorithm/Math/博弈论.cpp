#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

namespace Game_theoty {
	/*��������������ʲ���ġ�����������
		n ����Ʒ�������������ȡ
		����ȡ 1 �������ȡ m ��
		���ڸ����� n �� m
		���� win or lose��
		�������� 0 ��ʼ���˵���
		ͨ���ܷ�ת�Ƶ���һ�� lose״̬ 
		�жϵ�ǰ������Ʒ win or lose
		���磺0(l) 1 ~ m(w) m + 1(l)
		m + 2 ~ 2*m + 1(w) 2*m + 2(l)
		����������������������������
		���Է��֣��� n Ϊ m + 1 ��
		������ʱ�����ֱذ�*/
	void Bash_game () {
		int n, m;
		cin >> n >> m;
		if (n % (m + 1))  cout << "Win" << endl;
		else cout << "Lose" << endl; 
	} 
	//��������������������������������//
	
	/*���������������ġ��������������� 
		������ʯ�ӣ�ʯ�������Բ�ͬ��
		��������ȡʯ�ӣ�
		ÿ�ο�����һ����ȡ��
		���ߴ�������ȡ����ͬ������ʯ�ӣ�
		�������ޣ�ȡ�����һ��ʯͷ���˻�ʤ��
		�ж������Ƿ��ʤ��
		���ۣ���������ʯ��Ϊ (a , b)������ a < b��
		���ֱذܣ����ҽ���
		(b - a) * (sqrt (5.0) + 1.0) / 2 == a*/
	void Wythoff_game () {
		int a, b;
		cin >> a >> b;
		if (a > b) swap (a, b);
		if (((b - a) * ((sqrt (5.0)) + 1.0) / 2) == a) cout << "Lose" << endl;
		else cout << "Win" << endl;
	}
	//��������������������������������//
	
	/*������������Nim��Ϸ������������
	*/ 
}

void charming () {
	
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
}
