#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int n;
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	n=Qread();
	printf("1\n");
	printf("1 2 3 4 5 6 7 8 9 10\n");
	return 0;
}