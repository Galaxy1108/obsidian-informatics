#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,x,y;
int id[10],ans[500][500];
int bit[N];
void clear(){
    for(int i=1;i<=n*n;i++)bit[i]=0;
}
void add(int x){
    while(x)bit[x]++,x&=x-1;
}
int qry(int x){
    int res=0;
    while(x<=n*n)res+=bit[x],x+=x&-x;
    return res;
}
int solve1(){
//	puts("QWQ"); 
    for(int i=1;i<=n*n;i++)id[i]=i;
    do{
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans[i][j]=id[(i-1)*n+j];
        clear();
        int res1=0,res2=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            res1+=qry(ans[i][j]);
            add(ans[i][j]);
        }
        clear();
        for(int j=1;j<=n;j++)for(int i=1;i<=n;i++){
            res2+=qry(ans[i][j]);
            add(ans[i][j]);
        }
        if(res1==x&&res2==y){
            puts("YES");
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",ans[i][j]," \n"[j==n]);
            return 0;
        }
    }while(next_permutation(id+1,id+1+n*n));
    puts("NO");
    return 0;
}
int solve2(){
    clear();
    if(!x){
        int tot=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans[i][j]=++tot;
        int res=0;
        for(int j=1;j<=n;j++)for(int i=1;i<=n;i++){
            res+=qry(ans[i][j]);
            add(ans[i][j]);
        }
        if(res==y){
            puts("YES");
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",ans[i][j]," \n"[j==n]);
            return 0;
        }
        puts("NO");
    }else{
        int tot=0;
        for(int j=1;j<=n;j++)for(int i=1;i<=n;i++)ans[i][j]=++tot;
        int res=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            res+=qry(ans[i][j]);
            add(ans[i][j]);
        }
        if(res==x){
            puts("YES");
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",ans[i][j]," \n"[j==n]);
            return 0;
        }
    }
    return 0;
}
int solve(){
    scanf("%d%d%d",&n,&x,&y);
    if(n<=3)solve1();
    else if(min(x,y)==0)solve2();
    else{
        puts("YES");
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",(i-1)*n+j," \n"[j==n]);
    }
    return 0;
} 
int main(){
    freopen("matrixcascade.in","r",stdin);
    freopen("matrixcascade.out","w",stdout);
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}
