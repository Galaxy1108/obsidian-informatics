#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define siz(v) (int)v.size() 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--) 
using namespace std;
typedef pair<int,int> pii;
const int N=5010;
const int M=1e6+5;
int n,seed;
int a[N][N];
int f[20][M];
void gen(){
    mt19937 rd(seed);
    rep(i,1,n){
    	rep(j,1,n+1){
            a[i][j]=j;
            swap(a[i][j],a[i][rd()%j+1]);
        }
    }
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>seed;
	if(seed){
		gen();
	}
	else{
		rep(i,1,n){
			rep(j,1,n+1){
				cin>>a[i][j];
			}
		}
	}
	int siz=1<<(n+1);
	rep(i,1,n+1){
		f[n][(siz-1)^(1<<(i-1))]=i;
	}
	per(i,n-1,0){
		rep(j,0,siz-1){
			int mx=0,id=0;
			rep(k,1,n+1){
				if(j>>(k-1)&1){
					int p=f[i+1][j^(1<<(k-1))];
					if(!p){
						continue;
					}
					int x=a[i][p];
					if(x>mx){
						mx=x;
						id=p;
					}
				}
			}
			f[i][j]=id;
		}
	}
	cout<<f[0][0]<<'\n';
	return 0;
}
