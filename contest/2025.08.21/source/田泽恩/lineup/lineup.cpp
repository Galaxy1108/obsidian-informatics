#include <bits/stdc++.h>
using namespace std;
int a[51],bkt[229],b[51],ans,n,pos[51];
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i]; 
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(b[j]==a[i]){
				pos[i]=j+bkt[a[i]];
				bkt[a[i]]++;
				break;
			}
		}
		ans+=abs(pos[i]-i);
	}
	cout<<ans;
	return 0;
} 
