#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	int o=0,e=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x%2==0){
			e++;
		}else{
			o++;
		}
	}
	if(e==0||o==0){
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
		return 0;
	}
	memset(a,-1,sizeof(a));
	for(int i=1;i<=m;i++){
		int p,b;
		cin>>p>>b;
		a[p]=b%2;
	}
	for(int i=1;i<=q;i++){
		int u,p;
		cin>>u>>p;
		if(u==1){
			a[p]=-1;
		}else{
			int x;
			cin>>x;
			a[p]=x%2;
		}
		int lst=a[1];
		int ans=0;
		int e1=e,o1=o;
		for(int j=2;j<=n;j++){
			if(a[j]==0){
				e1--;
			}else{
				o1--;
			}
			if(lst==-1){
				if(a[j]==0){
					if(e1>0){
						e1--;
					}else{
						ans++;
					}
				}
				if(a[j]==1&&o==0){
					if(o1>0){
						o1--;
					}else{
						ans++;
					}
				}
				lst=a[j];
			}
			if(a[j]!=-1&&a[j]!=lst){
				ans++;
				lst=a[j];
			}
			if(a[j]==-1){
				if(lst==0){
					if(e1>0){
						e1--;
					}else{
						ans++;
						lst=1;
					}
				}
				if(lst==1){
					if(o1>0){
						o1--;
					}else{
						ans++;
						lst=0;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
