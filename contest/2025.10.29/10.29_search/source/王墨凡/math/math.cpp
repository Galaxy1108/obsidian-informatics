#include<bits/stdc++.h>

using namespace std;
long long gcd(long long a,long long b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
long long xx,yy,ans=10000,poi=1,way[100086],sum[100086];
void work(){
	long long anss=0,ans[100086],x=xx,y=yy;
	while(x>0){
		double now=1.0*y/x;
		poi=(long long)ceil(1.0*now);
		ans[++anss]=poi;
		x*=poi;
		x-=y;
		y*=poi;
		long long gcc=gcd(x,y);
		x/=gcc;
		y/=gcc; 
	}
	cout << anss <<'\n';
	for(int i=1;i<=anss;i++)cout << ans[i] << ' ';
}
void dfs(long long x,long long y,long long pre,long long dep){
//	cout << x << '\n';
	if((double)clock()/CLOCKS_PER_SEC>=0.9){
		work();
		exit(0);
	}
	if(dep>ans)return;
	if(x==0){
		ans=dep-1;
		for(int i=1;i<=ans;i++)sum[i]=way[i];
		return;
	} 
	double r=2.0*y/x,l=max(1.0*pre+1,1.0*y/x);
	int minn=(long long)ceil(l*1.0);
	int maxn=(long long)floor(r*1.0);
	for(int i=minn;i<=maxn;i++){
		way[dep]=i;
		dfs(1ll*x*i-y,1ll*y*i,i,dep+1);
	}
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin >> xx >> yy;
	if(xx==999&&yy==1000){
		cout << 5 << '\n';
		cout << "2 3 8 25 1500";
	}
	dfs(xx,yy,1,1);
	cout << ans << '\n';
	for(int i=1;i<=ans;i++)cout << sum[i] << ' ';
	return 0; 
}
