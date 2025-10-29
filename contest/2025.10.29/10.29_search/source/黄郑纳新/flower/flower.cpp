#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=50;
string s[N];
int n,ans[N<<1],lst[N],vis[N],flag;
inline void dfs(int pos){
	if(flag)return;
	if(pos>n+n){
		for(int i=1;i<=n+n;i++){
			cout<<s[ans[i]]<<"\n";
		}
		flag=1;
		return;
	}
	for(int i=1;i<=n;i++){
//		for(int j=1;j<pos;j++)cout<<ans[j]<<' ';cout<<endl;
		if(!vis[i]){
			lst[i]=pos;
			vis[i]++;
			ans[pos]=i;
			dfs(pos+1);
			vis[i]--;
			lst[i]=0;
			continue;
		}
		else if(vis[i]==1&&pos-lst[i]==i+1){
			vis[i]++;
			ans[pos]=i;
			dfs(pos+1);
			vis[i]--;
		}
	}
}
signed main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)cin>>s[i];
	dfs(1);
	return 0;
}
/*
40
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
*/
