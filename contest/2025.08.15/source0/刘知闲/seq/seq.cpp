#include<bits/stdc++.h>
using namespace std;
#define int long long
string A,B,s[10005],temp;
int num,n,m,tot,cnt;
long long ans;
void dfs(int pos,string t){
	if(pos==n){
		if(t!="")
			s[++tot]=t;
		s[++tot]=t+A[pos];
		return;
	}
	dfs(pos+1,t);
	dfs(pos+1,t+A[pos]);
	return;
}
signed main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num;
        A+=num+'0';
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>num; 
        B+=num+'0';
    }
    dfs(0,"");
    sort(s+1,s+tot+1);    
    cnt=unique(s+1,s+tot+1)-s-1;
    cnt=unique(s+1,s+cnt+1)-s-1;
    ans=lower_bound(s+1,s+cnt+1,B)-s-1;
    cout<<ans;
    return 0;
}
