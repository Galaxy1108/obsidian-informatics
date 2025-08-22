#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int g[2001][2001],a[2001],f[2001],b[2001],mi1=-1,mi2=-1,fl=0,fl1=0;
int ans=1e9;
void dfs(int x,int s){
	if(s==n+1){
		int sum=0;
		f[1]=1e9;
		for(int i=2;i<=n;i++){
			f[i]=min(f[i-1],g[a[i-1]][a[i]]);
			sum+=f[i];
		}
		ans=min(sum,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		b[i]=1;
		a[s]=i;
		dfs(i,s+1);
		b[i]=0;
	} 
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	fl=1;
	fl1=1;
	int x;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			cin>>x;
			g[i][i+j]=x;
			g[i+j][i]=x;
			if(x!=1&&x!=1e9) fl=0;
			if(x!=1) fl1=0;
			if(mi1==-1||g[mi1][mi2]>x) {
				mi1=i,mi2=i+j;
			}
		}
	} 
	if(n<=8){
		for(int i=1;i<=n;i++){
			a[1]=i,ans=1e9;
			b[i]=1;
			dfs(1,2);
			cout<<ans<<endl;
			b[i]=0;
		}
	}
	else if(fl==1){
		if(fl1){
			ans=1e9*(n-1);
			for(int i=1;i<=n;i++){
				cout<<ans<<endl;
			}
		}
		else{
			fl1=1;
			for(int i=1;i<=n;i++){
				fl1=0;
				for(int j=1;j<=n;j++){
					if(g[i][j]==1) fl1=1; 
				}
				if(fl1) f[i]=n-1;
				else f[i]=1e9+n-2;
			}
			for(int i=1;i<=n;i++) cout<<f[i]<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(i==mi1||i==mi2) ans=g[mi1][mi2]*(n-1); 
			else ans=min(g[i][mi1],g[i][mi2])+g[mi1][mi2]*(n-2);
			cout<<ans<<endl;
		} 
	}
	return 0;
} 
/*
3
1 2
3

6
2 9 9 6 6
7 1 9 10
9 2 5
4 10
8

*/
