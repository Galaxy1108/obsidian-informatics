#include<bits/stdc++.h>
using namespace std;
const int N = 41;
string s[N];
int p[N];
int n;
int ans[2*N][N];
int cnt[N];
bool flag = 0;
int e[2*N][N];
void dfs(int step){
    if(flag)return;
    if(step==2*n+1){
        for(int i = 1;i<=n;i++)if(cnt[i]!=2||(e[i][2]-e[i][1])!=i+1)return;
        for(int i = 1;i<=2*n;i++){
            ans[i][n] = p[i];
        }
        flag = 1;
        return;
    }
    for(int i = 1;i<=n;i++){
        if(cnt[i]>2)return;
        if(cnt[i]==2)continue;
        cnt[i]++;
        p[step] = i;
        e[i][cnt[i]] = step;
        dfs(step+1);
        e[i][cnt[i]] = 0;
        p[step] = 0;
        cnt[i]--;
    }
}
int main(){
	freopen("flower.in","r",stdin); 
    freopen("flower.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>s[i];
    dfs(1);
    for(int i = 1;i<=2*n;i++){
    	cout<<s[ans[i][n]]<<" ";
	}
    //for(int i = 1;i<=2*n;i++)cout<<ans[i][n]<<" ";
    //freopen("flower.in","r",stdin);
    //freopen("flower.out","w",stdout);
    //for(int i = 1;i<=10;i++){
       // memset(p,0,sizeof(p));
       // n = i*4-1;
       // dfs(1);
       // memset(p,0,sizeof(p));
        //n = i*4;
       // dfs(1);
    //}
    return 0;
}
