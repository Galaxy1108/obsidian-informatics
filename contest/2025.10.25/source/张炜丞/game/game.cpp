#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int a[N],n,b[N],cnt[N],vn;

bool pd(int k){
    for(int i=1;i<=vn;++i)cnt[i]=0;
    for(int i=1;i<=n;++i)cnt[a[i]/k]++;
    for(int i=vn;i>=1;--i){
        if(cnt[i]&1)return 0;
    }
    return 1;
}

signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll ans=0;
    n=read();
    bool flag=1;
    for(int i=1;i<=n;++i){
        a[i]=read();
        if(a[i]!=1)flag=0;
        vn=max(vn,a[i]);
    }
    if(flag){
        if(n&1)print(n);
        else print(0);
        putchar('\n');
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=a[i];++j){
            a[i]-=j;
            if(pd(j)){
                ++ans;
                // cout<<" i:"<<i<<" j:"<<j<<endl;
            }
            a[i]+=j;
        }
    }
    print(ans);putchar('\n');
    return 0;
}