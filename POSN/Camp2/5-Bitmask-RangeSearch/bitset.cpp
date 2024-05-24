#include <iostream>
#include <bitset>

using namespace std;

int main() {
	bitset<5> myset1;
	bitset<8> myset2(6);
	bitset<10> myset3(string("1111100000"));

	cout << "myset1: " << myset1 << endl;
	cout << "myset2: " << myset2 << endl;
	cout << "myset3: " << myset3 << endl;

	myset1.set(3);
	cout << "\nmyset1 set bit 3: " << myset1 << endl;

	// reset all bits
	myset2.reset();
	cout << "reset myset2 all: " << myset2 << endl;

	myset3.reset(7);
	cout << "reset myset3 bit 7: " << myset3 << endl << endl;


	if (myset3.test(1)) {
        cout << myset3 << " Bit " << 1 << " is Set (is 1)" << endl;
	}
    else {
        cout << myset3 << " Bit " << 1 << " is Not Set (is 0)" << endl;
	}

	if (myset3.test(9)) { 
        cout << myset3 << " Bit " << 9 << " is Set (is 1)" << endl << endl;
	}
    else {
        cout << myset3 << " Bit " << 9 << " is Not Set (is 0)" << endl << endl;
	}

    cout << myset3 << " has bit " << myset3.count() << " with 1 " << endl;
}