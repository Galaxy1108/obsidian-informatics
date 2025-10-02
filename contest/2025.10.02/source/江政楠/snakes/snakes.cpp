#include<bits/stdc++.h>
using namespace std;
int t,t_,n;
int a[1000005];
int check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(a[j]<a[i]){
				int cha=a[i]-a[j];
				int flag=1;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					if(a[k]>cha){
						flag=0;
						break;
					}
					else if(a[k]==cha){
						if(k>i){
							flag=0;
							break;
						}
					}
				}
				if(flag) cnt++;
			}
			else if(a[j]==a[i]&&i>j){
				int cha=a[i]-a[j];
				int flag=1;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					if(a[k]>cha){
						flag=0;
						break;
					}
					else if(a[k]==cha){
						if(k>i){
							flag=0;
							break;
						}
					}
				}
				if(flag) cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	t_=t;
	while(t_--){
		if(t_==t-1){
			cin>>n;
			for(int i=1;i<=n;i++) cin>>a[i];
			cout<<n-check()<<"\n";
		}
		else{
			int m;
			cin>>m;
			for(int i=1;i<=m;i++){
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			cout<<n-check()<<"\n";
		}
	}
}
