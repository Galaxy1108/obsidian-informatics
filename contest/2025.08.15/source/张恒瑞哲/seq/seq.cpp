#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 15;
const int MOD = -1;

vector<int> a(15),b(15),sv(15);
int n,m;
vector<string> s;
const string num[10] = {"0","1","2","3","4","5","6","7","8","9"};
string tmp = "";
void Dfs(int k){
	if(k == n){ s.push_back(tmp); return; }
	string tmp2 = tmp;
	tmp = tmp+num[a[k]];
	Dfs(k+1);
	tmp = tmp2;
	Dfs(k+1);
}

int main(){

    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
	
	sc("%d",&n); REP(i,0,n-1) sc("%d",&a[i]);
	sc("%d",&m); REP(i,0,m-1) sc("%d",&b[i]);
	sv = a; sort(sv.begin(),sv.end());
	sv.erase(unique(sv.begin(),sv.end()),sv.end());
	REP(i,0,n-1) a[i] = lower_bound(sv.begin(),sv.end(),a[i])-sv.begin()-1;
	REP(i,0,m-1) b[i] = lower_bound(sv.begin(),sv.end(),b[i])-sv.begin()-1;
	Dfs(0);
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	string s3 = "";
	REP(i,0,m-1) s3 = s3+num[b[i]];
	pr("%d",lower_bound(s.begin(),s.end(),s3)-s.begin());
	
	return 0;
}

