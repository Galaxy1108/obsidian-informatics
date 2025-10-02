#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b;
int c[1000005],bok[1000006];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,q,cnt=0;
	cin>>n>>m>>q;
	memset(bok,0,sizeof(bok));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=2;   
	}
	for(int i=1;i<=m;i++){
		cin>>c[i]>>b;
		a[c[i]]=b%2;
	}
	stable_sort(c+1,c+m+1);
	for(int i=2;i<=m;i++){
		if(a[c[i]]!=a[c[i-1]]){
			cnt++;
			bok[c[i]]=1;
		}          
	}
	while(q--){
		int op,pp;
		cin>>op>>pp;
		if(op==1){
			int rr=lower_bound(c+1,c+m+1,pp)-c;
			c[rr]=0x3f;
			if(rr==m){
				if(bok[pp]==1){
					cnt--;
				    bok[pp]=0;
				}
				cout<<cnt<<endl;
				continue;
			}
			if(rr==1){
				if(bok[c[2]]==1){
					cnt--;
					bok[c[2]]=0;
				}
				cout<<cnt<<endl;
				continue;
			}
			int r1=a[pp],r2=a[c[rr-1]],r3=a[c[rr+1]];
			if(r2==r3){
				if(bok[pp]==1&&bok[c[rr+1]]==1) cnt=cnt-2; 
				bok[c[rr+1]]=0;
				bok[pp]=0;
			}
			stable_sort(c+1,c+m+1);
			cout<<cnt<<endl;
		}
		if(op==2){
			long long x;
			cin>>x;
			x%=2;
			a[pp]=x;
			int rr=lower_bound(c+1,c+m+1,pp)-c;
			if(bok[c[rr]]==0&&a[pp]!=a[c[rr]]){
				cnt+=2;
				bok[c[rr]]=1;
				bok[pp]=1;
			}
			m=m+1;
			c[m]=pp;
			stable_sort(c+1,c+m+1);
			cout<<cnt<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	/*10 8 10 
	15 4 12 10 14 5 18 7 9 11 
	5 12 
	6 18 
	1 4 
	10 5 
	7 7 
	2 15 
	9 14 
	4 10 
	2 8 11 
	1 7 
	1 6 
	2 7 18 
	2 6 9 
	1 8 
	2 8 7 
	1 9
	1 4
	1 5*/
 } 
