#include<bits/stdc++.h>
#define Max(a,b) a=max(a,b) 
using namespace std;
const int N=2005;
int n;
double c,w[N],a[N],b[N];
double f1[N],f2[N];//人民币，美元 
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>w[i]>>a[i]>>b[i];
	f1[0]=f2[0]=0;
	for(int i=1;i<=n;i++){
		f1[i]=max(f1[i-1]+w[i],f2[i-1]*b[i]+w[i]-c);
		f2[i]=max(f2[i-1]+w[i]*a[i],f1[i]*a[i]); 
		double sum=0;
		for(int j=i;j;j--){
			sum+=w[j];
			Max(f2[i],(f1[j-1]+sum)*a[i]);
			Max(f1[i],sum+f2[j-1]*b[i]-c);
		}
	}
	cout<<fixed<<setprecision(4)<<f1[n];
	return 0;
}
