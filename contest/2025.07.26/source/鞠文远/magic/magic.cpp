#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct qust{int id,t,num;}qus[N];
int n,ary[N],arb[N],anslt[N],slt[N];
inline bool cmp(qust a,qust b){return a.t<b.t;}
inline bool mer()
{
	int mid=n>>1; 
	int a=1,b=mid+1;
	int cnt=0;
	while(a!=mid+1&&b!=n+1)
	{
		arb[++cnt]=min(ary[a],ary[b]);
		if(ary[a]>ary[b])++b;
		else ++a;
	}
	while(a!=mid+1)arb[++cnt]=ary[a++];
	while(b!=n+1)arb[++cnt]=ary[b++];
	bool pd=false;
	for(register int i=1;i<=n;++i)
	{
		if(ary[i]!=arb[i])
		{
			pd=true;
			break;
		}
	}
	for(register int i=1;i<=n;++i)ary[i]=arb[i];
	return pd;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>n>>q;
	for(register int i=1;i<=n;++i)
	{
		cin>>ary[i];
		slt[i]=ary[i];
	}
	for(register int i=1;i<=q;++i)
	{
		cin>>qus[i].t>>qus[i].num;
		qus[i].id=i;
	}
	sort(qus+1,qus+1+q,cmp);
	int res=0,qcnt=0;
	for(register int i=1;true;++i)
	{
		while(qus[++qcnt].t==res)anslt[qus[i].id]=ary[qus[i].num];
		bool s=mer();
		if(!s)break;
		++res;
	}
	++qcnt;
	for(register int i=qcnt;i<=q;++i)anslt[qus[i].id]=ary[qus[i].num];
	for(register int i=1;i<=q;++i)cout<<anslt[i]<<"\n";

	return 0;
} 
