#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 1e3+10;
const int INF = 1e8;

ll f[MAXN][MAXN]; 

int main(){

	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	int H,W;
	sc("%d%d",&H,&W);
	int a[MAXN],b[MAXN];
	REP(i,1,H) sc("%d",&a[i]);
	REP(i,1,W) sc("%d",&b[i]);
	REP(i,1,H){
		REP(j,1,W){
			if(i == 1){
				if(j != 1){
					f[i][j] = f[i][j-1]+a[1];
				}
			}else{
				if(j == 1){
					f[i][j] =f[i-1][j]+b[1];
				}else{
					f[i][j] = min(f[i][j-1]+a[i],f[i-1][j]+b[j]);
				}
			}
		}
	}

	pr("%lld",f[H][W]);

	return 0;
}

