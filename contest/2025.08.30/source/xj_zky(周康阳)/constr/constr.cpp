#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define ull unsigned long long 
#define vi vector < int > 
#define sz(a) ((int) (a).size()) 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 4e6 + 7;
bool vis[100];
 
int n = 10, U[100], V[100], cnt;

bool ban[N];
inline int calc(int *p) {
	int ns = 0;
	R(i, 10, 1) {
		ns *= i;
		L(j, 1, i - 1) 
			if(p[j] < p[i]) 
				++ns;
	}
	assert(ns < N);
	return ns;
}

int cur[N];
void doit(int x) {
	if(x >= 10) {
		ban[calc(cur)] = true; 
		return ;
	}
	doit(x + 1);
	swap(cur[x], cur[x + 1]);
	doit(x + 2);
	swap(cur[x], cur[x + 1]);
}
 
int ns = 0, mp[N];

void dfs(int x) {
	if(x == 6) {
		++cnt;
		L(i, 0, (1 << 5) - 1) {
			L(j, 1, 5) {
				cur[j * 2 - 1] = U[j], cur[j * 2] = V[j];
				if(i >> (j - 1) & 1) 
					swap(cur[j * 2 - 1], cur[j * 2]);
			}
			if(ban[calc(cur)]) 
				continue ;
			doit(1);
			++ns;
			L(i, 1, 10)
				mp[cur[i]] = i;
			L(i, 1, 10) 
				cout << mp[i] << ' ';
			cout << '\n';
			return ;
		}
		return ;
	}
	L(i, 1, 10) 
		L(j, i + 1, 10) 
			if(!vis[i] && !vis[j]) {
				vis[i] = true;
				vis[j] = true;
				U[x] = i, V[x] = j;
				dfs(x + 1);
				vis[i] = false;
				vis[j] = false;
			}
			
} 
int main() {
	freopen("constr.in", "r", stdin); 
	freopen("constr.out", "w", stdout); 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout << 113400 << '\n';
	dfs(1);
//	cout << "cnt = " << cnt << ' ' << ns << '\n';
	return 0;
}