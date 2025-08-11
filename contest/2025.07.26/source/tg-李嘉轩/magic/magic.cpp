//纯模拟能卡过所有大样例真没想到
#include<bits/stdc++.h>
using namespace std;
int qread(){
	int x = 0, k = 1;
	char c;
	while(1){
		c = getchar();
		if(c == '-'){
			k = -1;
			break;
		}else if(c >= '0' && c <= '9'){
			x = c - '0';
			break;
		}
	}
	while(1){
		c = getchar();
		if(c >= '0' && c <= '9')x = (x << 3) + (x << 1) + c - '0';
		else break;
	}
	return x * k;
}
void qwrite(int x){
	int t = 1;
	while(t <= x)t = (t << 3) + (t << 1);
	t /= 10;
	while(t){
		putchar(x / t + '0');
		x %= t;
		t /= 10;
	}
	putchar('\n');
}
int p[200001][2], f[1000001], ans[1000001];
struct query{int x, id;};
vector<query>a[200001];
int main(){
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	int n, q, m, l, r, t, cnt, now = 0, pre = 1;
	n = qread();
	q = qread();
	for(int i = 1; i <= n; i++)p[i][0] = qread();
	for(int i = 1; i <= q; i++){
		t = qread();
		f[i] = qread();
		if(t == 0)ans[i] = p[f[i]][0];
		else if(t <= n)a[t].push_back({f[i], i});
	}
	for(int i = 1; i <= n; i++){
		swap(now, pre);
		l = 1;
		r = (n >> 1) + 1;
		cnt = 0;
		while(l <= (n >> 1) && r <= n){
			if(p[l][pre] < p[r][pre])p[++cnt][now] = p[l++][pre];
			else p[++cnt][now] = p[r++][pre];
		}
		while(l <= (n >> 1))p[++cnt][now] = p[l++][pre];
		while(r <= n)p[++cnt][now] = p[r++][pre];
		t = a[i].size();
		for(int j = 0; j < t; j++)ans[a[i][j].id] = p[a[i][j].x][now];
		for(int j = 1; j <= n; j++)if(p[j][pre] != p[j][now])goto skip;
		m = i;
		break;
		skip:;
	}
	for(int i = 1; i <= q; i++){
		if(ans[i] == 0)qwrite(p[f[i]][now]);
		else qwrite(ans[i]);
	}
	return 0;
}
