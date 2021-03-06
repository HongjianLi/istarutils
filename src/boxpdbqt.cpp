#include <iostream>
#include <iomanip>
#include <array>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	const double bszr = argc < 2 ? 1.4 : stod(argv[1]);
	const double bsza = argc < 3 ? 6 : stod(argv[2]);
	const size_t d = 3;
	const array<char, d> c({ 'x', 'y', 'z' });
	const array<size_t, d> p({ 30, 38, 46 });
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
		cout << "size_"   << c[i] << '=' << (mx[i] - mn[i]) * bszr + bsza << endl;
	}
}