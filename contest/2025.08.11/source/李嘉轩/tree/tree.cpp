#include<bits/stdc++.h>
using namespace std;
int qread(){
	int x = 0;
	char c;
	while(1){
		c = getchar();
		if(c >= '0' && c <= '9'){
			x = c - '0';
			break;
		}
	}
	while(1){
		c = getchar();
		if(c >= '0' && c <= '9')x = x * 10 + c - '0';
		else break;
	}
	return x;
}
void qwrite(int x){
	int ans[114], siz = 0;
	while(x){
		ans[++siz] = x % 10;
		x /= 10;
	}
	for(int i = siz; i >= 1; i--)putchar(ans[i] + '0');
}
int w[500001], q[500001], nxt[500001], head[500001], cnt;
double ans[500001], sum, target;
void bfs(int x){
	int l = 1, r = 1, p;
	q[1] = x;
	int cur;
	while(l <= r){
		cur = q[l++];
		cnt++;
		sum += w[cur];
		p = head[cur];
		while(p){
			if(ans[p] >= target)q[++r] = p;
			p = nxt[p];
		}
	}
}
void dfs(int x){
	int p = head[x];
	while(p){
		dfs(p);
		p = nxt[p];
	}
	double l = w[x], r = 1000000000;
	while(r - l > (l / 1e6)){
		target = (l + r) / 2;
		cnt = sum = 0;
		bfs(x);
		if(sum / cnt >= target)l = sum / cnt;
		else r = target;
	}
	ans[x] = l;
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n, x;
	long long t;
	n = qread();
	for(int i = 2; i <= n; i++){
		x = qread();
		if(head[x] == 0)head[x] = i;
		else{
			nxt[i] = head[x];
			head[x] = i;
		}
	}
	for(int i = 1; i <= n; i++)w[i] = qread();
	dfs(1);
	for(int i = 1; i <= n; i++){
		t = (long long)(ans[i] * 1000000000ll + 0.5);
		qwrite(t / 1000000000ll);
		putchar('.');
		t %= 1000000000ll;
		if(t < 100000000)putchar('0');
		if(t < 10000000)putchar('0');
		if(t < 1000000)putchar('0');
		if(t < 100000)putchar('0');
		if(t < 10000)putchar('0');
		if(t < 1000)putchar('0');
		if(t < 100)putchar('0');
		if(t < 10)putchar('0');
		if(t < 1)putchar('0');
		qwrite(t);
		putchar('\n');
	}
	return 0;
}
