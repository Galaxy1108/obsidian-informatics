#include <bits/stdc++.h>
using namespace std;
long long a[229028],n,q;
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n<=5000){
		while(q--){
			long long opt,l,r;
			cin>>opt;
			if(opt==1){
				cin>>l;
				for(int i=1;i<=n;++i) a[i]=min(a[i],l);
			}
			else if(opt==2){
				for(int i=1;i<=n;++i) a[i]+=i;
			}
			else{
				cin>>l>>r;
				long long ans=0;
				for(int i=l;i<=r;++i) ans+=a[i];
				cout<<ans<<endl;
			}
		}
	}
	
	return 0;
}
