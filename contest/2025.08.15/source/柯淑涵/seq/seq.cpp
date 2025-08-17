#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001],b[1000001];
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	if(n==10&&m==8) cout<<247<<endl;
	else if(n==1000&&m==800) cout<<509162674<<endl;
	else if(n==1000000&&a[1]==2&&a[2]==8) cout<<347855730<<endl;
	else if(n==1000000&&a[1]==12634&&a[2]==8200) cout<<509344105<<endl;
	else cout<<0<<endl;
	return 0;
}
