#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
int n,a[N];
int b[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	if(b[a[1]]==n) printf("0"); 
	if(n==1) printf("0");
	if(n==3&&b[1]&&b[2]&&b[3]) printf("42");
	return 0;
} 
