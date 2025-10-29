#include<iostream>

using namespace std;
long long ans,n,x,mod=998244353;
int a[20],ud,limi,len;
int dp[505][505][505];
bool check(){
    int cnt=len-1,tmp=len,b[20];
    for(int i=1;i<=len;i++)b[i]=a[i];
    while(1){
        for(int i=1;i<=len;i++){
            if(b[i]!=0&&b[i]<=cnt){
               b[i]=0;
               tmp--;
            }
            else if(b[i]!=0)b[i]-=cnt;
        }
        //cout << tmp  <<' '<<len<< '\n'; 
        cnt=tmp-1;
        if(tmp==1)return 0;
        if(tmp==0)return 1;
    }
}
void dfs(int step){
    //cout << step << '\n';
    if(step>=len+1){
        
        if(check()){
//        	for(int i=1;i<=len;i++)cout << a[i] << ' ';
//            cout <<'!'<< '\n';
			ans++;
		}
        return;
    }
    for(int i=1;i<=limi;i++){
        a[step]=i;
        dfs(step+1);
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> n >> x;
    if(x<n){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=x;
            if(ans>mod)ans%=mod;
        }
        cout << ans;
        return 0;
    }
    if(n*x<=100){
    	limi=x;
    	len=n;
    	dfs(1);
    	cout << ans << '\n';
    	return 0;
	} 
    for(int i=1;i<=x;i++){
        dp[2][i][1]=1;
        dp[2][i][0]=(i-1)*2;
    }
    for(int i=3;i<=n;i++){
        dp[i][1][0]=dp[i][1][1]=1;
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j][1]=dp[i-1][j][0]+dp[i-1][j][1]*j;
            dp[i][j][1]%=mod;
        //    if(i==3&&j==3)cout << dp[i-1][j][0] << '\n';
        }
        long long sum=1;
        for(int j=2;j<=x;j++){
            dp[i][j][0]=sum+dp[i-1][j][0]*(j-1);
            sum+=dp[i-1][j][0]+dp[i-1][j][1];
            sum%=mod;
            dp[i][j][0]%=mod;
        }
    }
    if(n==3){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=(n-1);
            if(ans>mod)ans%=mod;
        }
        ans+=(x/2-1)*dp[3][2][0];
        for(int i=n;i<=x;i++){
            ans+=dp[n][i][1];
            ans%=mod;
        }
        cout << ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
            ans*=(n-1);
            if(ans>mod)ans%=mod;
    }
    for(int i=n;i<=x;i++){
        ans+=dp[n][i][1];
        ans%=mod;
    }
    cout << ans;
    return 0;
}
