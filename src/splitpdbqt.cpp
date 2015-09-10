#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	vector<string> lines;
	bool content = false;
	size_t id = 0;
	for (string line; getline(cin, line);)
	{
		if (line[0] == 'R')
		{
			content = true;
		}
		if (content)
		{
			lines.push_back(line);
		}
		if (line[0] == 'T')
		{
			content = false;
			ofstream ofs(to_string(++id) + ".pdbqt");
			for (const auto& line : lines)
			{
				ofs << line << endl;
			}
			lines.clear();
		}
	}
}
