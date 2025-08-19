//#include<bits/stdc++.h>
#include<algorithm> 
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef long long ll;
constexpr const int V=1e6;
namespace judge1{
	bool is(int a,int b,int c,int d,int k){
		return b<=100&&d<=100;
	}
	int gcd(int a,int b){
		while(b){
			int tmp=a;
			a=b;
			b=tmp%b;
		}
		return a;
	}
	ll query(int a,int b,int c,int d,int k){
		ll ans=0;
		for(int i=a;i<=b;i++){
			for(int j=c;j<=d;j++){
				if(gcd(i,j)==k){
					ans++;
				}
			}
		}
		return ans;
	}
}
namespace judge2{
	int preMu[V+1];
	void pre(){
		preMu[1]=1;
		static bool vis[V+1];
		static int size,prime[V+1];
		for(int i=2;i<=V;i++){
			if(!vis[i]){
				preMu[i]=-1;
				prime[++size]=i;
				vis[i]=i;
			}
			for(int j=1;j<=size&&i*prime[j]<=V;j++){
				vis[i*prime[j]]=prime[j];
				if(i%prime[j]==0){
					break;
				}
				preMu[i*prime[j]]=-preMu[i];
			}
		}
		for(int i=1;i<=V;i++){
			preMu[i]+=preMu[i-1];
		}
	}
	ll query(int a,int b,int c,int d,int k){
		ll ans=0;
		if(b>d){
			swap(a,c);swap(b,d);
		}
		for(int l=1,r=0;l<=b;l=r+1){
			int tb=b/l,td=d/l;
			int ta=(a-1)/l,tc=(c-1)/l;
			r=min(b/tb,d/td);
			if(ta){
				r=min(r,(a-1)/ta); 
			}
			if(tc){
				r=min(r,(c-1)/tc);
			}
			ans+=(tb/k-ceil(1.0*a/k/l)+1ll)*(td/k-ceil(1.0*c/k/l)+1ll)*(preMu[r]-preMu[l-1]);
		} 
	//	for(int t=1;t<=b;t++){
	//		ans+=mu[t]*(b/k/t-ceil(1.0*a/k/t)+1ll)*(d/k/t-ceil(1.0*c/k/t)+1ll);
	//	}
		return ans;
	}
} 
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	judge2::pre();
	int T;
	cin>>T;
	while(T--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k; 
		if(judge1::is(a,b,c,d,k)){
			cout<<judge1::query(a,b,c,d,k)<<'\n';
		}else{
			cout<<judge2::query(a,b,c,d,k)<<'\n';
		}
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
