#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	float g;
	for (string line; getline(cin, line);)
	{
		g = stod(line);
		cout.write(reinterpret_cast<char*>(&g), sizeof(g));
	}
}
