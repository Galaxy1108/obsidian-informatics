#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
const int N=1e6;
struct qk{
	bool l,r;
	int len,val;
} cu;
int a[N];
int n,m,q,jcnt=0,ocnt=0,x,p,y;
bool b[N],g[N];
inline bool cmp(const qk& djb,const qk& xjb)
{
	return djb.val>xjb.val;
}
deque<qk> d;
int main()
{
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x&1)
			jcnt++;
		else
			ocnt++;
	}
	while(m--)
	{
		cin>>p>>x;
		b[p]=1;
		if(x&1)
		{
			g[p]=1;
			jcnt--;
		}
		else
			ocnt--;
	}
	while(q--)
	{
		cin>>p>>x;
		if(p==1&&b[p]==1)
		{
			b[p]=0;
			if(g[p])
				jcnt++;
			else
				ocnt++;
		}
		int cnt=0,res=0;
		for(int i=1;i<=n;i++) 
		{
			if(b[i])
			{
				cu.len=i-res-1;	
				if(cu.len>0)
				{
					if(res)
					cu.l=g[res];
					cu.r=g[i];
					if(cu.l==cu.r)
						d.push_back(cu);
				}
				res=i;
			}
			
		}
	}
	return 0;
}
