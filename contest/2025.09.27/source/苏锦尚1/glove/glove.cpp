#include<bits/stdc++.h>
using namespace std;
long long l[100005],r[100005];
int main(){
	freopen("glove.in","r",stdin);
	freopen("glove.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=1;i<=m;i++){
		cin>>r[i];
	}
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
	int flag;
    long long minn=1e18;
	if(m==n){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,abs(l[i]-r[i]));
		}
		cout<<ans;
		return 0;
	}
	else if(m>n){
		for(int i=1;i<=m-n+1;i++){
			long long  maxn=0;
			flag=1;
			for(int j=1;j<=n;j++){
				maxn=max(maxn,abs(r[i+j-1]-l[j]));
				if(r[i+j-1]-l[j]<0)
				flag=0;
			}
			minn=min(minn,maxn);
			if(flag==1)
			{
				cout<<minn;
				return 0;
			}
		}
	}
    else if(n>m){
		for(int i=1;i<=n-m+1;i++){
			long long  maxn=0;
			flag=1;
			for(int j=1;j<=m;j++){
				maxn=max(maxn,abs(l[i+j-1]-r[j]));
				if(l[i+j-1]-r[j]<0)
				flag=0;
			}
			minn=min(minn,maxn);
			if(flag==1)
			{
				cout<<minn;
				return 0;
			}
		}
	}
}
