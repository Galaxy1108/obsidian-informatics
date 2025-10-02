#include<bits/stdc++.h>

using namespace std;
const int mx=1e6+10;
int n,k;

struct snk
{
	int a,id;
}s1[mx],s2[mx];
bool cmp(snk x,snk y)
{
	if(x.a==y.a) return x.id<y.id;
	return x.a<y.a;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	cin>>T;
	int rnd=T;
	while(rnd--)
	{
		cin>>n;
		if(rnd==T)
		{
			for(int i=1;i<=n;i++) 
			{
				cin>>s1[i].a,s1[i].id=i;
				s2[i]=s1[i];
			}
		} 
		else 
		{
			cin>>k;
			for(int i=1;i<=k;i++)
			{
				int x,y;
				cin>>x>>y;
				s2[x].a=y;
			}
		}
		sort(s2+1,s2+1+n,cmp);
		if(s2[3].a-s2[1].a>=s2[2].a&&s2[3].id>s2[2].id) cout<<1<<endl;
		else cout<<3<<endl;
	}
	


	return 0;
} 
