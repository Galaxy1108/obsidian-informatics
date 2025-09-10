#include<iostream>
#include<algorithm>
using namespace std;
int n,k,ans[1000086],sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int xx=1,yy=1,ii=i,jj=j;
			while(ii){
				int w=ii%10;
				xx*=w;
				ii/=10;
			}
			while(jj){
				int w=jj%10;
				yy*=w;
				jj/=10;
			}
			if(1<=xx&&xx<=n&&1<=yy&&yy<=n)ans[(xx-1)*n+yy]++;
		}
	}
	sort(ans+1,ans+1+n*n,cmp);
	for(int i=1;i<=k;i++){
		sum+=ans[i];
	}
	cout << sum;
}
