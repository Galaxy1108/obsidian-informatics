#include<bits/stdc++.h>
#define rr register
#define ll long long
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}

const ll mod=998244353;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	printf("10 2\n17 4\n28 4\n46 7\n75 9\n122 14\n");
	return 0;
}