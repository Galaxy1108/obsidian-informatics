#include<bits/stdc++.h>
#define int long long
#define N 150000
using namespace std;
int n,ans=INT_MIN,s[5]={},b[4][N+5];
pair<int,int>a[4][N+5];
bool f[5]={};
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first; 
}
void dfs(int x,int y){
	if(x>3){
		int j,sum=0,maxn[4]={};
		bool flag[N+5]={};
		maxn[1]=maxn[2]=maxn[3]=INT_MAX;
		for(int i=1;i<=3;i++){
			j=y;
			while(j<=n&&(flag[a[s[i]][j].second]||maxn[1]<=b[1][a[s[i]][j].second]||maxn[2]<=b[2][a[s[i]][j].second]||maxn[3]<=b[3][a[s[i]][j].second]))flag[a[s[i]][j].second]=1,j++;
			if(j>n){
//				cout<<maxn[1]<<" "<<maxn[2]<<" "<<maxn[3]<<" "<<i<<" "<<y<<" "<<"\n";
				return;
			}
//			cout<<a[s[i]][j].second<<" "<<a[s[i]][j].first<<"\n";
			flag[a[s[i]][j].second]=1,sum+=a[s[i]][j].first,maxn[s[i]]=a[s[i]][j].first;
		}
//		cout<<sum<<"\n";
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(f[i])continue;
		f[i]=1,s[x]=i,dfs(x+1,y),f[i]=0;
	}
	return;
}
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
main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		b[1][i]=a[1][i].first=read(),b[2][i]=a[2][i].first=read(),b[3][i]=a[3][i].first=read();
		a[1][i].second=a[2][i].second=a[3][i].second=i;
	}
	sort(a[1]+1,a[1]+1+n,cmp),sort(a[2]+1,a[2]+1+n,cmp),sort(a[3]+1,a[3]+1+n,cmp);
	for(int i=1;i<=n;i++)dfs(1,i);
	print(ans);
	return 0;
}
