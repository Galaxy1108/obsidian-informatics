#include<bits/stdc++.h>
using namespace std;
int dp[101][11][11],len;
char t[105];
int dfs(int wi,int aa,int bb,bool co){
	if(wi==len+1){
		int shu=0;
		if(aa>0) shu++;
		if(bb>0) shu++;
		if(co)shu++;
		return shu;
	}
	if(dp[wi][aa][bb]<200) return dp[wi][aa][bb];
	int ca=0,cb=0,cc=0;
	int ci=10-aa-bb;
	if(aa>0){
		for(int i=wi;i<=min(wi+aa-1,len);++i) {
			if(t[i]=='A') ca++;
			if(t[i]=='B') cb++;
			if(t[i]=='C') cc++;
		}
		if(wi+aa-1>=len) dp[wi][aa][bb]=min(dp[wi][aa][bb],dfs(len+1,ca,cb+bb,(ci+cc)>0)+1);
		else dp[wi][aa][bb]=min(dp[wi][aa][bb],dfs(wi+aa,ca,cb+bb,0)+1);
	}
	
	ca=0,cb=0,cc=0;
	if(bb>0){
		for(int i=wi;i<=min(wi+bb-1,len);++i) {
			if(t[i]=='A') ca++;
			if(t[i]=='B') cb++;
			if(t[i]=='C') cc++;
		}
		if(wi+bb-1>=len) dp[wi][aa][bb]=min(dp[wi][aa][bb],dfs(len+1,ca+aa,cb,(ci+cc)>0)+1);
		else dp[wi][aa][bb]=min(dp[wi][aa][bb],dfs(wi+bb,ca+aa,cb,0)+1);
	}
	
	ca=0,cb=0,cc=0;
	if(ci>0){
		for(int i=wi;i<=min(wi+ci-1,len);++i) {
			if(t[i]=='A') ca++;
			if(t[i]=='B') cb++;
			if(t[i]=='C') cc++;
		}
		if(wi+ci-1>=len) dp[wi][aa][bb]=min(dp[wi][aa][bb],dfs(len+1,aa+ca,cb+bb,cc>0)+1);
		else dp[wi][aa][bb]=min(dp[wi][aa][bb],dfs(wi+ci,aa+ca,cb+bb,0)+1);	
	}
	return dp[wi][aa][bb];
}
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	scanf("%d",&len);
	char c=getchar();
	for(int i=1;i<=len;++i){
		while(c<'A'||c>'Z') c=getchar();
		t[i]=c;
		c=getchar();
	}
	int ca=0,cb=0,cc=0;
	for(int i=1;i<=min(10,len);++i) {
		if(t[i]=='A') ca++;
		if(t[i]=='B') cb++;
		if(t[i]=='C') cc++;
	}
	if(len<=10) cout<<dfs(len+1,ca,cb,cc>0);
	else cout<<dfs(11,ca,cb,0);
	return 0;
}
