#include <cstdlib>

int main()
{
	while (true)
	{
		system("gen.exe");
		system("labyrinth.exe");
		system("brute.exe");
		if (system("fc x.out x.ans"))
			break;
	}
}
