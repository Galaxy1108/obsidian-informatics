#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
const int N=1e5+1;
ll n,tot,ans[N];
I f(ll x){return!x?0:f(x/10)+x%10;}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n;
	FOR(i,max(0ll,n-200),n)if(i+f(i)==n)ans[++tot]=i;
	cout<<tot<<'\n';
	FOR(i,1,tot)cout<<ans[i]<<'\n';
	return 0;
}
