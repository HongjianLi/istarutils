#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
//	const double ln10 = log(10);
//	const double RT = 0.592089377;
	cout.setf(ios::fixed, ios::floatfield);
	cout << setprecision(2);
	for (string line; getline(cin, line);)
	{
		double s = 0;
		switch (line.back())
		{
			case 'm': s =  3; break;
			case 'u': s =  6; break;
			case 'n': s =  9; break;
			case 'p': s = 12; break;
			case 'f': s = 15; break;
		}
		const double v = stod(s == 0 ? line : line.substr(0, line.size() - 1));
		const double pkd = s - log10(v);
//		const double fe = RT * (log(v) - s * ln10);
		cout
			<< pkd
//			<< '\t'
//			<< fe
			<< endl;
	}
}

