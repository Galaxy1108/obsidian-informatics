#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,q,a[10086],l,r;
bool check(int aa,int b,int c,int l,int r){
	for(int i=l;i<=r;i++){
//		cout << i << endl;
		if(a[i]!=((i-l)*aa+b)/c){
//			cout << i<<' ' <<a[i] << endl;
			return 0;
		}
	}
	return 1;
} 
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout); 
	cin >> t;
	while(t--){
		n=q=l=r=0;
		memset(a,0,sizeof a);
	 	cin >> n; 
		for(int i=1;i<=n;i++)cin >> a[i];
		cin >> q;
		for(int i=1;i<=q;i++){
			cin >> l >> r;
			for(int c=1;;c++){
				int lb=a[l]*c,rb=a[l]*c+c,la=0,ra=a[l+1]*(c+1);
//				cout << lb << ' ' << rb << ' ' << la << ' ' << ra << endl;
				for(int b=lb;b<=rb;b++){
					for(int a=la;a<=ra;a++){
						if(check(a,b,c,l,r)){
							cout << a << ' ' << b <<' '<< c << endl;
							goto mn;
						}
					}
				}
			}
			mn:;
		}
		
	} 
//	cout << endl<<check(1,4,3,1,5);
	return 0;
} 
/*
3
5 
1 1 2 2 2 
4 
1 5 
1 1 
3 5 
2 3 
5 
1 2 3 4 6 
3 
1 5 
2 4 
3 5 
3 
0 3 5 
1 
1 3 

*/
