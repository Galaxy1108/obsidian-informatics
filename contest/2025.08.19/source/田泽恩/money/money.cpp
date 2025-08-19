#include <bits/stdc++.h>
using namespace std;
int n;
double cst,w[2025],c[2025],d[2025],rmb[2025],dlr[2025];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d%lf",&n,&cst);
	for(int i=1;i<=n;++i) scanf("%lf%lf%lf",w+i,c+i,d+i);
	rmb[0]=dlr[0]=0;
	for(int i=1;i<=n;++i){
		rmb[i]=max(rmb[i-1]+w[i],dlr[i-1]*d[i]+w[i]-cst);
		dlr[i]=max(dlr[i-1]+w[i]*c[i],rmb[i]*c[i]);
		double sum=0;
		for(int j=i;j;--j){
			sum+=w[j];
			dlr[i]=max(dlr[i],(rmb[j-1]+sum)*c[i]);
			rmb[i]=max(rmb[i],sum+dlr[j-1]*d[i]-cst);
		}
	}
	printf("%.4lf",rmb[n]);
	return 0;
}
