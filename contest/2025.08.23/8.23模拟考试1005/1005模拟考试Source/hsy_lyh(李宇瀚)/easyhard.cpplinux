#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m,p;
int fz[1001];
map<vector<int>,int>ma;
int total=0;

inline int fpow(int a,int b){
    int ans=1,base=a;
    while(b>0){
        if(b&1) ans=(ans%p*base%p);
        base=(base%p*base%p)%p;
        b>>=1;
    }
    return ans;
}

void dfs(int nown,int hs,int bs){
    if(nown==m+1){
        vector<int> tmp;
        for(int i=1;i<=2*m;i++) tmp.push_back(fz[i]);
        if(!ma[tmp]) total=(total+1)%p,ma[tmp]=1;
        return;
    }
    if(hs!=0){
        fz[nown*2-1]=0;
        fz[nown*2]=0;
        dfs(nown+1,hs-1,bs+1);
        fz[nown*2-1]=0;
        fz[nown*2]=1;
        dfs(nown+1,hs,bs);
    }
    if(bs!=0){
        fz[nown*2-1]=1;
        fz[nown*2]=1;
        dfs(nown+1,hs+1,bs-1);
        fz[nown*2-1]=1;
        fz[nown*2]=0;
        dfs(nown+1,hs,bs);
    }
    return;
}

signed main(){
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    cin>>n>>m>>p;
    if(n==1){
        cout<<fpow(2,m+1)<<endl;
        return 0;
    }
    else if(m<=n){
        cout<<fpow(2,m*2)<<endl;
        return 0;
    }
    else{
        //Why is the problem so hard? Life is hard.
        int ans=0;
        for(int i=0;i<=n;i++){
            int j=n-i;
            dfs(1,i,j);
        }
        cout<<total%p<<endl;
    }
    return 0;
}