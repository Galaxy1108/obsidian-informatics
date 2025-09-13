#include <bits/stdc++.h>
#define N 2000006
using namespace std;
int n,lk,rk,x,y,q;
char a[N];
int f[N],s[N],siz[N]; 

int get(int p)
{
	return p==f[p]?p:f[p]=get(f[p]);
}

int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>lk>>rk;
	cin>>a+1;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[i]=='a'),f[i]=i,siz[i]=1;
	for(int i=1;i<=n;i++)
	{
		int st=lower_bound(s+1,s+1+n,lk+s[i-1])-s;
		for(int j=st;s[j]-s[i-1]<=rk && j<=n;j++)
		{
			int fi=get(i),fj=get(j);
			if(fi==fj)continue;
			if(siz[fi]>siz[fj])swap(fi,fj);
			f[fi]=fj;
			siz[fj]+=siz[fi];
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		if(get(x)==get(y))puts("Yes");
		else puts("No");
	}
	return 0;
}
