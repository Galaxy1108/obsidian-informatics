#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
	if(x<10) return 1;
	int lst=x%10;
	x/=10;
	while(x)
	{
		if((lst-x%10)<-2||(lst-x%10)>2) return 0;
		lst=x%10;
		x/=10;
	}
	return 1;
}
int main()
{
	int l,r,ans=0;
	cin>>l>>r;
	for(int i = l; i <= r; i++)
	{
		if(check(i)) ans++;
	}
	cout<<ans;
}
