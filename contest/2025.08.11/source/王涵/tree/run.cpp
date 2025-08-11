#include <cstdio>
#include <cstdlib>

int main()
{
	int cnt = 0;
	while (true)
	{
		system("gen.exe");
		system("tree.exe");
		system("brute.exe");
		printf("%d\n", ++cnt);
		if (system("checker.exe"))
			break;
	}
}
