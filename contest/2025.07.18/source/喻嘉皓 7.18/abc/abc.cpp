#include<bits/stdc++.h>
using namespace std;
const int N=61;
const int mod=998244353;
int n;
char s[3*N];
int tmp[3*N];
int cnt[4];
bool bk[3*N];
int chk[3][2];
void init(){
	chk[0][0]=1; chk[0][1]=2;
	chk[1][0]=2; chk[1][1]=0;
	chk[2][0]=0; chk[2][1]=1;
}
bool check(){
	int tot=0;
	memset(bk,0,sizeof(bk));
	for(int i=1;i<=3*n;i++){
		if(bk[i]) continue;
		int now=0;
		for(int j=i+1;j<=3*n;j++){
			if(bk[j]) continue;
			if(chk[tmp[i]][now]==tmp[j]){
				bk[j]=1; now++;
				if(now>1){
					tot+=3;
					break;
				}
			}
		}
	}
	if(tot==3*n) return 1;
	else return 0;
	
}
int ans;
void dfs(int now){
	if(now>3*n) return ans+=check(),void(); 
	if(s[now]!='?'){
		if(cnt[s[now]-'A']==n) return;
		cnt[s[now]-'A']++; tmp[now]=s[now]-'A';
		dfs(now+1);
		cnt[s[now]-'A']--; 
	}
	else{
		for(int i=0;i<3;i++){
			if(cnt[i]==n) continue;
			tmp[now]=i; cnt[i]++;
			dfs(now+1);
			cnt[i]--;
		}		
	}

}
int main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	cin>>s+1;
	init();
	if(n<=3){
		dfs(1);
		cout<<ans;
		return 0;
	}
	bool flag1=1;
	for(int i=1;i<=3*n;i++){
		if(s[i]=='?') flag1=0;
	}
	if(flag1){
		for(int i=1;i<=3*n;i++){
			tmp[i]=s[i]-'A';
			cnt[tmp[i]]++;
		}
		for(int i=0;i<3;i++){
			if(cnt[i]!=n){
				cout<<0;
				return 0;
			}
		}
		cout<<check();
		return 0;
	}
	return 0;
}

