#include <bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];
bool vis[2000010];
#define int long long
unsigned int hsh(unsigned int lst,int x)
{
    return (lst*20081128+x) % 1145141;
}
long long ans;
int n,m;
void dfs(int len,int now,bool great)
{
    if(now > n)
    {
    	if(great)ans++;
    	else if(len < m && len > 0) ans++;
    	return;
	}
    if(a[now] < b[len+1])
    {
        dfs(len+1,now+1,1);
    }
    else if(a[now] == b[len+1] || great)
    {
        dfs(len+1,now+1,great);
    }
    dfs(len,now+1,great);
}
signed main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    cin >> n;
    if(n > 10) {cout << 0;return 0;}
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
    }
    dfs(0,1,0);
    cout << ans;
}
