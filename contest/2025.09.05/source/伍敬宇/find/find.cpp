#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int mod = 1e9 + 7;
char s[15];
int n,k;
map<long long,long long> dp[15][2][2];
map<long long,long long> sum;
vector<long long> a;
struct Node{
    int x,y;
    bool operator<(const Node&rhs) const{
        return ((__int128)a[x])*((__int128)a[y]) < ((__int128)a[rhs.x])*((__int128)a[rhs.y]);
    }
};
priority_queue<Node> q;
long long ans = 0;
inline bool cmp(long long x,long long y)
{
    return x > y;
}
int main()
{
    freopen("find.in","r",stdin);
    freopen("find.out","w",stdout);
    scanf("%s",s+1);
    scanf("%d",&k);
    n = strlen(s+1);
    dp[0][1][0][1] = 1;
    for (int i=1;i<=n;i++)
    {
        for (int f=0;f<=1;f++)
            for (int g=0;g<=1;g++)
            {
                int l=0,r=9;
                if (f==0) l = 1;
                if (g==0) r = s[i] - '0';
                for (map<long long,long long>::iterator it=dp[i-1][f][g].begin();it!=dp[i-1][f][g].end();it++)
                {
                    for (int x=l;x<=r;x++)
                        dp[i][(x==0)][g||(x<s[i]-'0')][(it->first)*((x==0)?1:x)] += it->second;
                }
                dp[i-1][f][g].clear();
            }
    }
    for (int g=0;g<=1;g++)
        for (map<long long,long long>::iterator it=dp[n][0][g].begin();it!=dp[n][0][g].end();it++)
        {
            sum[it->first] += it->second;
        }
    for (map<long long,long long>::iterator it=sum.begin();it!=sum.end();it++)
        a.push_back(it->second);
    sort(a.begin(),a.end(),cmp);
    for (int i=0;i<a.size();i++)
        q.push({i,0});
    for (int i=1;i<=k;i++)
    {
        int x = q.top().x,y = q.top().y;
        ans = (ans + a[x]%mod*(a[y]%mod))%mod;
        q.pop();
        if (y+1<a.size()) q.push({x,y+1});
    }
    printf("%lld",ans);
    return 0;
}