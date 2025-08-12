 #include <bits/stdc++.h> 
 constexpr int MXN = 120005;
 using namespace std;
 vector<int> v[MXN];
 vector<int> w[MXN];
 int s[MXN],t[MXN];
 int fa[MXN][31], cost[MXN][31], dep[MXN];
 int n, m;
 int a, b;
 int lca(int x, int y) {
 	if (dep[x] > dep[y]) swap(x, y);
 	int tmp = dep[y] - dep[x], ans = 0;
 	for (int j = 0; tmp; ++j, tmp >>= 1)
 		if (tmp & 1) ans += cost[y][j], y = fa[y][j];
 	if (y == x) return ans;
 	for (int j = 30; j >= 0 && y != x; --j)
     {
 		if (fa[x][j] != fa[y][j]) {
 			ans += cost[x][j] + cost[y][j];
 			x = fa[x][j];
 			y = fa[y][j];
 		}
 	} 
 	ans += cost[x][0] + cost[y][0];
 	return ans;
 }
 void Solve() {
 	memset(fa, 0, sizeof(fa));
 	memset(cost, 0, sizeof(cost));
 	memset(dep, 0, sizeof(dep));
 	cin >> n;
 	for (int i = 1; i <= n; ++i) {
 		v[i].clear();
 		w[i].clear();
 	}
 	for (int i = 1; i < n;++i) {
 		cin >> a >> b;
 		v[a].push_back(b);
 		v[b].push_back(a);
 		w[a].push_back(1);
 		w[b].push_back(1);
 	}
 	cin>>m;
 	for(int i=1;i<=m;i++)
 	{
 		cin>>s[i]>>t[i];
 	}
 	for(int i=1;i<m;i++)
 	{
 		int x=lca(s[i],t[i]);
 		for(int j=i+1;j<=m;j++)
 		{
             if(s[i]==t[j] and s[j]==t[i])
             {
                 cout<<"No"<<endl;
                 return;
             }
             if(s[i]==t[j])
             {
                 if(x==lca(s[j],t[j]))
                 {
                     cout<<"No"<<endl;
                     return;
                 }
             }
 		}
 	}
 	cout<<"Yes"<<endl;
 	return;
 }
 int main()
 {
 	freopen("jail.in","r",stdin);
 	freopen("jail.out","w",stdout);
 	int T;
 	cin >> T;
 	while (T--)
 	{
 		Solve();
 	}
 	return 0;
 }
//#include <bits/stdc++.h>
//using namespace std;
//int a,b,s[120005],t[120005];
//vector<int> path[120005];//i号囚犯最短路经过的地方
//int n, m;
//vector<int> ma[120005];
//vector<int> g[120005];
//int inn[120005];
//bool toposort() {
//    vector<int> L;
//    queue<int> S;
//    for (int i = 1; i <= n; i++)
//    {
//    	if (inn[i] == 0)
//		{
//			S.push(i);
//		}
//	}
//    while (!S.empty()) {
//        int u = S.front();
//        S.pop();
//        L.push_back(u);
//        for (auto v : g[u]) {
//            if (--inn[v] == 0) {
//                S.push(v);
//            }
//        }
//    }
////    cout<<L.size()<<endl;
//    if (L.size() == n)
//    {
////        for (auto i : L)
////		{
////			cout << i << ' ';
////		}
//        return true;
//    }
//    return false;
//}
//bool book[120005];
//bool flag=false;
//int st,en;
//int p;
//void dfs(int x)
//{
//	book[x]=true;
//    if(x==en)
//    {
//        flag=true;
//        return;
//    }
//    for(auto v:ma[x])
//    {
//        if(!book[v])
//        {
////        	cout<<"从"<<x<<"到"<<v<<endl ; 
//            dfs(v);
//            if(flag)
//            {
//                path[p].push_back(v);
//                return;
//            }
//        }
//    }
//    return;
//}
//void solve()
//{
//    memset(g,0,sizeof(g));
//    memset(inn,0,sizeof(inn));
//    memset(path,0,sizeof(path));
//    memset(ma,0,sizeof(ma));
//    cin>>n;
//    for(int i=1;i<n;i++)
//    {
//        cin>>a>>b;
//        ma[a].push_back(b);
//        ma[b].push_back(a);
//    }
//    cin>>m;
//    for(int i=1;i<=m;i++)
//    {
//        cin>>s[i]>>t[i];
//    }
//    for(int i=1;i<=m;i++)
//    {
//        memset(book,0,sizeof(book));
//        st=s[i];
//        en=t[i];
//        flag=false;
//        p=i;
//        dfs(st);
//        path[i].push_back(st);
////        for(auto l : path[i])
////        {
////        	cout<<l<<" ";
////		}
////		cout<<endl;
//    }
//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            if(i==j)
//            {
//                continue;
//            }
//            bool flag1=false,flag2=false;
//            for(auto k:path[i])
//            {
//            	if(t[j]==k)
//                {
//                    g[s[i]].push_back(k);
//                    flag1=true;
//                    inn[k]++;
//                }
//                else if(s[j]==k)
//                {
//                    g[k].push_back(s[i]);
//                    flag2=true;
//                    inn[s[i]]++;
//                }
//            }
//            while(flag1 and flag2)
//            {
//            	cout<<"No"<<endl;
//            	return;
//			}
//        }
//    }
////    for(int i=1;i<=n;i++)
////    {
////    	cout<<inn[i]<<" ";
////	}
//    if(toposort()) cout<<"Yes"<<endl;
//    else cout<<"No"<<endl;
//    return;
//}
//int main()
//{
// 	freopen("jail.in","r",stdin);
//    freopen("jail.out","w",stdout);
//    int T;
//    cin>>T;
//    while(T--)
//    {
//        solve();
//    }
//    return 0;
//}
