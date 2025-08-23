#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int g[N][N];
int n,m,k;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
pair<int,int> zwj_ak_ioi(int s,int t,int final){
    int x=s,y=t,id=0,q=0;
    id=(s==0)?1:0;
    while(x<=n&&y<=m){
        x+=dx[id],y+=dy[id];
        if(g[x][y]==1){
            q++;
            if(q==final){
                return make_pair(x,y);
            }
            if(id==0)id=1;
            else if(id==1)id=0;
            
        }
        // cout << x << " " << y << " " << id << endl;
    }
    return make_pair(x,y);
    
}
int main(){
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    cin >> n >> n >> m >> k;
    for(int i=1;i<=k;i++){
        int x,y;
        cin >> x >> y;
        g[x][y]=1;
    }
    int Q;
    cin >> Q;
    while(Q--){
        int op;
        cin >> op;
        if(op==1){
            int x,y;
            cin >> x >> y;
            g[x][y]=1;
        }
        else{
            int x,y,q;
            cin >> x >> y >> q;
            pair<int,int>ans=zwj_ak_ioi(x,y,q);
            cout << ans.first << " " << ans.second << endl;
            // cout << "\n---\n\n";
        }
    }
    return 0;
}