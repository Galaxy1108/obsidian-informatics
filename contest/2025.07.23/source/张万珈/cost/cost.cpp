#include <bits/stdc++.h>
using namespace std;
int ls(int x) {return x<<1;}
int rs(int x) {return x<<1|1;}
bool w[1010];
int t[1010][1010],c[101],mode[101][101],cnta[401],cntb[401];
int n;
long long ans = 1e12;
void build(int p,int l,int r)
{
    if(l==r)
    {
        if(w[l]) cntb[p]++;
        else cnta[p]++;
        return;
    }
    int mid = (l+r)>>1;
    for(int i=l;i<=mid;i++)
    {
        for(int j=mid+1;j<=r;j++)
        {
            mode[i][j] = p;
            mode[j][i] = p;
        }
    }
    build(p<<1,l,mid);
    build((p<<1)|1,mid+1,r);
    cnta[p] = cnta[p<<1] + cnta[(p<<1)|1];
    cntb[p] = cntb[p<<1] + cntb[(p<<1)|1];
    return;
}
long long ask(int p,int l,int r)
{
    if(l==r) return 0;
    int mid = (l+r)>>1;
    long long ret = ask(ls(p),l,mid) + ask(rs(p),mid+1,r);
    if(cnta[p] >= cntb[p])
    {
        ret += cntb[ls(p)]*(r-mid);
        ret += cntb[rs(p)]*(r-mid);
    }
    else
    {
        ret += cnta[ls(p)]*(r-mid);
        ret += cnta[rs(p)]*(r-mid);
    }
    //cout << l << ' ' << r << ' ' << ret << endl;
    return ret;
}
long long solve()
{
	build(1,1,n);
    long long ret = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int nowm = mode[i][j];
            if(cnta[nowm] >= cntb[nowm])
            {
                ret += ((w[i]?1:0) + (w[j]?1:0)) * t[i][j];
            }
            else
            {
                ret += ((w[i]?0:1) + (w[j]?0:1)) * t[i][j];
           	}
//           	cout << ret << '\n';
        }
    }
//    cout << ret << '\n';
    return ret;
}
void dfs(int now,long long sum)
{
	if(sum > ans) return;
    if(now > n)
    {
        ans = min(ans,sum+solve());
        // cout << sum << ' ' << solve() << ' ' << ans << endl;
        return;
    }
    // cout << now << ' ' << 1  << ' ' << sum << endl;
    w[now] ^= 1;
    dfs(now+1,sum + c[now]);
    // cout << now << ' ' << 0 << ' ' << sum << endl;
    w[now] ^= 1;
    dfs(now+1,sum);
}
int main()
{
    freopen("cost.in","r",stdin);
    freopen("cost.out","w",stdout);
    cin >> n;
    n = 1<<n;
    for(int i=1;i<=n;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin >> t[i][j];
            t[j][i] = t[i][j];
        }
    }
    build(1,1,n);
//    for(int i=1;i<=n;i++)
//    {
//    	for(int j=1;j<=n;j++)
//    	{
//    		cout << mode[i][j] << ' ';
//		}
//		cout << endl;
//	}
	dfs(1,0);
    cout << ans;
    return 0;
}
