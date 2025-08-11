#include <bits/stdc++.h>
using namespace std;
int read()
{
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0'; 
		c=getchar();
	}
	return f*k;
}
const int maxn=1.5e5+100;
int n,x[maxn],y[maxn],z[maxn];
long long ans,cnt;
struct node{
	int w,index;
	bool operator < (const node &other){
		return w>other.w;
	}
}p[3][maxn];
bool vis[maxn];
vector <int> wait;
void dfs(int step,int k,long long sum)
{
	sum+=p[step][k].w;
	cnt++;if(cnt>=2.8e7) {
		cout<<-1;exit(0);	
	}
	if(step==1&&(y[wait[0]]>=y[p[1][k].index]||x[p[1][k].index]>=x[wait[0]])) return;
	if(step==2&&(z[wait[0]]>=z[p[2][k].index]||z[wait[1]]>=z[p[2][k].index]||y[p[2][k].index]>=y[wait[1]]||x[p[2][k].index]>=x[wait[0]])) return;
	if(step==2){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[p[step+1][i].index])
		{
			vis[p[step+1][i].index]=true;wait.push_back(p[step+1][i].index);
			dfs(step+1,i,sum);	
			vis[p[step+1][i].index]=false;wait.pop_back();
		}
	}
}
int main()
{
	freopen("battle3.in","r",stdin);
//	freopen("beetle.out","w",stdin);
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=p[0][i].w=read();y[i]=p[1][i].w=read();z[i]=p[2][i].w=read();
		p[0][i].index=i;p[1][i].index=i;p[2][i].index=i;
	}
	sort(p[0]+1,p[0]+1+n);sort(p[1]+1,p[1]+1+n);sort(p[2]+1,p[2]+1+n);
	for(int i=1;i<=n;i++){
		vis[p[0][i].index]=true; 
		wait.push_back(p[0][i].index);
		dfs(0,i,0);
		wait.pop_back();
		vis[p[0][i].index]=false;
	}
	if(ans==0) cout<<-1;
	else cout<<ans;
	return 0;
}
