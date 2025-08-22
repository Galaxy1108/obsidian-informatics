#include <bits/stdc++.h>

using namespace std;

//#define int long long

typedef long long ll;

const int N = 2005;

int n;
vector<pair<int,int> > E[N];

using IO_t=int;inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}inline IO_t read(){IO_t x=0;bool f=0;char ch=gc();while(!isdigit(ch)){f|=(ch=='-');ch=gc();}while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return(f?-x:x);}

using pqii = priority_queue<pair<int,int> >;

const int INF = 2e9;

struct VER {
	int s;
	bitset<N> book;
}p[N];
//queue<pair<int,int> > q;
pqii q;
int mk[N];
void spfa(int st){
//	pqii ().swap(q);
	while(!q.empty()) q.pop();
	for(int i = 0; i <= n + 1; ++ i){
		p[i].s = INF;
		p[i].book.reset();
	}
	q.push({-INF , st});
//	q.push({INF , st});
	memset(mk , 0 , sizeof mk);
	mk[st] = 1;
	p[st].book[st] = 1;
	while(!q.empty()){
//		int u = q.front().second; q.pop();
		int u = q.top().second; q.pop();
		mk[u] = 0;
//		assert(p[u].book[st] == 1);
//		assert((int)E[u].size() == n - 1);
		for(auto [w , v] : E[u]){
			if(v == u || p[u].book[v] == 1) continue;
			if(p[v].s > min(p[u].s , w)){
				p[v].s = min(p[u].s , w);
				p[v].book.reset();
				p[v].book |= p[u].book;
				p[v].book[v] = 1;
				if(mk[v] == 0){
					mk[v] = 1;
					q.push({-p[v].s , v});
//					q.push({p[v].s , v});
				}
			}
		}
	}
}

signed main(){
	freopen("b.in" , "r" , stdin);
	freopen("b.out" , "w" , stdout);
	
	n = read();
	for(int i = 1; i < n; ++ i){
		for(int j = 1; j <= n - i; ++ j){
			int w = read();
			E[i].push_back({w , i + j});
			E[i + j].push_back({w , i});
		}
	}
	for(int i = 1; i <= n; ++ i){
		sort(E[i].begin() , E[i].end());
	}
	
	for(int t = 1; t <= n; ++ t){
		spfa(t);
		ll ans = 0;
		p[t].s = 0;
		for(int i = 1; i <= n; ++ i){
//			cout << t << " " << i << " " << p[i].s << endl;
			ans += p[i].s;
		}
		printf("%lld\n" , ans);
	}
	
	return 0;
}
