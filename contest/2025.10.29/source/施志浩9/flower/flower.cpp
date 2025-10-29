#include<iostream>
#include<string>
using namespace std;
const int N=41;
string s[N];
bool use[N],head[N],v[N];
inline bool dfs(int x,int place)
{
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int n,o,i;
	cin>>n;
	o=n<<1;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(i=1;i<=n;i++)
	{
		fill(v,v+N,0);
		fill(use,use+N,0);
		use[i]=1;
		dfs(i,1);
	}
} 
