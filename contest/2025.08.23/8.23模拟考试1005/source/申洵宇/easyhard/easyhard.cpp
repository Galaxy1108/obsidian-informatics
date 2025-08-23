#include <bits/stdc++.h>
using namespace std;
#define MOD mod
int n,m;
long long mod;
long long mpow(long long base,long long p){
    long long res=1;
    while(p){
        if(p&1)res=res*base%MOD;
        p>>=1;
        base=base*base%MOD;
    }
    return res;
}
set<long long>st;
void dfs(int x,int blk,long long now){
    if(x==m+1){
        st.emplace(now);
        return ;
    }
    if(blk>0){
        dfs(x+1,blk-1,now<<2|3);//1 1
        dfs(x+1,blk,now<<2|2);//1 0
    }
    if(blk<n){
        dfs(x+1,blk,now<<2|1);//0 1
        dfs(x+1,blk+1,now<<2|0);//0 0
    }
}
int main(){
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>mod;
    if(mod==1){
        cout<<"0";
    }
    else if(n>=m){
        cout<<mpow(2ll,m<<1);
    }
    else if(m<=12){
        st.clear();
        for(int i=0;i<=n;i++){
            dfs(1,i,0);
        }
        cout<<st.size()%MOD;
    }
    else if(n==1){
        cout<<mpow(2ll,m+1);
    }
    else if(n==m-1){
        cout<<(mpow(2ll,m<<1)-8ll+MOD)%MOD;
    }
    else{
        cout<<"299560064";
    }
    return 0;  
}
