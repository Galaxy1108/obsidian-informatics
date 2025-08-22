#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,p;
ll mol(ll x)
{
	return x>=p?x-p:x;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>p;
	int dpl[n+1][m+2]={0},sl[n+1][m+2]={0},suml[n+1][m+2]={0};
	int dpr[n+1][m+2]={0},sr[n+1][m+2]={0},sumr[n+1][m+2]={0};
	for(ll i=1;i<=m;++i)
	{
		dpl[1][i]=m-i+1;dpr[1][i]=i;
		suml[1][i]=mol(suml[1][i-1]+dpl[1][i]);sumr[1][i]=mol(sumr[1][i-1]+dpr[1][i]);
		sr[1][i]=mol(sr[1][i-1]+dpr[1][i]*1ll*i%p);
	}
	for(ll i=m;i>=1;--i)sl[1][i]=mol(sl[1][i+1]+dpl[1][i]*1ll*(m-i+1)%p);
	for(ll i=2;i<=n;++i)
	{
		for(ll j=1;j<=m;++j)
		{
			dpl[i][j]=dpr[i][j]=0;
			dpl[i][j]=mol(dpl[i][j]+sl[i-1][j]);
			dpl[i][j]=mol(dpl[i][j]+mol(suml[i-1][j-1]-sumr[i-1][j-1]+p)*1ll*(m-j+1)%p);
			dpr[i][j]=mol(dpr[i][j]+sr[i-1][j]);
			dpr[i][j]=mol(dpr[i][j]+mol(mol(sumr[i-1][m]-sumr[i-1][j]+p)-mol(suml[i-1][m]-suml[i-1][j]+p)+p)*1ll*j%p);
			suml[i][j]=mol(suml[i][j-1]+dpl[i][j]); 
			sumr[i][j]=mol(sumr[i][j-1]+dpr[i][j]); 
			sr[i][j]=mol(sr[i][j-1]+dpr[i][j]*1ll*j%p);
		}
		for(ll j=m;j;--j)
		sl[i][j]=mol(sl[i][j+1]+dpl[i][j]*1ll*(m-j+1)%p);
	}
	cout<<suml[n][m];
}//不戳的计数题~(￣▽￣)~* 
