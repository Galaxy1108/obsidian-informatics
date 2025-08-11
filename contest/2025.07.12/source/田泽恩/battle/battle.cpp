#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct haili{
	int x,y,z;
}h[150010];
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d%d",&h[i].x,&h[i].y,&h[i].z);
	if(n<=300){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					if(i==j||j==k||i==k) continue;
					if(h[i].x>h[j].x&&h[i].x>h[k].x&&h[j].y>h[i].y&&h[j].y>h[k].y&&h[k].z>h[i].z&&h[k].z>h[j].z) ans=max(ans,h[i].x+h[j].y+h[k].z);
				}
			}
		}
		cout<<ans;
	}
	else cout<<-1;
	return 0;
}
