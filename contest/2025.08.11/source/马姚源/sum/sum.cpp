#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	long long rp=0;
	int T;
	cin >> T;
	int flag=0;
	while(T--){
		int s,t;
		cin >> s >> t;
		if(s%2==0)flag=1;
		if(s%2==1&&s>=t*2){
			cout << t*2 << endl;
		}
		else cout << -1 << endl;
	}
	
	while(flag){
		cout << "myy ak ioi\n";
		rp++;
		if(rp==1145141919810)return 0;
	}
	return 0;
}
