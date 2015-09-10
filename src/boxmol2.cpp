#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	// Locate the @<TRIPOS>MOLECULE record to parse the number of atoms.
	string line;
	while (getline(cin, line) && line != "@<TRIPOS>MOLECULE");
	getline(cin, line);
	getline(cin, line);
	const size_t num_atoms = stoul(line.substr(0, 5));

	// Locate the @<TRIPOS>ATOM record and parse the atoms.
	while (getline(cin, line) && line != "@<TRIPOS>ATOM");
	double x0 =  9999, y0 =  9999, z0 =  9999;
	double x1 = -9999, y1 = -9999, z1 = -9999;
	for (size_t i = 0; i < num_atoms && getline(cin, line); ++i)
	{
		const bool standard = 'A' <= line[47] && line[47] <= 'Z';
		const double x = stod(standard ? line.substr(16, 10) : line.substr(16, 14));
		const double y = stod(standard ? line.substr(26, 10) : line.substr(30, 14));
		const double z = stod(standard ? line.substr(36, 10) : line.substr(44, 14));
		if (x < x0) x0 = x;
		if (x > x1) x1 = x;
		if (y < y0) y0 = y;
		if (y > y1) y1 = y;
		if (z < z0) z0 = z;
		if (z > z1) z1 = z;
	}

	// Output the box.
	cout
		<< "center_x=" << (x0 + x1) * 0.5 << endl
		<< "center_y=" << (y0 + y1) * 0.5 << endl
		<< "center_z=" << (z0 + z1) * 0.5 << endl
		<< "size_x=" << x1 - x0 + 10 << endl
		<< "size_y=" << y1 - y0 + 10 << endl
		<< "size_z=" << z1 - z0 + 10 << endl
	;
}
