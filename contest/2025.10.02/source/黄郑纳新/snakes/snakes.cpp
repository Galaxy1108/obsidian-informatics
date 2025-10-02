#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,a[1000010],k;
signed main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[3]-a[1]>=a[2]) printf("1\n");
	else printf("3\n");
	for(int opzsy=2;opzsy<=t;opzsy++){
		cin>>k;
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		if(a[3]-a[1]>=a[2]) printf("1\n");
		else printf("3\n");
	}
} 

