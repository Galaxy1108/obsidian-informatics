#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define INFi 0x3f3f3f3f
#define INFl 0x3f3f3f3f3f3f3f3f
#define l first
#define r second
int n,m,a[N];
pair<int,int>s[N];
long long f[2][N];
void readin(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>s[i].l>>s[i].r;
    }
}
void inital(){
    sort(a+1,a+n+1);
    sort(s+1,s+m+1,[&](pair<int,int> x,pair<int,int> y){return x.l==y.l?x.r>y.r:x.l<y.l;});
    int _m=1,_t;
    for(int i=2;i<=m;i++){
        if(s[i].r<=s[_m].r)s[_m]=s[i];
        else s[++_m]=s[i];
    }
    m=_m;
    _m=0,_t=1;
    for(int i=1;i<=m;i++){
        while(_t<n&&a[_t]<s[i].l)_t++;
        if(s[i].l>a[_t]||s[i].r<a[_t])s[++_m]=s[i];
    }
    m=_m;
    // for(int i=1;i<=m;i++){
    //     cerr<<s[i].l<<' '<<s[i].r<<'\n';
    // }
}
int calc(int id,int le,int ri){
    if(le>ri)return 0;
    // s[le].r~s[ri].l
    if(s[le].r>=a[id]&&s[ri].l<=a[id]){
        return 0;
    }
    else if(s[le].r>=a[id]){
        return s[ri].l-a[id];
    }
    else if(s[ri].l<=a[id]){
        return a[id]-s[le].r;
    }
    else{
        return s[ri].l-s[le].r+min(s[ri].l-a[id],a[id]-s[le].r);
    }
}
long long solve(){
    int id=lower_bound(s+1,s+m+1,make_pair(a[1],0))-s;
    memset(f,0x3f,sizeof(f));
    for(int j=id-1;j<=m;j++){
        f[1][j]=calc(1,1,j);
    }
    for(int i=2;i<=n;i++){
        for(int j=id-1;j<=m;j++){
            f[i&1][j]=INFl;
        }
        for(int j=id-1;j<=m;j++){
            for(int k=j;k<=m;k++){
                f[i&1][k]=min(f[i&1][k],f[i&1^1][j]+calc(i,j+1,k));
            }
        }
    }
    return f[n&1][m];
}
int main(){
    freopen("points.in","r",stdin);
    freopen("points.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    readin();
    inital();
    cout<<solve();
    return 0;
}