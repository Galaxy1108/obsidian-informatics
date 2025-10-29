#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define sN 1005
#define INFl 0x3f3f3f3f3f3f3f3f
int n,a[N];
int f[sN][sN][6];//0:none 1:l 2:r 3:l,r 4:l,l 5:r,r
long long pre[N],suf[N];
void minto(int &x,int y){
    (x>y)&&(x=y);
}
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][i][0]=f[i][i][1]=f[i][i][2]=0;
        f[i][i][3]=(a[i]&1^1);
        f[i][i][4]=f[i][i][5]=(a[i]&1);
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+a[i];
    }
    for(int len=1;len<n;len++){
        for(int l=1,r;l+len-1<=n;l++){
            r=l+len-1;
            if(r<n){
                minto(f[l][r+1][0],f[l][r][2]+(a[r+1]&1));
                minto(f[l][r+1][2],f[l][r][2]+(a[r+1]&1^1));
                minto(f[l][r+1][1],f[l][r][3]+(a[r+1]&1));
                minto(f[l][r+1][3],f[l][r][3]+(a[r+1]&1^1));
                minto(f[l][r+1][0],f[l][r][5]+(a[r+1]&1));
                minto(f[l][r+1][2],f[l][r][5]+(a[r+1]&1^1));
                minto(f[l][r+1][5],f[l][r][5]+(a[r+1]&1));
            }
            if(l>1){
                minto(f[l-1][r][0],f[l][r][1]+(a[l-1]&1));
                minto(f[l-1][r][1],f[l][r][1]+(a[l-1]&1^1));
                minto(f[l-1][r][2],f[l][r][3]+(a[l-1]&1));
                minto(f[l-1][r][3],f[l][r][3]+(a[l-1]&1^1));
                minto(f[l-1][r][0],f[l][r][4]+(a[l-1]&1));
                minto(f[l-1][r][1],f[l][r][4]+(a[l-1]&1^1));
                minto(f[l-1][r][4],f[l][r][4]+(a[l-1]&1));
            }
        }
    }
    long long ans=INFl;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans=min(ans,min({f[i][j][0],f[i][j][1],f[i][j][2],f[i][j][3],f[i][j][4],f[i][j][5]})+pre[i-1]+suf[j+1]);
        }
    }
    cout<<ans;
    return 0;
}