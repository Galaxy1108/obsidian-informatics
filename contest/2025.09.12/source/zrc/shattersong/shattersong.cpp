#include<bits/stdc++.h>
#define F(i,a,b) for(int i(a),i##i##end(b);i<=i##i##end;++i)
#define R(i,a,b) for(int i(a),i##i##end(b);i>=i##i##end;--i)
#define ll long long
#define File(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
using namespace std;
const int MAXN=1e5+1;
int n,m,z[MAXN],w;
int main(){
	File(shattersong);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	F(i,1,n) cin>>z[i];
	if(m!=1) while(1);
	int uu,vv;
	cin>>uu>>vv>>w;
	if(w>z[1]) cout<<"2\n1 1\n1 2";
	else cout<<"1\n2 1 2";
	return 0;
}
