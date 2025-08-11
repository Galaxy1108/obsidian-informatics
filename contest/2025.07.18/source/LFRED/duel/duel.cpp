#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q;
int p[N];
int workans(int l,int r){
	if(l == r) return p[l];
	int mid = ((l + r) >> 1);
	int x = workans(l,mid);
	int y = workans(mid + 1,r);
	return (max(x,y) - min(x,y));
}
struct node{
	int op,x,y;
}que[N];
int st[N][21];
int logn[N];
int tree[N << 2];
void pushup(int x){tree[x] = max(tree[x * 2],tree[x * 2 + 1]) - min(tree[x * 2],tree[x * 2 + 1]);}
void build(int x,int l,int r){
	if(l == r) tree[x] = p[l];
	if(l == r) return;
	int mid = ((l + r) >> 1);
	build(x * 2,l,mid);
	build(x * 2 + 1,mid + 1,r);
	pushup(x);
}
void update(int x,int l,int r,int pos,int k){
	if(l == r) tree[x] = k;
	if(l == r) return;
	int mid = ((l + r) >> 1);
	if(pos <= mid) update(x * 2,l,mid,pos,k);
	else update(x * 2 + 1,mid + 1,r,pos,k);
	pushup(x);
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for(int i = 2;i <= n;++i) logn[i] = logn[i / 2] + 1;
	for(int i = 1;i <= n;++i) cin >> p[i];
	if(n <= 1000 && q <= 1000){
		while(q--){
			int op,x,y;
			cin >> op >> x >> y;
			if(op == 1){
				p[x] = y;
			}else{
				int l = x,r = x + (1 << y) - 1;
				cout << workans(l,r) << "\n";
			}
		}
		return 0;
	}
	bool if_n = 1;
	for(int i = 1;i <= q;++i){
		cin >> que[i].op >> que[i].x >> que[i].y;
		if(que[i].op == 1) if_n = 0;
	}
	if(if_n){
		for(int i = 1;i <= n;++i) st[i][0] = p[i];
		for(int log = 1;log <= 20;++log){
			for(int i = 1;i + (1 << log) - 1 <= n;++i){
				st[i][log] = max(st[i][log - 1],st[i + (1 << (log - 1))][log - 1]) - min(st[i][log - 1],st[i + (1 << (log - 1))][log - 1]);
			}
		}
		for(int i = 1;i <= q;++i){
			if(que[i].op == 1) continue;
			cout << st[que[i].x][que[i].y] << "\n";
		}
		return 0;
	}
	build(1,1,n);
	for(int i = 1;i <= q;++i){
		if(que[i].op == 1){
			p[que[i].x] = que[i].y;
			update(1,1,n,que[i].x,que[i].y);
		}else{
			cout << tree[1] << "\n";
		}
	}
	return 0;
} 
