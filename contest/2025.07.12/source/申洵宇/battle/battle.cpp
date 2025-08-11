#include <bits/stdc++.h>
using namespace std;
#define N 150005
struct node{
	int x,y,z;
}a[N];
int n;
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||a[j].x>=a[i].x||a[i].y>=a[j].y)continue;
			for(int k=1;k<=n;k++){
				if(k==i||k==j
				 ||a[k].x>=a[i].x||a[k].y>=a[j].y
				 ||a[i].z>=a[k].z||a[j].z>=a[k].z)continue;
				ans=max(ans,a[i].x+a[j].y+a[k].z);
			}
		}
	}
	cout<<ans;
	return 0;
}

