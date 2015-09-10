#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	const size_t d = 3;
	const array<size_t, d> p({ 30, 38, 46 });
	const array<char, d> c({ 'x', 'y', 'z' });
	vector<double> mn(d, numeric_limits<double>::max());
	vector<double> mx(d, numeric_limits<double>::lowest());
	for (string line; getline(cin, line);)
	{
		if (line[0] != 'A' && line[0] != 'H') continue;
		#pragma unroll
		for (size_t i = 0; i < d; ++i)
		{
			const double v = stod(line.substr(p[i], 8));
			mn[i] = min<double>(mn[i], v);
			mx[i] = max<double>(mx[i], v);
		}
	}
	#pragma unroll
	for (size_t i = 0; i < d; ++i)
	{
		cout << "center_" << c[i] << '=' << (mx[i] + mn[i]) * 0.5 << endl;
	}
	#pragma unroll
	for (size_t i = 0; i < d; ++i)
	{
		cout << "size_"   << c[i] << '=' << (mx[i] - mn[i]) + 10 << endl;
	}
}