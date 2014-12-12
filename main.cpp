#include <iostream>
#include "Test.h"
using namespace std;
using namespace program;

int main()
{
	/* Some Tests */
	int k = 2;
	cord a[2];
	a[0].x = 1;
	a[0].y = 2;
	a[1].x = 3;
	a[1].y = 6;
	Figure p(2,a);
	cout << p;
	
	Square s1;
	cin >> s1;
	cout << s1.area() << endl;
	cout << s1.ankyunagic() << endl;

	Circle c1;
	cin >> c1;
	cout << c1.area() << endl;
	cout << c1.lenght() << endl;
	c1.printhavasarum();
	return 0;
}