#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,L,R;
int a[N],book[N][2];
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> L >> R;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		cout << a[i] << " ";
	}
	for(int i=1;i<=R;i++){
		book[a[i]][0]++;
	}
	for(int i=L;i<=n;i++){
		book[a[i]][1]++;
//		cout << a[i] << " ";
	}
	int head=L-1,tail=R+1;
	while(head>0&&tail<=n){
		if(book[a[head]][0]==1&&book[a[tail]][1]==1&&a[head]!=a[tail]){
			cout << tail-head+1 << endl;
//			cout << a[head] << " " << a[tail] << endl;
//			cout << book[a[head]][1] << " " << book[a[tail]][0] << endl; 
			return 0;
		}
		if(book[a[head]][0]>1)head--;
		if(book[a[tail]][1]>1)tail++;
		if(book[a[head]][0]==1&&book[a[tail]][1]==1&&a[head]==a[tail])head--,tail++;
	}
	cout << -1;
    return 0;
}

