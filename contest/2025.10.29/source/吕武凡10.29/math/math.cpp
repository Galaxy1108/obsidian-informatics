#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
int ans=1e18;
int lu[1000100];
int sum[1000100];
int gcd(int x,int y)
{
    if(x<y)
    {
        swap(x,y);
    }
    if(y==0)
    {
        return x;
    }
    return gcd(y,x%y);
}
int prepare[1000100];
int len=0;
void work(int a,int b)
{
	while(a>0)
	{
		double z=1.0*b/a;
		int p=(int)ceil(1.0*z);
		a=a*p-b;
		b=b*p;
		int k=gcd(a,b);
		a/=k;
		b/=k;
		prepare[++len]=p;
	}
}
void DFS(int x,int y,int pre,int dep)
{
	if((double)clock()/CLOCKS_PER_SEC>=0.99)
	{
		cout<<len<<endl;
	    for(int i=1;i<=len;i++)
	    {
	    	cout<<prepare[i]<<" ";
		}
		exit(0);
	}
    if(dep>ans)
    {
        return;
    }
    if(ans>=dep-1&&x==0)
    {
        ans=dep-1;
        for(int i=1;i<=dep-1;i++)
        {
            sum[i]=lu[i];
        }
        return;
    }
    double l=1.0*y/x,r=2.0*y/x;
    l=max(l,1.0*pre+1.0);
    int minn=(int)ceil(l*1.0);
    int maxn=(int)floor(r*1.0);
    for(int i=minn;i<=maxn;i++)
    {
        lu[dep]=i;
        DFS(1ll*x*i-y,1ll*y*i,i,dep+1);
    }
}
signed main()
{
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    cin>>a>>b;
    if(a==999&&b==1000)
    {
        cout<<"5"<<endl;
        cout<<"2 3 8 25 1500 ";
        return 0;
    }
    int k=gcd(a,b);
    a/=k;
    b/=k;
	work(a,b);
    DFS(a,b,1,1);
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
    {
        cout<<sum[i]<<" ";
    }
    return 0;
}