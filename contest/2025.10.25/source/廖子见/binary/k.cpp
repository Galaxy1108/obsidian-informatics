#include<bits/stdc++.h>
#define int long long
#define N 100000
using namespace std;
main(){
	freopen("binary.in","r",stdin);
	freopen("binary.ans","w",stdout);
	int n,m,a[N+5],cnt0,cnt1,ans;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
//	cout<<m<<"\n";
	cin>>m;
	for(int i=1;i<=m;i++){
		int opt,l,r;
		ans=0;
		cin>>opt>>l>>r;
//		cout<<"l="<<l<<" r="<<r<<" "<<a[2]<<"\n"; 
		for(int s=l;s<=r;s++){
			cnt0=cnt1=0;
			for(int t=s;t<=r;t++){
				cnt0+=(!a[t]);
				cnt1+=a[t];
				if(cnt1%2==0)ans++;
				else if(cnt1>=3&&cnt0>=2)ans++;
//				cout<<cnt1<<" "<<cnt0<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
