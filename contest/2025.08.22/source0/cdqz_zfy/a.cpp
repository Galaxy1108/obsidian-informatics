#include<bits/stdc++.h>
using namespace std;
bool mst;
#define int long long
const int maxn=1e7+5;
int s[maxn],ss[maxn],sss[maxn];
int n,m,mod;
void pre(){
	for(int i=1;i<=m;i++)ss[i]=(ss[i-1]+s[i])%mod;
	for(int i=1;i<=m;i++)sss[i]=(sss[i-1]+s[i]*i)%mod;
}
bool med;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	// cerr<<(&mst-&med)/1024.0/1024.0<<endl;
	cin>>n>>m>>mod;
	s[1]=1;pre();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)s[j]=((m-j+1)*ss[j-1]%mod+(m+1)*(ss[m]-ss[j-1]+mod)%mod+mod-(sss[m]-sss[j-1])+mod-(m-j+1)*(ss[m]-ss[m-j+1]+mod)%mod)%mod;
		pre();
	}
	cout<<ss[m]<<endl;
	return 0;
}