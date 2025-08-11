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
constexpr const int N=200,K=7,B=(K+1)*K>>1,P=1e9+7;
int n,k,x[N+1];
namespace judge1{
	bool is(){
		return n*k<=25;
	}
	int ans,a[N+1][K+1];
	bool check(){
		for(int p=1;p<=n;p++){
			int cnt=0;
			for(int i=1;i<=k;i++){
				for(int j=p-k+i;j<=p;j++){
					cnt+=a[i][j];
				}
			}
			if(cnt!=x[p]){
				return false;
			}
		} 
		return true;
	}
	void make(int i,int j){
		if(j>n){
			make(i+1,1);
			return;
		}
		if(i>k){
			ans+=check();
			return;
		}
		a[i][j]=1;
		make(i,j+1);
		a[i][j]=0;
		make(i,j+1);
	}
	int main(){
		make(1,1);
		cout<<ans<<'\n';
		return 0;
	}
}
namespace judge2{
	int dp[2][K+1][K+1][K+1][K+1][K+1][K+1];
	int popcount(int x){
		int ans=0;
		while(x){
			ans++;
			x^=x&-x;
		}
		return ans;
	}
	int main(){
		bool mode;
		dp[mode][0][0][0][0][0][0]=1;
		int ans=0;
		for(int i=1;i<=n;i++){
			mode=!mode;
			memset(dp[mode],0,sizeof(dp[mode]));
			for(int a=0;!a||a<=min(6,x[i])&&k>=7;a++){
				for(int b=0;b<=min(5,x[i]-a)&&k>=6||!b;b++){
					for(int c=0;c<=min(4,x[i]-a-b)&&k>=5||!c;c++){
						for(int d=0;d<=min(3,x[i]-a-b-c)&&k>=4||!d;d++){
							for(int e=0;e<=min(2,x[i]-a-b-c-d)&&k>=3||!e;e++){
								for(int f=0;f<=min(1,x[i]-a-b-c-d-e)&&k>=2||!f;f++){
									for(int S=0;S<(1<<k);S++){
										int pl=popcount(S);
										if(pl+a+b+c+d+e+f!=x[i]){
											continue;
										}
										int pa=0,pb=0,pc=0,pd=0,pe=0,pf=0;
										if(k>=7){
											pa=b+(S>>5&1);
										}
										if(k>=6){
											pb=c+(S>>4&1);
										}
										if(k>=5){
											pc=d+(S>>3&1);
										}
										if(k>=4){
											pd=e+(S>>2&1);
										}
										if(k>=3){
											pe=f+(S>>1&1);
										}
										if(k>=2){
											pf=S&1;
										}
										int &A=dp[mode][pa][pb][pc][pd][pe][pf],&B=dp[!mode][a][b][c][d][e][f];
										A=(A+B)%P;
										if(i==n){
											ans=(ans+B)%P;
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]>(k*(k+1)>>1)){
			cout<<'0'<<endl;
			return 0;
		}
	}
	if(judge1::is()){
		judge1::main();
	}else{
		judge2::main();
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
