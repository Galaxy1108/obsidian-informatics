#include<bits/stdc++.h> 
using namespace std;
const int mod=1e9+7;
long long n;
struct node{
	long long a[15][15]={{1,1,1,0,0,0,0,0,0,0},{1,1,1,1,0,0,0,0,0,0},{1,1,1,1,1,0,0,0,0,0},{0,1,1,1,1,1,0,0,0,0},{0,0,1,1,1,1,1,0,0,0},{0,0,0,1,1,1,1,1,0,0},{0,0,0,0,1,1,1,1,1,0},{0,0,0,0,0,1,1,1,1,1},{0,0,0,0,0,0,1,1,1,1},{0,0,0,0,0,0,0,1,1,1}};;
}a,ans;
node operator*(node x,node y){
	node z;
	memset(z.a,0,sizeof z.a);
	for(int k=0;k<10;k++)
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;	
	return z;
}
void pow(){
	long long y=n-2;
	while(y){
		if(y&1)
			ans=ans*a;
		a=a*a;
		y>>=1;
	}
}
int main(){
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	pow();
	long long s[10]={0,1,1,1,1,1,1,1,1,1};
	long long cnt=0;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cnt=(cnt+s[j]*ans.a[i][j]%mod)%mod;
	cout<<cnt;
	return 0;
}
