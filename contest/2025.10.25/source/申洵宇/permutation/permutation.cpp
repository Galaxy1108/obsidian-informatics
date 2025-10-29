#include <bits/stdc++.h>
using namespace std;
#define N 305
#define MOD 1000000007
int n,a[N<<1];
bitset<(N<<1)>book;
set<long long>st;
void dfs(int x){
    if(x==(n<<1)+1){
        long long res=0;
        // for(int i=1;i<=(n<<1);i++){
        //     cerr<<a[i]<<' ';
        // }
        // cerr<<'\n';
        for(int i=1;i<=n;i++){
            res=res*21+min(a[(i<<1)-1],a[(i<<1)]);
            // cerr<<min(a[(i<<1)-1],a[(i<<1)])<<' ';
        }
        // cerr<<'\n';
        st.emplace(res);
        return ;
    }
    if(a[x]!=-1)return dfs(x+1);
    for(int i=1;i<=(n<<1);i++){
        if(!book[i]){
            a[x]=i;
            book[i]=1;
            dfs(x+1);
            a[x]=-1;
            book[i]=0;
        }
    }
}
int main(){
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=(n<<1);i++){
        cin>>a[i];
        if(a[i]!=-1)book[a[i]]=1;
    }
    dfs(1);
    cout<<st.size();
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define N 305
#define MOD 1000000007
int n,a[N<<1];
long long f[15][(1<<20)];
void add(long long &x,long long y){
    x+=y;
    (x>=MOD)&&(x-=MOD);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int now=0;
    for(int i=1;i<=(n<<1);i++){
        cin>>a[i];
        if(a[i]!=-1)now|=(1<<(a[i]-1));
    }
    f[0][now]=1;
    for(int i=1;i<=n;i++){
        for(int j=now;j<(1<<(n<<1));j++){
                if(a[(i<<1)-1]==-1){
                    for(int p=1;p<=(n<<1);p++){
                        if((j>>(p-1))&1)continue;
                    }
                }
                else{
                    int p=a[(i<<1)-1];
                }
                    if(a[(i<<1)]==-1){
                        for(int q=p;q<=(n<<1);q++){
                            if(p==q||((j>>(q-1))&1))continue;
                    }
                    else{
                        int q=a[(i<<i)];
                        add(f[i][j|(1<<(p-1))|(1<<(q-1))],f[i-1][j]);
                    }
                }
            }
        }
    }
    cout<<f[n][(1<<(n<<1))-1];
    return 0;
}
*/