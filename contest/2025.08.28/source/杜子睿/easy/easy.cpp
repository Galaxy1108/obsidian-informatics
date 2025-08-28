#include<bits/stdc++.h>
using namespace std;
int n,q;
long long a[10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<q;i++){
		int opt;
		long long x,y;
		cin>>opt;
		switch(opt){
			case 1:
				cin>>x;
				for(int j=1;j<=n;j++)
					a[j]=min(a[j],x);
				break;
			case 2:
				for(int j=1;j<=n;j++)
					a[j]+=j;
				break;
			case 3:
				cin>>x>>y;
				long long ans=0;
				for(int j=x;j<=y;j++)
					ans+=a[j];
				cout<<ans<<endl;
				break;
		}
	}
	return 0;
}

