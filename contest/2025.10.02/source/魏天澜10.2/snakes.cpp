#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
int a[N];
int main(){
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	int T;
	cin>>T;
	int n;
	cin>>n;
	for(int s = 1;s<=T;s++){
		if(s==1){
			for(int i = 1;i<=n;i++)cin>>a[i];
		}
		else{
			int k;cin>>k;
			for(int i = 1;i<=k;i++){
				int x,y;
				cin>>x>>y;
				a[x] = y;
			}
		}
		if(n==3){
			int maxn = -1,maxi;
			for(int i = 1;i<=n;i++){
				if(a[i]>=maxn){
					maxn = a[i];
					maxi = i;
				}
			}
			if(maxn>(a[1]+a[2]+a[3]-maxn)||(2*maxn==a[1]+a[2]+a[3])&&maxi==3){
				cout<<1<<"\n";
			}
			else cout<<3<<"\n";
		}
	}
	return 0;
}
