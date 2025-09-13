#include <bits/stdc++.h>
#define hh cout << endl;
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 4e6 + 10;
char c[N];
int f[N];
struct T{
	int fi, se, id;
}q[N];int qi;
bool cmp (T x, T y){
	return (x.fi == y.fi) ? x.se < y.se : x.fi < y.fi; 
}
int find(int x){
	return (x == f[x]) ? x : f[x] = find(f[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	f[fy] = fx;
}
int p[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("virtual.in", "r", stdin);
	freopen("virtual.out", "w", stdout);
	int n, lk, rk;
	cin >> n >> lk >> rk;
//	c[1] = getchar();
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		p[i] = p[i - 1];
		if(c[i] == 'a')p[i]++;
		f[i] = i;
//		cout << c[i];
	}
	if(lk == rk){
		c[0] = 'a';
		for(int i = 1; i <= n; i++){
			if(p[i] < lk)continue;
			int l = lower_bound(p, p + i, max(p[i] - rk, 0)) - p;
			int r = upper_bound(p + 1, p + i, p[i] - lk) - p;
			if(c[l] == 'a')l++;
//			if(l > r)continue;
			q[++qi].fi = l, q[qi].se = r, q[qi].id = i;
	//		cout << l << " " << r << " " << i << endl; 
	//		merge(l, i);
	//		merge(r, i);
		}
	}
//	hh
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j < i; j ++){
//			if(p[i] - p[j - 1] < lk)break;
//			if(p[i] - p[j - 1] >= lk && p[i] - p[j - 1] <= rk)merge(i, j);
//		}
//	}
	else{
		c[0] = 'a';
		for(int i = 1; i <= n; i++){
			if(p[i] < lk)continue;
			int l = lower_bound(p, p + i, max(p[i] - rk, 0)) - p;
			int r = upper_bound(p + 1, p + i, p[i] - lk) - p;
			if(c[l] == 'a')l++;
			if(l > r)continue;
			q[++qi].fi = l, q[qi].se = r, q[qi].id = i;
	//		cout << l << " " << r << " " << i << endl; 
	//		merge(l, i);
	//		merge(r, i);
		}
	}
	sort(q + 1, q + qi + 1, cmp);
	int lstr = 1e9, lstl = q[1].fi;
	vector<int> v;
	for(int i = 1; i <= qi; i++){
		if(q[i].fi == 0 || q[i].se == 0)continue;
		if(q[i].fi <= lstr){
			lstr = q[i].se;
//			lstl = q[i].fi;
			v.push_back(q[i].id);
		}
		else{
			
			for(int j = lstl; j <= lstr; j++){
				merge(q[i - 1].id, j);
			}
			for(int j = 0; j < v.size(); j++)merge(v[j], q[i - 1].id);
			v.clear();
			lstl = q[i].fi;
			lstr = q[i].se;
		}
//		cout << q[i].fi << " " << q[i].se << endl;
	}
//		cout << lstl << " " << lstr << endl;
	for(int j = 0; j < v.size(); j++)merge(v[j], q[qi].id);
	v.clear();
	for(int j = lstl; j <= lstr; j++){
		merge(j, q[qi].id);
//		cout << j << " ";
	}	
	int Q;
	cin >> Q;
	while (Q--){
		int x, y;
		cin >> x >> y;
		if(find(x) == find(y)){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
} 
