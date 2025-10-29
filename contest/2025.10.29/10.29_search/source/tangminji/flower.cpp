#include <cstdio>
#include <cstdlib>
#define N 42
#define L 12
#define IL inline
#define REP(a,b,c) for(a=b;a<=c;a++)
using namespace std;
//n>=2时才有解
//我错了，是必须隔i支鲜花
char name[N][L];
int num[N<<1],n,ed;bool used[N];
IL int rd(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
	return res;
}
IL void print(){
	int i;
	REP(i,1,ed-1)puts(name[num[i]]);
	exit(0);
}
IL void dfs(int i){
	while(num[i])i++;
	if(i==ed){print();}
	int j;
	for(j=n;used[j];j--);
	if(i+j+1>=ed)return;
	for(j=1;j<=n && i+j+1<ed;j++)
		if(!used[j] && !num[i+j+1]){
			used[j]=true;
			num[i]=num[i+j+1]=j;
			dfs(i+1);
			used[j]=false;
			num[i]=num[i+j+1]=0;
		}
}
int main(){
	freopen("flower.in","r",stdin),freopen("flower.out","w",stdout);
	int i;n=rd(),ed=n<<1|1;
	REP(i,1,n)scanf("%s",name[i]);
	dfs(1);
	return 0;
}
