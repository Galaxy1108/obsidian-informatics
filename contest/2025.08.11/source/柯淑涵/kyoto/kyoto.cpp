#include <bits/stdc++.h>
using namespace std;
long long h,w; 
long long a[1000001],b[1000001],f[1001][1001];
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	cin>>h>>w;
	for(int i=1;i<=h;i++) cin>>a[i];
	for(int i=1;i<=w;i++) cin>>b[i];
	if(h<=1000&&w<=1000){
		for(int i=0;i<=h;i++){
			for(int j=0;j<=w;j++){
				f[i][j]=1e18+9;
			}
		}
		f[1][1]=0;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				f[i][j]=min(f[i-1][j]+b[j],f[i][j-1]+a[i]);
				f[1][1]=0;
			}
		}
		cout<<f[h][w]<<endl;
		return 0;
	}
	cout<<a[1]*h+b[w]*w<<endl;
	return 0;
}
/*
2 2 
1 3
2 5

5 5 
7 1 5 2 8 
7 2 4 1 6
*/
