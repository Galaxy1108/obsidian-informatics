#include <bits/stdc++.h>
using namespace std;
#define N 1000005
constexpr __int128 INF=((__int128(0x3f3f3f3f3f3f3f3f))<<64ll)+(__int128(0x3f3f3f3f3f3f3f3f));
int h,w,a[N],b[N];//a:ÏòÓÒ£¬b:ÏòÏÂ 
__int128 f[1005][1005];
ostream& operator<<(ostream& os,__int128 x){
	static char buf[55];
	int cnt=0;
	while(x){
		buf[++cnt]=(x%10)^48;
		x/=10;
	}
	for(int i=cnt;i>=1;i--){
		os<<buf[i];
	}
	return os;
}
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		cin>>a[i];
	}
	for(int i=1;i<=w;i++){
		cin>>b[i];
	}
	memset(f,0x3f,sizeof(f));
	f[1][1]=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(j>1)f[i][j]=min(f[i][j],f[i][j-1]+a[i]);
			if(i>1)f[i][j]=min(f[i][j],f[i-1][j]+b[j]); 
		}
	}
	cout<<f[h][w];
	return 0;
}

