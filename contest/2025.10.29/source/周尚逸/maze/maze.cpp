#include<bits/stdc++.h>
using namespace std;
inline int rd()
{
    int x=0,f=1;
    char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s<='9'&&s>='0'){x=x*10+(s^48);s=getchar();}
    return x*f;
}
int n,m;
int x,y;
int a[100][100];
struct op{
    int x,y,step;
};
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
queue<op>q;
bool f[100][100]={0};
bool check(int h,int l)
{
    return h<=n&&h>=1&&l<=m&&l>=1&&a[h][l]==0&&f[h][l]==0;
}
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    n=rd();
    m=rd();
    x=rd();
    y=rd();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=rd();
        }
    }
    f[1][1]=1;
    if(x==1&&y==1)
    {
        cout<<1;
        return 0;
    }
    q.push({1,1,0});
    long long ans=0;
    int furina=0;
    while(!q.empty())
    {
        for(int i=0;i<4;i++)
        {
            int kh=q.front().x+dx[i];
            int kl=q.front().y+dy[i];
            if(kh==n&&kl==m)
            {
                ans++;
                if(furina==0)
                {
                    furina=q.front().step+1;
                }
                else
                {
                    if((q.front().step+1)>furina)
                    {
                        cout<<ans;
                        return 0;
                    }
                }
                continue;
            }
            if(check(kh,kl))
            {
                f[kh][kl]=1;
                q.push({kh,kl,q.front().step+1});
            }
        }
        q.pop();
    }
    cout<<ans;
    return 0;
}