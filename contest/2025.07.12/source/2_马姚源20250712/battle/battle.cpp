#include <bits/stdc++.h>
#define N 160005
using namespace std;
int n;
struct T{
	int d,id;	
}a[3][N];
bool cmp(T x,T y){
	return x.d>y.d;
}
int book[N];
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[0][i].d  >> a[1][i].d >> a[2][i].d;
		a[0][i].id=a[1][i].id=a[2][i].id=i;
	}
	sort(a[0]+1,a[0]+n+1,cmp);
	sort(a[1]+1,a[1]+n+1,cmp);
	sort(a[2]+1,a[2]+n+1,cmp);
	int cnt=0,x=1,y=1,z=1,o,p,q;
	int ans=0;
	while(x<=n&&y<=n&&z<=n){
		if(a[0][x].id!=a[1][y].id&&a[2][z].id!=a[1][y].id&&a[0][x].id!=a[2][z].id){
			ans+=a[0][x].d+a[1][y].d+a[2][z].d;
			break;
		}
		if(a[0][x].id==a[1][y].id){
			x++,y++;
		}
		if(a[0][x].id==a[2][z].id){
			x++,z++;
		} 
		if(a[2][z].id==a[1][y].id){
			z++,y++;
		}
//		cout << a[0][x].id << " " << a[1][y].id << " " << a[2][z].id << "\n";
//		cout << x << " " << y << " " << z << "\n";
//		cout << "\n";
	}
	if(ans!=0)cout << ans;
	else cout <<-1;
	return 0;
}

