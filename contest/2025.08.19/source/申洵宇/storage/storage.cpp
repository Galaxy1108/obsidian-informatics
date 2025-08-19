#include <bits/stdc++.h>
using namespace std;
/*
f[i]:在i处建仓库时，考虑前i个工厂的最小答案
sump[i]=sum(k=1~i){p[k]} 
sumw[i]=sum(k=1~i){p[k]*X[k]}
f[i]=min(j=0~i-1){f[j]+sum(k=j+1~i){p[k]*(X[i]-X[k])}+C[i]}
	=min(j=0~i-1){f[j]-sump[j]*X[i]+sumw[j]}+C[i]-sumw[i]+sump[i]*X[i]
对于x,y两个位置，x比y不劣（x<y）需要 
f[x]-sump[x]*X[i]+sumw[x]<=f[y]-sump[y]*X[i]+sumw[y]
((f[x]+sumw[x])-(f[y]+sumw[y]))/(sump[x]-sump[y])>=X[i]  注：(sump[x]-sump[y])<0 

舍弃x:((f[x]+sumw[x])-(f[y]+sumw[y]))>X[i]*(sump[x]-sump[y])
维护斜率单调递增的凸包 
*/
//bool stt; 
constexpr int N=1000005;
constexpr __int128 i128=(__int128)1;
int n,dis[N],p[N],c[N];
long long sump[N];
int que[N],head,tail;
__int128 f[N],sumw[N];
ostream& operator<<(ostream& os,__int128 x){
	static char buf[55];
	static int cnt;cnt=0;
	if(x<0)os<<'-',x=-x;
	while(x){
		buf[++cnt]=(x%10)^48;
		x/=10;
	}
	for(int i=cnt;i>=1;i--){
		os<<buf[i];
	}
	return os;
}
//bool edd;
int main(){
//	cerr<<(double)abs(&stt-&edd)/1024.0/1024.0;
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	sump[0]=0,sumw[0]=0,f[0]=0;
	for(int i=1;i<=n;i++){
		cin>>dis[i]>>p[i]>>c[i];
		sump[i]=sump[i-1]+p[i];
		sumw[i]=sumw[i-1]+i128*p[i]*dis[i];
	}
	head=1,tail=0;
	que[++tail]=0;
	for(int i=1;i<=n;i++){
		while(head+1<=tail&&
			  ((f[que[head]]+sumw[que[head]])-(f[que[head+1]]+sumw[que[head+1]]))
			  >i128*dis[i]*(sump[que[head]]-sump[que[head+1]]))
			head++;
		f[i]=f[que[head]]-i128*sump[que[head]]*dis[i]+sumw[que[head]]+c[i]-sumw[i]+i128*sump[i]*dis[i];
		while(head+1<=tail&&
			 ((f[que[tail-1]]+sumw[que[tail-1]])-(f[que[tail]]+sumw[que[tail]]))*(sump[que[tail-1]]-sump[i])
			 >((f[que[tail-1]]+sumw[que[tail-1]])-(f[i]+sumw[i]))*(sump[que[tail-1]]-sump[que[tail]]))
			tail--;
		que[++tail]=i;
//		cerr<<"F:"<<f[i]<<'\n';
	}
	cout<<f[n];
	return 0;
}

