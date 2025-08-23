#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e7 + 7;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T>inline void read(T& r) {
	r=0;bool w=0; char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9') r=r*10+(ch^48), ch=getchar();
	r=w?-r:r;
}

int n, f[N], w[N], siz[N];
ll wa[N], mx[N], tmx[N], cmx[N];
int mxp[N], c1[N], c2[N], c3[N], ns[N];
int main() {
//	return system("fc treeq.ans treeq.out"), 0;
	freopen("treeq.in", "r", stdin);
	freopen("treeq.out", "w", stdout);
	read(n);
	L(i, 2, n) read(f[i]), read(w[i]);
	
	R(i, n, 2) siz[i] += 1, siz[f[i]] += siz[i];
	siz[1] += 1;
	
	L(i, 2, n) wa[i] = (ll) w[i] * siz[i];
	
	R(i, n, 2) {
		ll omx = max(wa[i], mx[i]);
		if(omx > mx[f[i]]) tmx[f[i]] = mx[f[i]], mx[f[i]] = omx, mxp[f[i]] = i;
		else tmx[f[i]] = max(tmx[f[i]], omx);
	} 
	
	cmx[1] = 0;
	L(i, 2, n) {
		cmx[i] = max(cmx[f[i]], (ll) w[i] * (n - siz[i])); 
		if(i == mxp[f[i]]) cmx[i] = max(cmx[i], tmx[f[i]]);
		else cmx[i] = max(cmx[i], mx[f[i]]);
	} 
	
	L(i, 1, n) {
		if(mx[i] >= cmx[i]) c1[i] += 1;
		if(cmx[i] >= mx[i]) c2[i] += 1;
	}
	
	R(i, n, 2) {
		if(cmx[i] == (ll) w[i] * (n - siz[i])) ns[i] += c2[i];
		if(cmx[i] == cmx[f[i]]) c2[f[i]] += c2[i];
		if(i == mxp[f[i]]) {
			if(cmx[i] == tmx[f[i]]) c3[f[i]] += c2[i];
		} 
		else if(cmx[i] == mx[f[i]]) {
			c1[f[i]] += c2[i];
			if(mx[i] == mx[f[i]]) c1[i] -= c2[i];
			if(wa[i] == mx[f[i]]) ns[i] -= c2[i];
		} 
	}
	
	L(i, 2, n) {
		ll omx = max(wa[i], mx[i]);
		int cnt = 0;
		if(omx == mx[f[i]]) cnt += c1[f[i]];
		if(i != mxp[f[i]] && omx == tmx[f[i]]) cnt += c3[f[i]];
		if(cnt) {
			if(wa[i] == omx) ns[i] += cnt;
			if(mx[i] == omx) c1[i] += cnt;
		} 
	} 
	 
	int oplus = 0;
	L(i, 1, n) oplus ^= ns[i];
	cout << oplus << '\n';
	return 0;
}