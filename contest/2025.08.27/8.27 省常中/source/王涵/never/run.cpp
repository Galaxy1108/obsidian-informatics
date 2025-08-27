#include <cstdlib>

int main()
{
	while (true)
	{
		system("gen.exe");
		system("never.exe");
		system("brute.exe");
		if (system("fc never.out never.ans"))
			break;
	}
}
