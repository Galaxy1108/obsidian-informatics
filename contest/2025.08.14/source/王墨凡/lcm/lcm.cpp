#include<iostream>
#include<cstdio> 
using namespace std;
unsigned __int128 ans,pref[1000086],pree[1000086],lcm[1000086],inf=1;
long long t,n,p;
unsigned __int128 wgcd(__int128 a,__int128 b){
//	if(a<0 or b<0)cout << '!';
	if(b==0){
		return a;
	}
	return wgcd(b,a%b);
}
void premade(int n){
	pree[1]=1,pref[1]=1;
	for(int i=2;i<=n;i++){
		pree[i]=pree[i-1]+pref[i-1]*2;
		pref[i]=pree[i-1]+pref[i-1];
	}
}
void prelcm(int n){
	lcm[1]=1;
	lcm[2]=2;
	for(int i=3;i<=n;i++){
		unsigned __int128 k=wgcd(lcm[i-1],pref[i]);
		lcm[i]=lcm[i-1]*pref[i]/k;
//		lcm[i]%=p;
	}
}
void write(unsigned __int128 x){
	char c=x%10+'0';
	if(x<10){
		putchar(c);
		return;
	}
	write(x/10);
	putchar(c);
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	cin >> t;
	long long tt=t;
	while(t--){
		cin >> n >> p;
		ans=0;
		premade(n);
		prelcm(n);
		for(int i=1;i<=n;i++){
			ans+=i*lcm[i]%p;
			ans%=p;
		}
		write(ans);
		cout << '\n';
	}
	return 0;
} 
