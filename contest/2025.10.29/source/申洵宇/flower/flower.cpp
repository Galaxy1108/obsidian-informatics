#include <bits/stdc++.h>
using namespace std;
#define N 45
int n,a[N<<1];
char fl[N][15];
bitset<N>used;
void dfs(int x){
    if(x==(n<<1|1)){
        for(int i=1;i<=(n<<1);i++){
            cout<<fl[a[i]]<<'\n';
        }
        exit(0);
    }
    if(a[x]>0)return dfs(x+1);
    for(int i=n;i>=1;i--){
        if(used[i])continue;
        if(x+i+1>(n<<1))return ;
        if(a[x+i+1]>0)continue;
        a[x]=a[x+i+1]=i;
        used[i]=true;
        dfs(x+1);
        a[x]=a[x+i+1]=0;
        used[i]=false;
    }
}
int main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>fl[i];
    }
    if(n%4==1||n%4==2)return 0;
    dfs(1);
    return 0;
}
/*test code
#include <bits/stdc++.h>
using namespace std;
#define N 45
int n,a[N<<1];
char fl[N][15];
bitset<N>used;
bool dfs(int x){
    // cerr<<x<<'\n';
    if(x==(n<<1|1)){
        for(int i=1;i<=(n<<1);i++){
            // cout<<fl[a[i]]<<'\n';
            cout<<a[i]<<',';
        }
        cout<<'\n';
        cout.flush();
        // exit(0);
        return true;
    }
    if(a[x]>0)return dfs(x+1);
    for(int i=n;i>=1;i--){
        if(used[i])continue;
        if(x+i+1>(n<<1))return false;
        if(a[x+i+1]>0)continue;
        a[x]=a[x+i+1]=i;
        used[i]=true;
        if(dfs(x+1))return true;
        a[x]=a[x+i+1]=0;
        used[i]=false;
    }
    return false;
}
int main(){
    freopen("out2.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin>>n;
    // for(int i=1;i<=n;i++){
    //     cin>>fl[i];
    // }
    // cerr<<"OKK\n";
    for(int i=1;i<=40;i++){
        n=i;
        for(int j=1;j<=(n<<1);j++)a[j]=0;
        for(int j=1;j<=n;j++)used[j]=false;
        cout<<i<<":\n";
        if(i%4==1||i%4==2)continue;
        dfs(1);
    }
    return 0;
}
*/