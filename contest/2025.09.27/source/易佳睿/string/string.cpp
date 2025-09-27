#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

string s;
int a[405],N;
int b[405];
int c[405];
int ans;

deque<int> p[3];

int check(int top){
	int i=1;
	while(i<top){
		if(b[i]==b[i+1]) return i;
		i++;
	}
	return i;
}



int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	N=s.size();
	for(int i=1;i<=N;i++) a[i]=b[i]=s[i-1]-'0';
	int lst=0;
	for(int i=1;i<=N;i++){
		int maxn=0,maxp=0;
		for(int j=i;j>1;j--) swap(b[j],b[j-1]);
		for(int j=1;j<N;j++){
			if(check(N)>maxn) maxn=check(N),maxp=j;
			else if(check(N)==maxn&&abs(j-i)<abs(maxp-i)) maxp=j;
			swap(b[j],b[j+1]);
		}
		if(check(N)>maxn||(check(N)==maxn&&abs(N-i)<abs(maxp-i))) maxn=check(N),maxp=N;
		for(int j=N;j>maxp;j--) swap(b[j],b[j-1]);
	}
	if(check(N)!=N){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=N;i++) c[i]=a[i];
	for(int i=1;i<=N;i++){
		int pos=i;
		while(c[pos]!=b[i]) pos++;
		for(int j=pos;j>i;j--){
			swap(c[j],c[j-1]);
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
