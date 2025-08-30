#include<bits/stdc++.h>
using namespace std;
int anscnt,now1[15],now2[15],n,lss=0;
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	cin>>n;
	cout<<"14400\n";
	for(int i = 1; i <= 5; i++) now1[i]=now2[i]=i;
	for(int i = 1; i <= 120; i++)
	{
		for(int j = 1; j <= 120; j++)
		{
			for(int k = 1; k <= 5; k++)
			{
				cout<<now1[k]*2-1<<" "<<now2[k]*2<<" ";
			}
			cout<<'\n';
			next_permutation(now2+1,now2+6);
		}
		next_permutation(now1+1,now1+6);
	}
 } 
