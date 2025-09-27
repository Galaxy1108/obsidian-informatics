#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;

int a[MAXN];
int sum[MAXN];
int st[MAXN][20];
int cnt,N;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=1;i<=N;i++) sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=N;i++) st[i][0]=a[i];
	for(int i=1;(1<<i)<=N;i++)
		for(int j=1;j+(1<<i)-1<=N;j++)
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j++){
			int p;
			while((1<<p)<=(j-i+1)) p++;
			p--;
			int maxn=max(st[i][p],st[j-1<<p+1][p]);
			if((sum[j]^sum[i-1])<=maxn) cnt++;
		}
	}	
	
	cout<<cnt;
}
