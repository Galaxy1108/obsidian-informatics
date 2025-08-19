#include<bits/stdc++.h>
using namespace std;
int n,cost,w[2051];
double c[2051],d[2051],f[2051][2];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n>>cost;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>c[i]>>d[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0]+w[i]-cost+f[i-1][1]*d[i],f[i-1][0]+w[i]);
		f[i][1]=max(f[i-1][1]+f[i-1][0]*c[i],f[i][1]);
	}
	printf("%.4lf",f[n][0]);
	return 0;
}
