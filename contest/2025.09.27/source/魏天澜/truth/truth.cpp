#include<bits/stdc++.h>
using namespace std;
const int N = 310;
int n,k,m;
int a[N];
int vis[N];
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	int n,k,m;
	cin>>n>>k>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=m;i++){
		int op;
		cin>>op;
		if(op==1){
			int p,v;
			cin>>p>>v;
			a[p] = v;
		}
		if(op==2){
			int minn = 1e9;
			for(int i = 1;i<=n;i++){
				memset(vis,0,sizeof(vis));
				int cnt = k;
				int j;
				for(j = i;j<=n;j++){
					vis[a[j]]++;
					if(vis[a[j]]==1)cnt--;
					if(cnt==0)break;
				}
				if(cnt==0)minn = min(minn,j-i+1);
			}
			if(minn==1e9){
				cout<<-1<<"\n";
				continue;
			}
			cout<<minn<<"\n";
		}
	}
	return 0;
}
