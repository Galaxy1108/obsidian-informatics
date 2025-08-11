#include <bits/stdc++.h>
using namespace std;
int main()
{
	int p1,p2,p3;
	cin >> p1 >> p2>> p3;
	string n;
	cin >> n;
	for (int i =0;i < n.length();i++)
	{
		if (n[i]=='-')
		{
			if (n[i-1] >= 'a' and n[i-1] <= 'z' and n[i+1] >= 'a' and n[i+1] <= 'z' and n[i+1]>n[i-1])
			{
				if (p3 == 1)
				{
					if (p1==1)
					{
						for (char m = n[i-1]+1;m < n[i+1];m++)
						{
							for (int j = 1;j <= p2;j++)
							{
							cout << char(m);
							}
						}
						
					} 
					else if (p1==2)
					{
						for (char m = n[i-1]-31;m < n[i+1]-32;m++)
						{
							for (int j = 1;j <= p2;j++)
							{
								cout << char(m);
							}
						}	
					}
					else if (p1==3)
					{
						for (char m = n[i-1]+1;m < n[i+1];m++)
						{
							for (int j = 1;j <= p2;j++)
							{
								cout << '*';
							}
						}
					}
				}
				else
				{
					if (p1==1)
					{
						for (char m = n[i+1]-1;m > n[i-1];m-=1)
						{
							for (int j = 1;j <= p2;j++)
							{
							cout << char(m);
							}
						}
						
					} 
					else if (p1==2)
					{
						for (char m = n[i+1]-33;m > n[i-1]-32;m-=1)
						{
							for (int j = 1;j <= p2;j++)
							{
								cout << char(m);
							}
						}	
					}
					else if (p1==3)
					{
						for (char m = n[i-1]+1;m < n[i+1];m++)
						{
							for (int j = 1;j <= p2;j++)
							{
								cout << '*';
							}
						}
					}
				}
			}
			else if (n[i-1] >= '0' and n[i-1] <= '9' and n[i+1] >= '0' and n[i+1] <= '9' and n[i+1]>n[i-1])
			{
				if (p3 == 1)
				{
					if (p1!=3)
					{
						for (char m = n[i-1]+1;m < n[i+1];m++)
						{
							for (int j = 1;j <= p2;j++)
							{
							cout << char(m);
							}
						}
						
					} 
					else
					{
						for (char m = n[i-1]+1;m < n[i+1];m++)
						{
							for (int j = 1;j <= p2;j++)
							{
								cout << '*';
							}
						}
					}
				}
				else
				{
					if (p1!=3)
					{
						for (char m = n[i+1]-1;m > n[i-1];m-=1)
						{
							for (int j = 1;j <= p2;j++)
							{
							cout << char(m);
							}
						}
						
					} 
					else
					{
						for (char m = n[i-1]+1;m < n[i+1];m++)
						{
							for (int j = 1;j <= p2;j++)
							{
								cout << '*';
							}
						}
					}
				}
				 
			}
			else
			{
				cout << n[i];
			}
		 } 
		 else
		 {
		 	cout << n[i];
		 }
	}
	return 0;
}
