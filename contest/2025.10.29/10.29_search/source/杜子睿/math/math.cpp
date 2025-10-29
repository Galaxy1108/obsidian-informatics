#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9;
long long p,q;
vector<int> ans,out;
bool dfs(int d,long long a,long long b,int e){
    if(d==0){if(a==0)out=ans;return (a==0);}
    long long gc=__gcd(a,b);
    b/=gc;
    a/=gc;
    bool fl=false;
    int ex=max(e+1,int((b+a-1)/a));
    if(b>maxn*a)return false;
    do{
        if(d*b<ex*a)return fl;
        ans.push_back(ex);
        fl|=dfs(d-1,a*ex-b,b*ex,ex);
        ans.pop_back();
    }while(ex++);
    return fl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    cin>>q>>p;
    if(q==0){cout<<"0";return 0;}
    int dep;
    for(dep=1;dep<=100;dep++)if(dfs(dep,q,p,1))break;
    cout<<out.size()<<endl;
    for(auto i:out)cout<<i<<" ";
    return 0;
}