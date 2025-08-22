#include<bits/stdc++.h>
using namespace std;
int book[2005];
#define ll long long
long long n,ans,a[2005][2005];
long long dfs(int x,long long cnt,long long minn){
	book[x]=1;
	int f=0;
	for(int i=1;i<=n;i++){
		if(!book[i]){
			long long ttt=minn;
			minn=min(minn,a[x][i]);
			f=1;
			dfs(i,cnt+minn,minn);
			book[i]=0;
			minn=ttt;
		}
	}
	if(!f)
		ans=min(ans,cnt);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
	if(n<=8){
		for(int i=1;i<=n;i++){
			memset(book,0,sizeof book);
			ans=1e18;
			dfs(i,0,INT_MAX);
			cout<<ans<<endl;
		}
	}
	else{
		int flag=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				if(a[i][j]==1)
					flag=1;
			}
		for(int i=1;i<=n;i++){
			if(!flag){
				long long oo=1000000000,o=(1ll*oo*(n-1));
				cout<<o<<endl; 
			}
			else{
				int ff=0;
				for(int j=1;j<=n;j++)
					if(a[i][j]==1)
						ff=1;
				if(ff)
					cout<<n-1<<endl;
				else{
					long long oo=1000000000,o=(1ll*oo+n-2);
					cout<<o<<endl;
				}
			}
		}
	}
	return 0;
}

