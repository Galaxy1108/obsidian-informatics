#include<bits/stdc++.h>
#define L(i,j,k) for(int i = (j); i <= (k); ++i)
#define R(i,j,k) for(int i = (j); i >= (k); --i)
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define ll long long
#define fir first 
#define sec second
using namespace std;
const int N = 1e5 + 5;
int n, m;
int z[N];

struct qwq{
    int u, v, w;
}e[5 * N]; int ed;
map <pair<int, int>, int> s;
int col[N];
int f[N];
int rr[N];
int siz[N];

int find(int wi){
    if(f[wi] == 0 || f[wi] == wi) return wi;
    return f[wi] = find(f[wi]);
}
bool cmp(qwq aa, qwq bb){
    return aa.w < bb.w;
}

//--------
struct orz
{
	int a[1000005], cur, len = 0;
	void set() { cur = 0; }
	int readInt() { if (cur == len) exit(-1); return a[++cur]; }
	void add(int x) { a[++len] = x; }
}inf,ouf;
//--------


bool check() {
	memset(col, 0, sizeof(col));
	memset(f, 0, sizeof(f));
	memset(e, 0, sizeof(e)), memset(rr, 0, sizeof(rr)), memset(siz, 0, sizeof(siz));
	s.clear();
	ed = 0;
	inf.set(), ouf.set();
//    n = inf.readInt(), m = inf.readInt();
//    L(i, 1, n) z[i] = inf.readInt();
    int u, v, w;
    int cnt;
    cnt = ouf.readInt();
//    int ans_cnt = ans.readInt();
//    if(ans_cnt != cnt)   return 0;
    L(i, 1, cnt){
        siz[i] = ouf.readInt();
        L(j, 1, siz[i]){
            u = ouf.readInt();
            if(u <= 0 || u > n)  return 0;
            if(col[u] != 0)  return 0;
            col[u] = i;
        }
    }
    L(i, 1, m){
        u = inf.readInt(), v = inf.readInt(), w = inf.readInt();
        if(col[u] > col[v]) swap(u, v);
        if(col[u] != col[v]){
            if(s.count(mk(col[u], col[v]))) s[mk(col[u], col[v])] = min(s[mk(col[u], col[v])], w);
            else s[mk(col[u], col[v])] = w;    
        }
        else {
            e[++ed].u = u, e[ed].v = v, e[ed].w = w;
        }
    } 
    sort(e + 1, e + ed + 1, cmp);
    L(i, 1, ed){
        if(find(e[i].u) != find(e[i].v)){
            f[find(e[i].u)] = find(e[i].v);
            rr[col[e[i].u]] = max(rr[col[e[i].u]], e[i].w);
        }
    }
    for(auto v : s){
        if(v.sec <= min(rr[v.fir.fir] + z[siz[v.fir.fir]], rr[v.fir.sec] + z[siz[v.fir.sec]])){
            return 0;
        }
    }
    return 1;
}

int K, zzz[N], _, ct[N];
vector<int> C[N];

void dfs(int x)
{
	if (x > n)
	{
		for (int i = 1; i <= n; i++) C[i].clear();
		for (int i = 1; i <= n; i++)
			C[zzz[i]].push_back(i);
		for (int i = 1; i <= K; i++) if (!C[i].size()) return;
//		cout << "_\n";
		ouf.set(); ouf.len = 0;
		ouf.add(K);
		for (int i = 1; i <= K; i++)
		{
			ouf.add(C[i].size());
			for (int j : C[i]) ouf.add(j);
		}
		if (check())
		{
			ouf.set();
			cout << ouf.readInt() << '\n';
			for (int i = 1; i <= K; i++)
			{
				cout << ouf.readInt() << ' ';
				for (int j : C[i]) cout << ouf.readInt() << ' ';
				cout << '\n';
			}
			exit(0);
		}
		return;
	}
	for (int i = 1; i <= K; i++) 
	{
		if (ct[i] == n-K+1) continue;
		zzz[x] = i, ct[i]++;
		dfs(x + 1);
		ct[i]--;
	}
}

int main()
{
	freopen("shattersong.in", "r", stdin);
	freopen("shattersong.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> z[i];
	for (int i = 1, x, y, z; i <= m; i++)
	{
		cin >> x >> y >> z; inf.add(x), inf.add(y), inf.add(z);
		_ = z;
	}
	if (n == 2 && m == 1)
	{
		int __[1234] = {0,1,2,1,2};
		int _[1234] = {0,2,1,1,1,2};
		for (int i = 1; i <= 50; i++) ouf.add(__[i]);
		if (!check()) cout << "1\n2 1 2";
		else cout << "2\n1 1\n1 2";
		return 0;
	}
//	int _[123] = {0,4,
//			 2, 1, 2,
//			 1, 3,
//			 1, 4,
//			 1, 5};
//	int _[123] = {0,5,
//			 1, 1,
//			 1,2,
//			 1,3,
//			 1,4,
//			 1,5};
//	for (int i = 1; i <= 50; i++) ouf.add(_[i]);
	for (K = n; K >= 1; K--) dfs(1);
	return 0;
}
/*
2 1
2 47 
1 2 1
*/
