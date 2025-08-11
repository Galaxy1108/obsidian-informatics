#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define Q 1000005 
int n,n2,q,a[N],t[N],ans[Q];
int cnt=0;
vector<pair<int,int>>qs[Q];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	n2=(n>>1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int _t,_i;
	for(int i=1;i<=q;i++){
		cin>>_t>>_i;
		if(_t==0){
			ans[i]=a[_i];
			continue;
		}
		if(_t>n)_t=n+1;
		qs[_t].emplace_back(_i,i);
	}
	int r;
	for(r=1;;r++){
		static bool flag;flag=true;
		for(int i=1;i<=n2;i++){
			if(a[i]>a[n2+1]){
				flag=false;
				break;
			}
		}
		if(flag)break;
		for(int i=1;i<=n;i++){
			t[i]=a[i];
		}
		static int i,j,c;
		i=1,j=n2+1,c=0;
		while(i<=n2&&j<=n){
			if(t[i]<t[j]){
				a[++c]=t[i++];
			}
			else{
				a[++c]=t[j++];
			}
		}
		while(i<=n2){
			a[++c]=t[i++];
		}
		while(j<=n){
			a[++c]=t[j++];
		}
		for(auto v:qs[r]){
			ans[v.second]=a[v.first];
		}
	}
	for(;r<=n+1;r++){
		for(auto v:qs[r]){
			ans[v.second]=a[v.first];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

