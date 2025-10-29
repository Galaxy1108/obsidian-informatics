#include <bits/stdc++.h>
using namespace std;
int dd=0,minn=1145140,xj;
int sum[114514],ans[114514];
void dfs(int a,int b,int x)
{
	if(dd>=xj or x>=minn)
	{
		return;
	}
    if(b%a==0)
	{
        b/=a;
        if (b < x || b >= minn) {
            return;
        }
        sum[dd]=b;
        minn=b;
        for(int i=0;i<=dd;i++)
        {
        	ans[i]=sum[i];
		}
        return;
    }
	else
	{
		if(dd>=xj-1)
		{
            return;
        }
        while(a*x<=b and x<=minn)
		{
            x++;
        }
        while(x<minn)
		{
            if(a*x>=b*(xj-dd))
			{
                break;
            }
            sum[dd]=x;
            dd++;
            dfs(a*x-b,b*x,x+1);
            dd--;
            x++;
        }
    }
    return;
}
int main() {
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
    int a,b;
    cin>>a>>b; 
    for(xj=1;xj<=1000000;xj++)
	{
        dfs(a,b,1);
//5        cerr<<xj<<" ";
        if(minn<1145140)
        {
        	break;
		}
    }
    cout<<xj<<'\n';
    for(int i=0;i<xj;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
