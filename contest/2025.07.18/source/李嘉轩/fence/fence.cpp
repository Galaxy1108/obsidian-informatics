//小学奥数.png
//爆点:
//1. 单调栈写成单调队列(这个绷不住)
//2. 离散化的len多了1(回去再背一遍板子)
//3. 注意38行是小于号不然会炸掉(sum掉得特别慢)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define inv2 500000004
int h[100001], w[100001], t[100001], l[100001], r[100001];
vector<int>p[100001];
int calc(int l, int r){
	if(l > r)return 0;
	return (((w[r] - w[l - 1] + mod) * (w[r] - w[l - 1] + mod + 1)) % mod) * inv2 % mod;
}
signed main(){
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n, len, sum, ans = 0, x;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
		t[i] = h[i];
		l[i] = 1;
		r[i] = n;
	}
	sort(t + 1, t + n + 1);
	len = unique(t + 1, t + n + 1) - t - 1;
	for(int i = 1; i <= n; i++){
		p[lower_bound(t + 1, t + len + 1, h[i]) - t].push_back(i);
		cin >> w[i];
		w[i] = (w[i] + w[i - 1]) % mod;
	}
	sum = calc(1, n);
	stack<int>st;
	for(int i = 1; i <= n; i++){
		while(!st.empty() && h[i] < h[st.top()]){
			r[st.top()] = i - 1;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty())st.pop();
	for(int i = n; i >= 1; i--){
		while(!st.empty() && h[i] <= h[st.top()]){
			l[st.top()] = i + 1;
			st.pop();
		}
		st.push(i);
	}
	for(int i = 1; i <= len; i++){
		for(int j = 0; j < p[i - 1].size(); j++){
			x = p[i - 1][j];
			sum = (sum - calc(l[x], r[x]) + calc(l[x], x - 1) + calc(x + 1, r[x]) + mod) % mod;
		}
		ans = (ans + (sum * (t[i] - t[i - 1]) % mod) * ((t[i] + t[i - 1] + 1) * inv2 % mod)) % mod;
	}
	cout << ans;
	return 0;
}
