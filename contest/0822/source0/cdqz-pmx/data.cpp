#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+3;
mt19937 rd(time(0));
int main()
{
	freopen("b.in","w",stdout);
	int n=300;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cout<<(rd()&1?1e9:1)<<" ";
	cout<<endl;
}
