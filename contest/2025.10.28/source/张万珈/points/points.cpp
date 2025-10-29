#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
#define min(x,y) ((x)<(y)?x:y)
#define max(x,y) ((x)<(y)?y:x)
#define get(a,b,x) (max(0,(x)-r[a]) + max(0,l[b]-x) + min(max(0,x-r[a]),max(0,l[b]-x)))
struct node{
    int l,r;
    node()=default;
    node(int l,int r):
        l(l),r(r){}
};
bool cmp(node a,node b)
{
    if(a.r != b.r) return a.r < b.r;
    return a.l > b.l;
}
node line[N];
int a[N],l[N],r[N],tot;
ll dp[N],dp1[N];
int q[N],hd,tl;
int main()
{
    freopen("points.in","r",stdin);
    freopen("points.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    clock_t t = clock();
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin >> line[i].l >> line[i].r;
    }
    sort(line+1,line+m+1,cmp);
    int mnl = -INT_MAX;
    for(int i=1;i<=m;i++)
    {
        if(line[i].l <= mnl) continue;
        l[++tot] = line[i].l;
        r[tot] = line[i].r;
        mnl = line[i].l;
    }
    m = tot;
    cerr << m << '\n';
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++)
    {
        dp[i] = 1e15;
    }
    for(int x=1;x<=n;x++)
    {
        memcpy(dp1+1,dp+1,sizeof(ll)*m);
        for(int i=1;i<=m;i++) dp1[i] = dp[i];
        hd=1,tl=0;
        for(int i=1;i<=m;i++)
        {
            while(hd <= tl && (dp[q[tl]]+get(q[tl]+1,i,a[x])) >= (dp[i-1]+get(i,i,a[x]))) tl--;
            q[++tl] = i-1;
            while(hd < tl && (dp[q[hd]]+get(q[hd]+1,i,a[x])) >= (dp[q[hd+1]]+get(q[hd+1]+1,i,a[x]))) hd++;
            dp1[i] = min(dp1[i],dp[q[hd]]+get(q[hd]+1,i,a[x]));
        }
        memcpy(dp+1,dp1+1,sizeof(ll)*m);
    }
    cout << dp[m];
    cerr << (clock() - t)*1.0/CLOCKS_PER_SEC << "s";
}
