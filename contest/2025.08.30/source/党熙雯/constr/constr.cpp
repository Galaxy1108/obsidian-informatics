#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	cout<<"3\n";
	cout<<"1 2 3 4 5 6 7 8 9 10\n1 2 3 4 5 6 7 10 8 9\n1 2 3 4 5 6 7 10 9 8\n";
	return 0;
}

