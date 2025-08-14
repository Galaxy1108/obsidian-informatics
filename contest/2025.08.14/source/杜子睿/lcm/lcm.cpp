#include<bits/stdc++.h>
using namespace std;
int t,n;
long long sum,g[1000005],ans,p;
map<long long,long long> m;
long long pow(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)
			res=(res*x)%p;
		x=(x*x)%p;
		y>>=1;
	}
	return res;
}
void check(long long x){
	for(int i=2;i<=sqrt(x);i++){
		int cnt=0;
		while(x%i==0){
			cnt++;
			x/=i;
		}
		if(m[i]<cnt){
			sum*=pow(i,cnt-m[i]);
			sum=sum%p;
			m[i]=cnt;
		}
	}
	if(x!=1)
		if(m[x]<1){
			sum*=x;
			sum=sum%p;
			m[x]=1;
		}
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>p;
		map<long long,long long> mm;
		m=mm;
		sum=1;
		g[1]=1;
		ans=1;
		for(long long i=2;i<=n;i++){
			g[i]=g[i-1]*2;
			g[i]=g[i]%p;
			g[i]+=g[i-2];
			g[i]=g[i]%p;
			check(g[i]);
			ans=(ans+(sum*i)%p)%p;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
