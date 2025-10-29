#include <bits/stdc++.h>
using namespace std;
int q,n,a[1919810],b[1919810];
int main(){
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) a[i]=1;
	while(q--){
		int tp,m;
		cin>>tp>>m;
		if(tp==1){
			for(int i=1;i<=n;i+=m) a[i]=0;
		}
		else if(tp==2){
			int cnt=0;
			for(int i=1;i<=n;++i){
				cnt+=a[i];
				if(cnt%m==1) a[i]=0;
			}
		}
		else{
			bool flag=true;
			int lst=-1,cnt=0;
			for(int i=1;i<=n;++i) b[i]=a[i];
			while(flag){
				cnt=0;
				flag=false;
				for(int i=1;i<=n;++i){
					cnt+=b[i];
					if(cnt%m==1&&b[i]){
						b[i]=0;
						lst=i;
						flag=true;
					}
				}
				if(!flag) break;
				flag=false;
				cnt=0;
				for(int i=n;i;--i){
					cnt+=b[i];
					if(cnt%m==1&&b[i]){
						b[i]=0;
						lst=i;
						flag=true;
					}
				}
				if(!flag) break;
			}
			cout<<lst<<'\n';
		}
	}
	return 0;
} 
