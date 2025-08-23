#include <bits/stdc++.h>
using namespace std;
constexpr int N=50005;
int n,m,k,q;
set<int>h[N],l[N];
int main(){
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C;
    cin>>C>>n>>m>>k;
    for(int i=1;i<=n;i++){
        h[i].emplace(m+1);
    }
    for(int i=1;i<=m;i++){
        l[i].emplace(n+1);
    }
    int op,x,y,ta,dir;
    for(int i=1;i<=k;i++){
        cin>>x>>y;
        h[x].emplace(y);
        l[y].emplace(x);
    }
    cin>>q;
    while(q--){
        cin>>op>>x>>y;
        if(op==1){
            h[x].emplace(y);
            l[y].emplace(x);
        }
        else if(op==2){
            cin>>ta;
            if(x==0)dir=1;//down
            else if(y==0)dir=0;//right
            while(ta&&x!=n+1&&y!=m+1){
                if(dir==1){
                    x=*l[y].upper_bound(x);
                }
                else if(dir==0){
                    y=*h[x].upper_bound(y);
                }
                dir^=1;
                ta--;
            }
            cout<<x<<' '<<y<<'\n';
        }
    }
    return 0; 
}