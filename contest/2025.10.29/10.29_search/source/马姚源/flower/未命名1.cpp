#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("flower.in", "w", stdout);
	cout << "40\n";
	char c = 'a';
	int cnt = 0;
	for(int i = 0; i <= 39; i++){
		if(i % 10 == 0)c++, cnt = 0;
		cnt++;
		for(int j = 1; j <= cnt; j++)cout << c;
		cout << endl;
	}
	return 0;
}
