#include<iostream>
#include<cmath>
using namespace std;
long long n,p,pre[50][50],f[20],ans=0;
int main(){
//	freopen("gonna.in","r",stdin);
//	freopen("gonna.out","w",stdout);
	cin >> n >> p;
	if(n>=50){
		cout << 0;
		return 0;
	}
	for(int i=0;i<=30;i++)pre[0][i]=pre[i][0]=1;
	for(int i=1;i<=30;i++){
		for(int j=1;j<=30;j++){
			pre[i][j]=pre[i-1][j]+pre[i][j-1];
		}
	}
	for(int i=1;i<=11;i++){
		f[i]=1;
		for(int j=1;j<=i;j++){
			f[i]*=pre[j][i-j];
		}
//		cout << f[i] << ' ';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sqrt(f[i]);j++){
			if(f[i]%j==0){
				
				ans+=j;
				ans+=f[i]/j;
				if(j==sqrt(f[i]))ans-=j;
//				cout << j <<' '<<f[i]/j<<' '<<ans << endl;
				ans%=p;
			}
		}
	}
	cout << ans;
	return 0;
}
