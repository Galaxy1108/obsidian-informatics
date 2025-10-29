#include<iostream>

using namespace std;
int sum,a[2000086],n,ans,flag=0,len,maxn;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i]; 
	for(int i=1;i<=n;i++){
		if(!flag&&a[i]==0)continue;
		if(a[i]!=0)flag=1;
		if(a[i]%2==0)ans++;
	}
	len=0;
	for(int i=1;i<=n;i++){
		if(a[i]%2==1){
			maxn=max(maxn,len);
			len=0;
		}
		else len++;
	}
//	for(int i=n;i>=1;i--){
//		if(a[i]%2==1)break; 
//		if(a[i]%2==0)ans--;
//	}
	cout << ans-len <<'\n';
	return 0;
}
