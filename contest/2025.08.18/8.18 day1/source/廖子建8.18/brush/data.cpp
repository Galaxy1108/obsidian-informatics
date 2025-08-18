#include<bits/stdc++.h>
#define N 10000
#define M 100
#define rand(l,r) (rnd()%((r)-(l)+1)+(l))
using namespace std;
mt19937 rnd;
int main(){
	freopen("brush.in","w",stdout);
	rnd.seed(time(0));
	int n=N,m=M-5;
	cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++)cout<<rand(1,100000)<<" ";
	return 0;
}
