#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int to,w,c;
    edge(int a,int b,int c):
        to(a),w(b),c(c-b){}
};
struct node{
    int now,sum,now_w;
    node(int a,int b,int c):
        now(a),sum(b),now_w(c){}
};
bool operator <(node a,node b)
{
    return a.sum > b.sum;
}
int n,m,s,q;
int mp[101][101];
bool vis[101];
vector<edge> e[101];
void init(int now)
{
    priority_queue<node> q;
    q.push(node(now,0,0));
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        node x = q.top();q.pop();
        if(vis[x.now]) continue;
        mp[now][x.now] = x.sum;
        vis[x.now] = 1;
        for(edge i : e[x.now])
        {
            if(x.now_w > i.c)
            {
                q.push(node(i.to,x.sum+s-x.now_w+i.w,0));
            }
            else
            {
                q.push(node(i.to,x.sum+i.w,x.now_w+i.w));
            }
        }
    }
}
void bfs()
{
    int start,end,w;
    cin >> start >> end >> w;
    start++,end++;
    priority_queue<node> q;
    q.push(node(start,w,w));
    long long ans = 1e15;
    while(!q.empty())
    {
        node x = q.top();
        q.pop();
//        cout << x.now << ' ' << x.sum << ' ' << x.now_w << endl;
        if(x.now == end)
        {
        	ans = min(ans,(long long)x.sum);
		}
		if(x.sum > ans) continue;
        for(edge i : e[x.now])
        {
        	
            if(x.now_w > i.c)
            {
//            	cout << i.to << ' ' << i.w << ' ' << i.c << ' ' << x.sum+s-x.now_w+mp[i.to][end]<< ">.<" << endl;
                ans = min(ans,(long long)x.sum+s-x.now_w+mp[i.to][end]+i.w);
            }
            else
            {
                q.push(node(i.to,x.sum+i.w,x.now_w+i.w));
            }
        }
    }
    cout << ans-w << endl;
    return ;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
    cin >> n >> m >> s >> q;
    for(int i=1,u,v,w,c;i<=m;i++)
    {
        cin >> u >> v >> w >> c;
        e[u+1].push_back(edge(v+1,w,c));
        e[v+1].push_back(edge(u+1,w,c));
    }
    for(int i=1;i<=n;i++)
    {
        init(i);
    }
    for(int i=1;i<=q;i++)
    {
        bfs();
    }
}
