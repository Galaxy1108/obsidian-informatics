#include <bits/stdc++.h>
using namespace std;
constexpr int M=10000005;
int n,m;
long long MOD,INV2;
int f[2][M],g[2][M],sumf[M],sumft[M],sumg[M],sumgt[M];
inline long long mpow(long long base,long long p){
    long long res=1;
    while(p){
        if(p&1)res=res*base%MOD;
        p>>=1;
        base=base*base%MOD;
    }
    return res;
}
inline void add(int& x,int y){
    x+=y;
    x-=(x>=MOD?MOD:0);
}
inline void upd(int& x,int y){
    x=y;
    x-=(x>=MOD?MOD:0);
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>MOD;
    INV2=mpow(2,MOD-2);
    for(int i=1;i<=m;i++){
        f[1][i]=1ll*(i+1ll)*i%MOD*INV2%MOD;
        g[1][i]=1ll*(m-i+2)*(m-i+1)%MOD*INV2%MOD;
        // cerr<<f[1][i]<<' '<<g[1][i]<<'\n';
    }
    for(int i=2;i<=n;i++){
        sumf[0]=sumft[0]=sumg[m+1]=sumgt[m+1]=0;
        for(int j=1;j<=m+1;j++){
            upd(sumf[j],sumf[j-1]+f[i&1^1][j]);
            upd(sumft[j],sumft[j-1]+1ll*f[i&1^1][j]*j%MOD);
            upd(sumg[j],sumg[j-1]+g[i&1^1][j]);
            upd(sumgt[j],sumgt[j-1]+1ll*g[i&1^1][j]*j%MOD);
        }
        for(int j=1;j<=m;j++){
            /*
            f[i&1][j]=0;
            for(int l=1;l<=j;l++){
                for(int r=l;r<=j;r++){
                    f[i&1][j]=(f[i&1][j]+f[i&1^1][m]-f[i&1^1][l-1]-g[i&1^1][r+1]+MOD+MOD)%MOD;
                }
            }
            g[i&1][j]=0;
            for(int l=j;l<=m;l++){
                for(int r=l;r<=m;r++){
                    g[i&1][j]=(g[i&1][j]+f[i&1^1][m]-f[i&1^1][l-1]-g[i&1^1][r+1]+MOD+MOD)%MOD;
                }
            }
            */
            f[i&1][j]=0;
            add(f[i&1][j],1ll*(j+1)*j%MOD*INV2%MOD*f[i&1^1][m]%MOD);
            add(f[i&1][j],MOD-1ll*j*sumf[j-1]%MOD);
            add(f[i&1][j],sumft[j-1]);
            add(f[i&1][j],MOD-sumgt[j+1]);
            add(f[i&1][j],sumgt[1]);
            add(f[i&1][j],sumg[j+1]);
            add(f[i&1][j],MOD-sumg[1]);
            g[i&1][j]=0;
            add(g[i&1][j],1ll*(m-j+2)*(m-j+1)%MOD*INV2%MOD*f[i&1^1][m]%MOD);
            add(g[i&1][j],MOD-1ll*m*(sumf[m-1]-(j-2>=0?sumf[j-2]:0)+MOD)%MOD);
            add(g[i&1][j],sumft[m-1]);
            add(g[i&1][j],(j-2>=0?MOD-sumft[j-2]:0));
            add(g[i&1][j],MOD-sumgt[m+1]);
            add(g[i&1][j],sumgt[j]);
            add(g[i&1][j],1ll*j*(sumg[m+1]-sumg[j]+MOD)%MOD);
            /*
            f[i&1][j]= + 1ll*(j+1)*j%MOD*INV2%MOD*f[i&1^1][m]%MOD
                       - 1ll*j*sumf[j-1]%MOD+MOD
                       + sumft[j-1]
                       - sumgt[j+1]+MOD+sumgt[1]
                       + sumg[j+1]-sumg[1]+MOD;
            f[i&1][j]%=MOD;
            g[i&1][j]= + 1ll*(m-j+2)*(m-j+1)%MOD*INV2%MOD*f[i&1^1][m]%MOD
                       - 1ll*m*(sumf[m-1]-(j-2>=0?sumf[j-2]:0)+MOD)%MOD
                       + sumft[m-1]-(j-2>=0?sumft[j-2]:0)+MOD
                       - sumgt[m+1]+MOD+sumgt[j]
                       + 1ll*j*(sumg[m+1]-sumg[j]+MOD)%MOD;
            g[i&1][j]%=MOD;
            */
        }
    }
    cout<<f[n&1][m];
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long MOD;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>MOD;
    vector<vector<vector<long long>>>f(n+1,vector<vector<long long>>(m+1,vector<long long>(m+1,0)));
    vector<long long>pre(m+2,0),suf(m+2,0);
    for(int l=1;l<=m;l++){
        for(int r=l;r<=m;r++){
            f[1][l][r]=1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int r=1;r<=m;r++){
            pre[r]=pre[r-1];
            for(int l=1;l<=r;l++){
                pre[r]=(pre[r]+f[i-1][l][r])%MOD;
            }
        }
        for(int l=m;l>=1;l--){
            suf[l]=suf[l+1];
            for(int r=l;r<=m;r++){
                suf[l]=(suf[l]+f[i-1][l][r])%MOD;
            }
        }
        for(int l=1;l<=m;l++){
            for(int r=l;r<=m;r++){
                f[i][l][r]=(pre[m]-pre[l-1]+MOD-suf[r+1]+MOD)%MOD;
            }
        }
    }
    for(int r=1;r<=m;r++){
        pre[r]=pre[r-1];
        for(int l=1;l<=r;l++){
            pre[r]=(pre[r]+f[n][l][r])%MOD;
        }
    }
    cout<<pre[m];
	return 0;
}
*/