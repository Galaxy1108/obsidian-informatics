#include<bits/stdc++.h>
using namespace std;
int n,m,p,id;
long long f[2][10000005][2],s[10000005][2];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>p;
	for(int i=1;i<=m;i++){
		f[0][i][0]=(f[0][i-1][0]+i)%p;
		s[i][0]=(s[i-1][0]+f[0][i][0])%p;
	}
	for(int i=m;i>=1;i--){
		f[0][i][1]=(f[0][i+1][1]+m-i+1)%p;
		s[i][1]=(s[i+1][1]+f[0][i][1])%p;
	}
	for(int i=1;i<n;i++){
		id^=1;
		f[id][0][0]=0;
		f[id][m+1][1]=0;
		for(int j=1;j<=m;j++)
			f[id][j][0]=(j*f[id^1][m][0]+2*p-s[j-1][0]-j*f[id^1][j+1][1]%p+f[id][j-1][0])%p;
		for(int j=m;j>=1;j--)
			f[id][j][1]=((m-j+1)*f[id^1][m][0]+2*p-s[j+1][1]-(m-j+1)*f[id^1][j-1][0]%p+f[id][j+1][1])%p;
		for(int j=1;j<=m;j++)
			s[j][0]=(s[j-1][0]+f[id][j][0])%p;
		for(int j=m;j>=0;j--)
			s[j][1]=(s[j+1][1]+f[id][j][1])%p;
	}
	cout<<f[id][m][0];
	return 0;
}
