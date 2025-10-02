#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,a[1000010],p,b;
inline int f(){
	int cnt=0,r[1000010]={};
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			a[i]=a[i-1];
			r[i]=1;
		}
		cnt+=(a[i]%2==a[i-1]%2?0:1);
	}
	for(int i=1;i<=n;i++){
		if(r[i]){
			a[i]=-1;
		}
	}
	return cnt;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		int opzsy;
		cin>>opzsy;
		a[i]=-1;
	}
	for(int i=1;i<=m;i++){
		cin>>p>>b;
		a[p]=b;
	}
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		switch(op){
			case 1:{
				int l;
				cin>>l;
				a[l]=-1;
				break;
			}
			case 2:{
				int x,l;
				cin>>l>>x;
				a[l]=x;
				break;
			}
		}
		cout<<f()<<endl;
	}
} 



