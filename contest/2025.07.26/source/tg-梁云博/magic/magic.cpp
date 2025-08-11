#include <bits/stdc++.h> 
#define N 200005
using namespace std;
int n,q;
int p[N][2];
struct Q
{
	int t,i,ans,idx;
}req[1000007];
bool cmp(Q a,Q b)
{
	if(a.t==b.t)return a.i<b.i;
	else return a.t<b.t;
}
bool cx(Q a,Q b)
{
	return a.idx<b.idx;
}
bool ist(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(i!=p[i][x])return false;
	}
	return true;
}
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(register int i=1;i<=n;i++)
	{
		cin>>p[i][0];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>req[i].t>>req[i].i;
		req[i].idx=i;
	}
	sort(req+1,req+1+q,cmp);
	int tt=0,flg=1;//当前洗好牌的轮次 ,shifouquanyouxu
	for(int i=1;i<=q;i++)
	{
		while(tt<req[i].t && flg)
		{
			int li=1,ri=1+n/2,tot=0,sf=1;
			while(li<=n/2 && ri<=n)
			{
				if(p[li][tt&1]>p[ri][tt&1])
				{
					p[++tot][(tt+1)&1]=p[ri][tt&1];
					ri++;
				}
				else
				{
					p[++tot][(tt+1)&1]=p[li][tt&1];
					li++;
				}
				if(p[tot][1]!=p[tot][0])sf=0;
			}
			while(li<=n/2)
			{
				p[++tot][(tt+1)&1]=p[li][tt&1];
				li++;
				if(p[tot][1]!=p[tot][0])sf=0;
			}
			while(ri<=n)
			{
				p[++tot][(tt+1)&1]=p[ri][tt&1];
				ri++;
				if(p[tot][1]!=p[tot][0])sf=0;
			}
			tt++;
			if(sf)flg=0;
		}
		req[i].ans=p[req[i].i][tt&1];
	}
	sort(req+1,req+1+q,cx);
	for(int i=1;i<=q;i++)cout<<req[i].ans<<"\n";
	return 0;
}
