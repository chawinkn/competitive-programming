#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int b = atoi(argv[1]);
	int t = atoi(argv[2]);
	int mxn = atoi(argv[3]); // 1e3
	int mxc = atoi(argv[4]); // 1e5
	cout << b << " " << t << "\n";
	for (int i = 1; i <= t; i++) {
		int n = rnd.next(1, mxn);
		cout << n << " ";
		for (int j = 1; j <= n; j++) {
			int c = rnd.next(1, mxc);
			cout << c << " ";
		}
		cout << "\n";
	}
	return 0;
}