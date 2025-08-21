#include<bits/stdc++.h>
#define int long long
#define N 50
using namespace std;
int n,a[N+5],b[N+5],bans=INT_MAX,u[N+5];
int read(){
    int f=1,g=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        g=g*10+ch-'0';
        ch=getchar();
    }
    return f*g;
}
void print(int x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return;
}
int Rand(int l,int r){return rand()%(r-l+1)+l;}
void dfs(int dep,int sum){
    bool flag=1;
    if(sum>n*n||sum>bans||dep>10)return;
    for(int i=1;i<n;i++){
        if(u[i]>u[i+1]){
            flag=0;
            break;
        }
    }
    if(flag){
        bans=min(bans,sum);
        return;
    }
    for(int i=1;i<=3;i++){
        int l=Rand(1,n-1),r=Rand(l+1,n);
        while(u[l]==u[r])l=Rand(1,n-1),r=Rand(l+1,n);
        swap(u[l],u[r]),dfs(dep+1,sum+2*(r-l));
        swap(u[l],u[r]);
    }
    return;
}
void dfsb(int dep,int sum){
    bool flag=1;
    if(sum>n*n||sum>bans||dep>10)return;
    for(int i=1;i<n;i++){
        if(u[i]>u[i+1]){
            flag=0;
            break;
        }
    }
    if(flag){
        bans=min(bans,sum);
        return;
    }
    for(int i=1;i<=3;i++){
        int l=Rand(1,n-1),r=Rand(l+1,n);
        while(u[l]==u[r])l=Rand(1,n-1),r=Rand(l+1,n);
        swap(u[l],u[r]),dfsb(dep+1,sum+2*(r-l));
        swap(u[l],u[r]);
    }
    dfsb(dep+1,sum);
    return;
}
void dfsc(int dep,int sum){
    bool flag=1;
    if(sum>n*n||sum>bans||dep>10)return;
    for(int i=1;i<n;i++){
        if(u[i]>u[i+1]){
            flag=0;
            break;
        }
    }
    if(flag){
        bans=min(bans,sum);
        return;
    }
    for(int i=1;i<=6;i++){
        int l=Rand(1,n-1),r=Rand(l+1,n);
        while(u[l]==u[r])l=Rand(1,n-1),r=Rand(l+1,n);
        swap(u[l],u[r]),dfsc(dep+1,sum+2*(r-l));
        swap(u[l],u[r]);
    }
    return;
}
main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    n=read(),srand(time(0));
    for(int i=1;i<=n;i++)a[i]=u[i]=read();
    dfs(1,0),dfsb(1,0);
    dfsc(1,0);
    print(bans);
    return 0;
}
