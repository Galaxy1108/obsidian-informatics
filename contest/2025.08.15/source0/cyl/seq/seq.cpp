#include<bits/stdc++.h>
#define L(i,j,k) for(int i = (j); i <= (k); ++i)
#define R(i,j,k) for(int i = (j); i >= (k); --i)
#define ll long long
using namespace std;
const ll M = 998244353;
const int N = 1e6 + 6;
const int V = 1e5 + 6;
ll dp[N];
int a[N];
int n;
int pos[V];
void chek(ll &s){
	if(s > M) s -= M;
	if(s < 0) s += M; 
}
int nxt[N];
ll tr[N];
int mx = 0;
inline int lb(int wi){
	return wi & (- wi);
}
void add(int x, ll y){
	while(x <= mx){
		tr[x] += y; chek(tr[x]);
		x += lb(x);
	}
}
ll query(int x){
	ll as = 0;
	while(x){
		as += tr[x]; chek(as);
		x -= lb(x);
	}
	return as;
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	
	L(i, 1, n){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	ll sum = 0;
	R(i, n, 1){
		dp[i] = sum + 1;
		sum -= dp[pos[a[i]]];
		sum += dp[i];
		chek(sum);
		nxt[i] = pos[a[i]]; pos[a[i]] = i;
	}
	L(i, 1, mx){
		add(i, dp[pos[i]]);
	}
	int m ,x;
	cin >> m;
	ll ans = 0;
	int lt = 0, vo;
	L(i, 1, m){
		cin >> x;
		ans += (query(x - 1) + 1);
		chek(ans);
		vo = pos[x];
		while(lt < vo){
			++lt;
			add(a[lt], -dp[lt]);
			add(a[lt], dp[nxt[lt]]);
			pos[a[lt]] = nxt[lt];
		}
	}
	cout << ans;
	return 0;
}

