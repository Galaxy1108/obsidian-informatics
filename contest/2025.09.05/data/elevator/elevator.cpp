#include<bits/stdc++.h>
using namespace std;
const int N=2005;
struct peo{
	int ai,bi;
}que[N];
int n;
int dp[N][10][10][10][10][2];
int dfs(int nt,int wi,int a[3],int wo){
    int b[3];
    sort(a,a+3);
    for(int i=0;i<3;++i) b[i]=a[i];
    if(nt==n+1&&wo==0&&a[2]==0){
        return 0;
    }
	if(dp[nt][wi][a[0]][a[1]][a[2]][wo]>0) return dp[nt][wi][a[0]][a[1]][a[2]][wo];
    int ans=1e8;
    if((a[0]==0||wo==0)&&nt!=n+1){
        if(wo==0) {
        	ans=min(ans,dfs(nt+1,que[nt].ai,a,1)+abs(que[nt].ai-wi)+1);
        	for(int i=0;i<3;++i) a[i]=b[i];
		}
        else {
            a[0]=que[nt-1].bi;
            ans=min(ans,dfs(nt+1,que[nt].ai,a,1)+abs(que[nt].ai-wi)+1);
            for(int i=0;i<3;++i) a[i]=b[i];
        }
    }
    for(int i=0;i<3;++i){
        if(a[i]==0) continue;
        a[i]=0;
        ans=min(ans,dfs(nt,b[i],a,wo)+abs(b[i]-wi)+1);
        for(int i=0;i<3;++i) a[i]=b[i];
    }
    if(wo){
        ans=min(ans,dfs(nt,que[nt-1].bi,a,0)+abs(que[nt-1].bi-wi)+1);
        for(int i=0;i<3;++i) a[i]=b[i];
    }
    dp[nt][wi][a[0]][a[1]][a[2]][wo]=ans;
    return ans;
}
int main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&que[i].ai,&que[i].bi);
    }
    int a[3]={0,0,0};
    cout<<dfs(2,que[1].ai,a,1)+que[1].ai-1+1;
    return 0;
}
