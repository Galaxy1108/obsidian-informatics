#include <bits/stdc++.h>
using namespace std;
#define N 1005
long double f[N<<1][N],ans;
int n,w,b;
int main(){
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>w>>b;
	n=w+b;
	ans=0.0L;
	f[n][w]=1.0L;
	for(int i=n;i>=1;i--){
		for(int j=min(w,i),k;j>=0;j--){
			k=i-j;
			switch((n-i)%3){
			case 0://A
				if(j<i)f[i-1][j]+=f[i][j]*k/((long double)i);
				if(j>0)ans+=f[i][j]*j/((long double)i);
				break;
			case 1://B
				if(j<i)f[i-1][j]+=f[i][j]*k/((long double)i);
				break;
			case 2://jump out
				if(j<i)f[i-1][j]+=f[i][j]*k/((long double)i);
				if(j>0)f[i-1][j-1]+=f[i][j]*j/((long double)i);
				break;
			}
		}
	}
	cout<<fixed<<setprecision(9)<<ans;
	return 0;
}

