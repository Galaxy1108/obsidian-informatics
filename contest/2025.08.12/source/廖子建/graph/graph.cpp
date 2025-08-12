#include<bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;
int t,n,m,uus,uv,tot=0,k;
bool flag[N+5]={};
vector<int>ans[N+5];
vector<pair<int,int>>edge[N+5];
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
bool dfs(int x,int y,int z){
//	cout<<tot<<" "<<x<<" "<<y<<" "<<z<<" "<<flag[5]<<" solve\n";
	if(z==x){
		ans[y].push_back(z);
		return 1;
	}
//	cout<<x<<" "<<y<<" "<<z<<" "<<tot<<" a\n";
	for(pair<int,int>i:edge[x]){
//		cout<<i.first<<" "<<i.second<<" "<<flag[i.second]<<"\n";
		if(flag[i.second])continue;
		flag[i.second]=1;
		if(dfs(i.first,y,z)){
			ans[y].push_back(x);
			return 1;
		}
		flag[i.second]=0;
	}
	return 0;
}
main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	t=read();
	while(t--){
		n=read(),m=read(),k=ceil(m*1.0/(n-1));
		for(int i=1;i<=n;i++)edge[i].resize(0);
		for(int i=1;i<=m;i++){
			flag[i]=0;
			uus=read(),uv=read();
			edge[uus].push_back({uv,i});
			edge[uv].push_back({uus,i});
//			cout<<uus<<" "<<uv<<" "<<edge[uus].back().second<<"\n";
		}
		tot=0;
//		cout<<"sfasfdsf"<<"\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
//				cout<<i<<" "<<j<<" a\n";
				if(i==j||edge[i].size()<k)continue;
				tot=0;
				for(int u=1;u<=m;u++)flag[u]=0;
				for(pair<int,int>u:edge[i]){
//					cout<<i<<" "<<u.first<<" "<<u.second<<" run\n";
					int uuu=flag[u.second];
					flag[u.second]=1,ans[tot+1].resize(0);
					if(dfs(u.first,tot+1,j))tot++,ans[tot].push_back(i);
					else flag[u.second]=uuu;
					if(tot>=k)break;
				}
				if(tot>=k){
					cout<<i<<" "<<j<<"\n";
					for(int u=1;u<=k;u++){
						print(ans[u].size()),putchar(' ');
						for(int uu=ans[u].size()-1;uu>=0;uu--)print(ans[u][uu]),putchar(' ');
//						cout<<u<<" sdfsdfsdfdasd";
						putchar('\n');
					}
					break;
				}
			}
			if(tot>=k)break;
		}
//		cout<<t<<" sdfdsafasdfdsafsdafdfsdafdsffgerg\n";
		if(tot<k)print(-1),putchar('\n');
	}
	return 0;
}
