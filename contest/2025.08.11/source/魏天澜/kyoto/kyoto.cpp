#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;
ll a[N][N];
ll s1[N],s2[N];

int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	int h,w;
	cin>>h>>w;
	for(int i = 1;i<=h;i++)cin>>s1[i];
	for(int j = 1;j<=w;j++)cin>>s2[j];
	for(int i = 1;i<=h;i++){
		for(int j = 1;j<=w;j++){
			if(i==1&&j==1)continue;
			else if(i==1)a[i][j] = a[i][j-1]+s1[i];
			else if(j==1)a[i][j] = a[i-1][j]+s2[j];
			else a[i][j]  = min(a[i][j-1]+s1[i],a[i-1][j]+s2[j]);
		}
	}
	cout<<a[h][w]<<endl;
	return 0;
}
