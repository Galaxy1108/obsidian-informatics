#include <bits/stdc++.h>
using namespace std;
int a[105];
int n;
int cnt[105][5];
int sum[105][5],p[105][5];
int dp[105][105][105];
int ans=1e9;
void dfs(int x,int y,int z,int lst,int num){
    if(lst>n||num>n)return;
    if(x<0||y<0||z<0)return;
    cout << x << " " << y << " " << z << " " << num << " " << lst << endl;
    if(lst==n&&num!=0&&x==0&&y==0&&z==0){
        ans=min(num,ans);
        // cout << ans << " ";
        return;
    }
    
    if(x+y+z<10){
        dfs(x+sum[lst][1],y+sum[lst][2],z+sum[lst][3],lst+1,num);
    }
    else{
        dfs(x-cnt[lst][1],y,z,lst,num+1);
        dfs(x,y-cnt[lst][2],z,lst,num+1);
        dfs(x,y,z-cnt[lst][3],lst,num+1);
    }
}
int main(){
    freopen("worker.in","r",stdin);
    freopen("worker.out","w",stdout);
    
    cin >> n;
    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        if(c=='A')a[i]=1;
        if(c=='B')a[i]=2;
        if(c=='C')a[i]=3; 
    }
    // for(int i=1;i<=n;i++)cout << a[i] << " ";
    // cout << "\n\n---\n\n";
    for(int i=1;i<=n;i++){
        sum[i][a[i]]++;
        for(int j=max(i-9,0);j<=i;j++){
            cnt[i][a[j]]++;
        }
    }
    // for(int i=1;i<=n;i++){
        // cout << cnt[i][1] << " " << cnt[i][2] << " " << cnt[i][3] << endl;
    // }
    // cout << "\n---\n\n";
    for(int i=1;i<=n;i++){
        p[i][1]=p[i-1][1]+sum[i][1];
        p[i][2]=p[i-1][2]+sum[i][2];
        p[i][3]=p[i-1][3]+sum[i][3];
    }
    // for(int i=1;i<=n;i++){
        // cout << p[i][1] << " " << p[i][2] << " " << p[i][3] << endl;
    // }
    // cout << "\n---\n\n";
    // dfs(0,0,0,1,0);
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[0][cnt[i][2]][cnt[i][3]]=dp[cnt[i][1]][0][cnt[i][3]]=dp[cnt[i][1]][cnt[i][2]][0]=2;
        
        dp[0][0][cnt[i][3]]=dp[0][cnt[i][2]][0]=dp[cnt[i][1]][0][0]=1;
        dp[0][0][0]=0;
    }
    // dp[0][p[1][0]]
    for(int i=1;i<=n;i++){
        dp[p[i][1]][p[i][2]][p[i][3]]=min(min(dp[p[i][1]-cnt[i][1]][p[i][2]][p[i][3]],dp[p[i][1]][p[i][2]-cnt[i][2]][p[i][3]]),dp[p[i][1]][p[i][2]][p[i][3]-cnt[i][3]])+1;
        // int k,k1,k2;
        // k=p[i][1],k1=p[i][2],k2=p[i][3];
        // while(k>0)dp[k][k1][k2]=dp[p[i][1]][p[i][2]][p[i][3]],k--;
        // k=p[i][1],k1=p[i][2],k2=p[i][3];
        // while(k1>0)dp[k][k1][k2]=dp[p[i][1]][p[i][2]][p[i][3]],k1--;
        // k=p[i][1],k1=p[i][2],k2=p[i][3];
        // while(k2>0)dp[k][k1][k2]=dp[p[i][1]][p[i][2]][p[i][3]],k2--;
    }
    cout << dp[p[n][1]][p[n][2]][p[n][3]];
    // cout << ans;
    return 0;
}