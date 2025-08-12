#include <bits/stdc++.h>
using namespace std;
int g[505][505][4];
int n,m;
void color(int x,int y,int cnt,int flag){
    // cout  << x << " " << y << endl;
    int maxx=x,maxy=y;
    while(g[maxx][y][flag]==-1){
        maxx++;
    }
    while(g[x][maxy][flag]==-1){
        maxy++;
    }
    if(maxx>x)maxx--;
    if(maxy>y)maxy--;
    // cout << maxx << " " << maxy << endl;
    int low=maxy,ansx=x,ansy=y;
    for(int i=x;i<=maxx;i++){
        for(int j=y;j<=low;j++){
            if(g[i][j][flag]!=-1){
                low=j-1;
                if(ansx*ansy<low*i){
                    ansx=i;
                    ansy=low;
                }
                break;
            }
        }
        if(low==maxy){
            ansx=i;
            ansy=low;
        }
        // cout << ansx << " "<< ansy << endl;
    }
    // ansx--;
    for(int i=x;i<=ansx;i++){
        for(int j=y;j<=ansy;j++){
            g[i][j][flag]=cnt;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout  << endl;
}
int main(){
    freopen("rect.in","r",stdin);
    freopen("rect.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin >> c;
            for(int k=0;k<4;k++)g[i][j][k]=(c=='B')?0:-1;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int cnt=0,x=1e9,xi;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j][0]==-1){
                cnt++;
                color(i,j,cnt,0);
            }
        }
    }
    if(x>cnt)
    {x=cnt;
        xi=0;}
    cnt=0;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(g[i][j][1]==-1){
                cnt++;
                color(i,j,cnt,1);
            }
        }
    }
    if(x>cnt){
x=cnt;
        xi=1;
    }
        
    
    cnt=0;
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(g[i][j][2]==-1){
                cnt++;
                color(i,j,cnt,2);
            }
        }
    }
    if(x>cnt){x=cnt;
        xi=2;}
        
    
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(g[i][j][3]==-1){
                cnt++;
                color(i,j,cnt,3);
            }
        }
    }
    if(x>cnt){
    x=cnt;
            xi=3;
    }
        
    
    cnt=0;
    xi=0;
    if(xi==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << g[i][j][xi] << " ";
          }
         cout << endl;
        }
    }
    if(xi==1){
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                cout << g[i][j][xi] << " ";
          }
         cout << endl;
        }
    }
    if(xi==2){
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                cout << g[i][j][xi] << " ";
          }
         cout << endl;
        }
    }
    if(xi==3){
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                cout << g[i][j][xi] << " ";
          }
         cout << endl;
        }
    }
    return 0;
}
