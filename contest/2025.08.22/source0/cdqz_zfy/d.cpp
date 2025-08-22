#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int T,n,a[maxn],q;
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		cin>>q;
		for(int i=1;i<=q;i++){
			int l,r;cin>>l>>r;
			if(l==r)cout<<0<<" "<<a[l]<<" "<<1<<endl;
			else if(l==r-1){
				if(a[l]==a[r])cout<<0<<" "<<a[l]<<" "<<1<<endl;
				else cout<<a[r]-a[l]<<" "<<a[l]<<" "<<1<<endl;
			}else{
				bool flg=1;
				if(n<=20)for(int j=l+1;j<=r;j++)if(a[j]-a[j-1]!=a[l+1]-a[l]){flg=0;break;}
				if(flg){
					cout<<a[l+1]-a[l]<<" "<<a[l]<<" "<<1<<endl;
				}else{
					for(int c=1;c<=10;c++){
						if(flg)break;
						for(int A=0;A<=10;A++){
							if(flg)break;
							for(int b=0;b<=10;b++){
								if(flg)break;
								bool f=1;
								for(int j=l;j<=r;j++){
									f&=(a[j]==((A*(j-l)+b)/c));
								}
								if(f){
									cout<<A<<" "<<b<<" "<<c<<endl;
									flg=1;
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}