#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    { 
        if (ch == '-') w = -1; 
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0'); 
        ch = getchar();
    }
    return x * w; 
}
int a[500005];
int b[1000005];
struct node
{
	int l,r,c,id;
}th[500005];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int ans[500005];
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	if(n<=10005 and m<=10005)
	{
		for(int i=1;i<=m;i++)
		{
			int l,r,c;
			l=read(),r=read(),c=read();
			for(int j=l;j<=r;j++)
			{
				if(c<a[j]) c++;
				else if(c>a[j])c--;
			}
			cout<<c<<'\n'; 
		}
	}
	else
	{
		int maxc=-1;
		for(int i=1;i<=m;i++)
		{
			th[i].l=read();
			th[i].r=read();
			th[i].c=read();
			th[i].id=i;
			maxc=max(th[i].c,maxc);
		}
		for(int i=0;i<=maxc;i++)
		{
			b[i]=i; 
		} 
		sort(th+1,th+m+1,cmp);
		int lr=1;
		for(int i=1;i<=m;i++)
		{
			int r=th[i].r;
			while(lr<r)
			{
				for(int j=0;j<=maxc;j++)
				{
					if(b[j]<a[lr])
					{
						b[j]++;
					}
					else
					{
						b[j]--;
					}
				}
				lr++;
			}
			ans[th[i].id]=b[th[i].c];
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<'\n'; 
		}
	}
	return 0;
} 
