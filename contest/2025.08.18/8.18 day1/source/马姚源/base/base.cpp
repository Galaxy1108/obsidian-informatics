#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2005][5],p[2005][5];
int maxx[2005][5];
signed main(){
    freopen("base.in","r",stdin);
    freopen("base.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i][1];
    for(int i=1;i<=n;i++)cin >> a[i][2];
    for(int i=1;i<=n;i++){
        p[i][1]=p[i-1][1]+a[i][1];
        p[i][2]=p[i-1][2]+a[i][2];
    }
    // for(int i=1;i<=n;i++)cout << p[i][1] << " ";
    // cout << endl;
    // for(int i=1;i<=n;i++)cout << p[i][2] << " ";
    // cout << endl;
    memset(maxx,0x8f,sizeof(maxx));
    maxx[1][1]=a[1][1]+a[1][2];
    maxx[n][2]=a[n][1]+a[n][2];
    for(int i=2;i<=n;i++)maxx[i][1]=max(maxx[i-1][1]+a[i][1]+a[i][2],a[i][1]+a[i][2]);
    for(int i=n-1;i>=1;i--)maxx[i][2]=max(maxx[i+1][2]+a[i][1]+a[i][2],a[i][1]+a[i][2]);

    // for(int i=1;i<=n;i++)cout << maxx[i][1] << " ";
    // cout << endl;
    // for(int i=1;i<=n;i++)cout << maxx[i][2] << " ";
    // cout << endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<i-1;j++){
            sum=maxx[j][1]+maxx[i][2]+p[i-1][2]-p[j][2];
            ans=max(ans,sum);
        }
    }
    cout << ans;
    return 0;
}