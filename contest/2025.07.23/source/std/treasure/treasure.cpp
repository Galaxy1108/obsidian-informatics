#include <bits/stdc++.h>
#define Mod 1000000007
using namespace std;
void add(int &a,int b){a+=b;if(a>=Mod) a-=Mod;}
int n,k,st,pct[1<<10];
vector<int> val[10];
int a[210];
vector<int> typ;
int lm,bs[10],cnt[10],tot;
int f[210][6010];
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>n>>k;st=1<<k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	pct[0]=0;val[0].push_back(0);
	for(int i=1;i<st;i++)
		val[pct[i]=pct[i-(i&-i)]+1].push_back(i);

	bs[1]=1;
	for(int i=2;i<=k;i++)
		bs[i]=bs[i-1]*i%Mod;
	f[1][0]=1;lm=bs[k];

	for(int i=1,j_;i<=n;i++) for(int j=0;j<=lm;j++) if(f[i][j])
	{
		tot=cnt[0]=0;
		for(int t=1;t<k;t++)
			tot+=(cnt[t]=j/bs[t]%(t+1));

		if(tot>a[i]||tot+k<a[i]) continue;
		for(int g:val[a[i]-tot])
		{
			for(int t=0;t<k;t++) if(g&(1<<t)) cnt[t]++;
			j_=0;
			for(int t=1;t<k;t++)
				j_+=bs[t]*cnt[t-1];
			add(f[i+1][j_],f[i][j]);
			for(int t=0;t<k;t++) if(g&(1<<t)) cnt[t]--;
		}
	}

	int ans=0;
	for(int j=0;j<=lm;j++)
		add(ans,f[n+1][j]);
	cout<<ans;
	return 0;
}