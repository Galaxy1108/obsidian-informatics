#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>ary;
vector<vector<int>>vec;
void getans(int t)
{
	ary.clear();
	for(int i=1;i<=10;i++)ary.push_back(i);
	vec.push_back(ary);
	while(t--)
	{
		int x=rand()%10;
		int y=rand()%10;
		if(x!=y)swap(ary[x],ary[y]);
		bool av=true;
		for(int i=0;i<vec.size();++i)
		{
			bool pd=true;
			for(int j=0;j<10;++j)
				if(abs(ary[j]-vec[i][j])>1)
				{
					pd=false;
					break;
				}
			if(pd)
			{
				av=false;
				break;	
			}
		}
		if(av)vec.push_back(ary);
	}
}
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	getans(10000);
	cout<<vec.size()<<"\n";
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<10;j++)cout<<vec[i][j]<<" ";
		cout<<"\n";
	}
	
	return 0;
} 
