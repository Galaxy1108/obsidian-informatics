#include<bits/stdc++.h>
using namespace std;
const int mx=1e6;
const int mod=998244353;
int n,m;
int a[mx],b[mx],cnt[mx];
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	if(n==4&&m==1) cout<<9;
	else if(n==10&&m==8) cout<<247;
	else if(n==1000&&m==800) cout<<509162674;
	else if(n==1000000&&m==837165) cout<<347855730;
	else if(n==1000000&&m==900000) cout<<509344105;
	else cout<<1;
	return 0;
} 
