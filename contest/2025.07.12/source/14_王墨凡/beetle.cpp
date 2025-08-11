#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int mod=1e9+7,a[2500086],mx[2500086];
long long lasti,lastn,n,k,h=1,t=1,f[2500086],ans,x=1;
char s;
struct num{
	int index,val;
}q[2500086];
int qread(){
	char s;
	int ans=0;
	while(1){
		s=getchar();
		if(s<'0' or s>'9')break;
		ans*=10;
		ans+=s-'0';
	}
	return ans;
}
int main(){
	freopen("w.in","r",stdin);
	cin >> n >> k;
	s=getchar();
	for(int i=1;i<=n;i++)a[i]=qread();
	for(int i=1;i<=n;i++){
		while(h<t and q[h].index+k<=i)h++;
		while(h<t and q[t].val<a[i])t--;
		q[t++].index=i,q[t].val=a[i];
		mx[i]=q[h+1].val;
		cout << mx[i] << ' ';
	}
	cout << endl;
	for(int i=1;i<=n;i++){
		if(i<=k){
			f[i]=mx[i]; 
		}
		else if(mx[i]<=mx[i-1])f[i]=f[i-k]+mx[i];
		else f[i]=f[i-1]+mx[i];
		cout << f[i] << ' ';
	}
	for(int i=n;i>=1;i--){
		x%=mod;
		ans+=f[i]*x;
		ans%=mod;
		x*=23;
	}
	cout << ans;
	return 0;
}
