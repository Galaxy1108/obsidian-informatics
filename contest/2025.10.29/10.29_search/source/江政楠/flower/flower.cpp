#include<bits/stdc++.h>
using namespace std;
int n;
string s[1005];
bool flag_s[1005];
bool flag_pos[1005];
int pos_[1005];
void dfs(int pos,int x){
    if(x==n){
        for(int i=1;i<=2*n;i++) cout<<s[pos_[i]]<<"\n";
        exit(0);
    };
    if(flag_pos[pos]){
    	dfs(pos+1,x);
    	return;
	}
    for(int i=1;i<=n;i++){
        if(flag_s[i]) continue;
		if(pos+i+1>2*n) return;
        if(flag_pos[pos+i+1]) continue;
        pos_[pos]=i;
        pos_[pos+i+1]=i;
        flag_pos[pos]=1;
        flag_pos[pos+i+1]=1;
        flag_s[i]=1;
        dfs(pos+1,x+1);
        pos_[pos]=0;
        pos_[pos+i+1]=0;
        flag_pos[pos]=0;
        flag_pos[pos+i+1]=0;
        flag_s[i]=0;
    }
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    dfs(1,0);
    //for(int i=1;i<=n;i++) cout<<s[pos_[i]]<<"\n";
    return 0;
}

