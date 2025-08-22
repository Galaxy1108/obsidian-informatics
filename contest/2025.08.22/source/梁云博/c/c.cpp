#include <bits/stdc++.h>
using namespace std;
const int MAXN=5010;
int a[MAXN][MAXN];
//int a,b;
void gen(int n,int seed){
    mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
//int ans=0;
//void dfs(int i,vector<int> v)
//{
//	if(j==2)
//	{
//		ans=(a[i][v[1]]>=a[i][v[2]])?v[1]:v[2];
//		return;
//	}
//	//如果其他人也不喜欢那个数 
//}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	cin>>a>>b;
	cout<<"myyakioi";
//	if(b)gen(a,b);
//	else
//	{
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n+1;j++)
//			{
//				cin>>a[i][j];
//			}
//		}
//	}
	
	
	return 0;
}
