#include "Vec3.h"
#include <iostream>

using namespace std;


int main()
{
	Vec3<int> v1, v2(20, 20, 25), v3(10, 10, 10);
	Vec3<int> *v4 = new Vec3<int>(4, 3, 2);
	int scalar = 5;
	bool ret = false;
	long long1;
	double double1;

	v1.display();

	v1 = v2;
	v1.display();
	v1 = (v2 + v3);
	v1.display();
	v1 = (v2 - v3);
	v1 = -v2;
	v1 = +v2;
	v1 = (v2 * v3);
	v1 = (v2 * scalar);
	v1 = (v2 / v3);
	v1 = (v2 / scalar);
	v1 = (v2 % v3);


	v1 += v2;
	v1 -= v2;
	v1 *= v2;
	v1 %= v2;
	v1 /= v2;
	v1 *= scalar;
	v1 /= scalar;


	v1++;
	++v1;
	v1--;
	--v1;

	ret = v2 > v3;
	ret = v2 < v3;
	ret = v2 == v3;
	ret = v2 != v3;
	ret = v2 >= v3; ret = v3 >= v3;
	ret = v2 <= v3; ret = v3 <= v3;

	double1 = v2;
	long1 = v1;

	v1 = ~v2;
	v1 = (v2 & v3);
	v1 = (v2 | v3);
	v1 = (v2 ^ v3);

	v1 ^= v2;
	v1 &= v2;
	v1 |= v2;
	
	ret = !v1;
	ret = v1;
	v2 >>= *v4;
	v2 <<= *v4;

	long1 = v2[2];
	long1 = (*v4)[0];
	v1(*v4);
	v1 = Vec3<int>::Zero;
	*v4 = Vec3<int>::Zero;
	delete (v4);
	return 0;
}

