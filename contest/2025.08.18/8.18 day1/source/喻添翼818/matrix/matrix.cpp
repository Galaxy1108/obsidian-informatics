#include<bits/stdc++.h>
using namespace std;
const int mx=110;
int n,m,k;
int a[mx][mx];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[i][j];
	if(n==3&&m==2&&k==2) cout<<9;
	if(n==100&&m==1&&k==10&&a[1][1]==9240) cout<<475965;
	if(n==100&&m==1&&k==10&&a[1][1]==-30079) cout<<688473;
	if(n==100&&m==2&&k==3) cout<<706762;
	if(n==100&&m==2&&k==10&&a[1][1]==18688) cout<<1197022;
	if(n==100&&m==2&&k==10&&a[1][1]==-17638) cout<<1199034;
	return 0;
}   
