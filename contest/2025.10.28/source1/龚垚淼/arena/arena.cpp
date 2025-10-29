#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
const long long p=998244353;
long long n,x,ans;
int a[200];
bool check(){
	int hert=0;
	while(1){
		int r=0,la=hert;
		for(int i=1;i<=n;++i){
			hert+=(a[i]>la);
		}
		hert--;
		for(int i=1;i<=n;++i){
			r+=(a[i]>hert);
		}
		if(r==0) return 1;
		if(r==1) return 0;
	}
}
void dfs(int deep){
	if(deep>n){
		if(check()){
			++ans;
		}
		return ;
	}
	for(int i=1;i<=x;++i){
		a[deep]=i;
		dfs(deep+1);
	}
}
bool ksm(long long num,int y){
	long long sum=1;
	while(y){
		if(y&1) sum*=num;
		if(num>=100000000) return 0;
		num*=num,y>>=1;
		//cout<<sum<<endl;
		if(sum>=100000000) return 0;
		//cout<<y<<endl;
	}
	//cout<<2222<<endl;
	return 1;
}
long long ksm2(long long num,int y){
	long long sum=1;
	while(y){
		if(y&1) sum=sum*num%p;
		num=num*num%p;y>>=1;
	}
	return sum;
}
int dp[50][50];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),x=read();
	if(n==1){
		cout<<0;
	}
	else if(n==3){
		int sum=1;
		for(int i=1;i<=x;++i){
			ans=(ans+sum)%p;
			if(i&1) sum+=6;
		}
		cout<<ans;
	}
	else if(n==2){
		cout<<x;
	}
	else if(ksm(x,n)){
		dfs(1);
		cout<<ans;
	}
	else{
		//cout<<"1111"<<endl;
		cout<<ksm2(x,n);
	}
	return 0;
}
