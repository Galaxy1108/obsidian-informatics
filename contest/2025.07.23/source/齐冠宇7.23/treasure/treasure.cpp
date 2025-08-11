#include <bits/stdc++.h>
using namespace std;
constexpr int N=205,mod=1e9+7;
bool m1;
int n,k;
int b[N];
int f[N][7][7][7][7][7][7];
int ans;
bool m2;
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//cerr<<fabs(&m1-&m2)/1024.0/1024.0<<"MB";
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	f[0][0][0][0][0][0][0]=1;
	for(int i=1;i<=n;i++){
	int lim1=0;
	if(k>=7)lim1=6;
	for(int a1=0;a1<=min(lim1,b[i]);a1++){
	int lim2=0;
	if(k>=6)lim2=5;
	for(int a2=0;a2<=min(lim2,b[i]-a1);a2++){
	int lim3=0;
	if(k>=5)lim3=4;
	for(int a3=0;a3<=min(lim3,b[i]-a1-a2);a3++){
	int lim4=0;
	if(k>=4)lim4=3;
	for(int a4=0;a4<=min(lim4,b[i]-a1-a2-a3);a4++){
	int lim5=0;
	if(k>=3)lim5=2;
	for(int a5=0;a5<=min(lim5,b[i]-a1-a2-a3-a4);a5++){
	int lim6=0;
	if(k>=2)lim6=1;
	for(int a6=0;a6<=min(lim6,b[i]-a1-a2-a3-a4-a5);a6++){
	for(int S=0;S<(1<<k);S++){
	int cnt=__builtin_popcount(S);
	if(cnt+a1+a2+a3+a4+a5+a6==b[i]){
	int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
	if(k>=7)c1=a2+((S>>5)&1);
	if(k>=6)c2=a3+((S>>4)&1);
	if(k>=5)c3=a4+((S>>3)&1);
	if(k>=4)c4=a5+((S>>2)&1);
	if(k>=3)c5=a6+((S>>1)&1);
	if(k>=2)c6=((S>>0)&1);
	//cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<' '<<c5<<' '<<c6<<'\n';
	(f[i][c1][c2][c3][c4][c5][c6]+=f[i-1][a1][a2][a3][a4][a5][a6])%=mod;
	if(i==n)(ans+=f[i-1][a1][a2][a3][a4][a5][a6])%=mod;
	}}}}}}}}}
	cout<<ans;
	return 0;
}
