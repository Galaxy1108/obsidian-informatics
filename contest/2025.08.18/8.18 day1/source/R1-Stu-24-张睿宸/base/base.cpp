#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(int i(a);i<=b;++i)
#define R(i,a,b) for(int i(a);i>=b;--i)
#define _ 0
using namespace std;
int n,range[2001][2];
int dp[2001][3];
bool book[2001][3];
inline int input(){
	int x;char ch;bool y=0;
	for(ch=getchar();!isdigit(ch);ch=getchar()) if(ch=='-') y=1;
	for(x=0;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return y?-x:x;
}
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	n=input();
	F(i,0,1) F(j,1,n) range[j][i]=input();
	F(i,1,n){
		dp[i][0]=dp[i][1]=dp[i][2]=-0x7fffffff-1;
		dp[i][0]=range[i][0]+range[i][1]+(dp[i-1][0]<0?0:dp[i-1][0]);
		book[i][0]=1;
		if(!book[i-1][1]){
			if(book[i-1][0]) dp[i][1]=range[i][1]+dp[i-1][0];
			book[i][1]=book[i-1][0];
		}else{
			dp[i][1]=range[i][1]+max(dp[i-1][1],dp[i-1][0]);
			book[i][1]=1;
		}
		if(!book[i-1][2]){
			if(book[i-1][1]) dp[i][2]=range[i][0]+range[i][1]+dp[i-1][1];
			book[i][2]=book[i-1][1];
		}else{
			dp[i][2]=range[i][0]+range[i][1]+max(dp[i-1][2],dp[i-1][1]);
			book[i][2]=1;
		}	
	} 
	cout<<dp[n][2];
	return ~~(0^_^0);
} 
