#include<bits/stdc++.h>
using namespace std;
struct fs{
	int top;
	int bot;
};
bool cmp(fs a,fs b){
	int gc = __gcd(a.bot,b.bot);
	int bo = a.bot / gc;
	int bobo = b.bot / gc;
	int lc = bo * bobo * gc;
	a.top = a.top * bobo;
	b.top = b.top * bo;
	return a.top >= b.top; 
}
fs deal(fs a,fs b){
	int gc = __gcd(a.bot,b.bot);
	int bo = a.bot / gc;
	int bobo = b.bot / gc;
	int lc = bo * bobo * gc;
	a.top = a.top * bobo;
	b.top = b.top * bo;
//	cout<< "---------------" << a.top <<" "<< b.top << endl;
	a.top -= b.top;
	return {a.top,lc};
}
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
//	ios::sync_with_stdio(NULL);
//	cin.tie(0),cout.tie(0);
	fs ab;
	cin >> ab.top >> ab.bot;
	int sz = 2;
	vector<int> ve;
//	int cnt = 0;
	while(1){
		if(cmp(ab,{1,sz})){
			ab = deal(ab,{1,sz});
			ve.push_back(sz);
//			cout << sz << endl;
//			cnt -=-1;
		}
		sz ++;
//		cout << ab.top <<" "<<ab.bot <<endl;
		if(ab.top == 0){
			break;
		}
	}
	cout << ve.size() <<endl ;
	for(auto dk:ve){
		cout << dk <<' ';
	}
	return 0;
}
