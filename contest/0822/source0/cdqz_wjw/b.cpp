#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int w[2005][2005];
bool ch2=1;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			int x;
			cin>>x;
			if(x!=1&&x!=1000000000)ch2=0;
			w[i][j+i]=w[i+j][i]=x;
		}
	}
	if(ch2){
		bool ch=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(w[i][j]==1){
					ch=1;
					break;
				}
			}
			if(ch)break;
		}
		if(!ch){
			for(int i=1;i<=n;i++){
				cout<<1000000000ll*(n-1)<<"\n";
			}
			return 0;
		}
		for(int i=1;i<=n;i++){
			ch=0;
			for(int j=1;j<=n;j++){
				if(w[i][j]==1){
					ch=1;break;
				}
			}
			if(!ch)cout<<1000000000+(n-2)<<"\n";
			else cout<<n-1<<"\n";
		}
	}
	return 0;
}
