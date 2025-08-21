#include<bits/stdc++.h>
using namespace std;
const int inf=1000000007;
long long a[5010];
//bool comp(long long x1,long long x2){
//	return x1>x2;
//}
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long ans1=0,ans2=0;
	for(int i=1;i<=n;i=i+1){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=a[n];i=i+1){
		for(int j=1;j<=n;j=j+1){
			if(a[j]>=i){
				ans1+=i;
			}
		}
		ans2+=1;
	}
	double ans=ans1/ans2;
	int sh=ans/inf;
	printf("%d",(ans-inf*sh));
	return 0;
}
