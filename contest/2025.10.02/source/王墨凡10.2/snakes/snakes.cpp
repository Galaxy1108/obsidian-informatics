#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a[1086],k,x,s,v,ans;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin >> t >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	ans=3;
	t--; 
	sort(a+1,a+1+n);
	if(a[3]-a[1]>=a[2])ans=1;
	else ans=3;
	cout << ans;
	while(t--){
		cin >> k;
		for(int i=1;i<=k;i++){
			cin >> x >> v;
			a[x]=v;
		}
		sort(a+1,a+1+n);
		if(a[3]-a[1]>=a[2])ans=1;
		else ans=3;
		cout << ans << endl;
	}
	return 0;
}
