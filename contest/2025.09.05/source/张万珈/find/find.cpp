#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int t[11] = {0,0,1,37,2,37*25,38,37*25*13,3,37+37};
const int N = 156325, mod = 1e9+7;
ull s[14][200010],cnt[200010],f[14];

struct node{
    int x,y;
    node() = default;
    node(int x,int y):
        x(x),y(y){}
};
struct nodee{
    ull x;
    node y;
    nodee() = default;
    nodee(ull x,node y):
        x(x),y(y){}
};
bool operator<(nodee x,nodee y)
{
    return x.x < y.x;
}

void solve()
{
    int cnt = 1;
    f[0] = 1,f[1] = 10;
    for(int i=1;i<=9;i++) s[1][t[i]] = 1;
    for(cnt=2;cnt<=13;cnt++)
    {
        f[cnt] = f[cnt-1] * 10;
        for(int i=1;i<=9;i++)
        {
            for(int j=0;j<=N;j++)
            {
                s[cnt][j+t[i]] = (s[cnt][j+t[i]] + s[cnt-1][j]) % mod;
            }
        }
    }
    return;
}
bool cmp(ull a,ull b)
{
    return a > b;
}

int main()
{
    freopen("find.in","r",stdin);
    freopen("find.out","w",stdout);
    long long n,k;
    cin >> n >> k;

    solve();
    int m,r=0;
    for(int i=1;i<=n;i++) 
    {
        if(n < f[i]) {m = i;break;}
    }

    for(int i=1;i<=m-1;i++)
    {
        for(int j=0;j<=N;j++)
        {
            cnt[j] += s[i][j];
        }
    }
    for(int i=m;i>=1;i--)
    {
        int now = (n % f[i]) / f[i-1];
        if(now == 0) break;
        if(i == 1)
        {
            for(int j=1;j<=now;j++)
            {
                cnt[r+t[j]] ++;
            }
            break;
        }
        else
        {
            for(int j=1;j<now;j++)
            {
                for(int x = 0;x<=N;x++)
                {
                    cnt[x+r+t[j]] += s[i-1][x];
                }
            }
            r += t[now];
        }
    }

    sort(cnt,cnt+N+1,cmp);
    int tot;
    priority_queue<nodee> q;
    for(int i=0;i<=N;i++)
    {
        tot = i;
        if(cnt[i] == 0) break;
        q.push(nodee(cnt[i] * cnt[0],node(i,0)));
    }
    unsigned long long ans = 0;
    for(int i=1;i<=k;i++)
    {
        nodee now = q.top();
        q.pop();
        ans = (ans + (now.x % mod)) % mod;
        if(now.y.y == tot) continue;
        q.push(nodee(cnt[now.y.x] * cnt[now.y.y + 1],node(now.y.x,now.y.y+1)));
    }
    
    cout << ans;
    return 0;
}