#include<bits/stdc++.h>
#define int long long
#define N 1000000
#define r(x) ((x-1)%n+1)
using namespace std;
int n,a[N+5],dp[N+5][2][2];
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
void pans(int x,int y,int z){
	if(!x)return;
	if(!y&&!z){
		if(dp[x-1][0][1]&&a[x]>=a[r(x+1)])pans(x-1,0,1);
		else pans(x-1,1,1);
	}
	else if(y&&!z){
		if(dp[x-1][0][0]&&a[x]<=a[r(x+1)])pans(x-1,0,0);
		else pans(x-1,1,0);
	}
	else if(!y&&z){
		if(dp[x-1][0][1]&&a[x]*2>=a[r(x+1)])pans(x-1,0,1);
		else pans(x-1,1,1);
	}
	else{
		if(dp[x-1][0][0]&&a[x]*2<=a[r(x+1)])pans(x-1,0,0);
		else pans(x-1,1,0);
	}
	if(y)print(r(x+1)),putchar(' ');
	else print(x),putchar(' ');
	return;
}
main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
//	cout<<"sadfasdfsda\n";
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<=n;k++)dp[k][0][0]=dp[k][0][1]=dp[k][1][0]=dp[k][1][1]=0;
			dp[0][i][j]=1;
//			cout<<i<<" "<<j<<"\n";
			for(int k=1;k<=n;k++){
				dp[k][0][0]=((dp[k-1][0][1]&&a[k]>=a[r(k+1)])||(dp[k-1][1][1]&&a[k]>=a[r(k+1)]*2));
				dp[k][1][0]=((dp[k-1][0][0]&&a[k]<=a[r(k+1)])||(dp[k-1][1][0]&&a[k]<=a[r(k+1)]*2));
				dp[k][0][1]=((dp[k-1][0][1]&&a[k]*2>=a[r(k+1)])||(dp[k-1][1][1]&&a[k]>=a[r(k+1)]));
				dp[k][1][1]=((dp[k-1][0][0]&&a[k]*2<=a[r(k+1)])||(dp[k-1][1][0]&&a[k]<=a[r(k+1)]));
//				cout<<dp[k][0][0]<<" "<<dp[k][1][0]<<" "<<dp[k][0][1]<<" "<<dp[k][1][1]<<" "<<k<<" "<<a[k]<<" "<<a[r(k+1)]<<"\n";
			}
			if(dp[n][i][j]){
//				cout<<i<<" "<<j<<" good\n";
				pans(n,i,j),putchar('\n');
				return 0;
			}
		}
	}
	printf("NIE");
	return 0;
}
