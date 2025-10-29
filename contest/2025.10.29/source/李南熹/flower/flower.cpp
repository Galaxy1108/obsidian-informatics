#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[50];
int n,ans[100]={0},miku[50][5],cnt[50],anss=0;
bool f=0;
inline void dfs(int dep,int num){
	if(cnt[num]==3) return;
	if(miku[num][2]!=0&&dep!=num+2+miku[num][1]){
		return;
	}
	if(dep==2*n+1){
		for(int i=1;i<=n;i++){
			ans[miku[i][1]]=i;
			ans[miku[i][2]]=i;
		}
		for(int i=1;i<=2*n;i++){
			cout<<s[ans[i]]<<endl;
		}
		exit(0);
	}
	for(int i=n;i>=1;i--){
		//if(f==1) return;
		cnt[i]++;
		miku[i][cnt[i]]=dep;
		dfs(dep+1,i);
		miku[i][cnt[i]]=0;
		cnt[i]--;
		//if(cnt[i]==2) cnt[i]--;
	}
}
signed main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	dfs(1,0);
	return 0;
}
