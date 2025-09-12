#include<bits/stdc++.h>
using namespace std;
int t,n,f[200005],m;
vector<int> e[200005];
void dp(int x,int fa){
	f[x]=1;
	int maxx=0,maxn=0;
	for(int i:e[x]){
		if(i==fa)
			continue;
		dp(i,x);
		if(f[i]>=maxx){
			maxn=maxx;
			maxx=f[i];
		}
		else if(f[i]>maxn)
			maxn=f[i];
	}
	f[x]+=maxx;
	m=max(m,maxx+maxn+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		m=0;
		dp(1,0);
		int k=m/2;
		int kk=log2(k);
		if(pow(2,kk)!=k)
			kk++;
		cout<<kk+2<<endl;
	}
	return 0;
} 
