#include<bits/stdc++.h>
using namespace std;
int p[1010];
int a[510],b[510];
int m[1010][1010];
int maxn1,maxn2;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>p[i];
	for(int i = 1;i<=n/2;i++)a[i] = p[i];
	for(int i = 1;i<=n/2;i++)b[i] = p[n/2+i];
	a[n/2+1] = 1000000000;
	b[n/2+1] = 1000000000;
	int op = 0;
	for(int i = 1;i<=n;i++)m[0][i] = p[i];
	while(op<=1001){
		op++;
		int cnt1 = 1,cnt2 = 1;
		
		while(cnt1<=n/2||cnt2<=n/2){
			//if(cnt1==n/2+1)cnt2++,p[cnt1+cnt2-1] = b[cnt1-1];
			if(a[cnt1]<b[cnt2])cnt1++,p[cnt1+cnt2-2] = a[cnt1-1];
			else cnt2++,p[cnt1+cnt2-2] = b[cnt2-1];
		}
		for(int i = 1;i<=n;i++){
			m[op][i] = p[i];
		}
		for(int i = 1;i<=n/2;i++){
			a[i] = m[op][i];
		}
		for(int i = 1;i<=n/2;i++){
			b[i] = m[op][i+n/2];
		}
	}
	while(q--){
		int t,i;
		cin>>t>>i;
		if(t>=op)cout<<m[op][i]<<"\n";
		else cout<<m[t][i]<<"\n";
	}
	return 0;
}
