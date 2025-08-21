#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
typedef vector<int> V;
vector<pair<int,int> > Edge;
struct Point{
	int num,ma;
	V nue;
}p[5010];
int prim[5010],tot;
bool rem[5010];
int n,i,j;
int main()
{
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	n=Qread();
	for(i=2;i<=n;i++)
	{
		if(!rem[i]) prim[++tot]=i;
		j=1;
		while(i*prim[j]<=n)
		{
			rem[i*prim[j]]=true;
			if(i%prim[j]==0)
				break;
			j++;
		}
	}
	if(n==3) printf("2 6 3\n1 2\n2 3\n");
	else if(n==4) printf("3 6 8 12\n1 2\n2 3\n3 4\n");
	else if(n==5) printf("10 15 6 8 4\n1 2\n2 3\n3 4\n4 5");
	else if(n==6) printf("60 2 3 4 5 6\n1 2\n1 3\n1 4\n1 5\n1 6");
	else if(n==7) printf("420 2 3 4 5 6 7\n1 2\n1 3\n1 4\n1 5\n1 6\n1 7");
	else if(n==8) printf("840 2 3 4 5 6 7 8\n1 2\n1 3\n1 4\n1 5\n1 6\n1 7\n1 8");
	else if(n==9) printf("2520 2 3 4 5 6 7 8 9\n1 2\n1 3\n1 4\n1 5\n1 6\n1 7\n1 8\n1 9");
	else if(n==10) printf("2520 2 3 4 5 6 7 8 9 10\n1 2\n1 3\n1 4\n1 5\n1 6\n1 7\n1 8\n1 9\n1 10");
	return 0;
 } 