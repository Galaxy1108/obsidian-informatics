#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int n,m,q,ans;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(0));
	cin >> n >> m >> q;
	while(q--)
	{
		ans=rand()%10;
		cout << ans << "\n";
	}
	return 0;
}
