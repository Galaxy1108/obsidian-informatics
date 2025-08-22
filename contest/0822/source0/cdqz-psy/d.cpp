#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int x[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}		
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int l,r,ans=0;cin>>l>>r;
		for(int c=1;c<=10;c++){
			for(int a=0;a<=10;a++){
				for(int b=0;b<=10;b++){
					if(ans) break;
					int ok=1;
					for(int j=l;j<=r;j++){
						if((a*(j-l)+b)/c!=x[j]) ok=0;
					}
					if(ok){
						cout<<a<<" "<<b<<" "<<c<<"\n";
						ans=1;
					}
				}
			}
		}
		if(!ans){
			if(l==r){
				cout<<0<<" "<<x[l]<<" "<<1<<"\n";
			}
			else{
				int a=(x[l+1]-x[l]),b=x[l];
				cout<<a<<" "<<b<<" "<<1<<"\n"; 
			}				
		}
	}
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;cin>>T;
	while(T--) solve(); 
} 
