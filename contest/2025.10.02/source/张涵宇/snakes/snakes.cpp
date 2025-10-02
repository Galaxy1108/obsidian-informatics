#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,T;
int s[3];
signed main()
{
	freopen("snakes.in","r",stdin); 
	freopen("snakes.out","w",stdout); 
	cin>>T;int n;T--;
	cin>>n>>s[0]>>s[1]>>s[2];
	if(s[2]-s[0]>=s[1]) printf("1\n");
	else printf("3\n");
	while(T--){
		cin>>n;
		int a; 
		cin>>a>>s[0]>>a>>s[1]>>a>>s[2];
		if(s[2]-s[0]>=s[1]) printf("1\n");
		else printf("3\n");
	}
	return 0;
}
/*
2  
3   
11 14 14   
3  
1 5 2 6 3 25 
*/
