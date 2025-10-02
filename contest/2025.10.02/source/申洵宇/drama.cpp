#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& os,__int128 x){
	if(x<0){
		os<<' ';
		x=-x;
	}
	else if(x==0){
		return os<<'0';
	}
	static char buf[256];
	static int cnt;
	cnt=0;
	while(x){
		buf[++cnt]=(x%10)^48;
		x/=10;
	}
	for(int i=cnt;i>=1;i--){
		os<<buf[i];
	}
	return os;
}
#define INF 0x3f3f3f3f
#define N 2000005
#define LGN 22
int n,a[N],l[N],r[N];
__int128 ans;
int que[N],tail;
int lg[N],st[N][LGN];
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			static int minn,maxn;
			minn=INF,maxn=-INF;
			for(int j=i;j<=n;j++){
				minn=min(minn,a[j]);
				maxn=max(maxn,a[j]);
				ans=max(ans,(__int128)minn*maxn*(j-i+1));
			}
		}
	}
	else{
		lg[1]=0;
		for(int i=2;i<=n;i++){
			lg[i]=lg[i>>1]+1;
		}
		for(int i=1;i<=n;i++){
			st[i][0]=a[i];
		}
		for(int i=1;i<=lg[n];i++){
			for(int j=1;j+(1<<(i-1))<=n;j++){
				st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			}
		}
		for(int i=1;i<=n;i++){
			while(tail>0&&a[que[tail]]>=a[i])tail--;
			l[i]=que[tail]+1;
			que[++tail]=i;
		}
		tail=0;
		que[0]=n+1;
		for(int i=n;i>=1;i--){
			while(tail>0&&a[que[tail]]>=a[i])tail--;
			r[i]=que[tail]-1;
			que[++tail]=i;
		}
		for(int i=1;i<=n;i++){
			// cerr<<i<<":"<<l[i]<<"~"<<r[i]<<'\n';
			static int lgnn;lgnn=lg[r[i]-l[i]+1];
			ans=max(ans,(__int128)a[i]*max(st[l[i]][lgnn],st[r[i]-(1<<lgnn)+1][lgnn])*(r[i]-l[i]+1));
		}
	}
	cout<<ans;
	return 0;
} 
