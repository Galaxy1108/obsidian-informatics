#include<bits/stdc++.h>
using namespace std;
const int N=100,M=998244353;
int n,m,l[N],r[N],hw[1100],ans;
void qhw(int num,int pos,int w)
{
	hw[num]=1;
	//cout<<num<<endl;
	if(pos>(w+1)/2) return ;
	if(w%2&&pos==(w+1)/2) qhw(num+(1<<((w-pos))),pos+1,w);
	else qhw(num+(1<<(w-pos))+(1<<(pos-1)),pos+1,w);
	qhw(num,pos+1,w);
}
void dfs(int pos,int sum,int w)
{
	if(pos>w)
	{
		if(hw[sum]) ans++;
		return ;
	}
	for(int i=l[pos];i<=r[pos];i++) dfs(pos+1,sum^i,w);
}
int main()
{
    freopen("far.in","r",stdin);
    freopen("far.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    //cout<<0+(1<<1)+(1<<0)<<endl;
    if(m<=10)
    {
    	
    	qhw(0,1,m);
    	//hw[0]=0;
  		for(int i=1;i<=n;i++)
    	{
    		ans=0;
    		dfs(1,0,i);
   	 		cout<<ans<<endl;
		}
	}
    return 0;
}
