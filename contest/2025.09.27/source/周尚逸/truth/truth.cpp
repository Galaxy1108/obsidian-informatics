#include<bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x=0; char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x;
}
int n,k,m;
int a[500005];
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	n=rd();
	k=rd();
	m=rd();
	for(int i=1;i<=n;i++)
	{
		a[i]=rd();
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		x=rd();
		if(x==1)
		{
			y=rd();
			z=rd();
			a[y]=z;
		}
		else
		{
			int ans=500005;
			int cnt=0;
			int b=1;
			int fufu[31]={0};
			for(int j=1;j<=n;j++)
			{
				if(fufu[a[j]]==0)cnt++;
				fufu[a[j]]++;
				while(fufu[a[b]]>1)b++;
				if(cnt==k)ans=min(ans,j-b+1);
			}
			if(ans==500005)cout<<-1<<endl;
			else cout<<ans<<endl;
		}
	}
	return 0;
}
