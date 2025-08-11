#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[1000005],b[1000005],c[1000005];
signed main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]=a[i]*2;
	} 
	for(int i=1;i<n;i++){
		if(a[i]/2>a[i+1]){
			b[i]=1;
			c[i]++;
		}
		else if(a[i]<a[i+1]/2){
			b[i]=2;
			c[i+1]++;
		}
	}
	if(a[n]/2>=a[1]){
		b[n]=1;
		c[n]++;
	}
	else if(a[n]<=a[1]/2){
		b[n]=2;
		c[1]++;
	}
	int cnt1=1e9,cnt2=1e9,tot1=1e9,tot2=1e9;
	b[0]=1;
	for(int i=1;i<n;i++){
		if(b[i]==0){
			cnt1=min(cnt1,i);
			cnt2=i;
		}
		else if(b[i]!=0&&cnt1!=1e9){
			if(b[cnt1-1]==1&&b[i]==1||b[cnt1-1]==1&&b[i]==2){
				for(int j=cnt1;j<=i-1;j++){
					c[j]++;
					b[j]=1;
				}
			}
			else if(b[cnt1-1]==2&&b[i]==2){
				for(int j=cnt1;j<=i-1;j++){
					c[j+1]++;
					b[j]=2;
				}
			}
			else if(b[cnt1-1]==2&&b[i]==1){
				for(int j=cnt1;j<i-1;j++){
					c[j+1]++;
					b[j]=2;
				}
				if(a[i-1]>=a[i]){
					c[i-1]++;
					b[i-1]=1;
				} 
				else{
					c[i]++;
					b[i-1]=2;
				}
			}
			cnt1=1e9,cnt2=1e9;
		}
	}
	int i=n;
	b[i]=1;
	if(cnt1!=1e9){
		if(b[cnt1-1]==1&&b[i]==1||b[cnt1-1]==1&&b[i]==2){
			for(int j=cnt1;j<=i-1;j++){
				c[j]++;
				b[j]=1;
			}
		}
		else if(b[cnt1-1]==2&&b[i]==2){
			for(int j=cnt1;j<=i-1;j++){
				c[j+1]++;
				b[j]=2;
			}
		}
		else if(b[cnt1-1]==2&&b[i]==1){
			for(int j=cnt1;j<i-1;j++){
				c[j+1]++;
				b[j]=2;
			}
			if(a[i-1]>=a[i]){
				c[i-1]++;
				b[i-1]=1;
			} 
			else{
				c[i]++;
				b[i-1]=2;
			}
		}
	}
	int x,y;
	if(b[n]==0){
		x=a[n],y=a[1];
		if(c[n]>=1) x/=2;
		if(c[1]>=1) y/=2;
		if(x>y) b[n]=1;
		else b[n]=2;
	}
	for(int i=1;i<n;i++){
		if(b[i]==1) cout<<i<<" ";
		else if(b[i]==2) cout<<i+1<<" ";
	}
	if(b[n]==1) cout<<n<<" ";
	else cout<<1<<" ";
	return 0;
} 
/*
5 
5 3 7 2 9
*/
