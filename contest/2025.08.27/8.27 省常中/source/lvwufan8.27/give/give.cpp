#include<bits/stdc++.h>
using namespace std;
int t;
long long m,s,n;
long long a[210];
int dp[2010][5010];
int main()
{
    freopen("give.in","r",stdin);
    freopen("give.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>m>>s>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            dp[1][a[i]]=1;
        }
        for(int i=2;i<=m;i++)
        {
            for(int j=1;j<=s;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(j>=a[k])
                    {
                        dp[i][j]+=dp[i-1][j-a[k]]%2;
                        dp[i][j]%=2;
                    } 
                }
            }
        }
        cout<<dp[m][s]%2<<endl;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=s;j++)
            {
                dp[i][j]=0;
            }
        }
    }
}