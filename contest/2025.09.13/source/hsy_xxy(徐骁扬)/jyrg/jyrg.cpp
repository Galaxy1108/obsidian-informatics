#include <bits/stdc++.h>
using namespace std;
long long Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x; 
}
typedef pair<int,int> pr;
const long long inf=3e18;
int T,n,i;
long long a[100010];
long long ans;
int tim[110];
bool chk()
{
	for(int i=1;i<n;i++)
		if(a[i]<a[i+1])
			return false;
	return true;
}
void solve(int dep,int las,long long minn)
{
	if(dep>=40) return;
	if(chk()) return ans=min(ans,minn),void();
	pr f[10];
	for(int i=1;i<n;i++)
		f[i].first=tim[i],f[i].second=i;
	sort(f+1,f+n);
	for(int i=1;i<n;i++)
	{
		if(i==las) continue;
		swap(a[i],a[i+1]),a[i]--,a[i+1]++,tim[i]++;
		solve(dep+1,i,max(minn,a[i]+a[i+1]));
		swap(a[i],a[i+1]),a[i]--,a[i+1]++,tim[i]--;
	}
	return;
}
int main()
{
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	T=Qread();
	while(T--)
	{
		n=Qread();
		for(i=1;i<=n;i++)
			a[i]=Qread();
		if(chk()) printf("0\n");
		else if(n>8) printf("-1\n");
		else
		{
			ans=inf;
			solve(0,0,0);
			if(ans==inf) printf("-1\n");
			else printf("%lld\n",ans);
		}
	}
	return 0;
}