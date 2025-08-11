#include <cstdlib>
#include <cstdio>

int main()
{
	int cnt = 0;
	while (true)
	{
		system("Î´ÃüÃû4.exe");
		system("Î´ÃüÃû3.exe");
		system("bus.exe");
		printf("%d\n", ++cnt);
		if (system("fc bus.out bus.ans"))
		{
			break;
		}
	}
}
