/*
sto XaoWa118 orz
sto HasNoName orz
sto one_of_the_person orz
sto HeYuChenC orz
sto Vct14 orz
sto PokerKing orz
sto weistars orz
sto keshuhan orz
sto tham orz
sto Xun_Xiaoyao orz
sto int256_t orz
sto zjj2024 orz
sto kkksc03 orz
sto chen_zhe orz
sto xht orz
sto dottle orz
sto PinkieRabbit orz

C++14 O2 2.3s
*/
#include <iostream>
using namespace std;
#define ull unsigned long long
int n;
ull s1,s2,s3,s4,s5;
ull my_rand()
{
    s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query(int &op,ull &num1,ull &num2)
{
    op=(my_rand()&1)+1;
    num1=my_rand()%n+1;
    num2=my_rand()%n+1;
    if(op==2)
    {
        if(num1>num2)
        {
        	s5=num1;
        	num1=num2;
        	num2=s5;
    	}
    }
    return;
}
int Q;
int opp;
ull op1,op2,f[10000005],f2[10000005];
ull query2(ull x)
{
	ull ans=0;
	for(int i = x; i; i-=(i&(-i)))
	{
		ans+=f2[i];
	}
	return ans;
}
/*void insert2(ull x,ull k)
{
	for(int i = x; i <= n; i+=(i&(-i)))
	{
		f2[i]+=k;
	}
	return;
}*/
ull cnt=0;
void insert(ull x,ull k)
{
	cnt=0;
	for(int i = x; i <= n; i+=(i&(-i)))
	{
		cnt++;
		//insert2(i,k);
		f2[i]+=k*cnt;
	}
	return;
}
ull finans=0;
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    cin>>n>>Q>>s1>>s2;
    for(int qr = 1; qr <= Q; qr++)
    {
    	//cout<<qr<<endl;
    	get_query(opp,op1,op2); 
    	//cout<<opp<<" "<<op3<<" "<<op4<<endl;
    	if(opp==1)
    	{
    		insert(op1,op2);
		}
		else
		{
			finans^=qr*(query2(op2)-query2(op1-1));
		}
	}
	cout<<finans<<endl;
    return 0;
}
