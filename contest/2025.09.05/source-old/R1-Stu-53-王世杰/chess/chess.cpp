#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int h[105];
void dfs(int x)
{
	if(x>m)
	{
		ans++;
		ans%=9999973;
	}
	else
	{
		for(int i=0;i<=n;i++)
		{
			if(i==0||h[i]<2)
			{
				h[i]++;
				for(int j=i;j<=n;j++)
				{
					if(j==0||(i!=j&&h[j]<2))
					{
						h[j]++;
						dfs(x+1);
						h[j]--;
					}
				}
				h[i]--;
			}
		}
	}

}

int main()
{
	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	cin>>n>>m;
	dfs(1);
	cout<<ans;
	return 0;
}
