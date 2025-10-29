#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
	freopen("math.in","w",stdout);
	srand(time(0));
	int len=rand()%500+1,b=rand()%(1000-len+1)+1;
	cout<<b<<" "<<b+len-1<<"\n";
	cerr<<b<<" "<<b+len-1<<"\n";
	return 0;
}
