#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
signed main()
{
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int tt=a[i],k=i,r=a[i];
		while(k<=n){
			tt=max(tt,a[k]);
			if(r^a[k]<=tt) ans++;
			k++;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
