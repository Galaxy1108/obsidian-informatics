#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int C[100][100],f[100],g[100];
signed main(){
    freopen("gonna.in","r",stdin);
    freopen("gonna.out","w",stdout);
    int n,p;
    cin >> n >> p;
    for(int i=0;i<=100;i++)C[i][0]=1;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<=i;j++){
            f[i]*=C[i][j];
        }
        int m=f[i];
        for(int j=1;j*j<=m;j++){
            if(m%j==0){
                g[i]+=j;
                if(j!=m/j)g[i]+=(m/j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=g[i];
        ans%=p;
    }
    cout << ans;
    return 0;   
}