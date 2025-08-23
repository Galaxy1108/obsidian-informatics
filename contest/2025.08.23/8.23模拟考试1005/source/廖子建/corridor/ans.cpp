#include<bits/stdc++.h>
#define int long long
#define N 50000
#define M 1000
using namespace std;
struct UpNode{
    int x,y;
    bool friend operator<(UpNode const &u,UpNode const &v){
        if(u.y==v.y)return u.x<v.x;
        return u.y<v.y;
    }
};
struct LeftNode{
    int x,y;
    bool friend operator<(LeftNode const &u,LeftNode const &v){
        if(u.x==v.x)return u.y<v.y;
        return u.x<v.x;
    }
};
int type,n,m,k,ux,uy,q,opt,p;
int a[M+5][M+5]; 
set<UpNode>upSet;
set<LeftNode>leftSet;
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
 void dfs(int x,int y,int d,int cnt){
     if(x>n||y>m){
         print(x),putchar(' ');
         print(y),putchar('\n');
         return;
     }
     if(!a[x][y]){
         if(d)dfs(x+1,y,d,cnt);
         else dfs(x,y+1,d,cnt);
         return;
     }
     if(cnt==1){
         print(x),putchar(' ');
         print(y),putchar('\n');
         return;
     }
     if(d)dfs(x,y+1,!d,cnt-1);
     else dfs(x+1,y,!d,cnt-1);
     return;
 }
void solve(int x,int y,int d){
    set<UpNode>::iterator uu;
    set<LeftNode>::iterator uv;
    // cout<<x<<" "<<y<<" "<<d<<" "<<p<<" solve\n";
    while(1){
        p--;
        if(d){
            uu=upSet.upper_bound({x,y});
            x=uu->x,y=uu->y;
            if(x>n){
                print(x),putchar(' ');
                print(y),putchar('\n');
                return;
            }
        }
        else{
            uv=leftSet.upper_bound({x,y});
            x=uv->x,y=uv->y;
            if(y>m){
                print(x),putchar(' ');
                print(y),putchar('\n');
                return;
            }
        }
        if(!p){
            print(x),putchar(' ');
            print(y),putchar('\n');
            return;
        }
        // cout<<"x="<<x<<" y="<<y<<" p="<<p<<"\n";
        d=!d;
    }
    return;
}
main(){
    freopen("corridor.in","r",stdin);
    freopen("corridor.ans","w",stdout);
    type=read(),n=read(),m=read(),k=read();
    // cout<<"efbuifwhfweu8f\n";
    // int ttt[6]={0,1,2,3,4,5};
    // cout<<*upper_bound(ttt+1,ttt+5,2);
    // if(!type){
         for(int i=1;i<=k;i++){
             ux=read(),uy=read();
             a[ux][uy]=1;
         }
         q=read();
         for(int i=1;i<=q;i++){
             opt=read();
             if(opt==1){
                 ux=read(),uy=read();
                 a[ux][uy]=1;
             }
             else if(opt==2){
                 ux=read(),uy=read(),p=read();
                 dfs(ux,uy,ux==0,p);
             }
         }
         return 0;
    // }
    for(int i=1;i<=n;i++){
        upSet.insert({i,0});
        upSet.insert({i,m+1});
        leftSet.insert({i,0});
        leftSet.insert({i,m+1});
    }
    for(int i=1;i<=m;i++){
        upSet.insert({0,i});
        upSet.insert({n+1,i});
        leftSet.insert({0,i});
        leftSet.insert({n+1,i});
    }
    for(int i=1;i<=k;i++){
        ux=read(),uy=read();
        upSet.insert({ux,uy});
        leftSet.insert({ux,uy});
    }
    q=read();
    for(int i=1;i<=q;i++){
        // cout<<"i="<<i<<"\n";
        opt=read();
        if(opt==1){
            ux=read(),uy=read();
            upSet.insert({ux,uy});
            leftSet.insert({ux,uy});
        }
        if(opt==2){
            ux=read(),uy=read(),p=read();
            solve(ux,uy,ux==0);
        }
    }
    return 0;
}
