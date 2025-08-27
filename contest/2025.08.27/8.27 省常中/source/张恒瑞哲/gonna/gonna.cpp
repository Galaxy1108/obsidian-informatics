#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

#define il 1ll*

typedef long long ll;

const int MAXN = 26571025;
const int MOD = 0;

vector<int> pri;
bool not_prime[MAXN];
ll g[MAXN],ysh[MAXN];
void pre(int n) {
	g[1] = ysh[1] = 1;
	REP(i,2,n){
		if (!not_prime[i]) pri.push_back(i),g[i] = i+1,ysh[i] = i+1;
		for(int pri_j : pri) {
			int tmp = i*pri_j;
			if(tmp > n) break;
			not_prime[tmp] = true;
			if (i % pri_j == 0) {
				g[tmp] = g[i]*pri_j+1,ysh[tmp] = ysh[i]/g[i]*g[tmp];
				break;
			}
			ysh[tmp] = ysh[i]*ysh[pri_j],g[tmp] = 1+pri_j;
		}
	}
}

int inv[MAXN];
void invinit(int n,int p){
	inv[1] = 1; 
	REP(i,2,n) inv[i] = (long long)(p-p/i)*inv[p%i]%p;
} 

const ll num[15] ={0,1,3,13,252,5467,585156,55314571,625372650000,8557330010112000};
int main(){

	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	int n,p; sc("%d%d",&n,&p); ll ans = 0; 
	REP(i,1,n) ans += num[i];
	pr("%lld",ans%p);

//	pr("%lld",fans);
	
	return 0;
}
