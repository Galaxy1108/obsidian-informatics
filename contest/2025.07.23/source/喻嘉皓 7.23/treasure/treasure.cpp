#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=1e9+7;
int L[210],R[210];
int b[210];
int main(){
	//freopen("treasure.in","r",stdin);
	//freopen("treasure.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>b[i];
	L[1]=R[1]=b[1];
	for(int i=2;i<=m;i++){
		int mi=0,ma=0;//代表减去的最大/最小值 
		for(int j=i-1;j>=max(1,i-n+1);j--){
			ma+=min(R[j],n-(i-j));
			mi+=max(0,L[j]-(i-j));
		}
		L[i]=max(0,b[i]-ma);
		R[i]=min(n,b[i]-mi);
		if(L[i]>n||R[i]<0){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<L[i]<<' '<<R[i]<<'\n';
	} 
	return 0;
}

