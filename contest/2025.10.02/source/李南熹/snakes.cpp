#include<bits/stdc++.h>
using namespace std;
struct peo{
	int a,b;
}miku[3000005];
bool cmp(peo x,peo y){
	if(x.a==y.a) return x.b>y.b;
	return x.a>y.a;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	cin>>t;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>miku[i].a;
		miku[i].b=i;
	}	
	stable_sort(miku+1,miku+1+n,cmp);
	int k=n,q=miku[1].a,cnt=0;
	while(1){
		if(k==2){
			if(q>=miku[k].a) cnt++;
			break;
		}
		else if(q-miku[k].a<miku[2].a) break;
		q-=miku[k].a;
		k--;
		cnt++;
	}
	cout<<n-cnt<<endl;
	for(int z=2;z<=t;z++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int xx,yy;
			cin>>xx>>yy;
			miku[xx].a=yy;
		}
		stable_sort(miku+1,miku+1+n,cmp);
		k=n;
		q=miku[1].a;
		cnt=0;
	    while(1){
		    if(k==2){
			    if(q>=miku[k].a) cnt++;
			    break;
		    }
		    else if(q-miku[k].a<miku[2].a){
		    	if(miku[2].a-q+miku[k].a<miku[3].a) break;
			} 
		    q-=miku[k].a;
		    k--;
		    cnt++;
	    }
	    cout<<n-cnt<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
