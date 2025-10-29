#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
int gcd(int x,int y){return x%y==0?y:gcd(y,x%y);}
bool vis[1005];
vector<int>res,anslt;
void dfs(int pa,int pb,int prev)
{
	if(pa>1e5||pb>1e5)return;
	if(pa*b>pb*a)return;
	int lpa=pb*a-pa*b;
	int lpb=pb*b;
	int gcl=gcd(lpa,lpb);
	lpa/=gcl,lpb/=gcl;
	if(lpa==1&&prev<lpb)
	{
		res.push_back(lpb);
		if(anslt.size()==0||anslt.size()>res.size())anslt=res;
		res.pop_back();
		return;
	}
	if(pa==a&&pb==b)
	{
		if(anslt.size()==0||anslt.size()>res.size())anslt=res;
		return;
	}
	if(res.size()>=anslt.size()&&anslt.size()!=0)return;
	for(int i=prev+1;i<=40;i++)
	{
		res.push_back(i);
		int gc=gcd(i*pa+pb,i*pb);
		dfs((i*pa+pb)/gc,(i*pb)/gc,i);
		res.pop_back();
	}
}
signed main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin>>a>>b;
	int gcs=gcd(a,b);
	a/=gcs,b/=gcs;
	dfs(0,1,1);
	cout<<anslt.size()<<"\n";
	for(int i=0;i<anslt.size();i++)cout<<anslt[i]<<" ";
	
	return 0;
} 
