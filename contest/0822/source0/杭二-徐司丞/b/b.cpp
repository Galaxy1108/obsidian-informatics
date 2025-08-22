#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int n,tot=0;
struct pt{
	int xy,w;
}e[N*N];
bool cmp(pt x,pt y){
	return x.w<y.w;
}
long long cst[N],bs;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			e[++tot].xy=N*i+j;
			cin>>e[tot].w;
		}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=n;i++)
		cst[i]=1e18;
	cst[e[1].xy%N]=0;
	cst[e[1].xy/N]=0;
	bs=1ll*e[1].w*(n-1);
	for(int i=tot;i;i--)
		e[i].w-=e[1].w;
	for(int i=1;i<=tot;i++){
		int xx=e[i].xy%N;
		int yy=e[i].xy/N;
		cst[yy]=min(cst[yy],cst[xx]+e[i].w);
		cst[xx]=min(cst[xx],cst[yy]+e[i].w);
		cst[xx]=min(cst[xx],2ll*e[i].w);
		cst[yy]=min(cst[yy],2ll*e[i].w);
	}
	for(int i=1;i<=n;i++){
		cout<<bs+cst[i]<<"\n";
	}
	return 0;
}
