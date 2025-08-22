#include<bits/stdc++.h>
#define int long long
using namespace std;
int A[100001];
bool ck(int a,int b,int c,int l,int r){
	for(int i=l;i<=r;i++){
		double xi=i-l;
		double yi=(1.0*xi*a+(double)b)/(double)(c);
		double v=A[i];
		if(floor(yi)!=v)return 0;
	}
	return 1;
}
void sol(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		bool f=1;
		for(int c=1;c<=10&&f;c++){
			for(int a=0;a<=10&&f;a++){
				for(int b=0;b<=10&&f;b++){
					if(ck(a,b,c,l,r)){
						cout<<a<<' '<<b<<' '<<c<<'\n';
						f=0;
						break;
					}
				}
			}
		}
	}
}
signed main(){
	freopen("d1.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		sol();
	}
}
