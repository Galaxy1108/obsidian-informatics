#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int n,m,H;
inline int adc(int x,int v){return x+v>=H?x+v-H:x+v;}
inline void add(int &x,int v){x=adc(x,v);}
inline int dec(int x,int v){return x<v?x+H-v:x-v;}
inline int mul(int x,int y){return 1ll*x*y%H;}
int suf[N],pre[N],sum,tsuf[N],tpre[N],tsum,stpre[N],stsuf[N];
void File_Work(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}
signed main(){
	File_Work();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>H;
	for(int i=1;i<=m;++i) pre[i]=1ll*i*(i+1)/2%H,suf[i]=1ll*(m-i+1)*(m-i+2)/2%H;
	sum=1ll*m*(m+1)/2%H;
	for(int T=2;T<=n;++T){
		for(int i=1;i<=m;++i) tpre[i]=pre[i],stpre[i]=adc(stpre[i-1],tpre[i]);
		for(int i=m;i;--i) tsuf[i]=suf[i],stsuf[i]=adc(stsuf[i+1],tsuf[i]);
		tsum=sum,sum=0;
		for(int r=1;r<=m;++r)
			pre[r]=dec(mul(dec(tsum,tsuf[r+1]),r),stpre[r-1]),
			suf[r]=dec(mul(dec(tsum,tpre[r-1]),(m-r+1)),stsuf[r+1]),
			add(sum,pre[r]);
		for(int i=1;i<=m;++i) add(pre[i],pre[i-1]);
		for(int i=m;i;--i) add(suf[i],suf[i+1]);
	}
	cout<<sum<<"\n";
}
