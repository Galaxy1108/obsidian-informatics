#include<iostream>
#include<map>
using namespace std;
int a[1086],n,b[1086],flag1,ans,now;
long long hash1=223092871;
bool vis[1086],m[233092871];
bool check(){
	long long b=0;
	for(int i=1;i<=n;i++){
		b*=10;
		b+=min(a[i*2-1],a[i*2]);
		if(b>hash1)b%=hash1;
	}
	if(m[b])return 0;
	m[b]=1;
	return 1;
}
void dfs(int step){
//  cout << step << '\n';
    if(step==2*n+1){
    //	for(int i=1;i<=n*2;i++)cout << a[i];
    //	cout<< '\n';
        if(check())ans++;
        return;
    }
    if(a[step]!=-1){
        dfs(step+1);
        return;
    }
    for(int i=1;i<=n*2;i++){
        if(vis[i])continue;
        vis[i]=1;
        a[step]=i;
        dfs(step+1);
        a[step]=-1;
        vis[i]=0;
    }
} 
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
    flag1=1;
    cin >> n;
    for(int i=1;i<=n*2;i++){
        cin >> a[i];
        vis[a[i]]=1;
        if(a[i]!=-1)flag1=0;
    }
    dfs(1);
    cout << ans;
    return 0;
}
