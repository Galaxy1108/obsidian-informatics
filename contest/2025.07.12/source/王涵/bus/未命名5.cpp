#include <cstdlib>
#include <cstdio>

int main()
{
	int cnt = 0;
	while (true)
	{
		system("δ����4.exe");
		system("δ����3.exe");
		system("bus.exe");
		printf("%d\n", ++cnt);
		if (system("fc bus.out bus.ans"))
		{
			break;
		}
	}
}
