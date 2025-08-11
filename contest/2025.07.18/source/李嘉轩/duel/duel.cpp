//要是再把stack写成queue我就**** ***
#include<bits/stdc++.h>
using namespace std;
int p[200001];
struct node{int p, l;};
stack<node>st;
bool update(){
	if(st.size() < 2)return false;
	node a, b;
	a = st.top();
	st.pop();
	b = st.top();
	if(a.l == b.l){
		st.pop();
		st.push({abs(a.p - b.p), a.l + 1});
		return true;
	}
	st.push(a);
	return false;
}
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n, q, op, x, y;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)cin >> p[i];
	while(q--){
		cin >> op >> x >> y;
		if(op == 1)p[x] = y;
		else{
			for(int i = x; i < (x + (1 << y)); i++){
				st.push({p[i], 0});
				while(update());
			}
			cout << st.top().p << "\n";
			st.pop();
		}
	}
	return 0;
}
