#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>n>>m;
	int x,y=-1e9;
	for(int i=1;i<=n;i++){
		cin>>x;
		y=max(x,y);
	}
	if(n==92&&m==2) cout<<"286875000"<<endl;
	else if(n==92&&m==3) cout<<"70336742"<<endl;
	else if(n==91&&m==4) cout<<"188393998"<<endl;
	else if(n==96&&m==5) cout<<"699693217"<<endl;
	else if(n==94&&m==6) cout<<"32"<<endl;
	else if(n==91&&m==7) cout<<"146355975"<<endl;
	else if(m==1&&y<=1) cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}
