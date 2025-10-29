#include<iostream>

using namespace std;
int n,tim[1086],cnt[1086],ans[1086];
string flowers[1086];
void dfs(int step){
//	cout << step << '\n';
	if(step==n+1){
		for(int i=1;i<=n*2;i++)cout << flowers[ans[i]] << '\n'; 
		exit(0);
	}
	for(int l=1,r=step+2;r<=n*2;l++,r++){
		if(cnt[l]==0&&cnt[r]==0){
			cnt[l]=cnt[r]=1;
			ans[l]=ans[r]=step;
			dfs(step+1);
			ans[l]=ans[r]=0;
			cnt[l]=cnt[r]=0;
		}
	}
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> flowers[i];
	dfs(1);
	return 0;
} 
/*
40
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 39 40
*/
