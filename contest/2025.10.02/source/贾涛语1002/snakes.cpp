#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[1008611];
int ans;
void tan(){
	ans=3;
	if(a[3]-a[1]>=a[2]) a[3]-=a[1]+a[2],a[1]=a[2]=0,ans-=2;
	else return;
}
int main(){
	freopen("snakes.in","r",stdin);freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int x,y,k;
	for(int i=1;i<t;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[x]=y;
		}
		tan();
		cout<<ans<<'\n';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
