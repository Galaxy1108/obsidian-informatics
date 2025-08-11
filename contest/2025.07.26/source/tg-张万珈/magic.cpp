#include <bits/stdc++.h>
using namespace std;
int f[2][200010];
struct node{
    int cnt,id,i;
};
bool cmp(node a,node b){if(a.cnt != b.cnt){return a.cnt < b.cnt;}else return a.id < b.id;}
node q[1000010];
int n,m,now,ans[1000010];
void check(register int x,register int which)
{
    while(q[now].cnt == x)
    {
        ans[q[now].i] = f[which][q[now].id];
        // cout << now << ' ' << q[now].cnt << ' ' << x << '\n';
        now++;
    }
    return;
}
void finalcheck(register int which)
{
    for(register int i=now;i<=m;i++)
    {
        ans[q[now].i] = f[which][q[now].id];
        now++;
    }
    return;
}
int read()
{
	register int p = 0;
	char c = _getchar_nolock();
    while('0' > c || '9' < c){c = _getchar_nolock();}
    while('0' <= c && c <= '9'){p = p*10 + (c - '0');c = _getchar_nolock();}
    return p;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
    n = read(),m = read();
    for(register int i=1;i<=n;i++)
    {
        f[0][i] = read();
    }
    for(register int i=1;i<=m;i++)
    {
       	q[i].cnt = read(),q[i].id = read();
        q[i].i = i;
    }
    sort(q+1,q+m+1,cmp);
    now = 1;
    check(0,0);
    bool flag = 1;
    register int t=0,cnt1=0;
    while(flag)
    {
        flag = 0;
        t^=1;
        cnt1++;
        register int l = 1,r = ((n>>1)+1),tot = 0;
        while(l <= (n>>1) && r <= n)
        {
            if(f[t^1][l] < f[t^1][r])
            {
                f[t][++tot] = f[t^1][l];
                l++;
            }
            else
            {
                f[t][++tot] = f[t^1][r];
                r++;
            }
        }
        if(l >= (n>>1))
        {
            if(r != (n>>1)+1) flag = 1;
            for(register int i=r;i<=n;i++)
            {
                f[t][++tot] = f[t^1][i];
            }
        }
        else
        {
        	flag = 1;
            for(register int i = l;i<=n>>1;i++)
            {
                f[t][++tot] = f[t^1][i];
            }
        }
        check(cnt1,t);
        if(now > m) break;
    }
    finalcheck(t);
    for(register int i=1;i<=m;i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
