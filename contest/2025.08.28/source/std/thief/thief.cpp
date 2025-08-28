#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
namespace BIT{
	const int n=2000000;
	int num[2000010];
	void init()
	{
		for(int i=1;i<=n;i++)
			num[i]=i&-i;
	}
	int get_kth(int x)
	{
		int cur=0;
		for(int i=1<<20;i;i>>=1)
			if(cur+i<=n&&x>num[cur+i])
				x-=num[cur+=i];
		return cur+1;
	}
	void del(int x){for(;x<=n;x+=(x&-x)) num[x]--;}
	int sum(int x){int ret=0;for(;x;x-=(x&-x)) ret+=num[x];return ret;}
}
int n,m,bas=-500000;
int a[500010];
int l[500010],r[500010],c[500010],id[500010];
int ans[500010];
vector<int> gid[500010],qry[500010];
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	
	BIT::init();
	n=Qread(),m=Qread();
	for(int i=1;i<=n;i++) a[i]=Qread();
	for(int i=1;i<=m;i++)
	{
		l[i]=Qread(),r[i]=Qread(),c[i]=Qread();
		gid[l[i]].push_back(i);
		qry[r[i]].push_back(i);
	}

	for(int i=1;i<=n;i++)
	{
		for(int g:gid[i]) id[g]=BIT::get_kth(c[g]-bas);
		BIT::del(BIT::get_kth(a[i]-bas));
		BIT::del(BIT::get_kth(a[i]-bas));
		bas++;
		for(int g:qry[i]) ans[g]=BIT::sum(id[g])+bas;
	}

	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}