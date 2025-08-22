#include <bits/stdc++.h>
#include <random>
#include <algorithm>
using namespace std;
const int MAXN=5010;
struct node{
	int val,id;
}a[MAXN][MAXN];
int b[MAXN][MAXN];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j].val=j;
            std::swap(a[i][j].val,a[i][rng()%j+1].val);
        }
    }
}
bool cmp(node a,node b)
{
	return a.val>b.val;
}
int n;
bool can[5005];
int seed;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>seed;
	if(!seed)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n+1;j++)
			{
				cin>>a[i][j].val;
				a[i][j].id=j;
				b[i][j]=a[i][j].val;
			}
		}
	}
	else
	{
		gen(n,seed);
	}
	for(int i=1;i<=n;i++)
	{
		sort(a[i]+1,a[i]+n+2,cmp);
		//for(int j=1;j<=n+!;j++)
	}
	for(int i=1;i<=n;i++)
	{
		memset(can,0,sizeof(can));
		int tot=0;
		for(int j=i;j<=n+i-1;j++)
		{
			tot++;
			int t=1;
			int jj=j%n;
			if(jj==0) jj=n;
			while(can[a[jj][t].id])
			{
				t++;
			}
			//cout<<"likebest"<<a[jj][t].id<<"\n";
			int mn=1e9;
			int wh=jj;
			for(int k=1;k<=n;k++)
			{
				if(b[k][a[wh][t].id]<mn)
				{
					mn=b[k][a[wh][t].id];
					wh=k;
				}
			}
//			cout<<"who:"<<wh<<"\n";
//			cout<<"mn:"<<mn<<"\n";
			if(mn>n-tot+1)
			{
				t=n+1;
				while(can[a[wh][t].id]) {
					t--;
				}
				//cout<<"b "<<i<<" "<<wh<<" "<<a[wh][t].id<<"\n";
				can[a[wh][t].id]=1;
			}
			else
			{
				t=1;
				while(can[a[wh][t].id]) {
					t++;
				}
				can[a[wh][t].id]=1;
				//cout<<"n "<<i<<" "<<wh<<" "<<a[wh][t].id<<"\n";
			}
		}
		//int bh=0;
		for(int j=1;j<=n+1;j++)
		{
			if(!can[j]) 
			{
				//bh++;
				cout<<j<<" ";
			}
		}
	}
	
	
	
	return 0;
} 
