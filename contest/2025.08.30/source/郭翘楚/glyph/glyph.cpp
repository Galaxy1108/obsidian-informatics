#include <bits/stdc++.h>
using namespace std;
int a[305][305];
long long dp[305][305];
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
void write(int x)
{
    static int sta[35];
    int top = 0;
    do 
    {
        sta[top++] = x % 10, x /= 10;
    }while (x);
    while(top) putchar(sta[--top] + 48);
}
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x1,x2,y1,y2;
		x1=read(),x2=read(),y1=read(),y2=read(); 
		dp[x1][y1]=a[x1][y1];
		for(int j=x1;j<=x2;j++)
		{
			for(int k=y1;k<=y2;k++)
			{
				if(j==x1 and k==y1) continue;
				if(j==x1)
				{
					dp[j][k]=dp[j][k-1]+a[j][k];
				}
				else if(k==y1)
				{
					dp[j][k]=dp[j-1][k]+a[j][k];
				}
				else
				{
					dp[j][k]=min(dp[j-1][k],dp[j][k-1])+a[j][k];
				}
			}
		}
		cout<<dp[x2][y2]<<'\n';
	}
}
