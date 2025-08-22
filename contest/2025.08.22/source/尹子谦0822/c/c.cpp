#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010;
int a[MAXN][MAXN],n,seed;
bool vis[N];
void dfs()
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>seed;
	if(seed) gen(n,seed);
	else
	{
		for(int i=1;i<=n+1;i++)
			for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++) 
	{
		int maxx=-1,pos;
		for(int j=1;j<=n+1;j++) 
		{
			if(a[i][j]>maxx) maxx=a[i][j],pos=j;
		}
		cout<<pos<<endl;
	}
	return 0;
}

