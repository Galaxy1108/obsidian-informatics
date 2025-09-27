#include <cstdlib>

int main()
{
	while (true)
	{
		system("gen.exe");
		system("truth.exe");
		system("ans.exe");
		if (system("fc truth.out truth.ans"))
			break;
	}
}
