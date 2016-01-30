#include <iostream>
#include <iomanip>
#include <array>
#include <limits>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	const size_t d = 3;
	const array<char, d> c({ 'x', 'y', 'z' });
	const array<size_t, d> p0({ 16, 26, 36 });
	const array<size_t, d> p1({ 16, 30, 44 });
	vector<double> mn(d, numeric_limits<double>::max());
	vector<double> mx(d, numeric_limits<double>::lowest());

	// Locate the @<TRIPOS>MOLECULE record to parse the number of atoms.
	string line;
	while (getline(cin, line) && line != "@<TRIPOS>MOLECULE");
	getline(cin, line);
	getline(cin, line);
	const size_t num_atoms = stoul(line.substr(0, 5));

	// Locate the @<TRIPOS>ATOM record and parse the atoms.
	while (getline(cin, line) && line != "@<TRIPOS>ATOM");
	for (size_t i = 0; i < num_atoms && getline(cin, line); ++i)
	{
		const bool standard = 'A' <= line[47] && line[47] <= 'Z';
		#pragma unroll
		for (size_t i = 0; i < d; ++i)
		{
			const double v = stod(standard ? line.substr(p0[i], 10) : line.substr(p1[i], 14));
			mn[i] = min<double>(mn[i], v);
			mx[i] = max<double>(mx[i], v);
		}
	}

	// Output the box.
	cout.setf(ios::fixed, ios::floatfield);
	cout << setprecision(3);
	#pragma unroll
	for (size_t i = 0; i < d; ++i)
	{
		cout << "center_" << c[i] << '=' << (mx[i] + mn[i]) * 0.5 << endl;
	}
	#pragma unroll
	for (size_t i = 0; i < d; ++i)
	{
		cout << "size_"   << c[i] << '=' << (mx[i] - mn[i]) * 1.3 + 4 << endl;
	}
}
