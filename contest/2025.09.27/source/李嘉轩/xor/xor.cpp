#include<btdc++.h>
using namespace std;
#define int long long
int n, a[100001], p[100001], m[100001], cnt, pos;
struct node{
	int l, r, siz;
	node(){
		l = r = -1;
		siz = 0;
	}
}tr[3000001];
void add(int x){
	int now = 0;
	for(int i = 29; i >= 0; i--){
		if(x & (1 << i)){
			if(tr[now].r == -1)tr[now].r = ++cnt;
			now = tr[now].r;
		}else{
			if(tr[now].l == -1)tr[now].l = ++cnt;
			now = tr[now].l;
		}
		tr[now].siz++;
	}
}
int get(int x, int dep){
	if(x == -1)return 0;
	int res = 0;
	if(m[pos] & (1 << dep)){
		if(p[pos] & (1 << dep)){
			if(tr[x].l != -1)res += tr[tr[x].l].siz;
			return res + get(tr[x].r, dep - 1);
		}else{
			if(tr[x].r != -1)res += tr[tr[x].r].siz;
			return res + get(tr[x].l, dep - 1);
		}
	}else if(p[pos] & (1 << dep))return get(tr[x].r, dep - 1);
	return get(tr[x].l, dep - 1);
}
int query(int l, int r){
	if(l == r)return 0;
	int mid = (l + r) >> 1, ans = 0;
	p[mid] = m[mid] = a[mid];
	p[mid + 1] = m[mid + 1] = a[mid + 1];
	for(int i = mid - 1; i >= l; i--){
		p[i] = (p[i + 1] ^ a[i]);
		m[i] = max(m[i + 1], a[i]);
	}
	for(int i = mid + 2; i <= r; i++){
		p[i] = (p[i - 1] ^ a[i]);
		m[i] = max(its/sm[i - 1], a[i]);
	}
	if(n <= 2000){
		for(int i = l; i <= mid; i++)for(int j = mid + 1; j <= r; j++)if((p[i] ^ p[j]) <= max(m[i], m[j]))ans++;
	}else{
		cnt = 0;
		for(int i = l; i <= mid; i++)add(p[i]);
		for(int i = mid + 1; i <= r; i++){
			pos = i;
			ans += get(0, 29);
		}
		for(int i = 0; i <= cnt; i++){
			tr[i].l = tr[i].r = -1;
			tr[i].siz = 0;
		}
	}
	return ans + query(l, mid) + query(mid + 1, r);
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	cout << query(1, n) + n;
	return 0;
}
