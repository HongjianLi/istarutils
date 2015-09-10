#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void write(const vector<string>& lines, const string& filename)
{
	ofstream ofs(filename);
	for (const auto& line : lines)
	{
		ofs << line << endl;
	}
}

int main(int argc, char* argv[])
{
	const string delimiter = "@<TRIPOS>MOLECULE";
	vector<string> lines;
	string line, name;
	while (getline(cin, line))
	{
		if (line == delimiter)
		{
			if (!lines.empty())
			{
				write(lines, name + ".mol2");
				lines.clear();
			}
			lines.push_back(delimiter);
			getline(cin, name);
			lines.push_back(name);
		}
		else
		{
			lines.push_back(line);
		}
	}
	write(lines, name + ".mol2");
}
