#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int cnt[3],i,n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
		cnt[s[i]-'0']++;
	int m=n/2+n%2;
	if(cnt[1]>m||cnt[2]>m||cnt[0]>m)
	{
		printf("-1");
	}
	else
	{
		srand(time(0));
		int x=rand()%n+1;
		printf("%d",x);
	}
	return 0;
}
