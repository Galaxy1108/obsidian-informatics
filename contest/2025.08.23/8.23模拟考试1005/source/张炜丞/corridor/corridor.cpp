#include<bits/stdc++.h>
using namespace std;
// #define int long long
// typedef long long ll;
// #define ls (p<<1)
// #define rs (p<<1|1)
// #define lb(x) (x&(-x))
const int N=5e4+5,K=20,inf=1e9;
#define pii pair<int,int>
#define mpr make_pair
// signed P=998244353;

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

int type,n,m,cn;
// st[150005][K][2],qx[150005+N*2],qy[150005+N*2];
// unordered_map<pii,int> ma;
set<int> ax[N],ay[N];
// void work2(int x,int y,int q,int f);

// void workk(){
//     for(int i=1;i<=cn;++i){
//         ma[mpr(qx[i],qy[i])]=i;
//     }
//     for(int i=1;i<=n;++i){
//         qx[++cn]=i;qy[++cn]=m+1;
//     }
//     for(int i=1;i<=m;++i){
//         qx[++cn]=n+1;qy[++cn]=i;
//     }
//     for(int i=1;i<=cn-m-n;++i){
//         int x=qx[i],y=qy[i];
//         auto p=ax[x].upper_bound(y);
//         int v=ma(mpr(x,p==ax[x].end()?m+1:*p));
//         st[i][0][0]=v;
//         auto p=ay[y].upper_bound(x);
//         int v=ma(mpr(p==ay[y].end()?n+1:*p,y));
//         st[i][0][1]=v;
//     }
//     for(int i=cn-m-n+1;i<=cn;++i){
//         st[i][0][0]=st[i][0][1]=i;
//     }
//     for(int i=1;i<=cn;++i){
//         st[i][1][0]=st[st[i][0][0]][0][1];
//         st[i][1][1]=st[st[i][0][1]][1][0];
//     }
//     for(int i=2;i<K;++i){
//         for(int j=1;j<=cn;++j){
//             for(int f=0;f<=1;++f){
//                 st[j][i][f]=st[st[j][i-1][f]][i-1][f];
//             }
//         }
//     }
//     int Q=read();
//     for(int i=1,op,x,y,q;i<=Q;++i){
//         op=read(),x=read(),y=read();
//         q=read();
//         work2(x,y,q,x==0);
//     }
// }

// void workd(int v,int d,bool f){

//     for(int i=K-1;i>=0;--i)
// }

// void work2(int x,int y,int d,bool f){
//     if(f==0){
//         auto p=ax[x].upper_bound(y);
//         workd(x,p==ax[x].end()?m+1:*p,d-1,1);
//     }
//     else{
//         auto p=ay[y].upper_bound(x);
//         workd(p==ay[y].end()?n+1:*p,y,d-1,0);
//     }
// }
void work(int x,int y,int d,bool f){
    // cout<<" /work x:"<<x<<" y:"<<y<<" d:"<<d<<" f:"<<f<<endl;
    if(d==0||x==n+1||y==m+1){
        print(x);putchar(' ');print(y);putchar('\n');
        return;
    }
    if(f==0){
        auto p=ax[x].upper_bound(y);
        work(x,p==ax[x].end()?m+1:*p,d-1,1);
    }
    else{
        auto p=ay[y].upper_bound(x);
        work(p==ay[y].end()?n+1:*p,y,d-1,0);
    }
}

signed main(){
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    type=read();n=read();m=read();cn=read();
    for(int i=1,x,y;i<=cn;++i){
        x=read();y=read();
        ax[x].insert(y);
        ay[y].insert(x);
        // qx[i]=x;qy[i]=y;
    }
    int Q=read();
    for(int i=1,op,x,y,q;i<=Q;++i){
        op=read(),x=read(),y=read();
        if(op==1){
            ax[x].insert(y);
            ay[y].insert(x);
        }
        else{
            q=read();
            work(x,y,q,x==0);
        }
    }
    return 0;
}