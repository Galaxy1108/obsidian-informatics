#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,p;
int memal[N][N][2][2];
bool visal[N][N][2][2];
#define mem memal[pos][b][pd1][pd2]
#define vis visal[pos][b][pd1][pd2]
int dfs(int pos,int b,bool pd1,bool pd2)
{	
	if(vis)return mem;
	vis=true;
	if(pos==m+1)return mem=(pd1||pd2); 
	int res=0;
	if(b<n)res+=dfs(pos+1,b+1,pd1||(b+1==0),pd2||(b+1==n)),res%=p;
	if(b>0)res+=dfs(pos+1,b-1,pd1||(b-1==0),pd2||(b-1==n)),res%=p;
	if(b<n)res+=dfs(pos+1,b,pd1||(b==0),pd2||(b==n)),res%=p;
	if(b>0)res+=dfs(pos+1,b,pd1||(b==0),pd2||(b==n)),res%=p;
	return mem=res;
}
int main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	cin>>n>>m>>p;
	int anslt=0;
	for(int i=0;i<=n;++i)anslt=(anslt+dfs(1,i,0,0))%p;
	cout<<anslt;
	
	return 0;
} 
