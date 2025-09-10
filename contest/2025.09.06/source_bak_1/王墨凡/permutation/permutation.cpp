#include<iostream>
#include<cstring>
using namespace std;
int now[10086],p[10086],q[10086],tick[10086],n;
bool f=0;
bool check(){
	int no[10086],ans1[10086],ans2[10086];
	memset(no,0,sizeof no);
	memset(ans1,0,sizeof ans1);
	memset(ans2,0,sizeof ans2);
	for(int i=1;i<=n;i++){
		no[now[i]]=i;		
	}
	for(int i=1;i<=n;i++){
		ans1[i]=p[now[i]];
	}
	for(int i=1;i<=n;i++){
		ans2[i]=no[ans1[i]];
//		cout << ans2[i] <<' ';	
	}
	for(int i=1;i<=n;i++){
		if(ans2[i]!=q[i]){
//			cout << endl;
			return 0;
		} 
	}
//	cout << endl;
	return 1;
}
void dfs(int deep){
	if(f)return;
	if(deep==n+1){
		if(check()){
				f=1;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(f)break;
		if(tick[i])continue;
		tick[i]=1;
		now[deep]=i;
		dfs(deep+1);
//		now[deep]=0;
		tick[i]=0;
	}
}
int main(){
	freopen("perutation.in","r",stdin);
	freopen("perutation.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> p[i];
	for(int i=1;i<=n;i++)cin >> q[i];
	dfs(1);
	if(!f){
		cout << "NO";
	}
	else{
		cout << "YES" << endl;
		for(int i=1;i<=n;i++)cout << now[i] << ' ';
	}
	return 0;
}
/*
8
2 3 4 5 6 7 8 1
1 2 4 3 6 8 5 7
*/
