#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
const int N=1e5+2e4+3;
struct G
{
	int a,b;
}a[2*N];
struct R
{
	int s,t;
}b[N];
int c[N];
bool cmp(G x,G y)
{
	return x.a<y.a;
}
bool cmp2(R x,R y)
{
	return x.s<y.s;
}
//void dij(int x,int y)
//{
//	queue<int> Q;
//	int i,j,t=1;
//	for(i=c[x];i<c[x+1];++i) Q.push(a[i].b);
//	Q.push(99898899);
//	while(!Q.empty())
//	{
//		int q=Q.front();
//		Q.pop();
//		if(q==99898899)
//		{
//			++t;
//			Q.push(99898899);
//		}
//		if(q==y)
//		{
//			return 
//		}
//	}
//}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	int T=read(),n,m,i,j;
	while(T--)
	{
		n=read();
		bool f=true;
		for(i=1;i<=n-1;++i)
		{
			a[2*i].a=a[2*i-1].b=read();
			a[2*i-1].a=a[2*i].b=read();
			if(a[2*i].a!=i||a[2*i].b!=i+1) f=false;
		}
		m=read();
		for(i=1;i<=m;++i)
		{
			b[i].s=read();
			b[i].t=read();
		}
		if(f)
		{
			sort(b+1,b+m+1,cmp2);
			for(i=1;i<=m;++i)
			{
				for(j=i+1;j<=m;++j)
				{
					if(b[i].t>b[j].t)
					{
						cout<<"No\n";
						f=false;
						break;
					}
				}
				if(!f) break;
			}
			if(f) cout<<"Yes\n";
			continue;
		}
		cout<<"Yes\n";
//		sort(a+1,a+n+n+1,cmp);
//		for(i=1;i<=2*n;++i) if(a[i].a!=a[i-1].a) c[a[i].a]=i;
//		
	}
}
