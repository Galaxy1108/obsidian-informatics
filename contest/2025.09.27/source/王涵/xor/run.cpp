#include <cstdlib>

int main()
{
	while (true)
	{
		system("gen.exe");
		system("xor.exe");
		system("ans.exe");
		if (system("fc xor.out xor.ans"))
			break;
	}
}
