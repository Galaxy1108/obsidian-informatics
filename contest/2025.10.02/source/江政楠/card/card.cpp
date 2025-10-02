#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[1000005];
int pos[1000005];
int flag[1000005];
int v1[10005],v2[10005];
void swap_(int p,int b){
	int temp=a[p],pos1=pos[b];
	a[pos[b]]=a[p];
	a[p]=b;
	pos[b]=p;
	pos[temp]=pos1;
}
void cout_(){
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<flag[i]<<" ";
	cout<<endl;
}
int cow(){
	memset(v1,0,sizeof(v1));
	memset(v2,0,sizeof(v2));
	int cnt1=0,cnt2=0;
	for(int j=1;j<=n;j++){
		if(a[j]%2==1&&!flag[j]) v1[++cnt1]=a[j];
		else if(a[j]%2==0&&!flag[j]) v1[++cnt2]=a[j];
	}
	int start=a[1]%2,ans=0;
	for(int j=2;j<=n;j++){
		if(a[j]%2!=start){
			if(flag[j]){
				ans++;
				continue;
			}
			if(a[j]%2==1){
				if(cnt1){
					int x=v1[cnt1];
					cnt1--;
					swap_(x,a[j]);
				}
				else{
					start=1;
					ans++;
				} 
			}
			else{
				if(cnt2){
					int x=v2[cnt2];
					cnt2--;
					swap_(x,a[j]);
				}
				else{
					start=0;
					ans++;
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int p,b;
		cin>>p>>b;
		flag[p]=1;
		swap_(p,b);
	}
	//cout_();
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int x;
			cin>>x;
			flag[x]=0;
			//cout_();
			cout<<cow()<<"\n";
		}
		else{
			int x,y;
			cin>>x>>y;
			flag[x]=1;
			swap_(x,y);
			//cout_();
			cout<<cow()<<"\n";
		}
	}
	return 0;
}
