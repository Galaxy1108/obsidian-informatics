#include<bits/stdc++.h>
using namespace std;
int T;
int n,q,l,r;
int x[100010];
int eq;
bool ch2=1;
double xie1[55][55],xie2[55][55];
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=50){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++)xie1[i][j]=1.0*(x[j]-x[i])/(j-i),xie2[i][j]=1.0*(x[j]+1-x[i])/(j-i);
			}
		}
		eq=x[2]-x[1];
		ch2=1;
		for(int i=2;i<n;i++){
			if(eq!=x[i+1]-x[i]){
				ch2=0;break;
			}
		}
		cin>>q;
		for(int i=1;i<=q;i++){
			cin>>l>>r;
			if(ch2){
				cout<<eq<<" "<<x[l]<<" 1\n";continue;
			}
			bool pr=0;
			for(int c=1;c<=10&&!pr;c++)for(int a=0;a<=10&&!pr;a++)
				for(int b=0;b<=10;b++){
				bool ch=1;
				for(int j=l;j<=r;j++){
					if(x[j]!=(a*(j-l)+b)/c){
						ch=0;break;
					}
				}
				if(ch){
					cout<<a<<" "<<b<<" "<<c<<"\n";
					pr=1;
					break;
				}
			}
//			for(int c=1;c<=r-l+1;c++){
//				double ma=-1,mi=1e18;
//				for(int j=l+1;j<=r;j++){
//					ma=max(ma,xie1[l][j]);
//					mi=min(mi,xie2[l][j]);
//				}
//				cout<<ma<<" "<<mi<<"\n";
//			}
		}
	}
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
