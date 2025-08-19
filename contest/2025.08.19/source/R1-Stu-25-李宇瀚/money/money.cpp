#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e6+5;

double f1[MAXN],f2[MAXN];
int n,cost;
double w[MAXN],c[MAXN],d[MAXN];

signed main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n>>cost;
	for(int i=1;i<=n;i++) cin>>w[i]>>c[i]>>d[i];
	for(int i=1;i<=n;i++) f1[i]=f2[i]=-9999999999999999;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++) f1[i]=max(f1[i],f1[j]+w[i]);
		for(int j=0;j<i;j++) f1[i]=max(f1[i],f2[j]*d[i]+w[i]);
		for(int j=0;j<i;j++) f2[i]=max(f2[i],f2[j]);
		for(int j=0;j<i;j++) f2[i]=max(f2[i],f1[j]*c[i]-cost);
		f1[i]=max(f1[i],f2[i]*d[i]+w[i]);
		f2[i]=max(f2[i],(f1[i]+w[i])*c[i]-cost);
	}
	printf("%.4lf",f1[n]);
	return 0;
}
