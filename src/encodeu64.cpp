#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	uint64_t g;
	for (string line; getline(cin, line);)
	{
		g = stoul(line);
		cout.write(reinterpret_cast<char*>(&g), sizeof(g));
	}
}
