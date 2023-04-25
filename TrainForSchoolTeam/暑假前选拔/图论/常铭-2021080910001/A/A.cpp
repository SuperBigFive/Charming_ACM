#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
const int maxn=300+5;
const int inf=9999999;

int n,m,min_cut=inf;
int map[maxn][maxn],dist[maxn];//�ڽӾ��󣬴洢��������֮��ı���;dist���漯��A����㵽����A����С�� 
bool vis[maxn],combine[maxn];//vis�����ж�ÿ��ѭ���ж��Ƿ��Ѿ����ʹ�;combine�����жϸõ��Ƿ��Ѿ����ںϲ�

void SW(); //�����ѭ��ÿѭ��һ��ȥ��һ���㣬һ��n���㣬����Ҫѭ��n-1�� 
		   //�����ѭ����Ƕ���������ڲ�ѭ�����ֱ������ر����ıߡ��ϲ���һ���Ӽ���ע����Ӧ�ĵ�ͱߵı仯���������ؽ������㣨��㼯������һ�� 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		++map[u][v];
		++map[v][u];
	}
	SW();
	printf("%d",min_cut%10000);
	return 0;
}

void SW(){
	int s,t,max,max_v;
	for(int i=1;i<n;++i){
		memset(vis,false,sizeof vis);
		memset(dist,0,sizeof dist);
		s=t=0;
		for(int j=1;j<=n-i+1;++j){
			s=t;
			t=0;
			max=0;
			max_v=0;
			for(int k=1;k<=n;++k){
				if(!vis[k]&&!combine[k]){
					if(dist[k]>max||!max_v){
						max=dist[k];
						max_v=k;
					}
				}
			}
			t=max_v;
			vis[t]=true;
			for(int k=1;k<=n;++k){
				if(!combine[k]&&!vis[k])
					dist[k]+=map[t][k];
			}
		}
		if(min_cut>dist[t]) 
			min_cut=dist[t];
		combine[s]=1;
		for(int j=1;j<=n;++j){
				map[t][j]+=map[s][j];
				map[j][t]+=map[j][s];
		}
	}
}
