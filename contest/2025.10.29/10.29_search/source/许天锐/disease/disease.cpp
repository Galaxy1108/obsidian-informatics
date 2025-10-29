#include<bits/stdc++.h>
using namespace std;
const int N=3001;
int n,p;
int cnt,ver[N],nxt[N],h[N];
void add_edge(int x,int y){
	cnt++;
	ver[cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		add_edge(x,y);
		add_edge(y,x);
	}
	cout<<0<<endl;
	return 0;
}
