#include<bits/stdc++.h>
using namespace std;
const int maxn=405;
string s;
int dp[maxn][maxn];
int cnt0,cnt1,cnt2;
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>s;
	int len=s.size();
	int cnt;
	for(int i=0;i<len;i++){
		if(s[i]=='0') cnt0++;
		else if(s[i]=='1') cnt1++;
		else if(s[i]=='2') cnt2++;
	}
	if(cnt0>len/2||cnt1>len/2||cnt2>len/2){
		cout<<-1;
		return 0;
	}
	memset(dp,0x3f3f,sizeof(dp));
	for(int i=1;i<=len;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<len;i++){
		for(int j=1;j<len;j++){
			if(s[i]==s[i-1]&&s[j]==s[j+1])dp[i][j]=min(dp[i-1][j+1]+2,dp[i][j]);
			else if(s[i]==s[i-1])dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
			else if(s[j]==s[j+1])dp[i][j]=min(dp[i][j+1]+1,dp[i][j]);
			else dp[i][j]=min(dp[i-1][j],dp[i][j+1]);
		}
	}
	cout<<dp[1][len-1];
	return 0;
}
