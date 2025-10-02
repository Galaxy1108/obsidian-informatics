#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000005],nx,x,y;
struct shu{
	int num2,sum;
}b[100005];
bool cmp(shu a,shu b){
	return a.sum<b.sum;
}
void ck(){
	int num=1,z=0;
	shu num2[10005]={};
	for(bool i1=(b[n].sum-b[num].sum>=b[n-1].sum)||(n-num==1);n-num>=1&&i1;){
		b[n].sum-=b[num].sum;
		for(int i=1;i<=z;i++){
			if(b[num].num2==num2[i].num2){
				cout<<num2[i].sum<<endl;
				return ;
			}
		}
		if(!(i1)){
			z++;
			num2[z].sum=n-num+1;
			num2[z].num2=b[n].num2;
			sort(b+num+2,b+n+1,cmp);
		}
		num++;
	}
	cout<<n-num+1<<endl;
	return ;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	T--;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		b[i].sum=a[i];
		b[i].num2=i;
	}
	ck();
	while(T--){
		cin>>nx;
		for(int i=1;i<=nx;i++){
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		for(int i=1;i<=n;i++){
			b[i].sum=a[i];
			b[i].num2=i;
		}
		ck();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
