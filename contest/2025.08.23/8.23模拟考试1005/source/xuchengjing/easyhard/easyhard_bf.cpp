#include <cstdio>
int ans=0;
int n,m,p;
int stk[100001];
#define set(x,y) stk[depth<<1]=x,stk[(depth<<1)+1]=y
void dfs(int wh,int bk,int depth){
  // printf("<%d,%d>",wh,bk);
  if(depth==m){
    // for(int i=0;i<m;i++) printf("%d %d ",stk[i<<1],stk[(i<<1)+1]);printf("\n");
    // printf("end");
    ans=(ans+1)%p;
  }else{
    if(wh){
      set(0,0),dfs(wh-1,bk+1,depth+1);
      set(0,1),dfs(wh,bk,depth+1);
    }
    if(bk){
      set(1,0),dfs(wh,bk,depth+1);
      set(1,1),dfs(wh+1,bk-1,depth+1);
    }
  }
}
int main(){
  scanf("%d%d%d",&n,&m,&p);
  for(int i=0;i<=n;i++){
    // printf("<%d,%d>\n",i,n-i);
    dfs(i,n-i,0);
    // printf("\n");
  }
  printf("%d\n",ans);
}
