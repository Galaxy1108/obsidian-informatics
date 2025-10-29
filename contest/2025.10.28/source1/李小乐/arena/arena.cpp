#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
void read(int &x){
	x=0;char c=getchar();int w=0;
	while(!isdigit(c)){
		(c=='-')&&(w=1);
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c^48);
		c=getchar();
	}
	w&&(x=-x);
}
int n,p,b[21],a[21],ans;
void dfs(int now){
	if(now==n+1){
		for(int i=1;i<=n;i++)b[i]=a[i];
		while(1){
			int tmp=0;
			for(int i=1;i<=n;i++){
				if(b[i]>0)tmp++;
			}
			if(tmp==1){
				break;
			}
			else if(tmp==0){
				ans++;	break;
				
			}
			tmp--;
			for(int i=1;i<=n;i++){
				if(b[i]>0)b[i]-=tmp;
			}
		}
		return;
	}
	for(int i=1;i<=p;i++){
		a[now]=i;
		dfs(now+1);
	}
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>p;
	ans=0;
	dfs(1);
	printf("%d ",ans);
}
