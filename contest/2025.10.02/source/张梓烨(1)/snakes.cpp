#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int a[100005];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++){
		if(l==1){
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
		}else{
			cin>>k;
			for(int i=1;i<=k;i++){
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
		}
		int sum=a[1];
		int o=n;
		for(int i=2;i<=n-1;i++){
			sum+=a[i];
			if(sum>=a[n]) break;
			o--;
		}
		if(o==2) cout<<1<<endl; 
		else cout<<o<<endl;
	}
	return 0;
} 
