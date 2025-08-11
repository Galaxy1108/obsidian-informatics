#include <bits/stdc++.h>
using namespace std;
#define succ(x) ((x)==n?1:(x)+1) 
#define pre(x) ((x)==1?n:(x)-1) 
#define LSM 105
#define SM 200005
#define MV 2000000
int n,m[SM],t[SM];
long long val[LSM][LSM][LSM]; 
__int128 f[LSM][LSM];
vector<int>a[SM];
ostream& operator<<(ostream& os,__int128 x){
	static char buf[155];
	static int cnt;cnt=0;
	while(x){
		buf[++cnt]=(x%10)^48;
		x/=10;
	}
	for(int i=cnt;i>=1;i--){
		os<<buf[i];
	}
	return os;
}
int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		a[i].resize(m[i]+1);
		for(int j=1;j<=m[i];j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		static int s,c;s=succ(i);
		for(int x=1;x<=m[i];x++){
			for(int xs=1;xs<=m[s];xs++){
				c=0;
				for(int j=1;j<xs;j++){
					t[++c]=a[s][j];
				}
				for(int j=x;j<=m[i];j++){
					t[++c]=a[i][j];
				}
				t[0]=0;
				t[c+1]=MV;
				sort(t+1,t+c+1);
				for(int j=0;j<=c;j++){
					val[i][x][xs]+=1ll*(t[j+1]-t[j])*(t[j+1]-t[j]);
				}
			}
		}
	}
	__int128 ans=((__int128)1)<<126ll;
	for(int xn=1;xn<=m[n];xn++){
		for(int i=1;i<=n;i++){
			for(int x=1;x<=m[i];x++){
				f[i][x]=((__int128)1)<<126ll;
			}
		}
		for(int x=1;x<=m[1];x++){
			f[1][x]=val[n][xn][x];
		}
		for(int i=2;i<=n;i++){
			for(int x=1;x<=m[i];x++){
				static int p;p=pre(i);
				for(int xp=1;xp<=m[p];xp++){
					f[i][x]=min(f[i][x],f[p][xp]+val[p][xp][x]);
				}
			}
		}
		ans=min(ans,f[n][xn]);
	}
	cout<<ans;
	return 0;
}

