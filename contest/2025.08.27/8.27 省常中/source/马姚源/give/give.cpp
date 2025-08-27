#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500];
int m,s,n;
int ans=0;

void dfs(int cnt,int sum){
    if(cnt>m||sum>s)return;
    if(cnt==m&&sum==s){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        dfs(cnt+1,sum+a[i]);
    }
}

void Main(){
    cin >> m >> s >> n;
    ans=0;
    int k=0;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
    	if(a[i]==a[i-1])k++;
	}
	if(k+1==n){
		if(m*a[1]==s)
			cout << 1 << "\n";
		else cout << 0 << '\n';
		return;
	}
    dfs(0,0);
    cout << (ans%2) << '\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("give.in","r",stdin);
    freopen("give.out","w",stdout);
    int T;
    cin >> T;
    while(T--)Main();
    return 0;
}
