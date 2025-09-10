#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(int i(a);i<=b;++i)
#define R(i,a,b) for(int i(a);i>=b;--i)
#define _ 0
using namespace std;
const int MOD=1e9+7;
int k;
ll n,ans;
int num[1001][1001],gold[2000000],cnt;
inline int f(int x){return x?f(x/10)*(x%10):1;}
int main(){
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	scanf("%lld%d",&n,&k);
	if(n>1000) while(1);
	F(i,1,n) F(j,1,n) ++num[f(i)][f(j)];
	F(i,1,n) F(j,1,n) gold[++cnt]=num[i][j];
	sort(gold+1,gold+cnt+1,greater<int>());
	F(i,1,k) ans+=gold[i];
	cout<<ans;
	return ~~(0^_^0);
}
