#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define endl '\n'
const int N=7005;
ll f[N][N],p[N][N];
//bool b[100005][100005];
ll Mod(ll x,ll y){
    return x%y;
}
const ll mod=1e9+9;
int main(){
	 freopen("newfile.in","r",stdin);
	 freopen("newfile.out","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
//    if(n<=50){
//    	memset(p,0,sizeof(p));
//    	memset(f,0,sizeof(f));
//    	for(int i=1;i<=m;i++){
//	        int ul,ur;
//	        ll x;
//	        cin >> ul >> ur >> x;
//	        if(ul>ur)swap(ul,ur);
//	        for(int j=1;j<=n;j++){
//	        	f[i][j]=f[i-1][j];
//			}
//	        for(int j=ul;j<=ur;j++){
//	            f[i][j]+=x;
//	        }
//	    }
//	    for(int i=1;i<=m;i++){
//	    	for(int j=1;j<=n;j++){
//	    		p[i][j]=p[i-1][j]+f[i][j];
//			}
//		}
//	    for(int i=1;i<=q;i++){
//	        int u,d,l,r;
//	        cin >> u >> d >> l >> r;
//	        ll ans=0;
//	        if(d<u)swap(d,u);
//	        if(r<l)swap(l,r);
//	//        for(int k=u;k<=d;k++)
//	        for(int j=l;j<=r;j++){
//	        	ans+=p[d][j]-p[u-1][j];
//	//			ans+=f[k][j];
//			}
//	        cout << ans << endl;
//	    }
//	}
    if(n<=5000){
    	for(int i=1;i<=m;i++){
	        int ul,ur;
	        ll x;
	        cin >> ul >> ur >> x;
	        if(ul>ur)swap(ul,ur);
	        for(int j=1;j<=n;j++){
	        	f[i][j]=f[i-1][j];
			}
	        for(int j=ul;j<=ur;j++){
	            f[i][j]+=Mod(x,mod);
	            f[i][j]=Mod(f[i][j]+mod,mod);
	        }
	    }
	    for(int i=1;i<=m;i++){
	    	for(int j=1;j<=n;j++){
	            p[i-1][j]=Mod(p[i-1][j]+mod,mod);
	    		p[i][j]=Mod(p[i-1][j]+f[i][j]+mod,mod);
			}
		}
		p[1][0]=0;
	    for(int i=1;i<=q;i++){
	        int u,d,l,r;
	        cin >> u >> d >> l >> r;
	        ll ans=0;
	        if(d<u)swap(d,u);
	        if(r<l)swap(l,r);
	//        for(int k=u;k<=d;k++)
	        for(int j=l;j<=r;j++){
	        	ans+=Mod(p[d][j]-p[max(u-1,0)][j]+mod,mod);
	            ans=Mod(ans+mod,mod);
	//			ans+=f[k][j];
			}
	        cout << ans << endl;
	    }
	}
    else{
    	for(int i=1;i<=n;i++){
    		
		}
	}
    return 0;
}

