#include<bits/stdc++.h>
using namespace std;
int n,q;
int l1[200010],r1[200010],l2[200010],r2[200010];
int a[310][310];
long long dp[310][310];
long long mem[210][210][210];
int main()
{
    freopen("glyph.in","r",stdin);
    freopen("glyph.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    bool f=0;
    for(int i=1;i<=q;i++)
    {
        cin>>l1[i]>>l2[i]>>r1[i]>>r2[i];
        if(l1[i]!=1)
        {
            f=1;
        }
    }
    if(!f)
    {
        for(int i=1;i<=n;i++)
        {
            mem[1][i][i]=a[1][i];
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(j!=1&&k!=i)
                    {
                        mem[j][k][i]=min(mem[j][k-1][i],mem[j-1][k][i])+a[j][k];
                    }
                    else if(j==1&&k!=i)
                    {
                        mem[j][k][i]=mem[j][k-1][i]+a[j][k];
                    }
                    else if(j!=1&&k==i)
                    {
                        mem[j][k][i]=mem[j-1][k][i]+a[j][k];
                    }
                }
                
            }
        }
        for(int i=1;i<=q;i++)
        {
            cout<<mem[l2[i]][r2[i]][r1[i]]<<endl;
        }
    }
    else
    {
        for(int i=1;i<=q;i++)
        {
            memset(dp,0x3f3f3f3f,sizeof(dp));
            dp[l1[i]][r1[i]]=a[l1[i]][r1[i]];
            for(int l=l1[i];l<=l2[i];l++)
            {
                for(int r=(l==l1[i])?r1[i]+1:r1[i];r<=r2[i];r++)
                {
                    dp[l][r]=min(dp[l-1][r]+a[l][r],dp[l][r-1]+a[l][r]);
                }
            }
            cout<<dp[l2[i]][r2[i]]<<endl;
        }
    }
}