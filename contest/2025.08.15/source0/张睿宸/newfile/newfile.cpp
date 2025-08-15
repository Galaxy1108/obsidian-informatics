#include<bits/stdc++.h>
#define F(i,a,b) for(int i(a),i##i##end(b);i<=i##i##end;++i)
#define R(i,a,b) for(int i(a),i##i##end(b);i>=i##i##end;--i)
#define ll long long
using namespace std;
const int MOD=1e9+9;
int n,m,q;
struct Meow{
	int l,r,x;
}op[100001];
int sum[100001];
inline void add(int l,int r,int x){
	int cnt(x);
	F(i,l,n){
		sum[i]+=cnt;
		sum[i]>=MOD&&(sum[i]-=MOD);
		i<r&&(cnt+=x);
		cnt>=MOD&&(cnt-=MOD);
	}
	return;
}
int main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	F(i,1,m) cin>>op[i].l>>op[i].r>>op[i].x;
	F(i,1,q){
		int u,d,l,r;
		cin>>u>>d>>l>>r;
		int ans(0);
		memset(sum,0,sizeof(sum));
		F(i,1,d){
			add(op[i].l,op[i].r,op[i].x);
			if(i>=u){
				ans+=sum[r]-sum[l-1];
				ans>=MOD&&(ans-=MOD);
				ans<0&&(ans+=MOD);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
