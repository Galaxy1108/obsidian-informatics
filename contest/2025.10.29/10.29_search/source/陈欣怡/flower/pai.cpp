#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
int main()
{
	int i=0;
	while(true)
	{
		printf("%d\n",++i);
		system("data.exe");
		system("flower.exe");
		system("baoli.exe");
		if(system("fc flower.out flower.ans")) break;
	}
	
	return 0;
}
