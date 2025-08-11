#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5,Q=1e6+5;
int n,q;
int a[N],a1[N];
struct node{
	int t,k,id;
}s[Q];
int ans[Q];
int b1[N],b2[N];
int cnt;
bool fl;
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=q;i++)
		cin>>s[i].t>>s[i].k,s[i].id=i;
	sort(s+1,s+1+q,[](node x,node y){return x.t<y.t;});
	int id=1;
	while(id<=q && !s[id].t)
		ans[s[id].id]=a[s[id].k],id++;
	cnt=1;
	while("Íõº­AKIOI" && id<=q)
	{
		int mid=n/2;
		for(int i=1;i<=mid;i++)
			b1[i]=a[i],b2[i+mid]=a[i+mid];
		int l=1,r=mid+1,now=0;
		while(l<=mid && r<=n)
		{
			a1[++now]=min(b1[l],b2[r]);
			if(b1[l]<b2[r])
				l++;
			else
				r++;
		}
		while(l<=mid)
			a1[++now]=b1[l++];
		while(r<=n)
			a1[++now]=b2[r++];
		fl=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a1[i])
				fl=0;
			a[i]=a1[i];
		}
		while(id<=q && s[id].t==cnt)
			ans[s[id].id]=a[s[id].k],id++;
		if(fl)break;
		cnt++;
	}
	if(fl)
		while(id<=q)ans[s[id].id]=a[s[id].k],id++;
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	return 0;
} 
