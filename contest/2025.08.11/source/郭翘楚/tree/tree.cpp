#include <bits/stdc++.h>
#include <random>
using namespace std;
int fa[500005],w[500005];
int dp[500005];
vector<int> son[500005];
long long sum=0;
int g=1;
void dfs(int u)
{
    sum+=w[u];
    for(int i=0;i<son[u].size();i++)
    {
        if((sum+w[son[u][i]])/(g+1)>sum/g or rand()%2)
        {
            dfs(son[u][i]);
            g++;
        }
    }
    return ;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    srand(time(0));
    int n;
    cin>>n;
    fa[1]=1;
    for(int i=2;i<=n;i++)
    {
        cin>>fa[i];
        son[fa[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum=0,g=1;
        dfs(i);
        printf("%.10lf\n",sum*1.0/g);
    }
    return 0;
}