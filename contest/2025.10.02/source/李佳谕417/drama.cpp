#include<iostream>
#include<algorithm>
#include<climits>
#define int long long
using namespace std;
int a[200005];
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("drama.in","r",stdin);
    freopen("drama.out","w",stdout);
    int ans=0;
    int n;
    cin>>n;
    int maxa=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int maxa=0,mina=LONG_LONG_MAX;
            for(int k=i;k<=j;k++){
                maxa=max(maxa,a[k]);
                mina=min(mina,a[k]);
            }
            ans=max(ans,maxa*mina*(j-i+1));
        }
    }
    cout<<ans;
    return 0;
}