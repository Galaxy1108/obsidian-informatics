#include <bits/stdc++.h>
using namespace std;
#define N 15
#define V 5005
int m,n,len[N];
bitset<V>book;
char ans[V][V];
void dfs(int x,int dep,int up,int left){
#define ls (x<<1)
#define rs (x<<1|1)
	if(dep==m){
		if(x&1){
			ans[up][left+1]='o';
		}
		else{
			ans[up][left]='o';
		}
		return ;
	}
	ans[up][left+len[dep+1]]='o';
	if(!book[ls]){
		for(int i=1;i<=len[dep+2];i++){
			ans[up+i][left+len[dep+1]-i]='/';
		}
		dfs(ls,dep+1,up+len[dep+2]+1,left);
	}
	if(!book[rs]){
		for(int i=1;i<=len[dep+2];i++){
			ans[up+i][left+len[dep+1]+i]='\\';
		}
		dfs(rs,dep+1,up+len[dep+2]+1,left+len[dep+1]+1);
	}
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	scanf("%d%d",&m,&n);
	int _u,_v;
	while(n--){
		scanf("%d%d",&_u,&_v);
		book[(1<<(_u-1))+_v-1]=true;
	}
	len[m+1]=1;
	len[m]=2;
	for(int i=m-1;i>=1;i--){
		len[i]=len[i+1]<<1|1;
	}
	memset(ans,' ',sizeof(ans));
	if(!book[1])dfs(1,1,1,1);
	for(int i=1;i<=len[2]+1;i++){
		ans[i][len[1]+2]='\0';
		printf("%s\n",ans[i]+1);
	}
	return 0;
}

