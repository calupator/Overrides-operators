
#pragma once
#include <iostream>
#include <math.h>

using namespace std;

template <class T> class Vec3
{
private:
	T x, y, z;

public:
	static const Vec3<T> Zero;

	// ------------ ����������� ------------

	// ����������� �����������
	Vec3(void)
		: x(0), y(0), z(0)
	{			
	}
 
    // ����������� � ����� �����������
    Vec3(T x, T y, T z)
		: x(x), y(y), z(z)
    {
    }

    // ------------ Helper methods ------------

    // Method to reset a vector to zero
    void zero()
    {
        x = y = z = 0;
    }

    // Method to normalise a vector
    void normalise()
    {
        // Calculate the magnitude of our vector
        T magnitude = sqrt((x * x) + (y * y) + (z * z));

        // As long as the magnitude isn't zero, divide each element by the magnitude
        // to get the normalised value between -1 and +1
        if (magnitude != 0)
        {
            x /= magnitude;
            y /= magnitude;
            z /= magnitude;
        }
    }

    // Static method to calculate and return the scalar dot product of two vectors
    //
    // Note: The dot product of two vectors tell us things about the angle between
    // the vectors. That is, it tells us if they are pointing in the same direction
    // (i.e. are they parallel? If so, the dot product will be 1), or if they're
    // perpendicular (i.e. at 90 degrees to each other) the dot product will be 0,
    // or if they're pointing in opposite directions then the dot product will be -1.
    //
    // Usage example: double foo = Vec3<double>::dotProduct(vectorA, vectorB);
    static T dotProduct(const Vec3 &vec1, const Vec3 &vec2)
    {
        return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
    }

    // Non-static method to calculate and return the scalar dot product of this vector and another vector
    //
    // Usage example: double foo = vectorA.dotProduct(vectorB);
    T dotProduct(const Vec3 &vec) const
    {
        return x * vec.x + y * vec.y + z * vec.z;
    }

    // Static method to calculate and return a vector which is the cross product of two vectors
    //
    // Note: The cross product is simply a vector which is perpendicular to the plane formed by
    // the first two vectors. Think of a desk like the one your laptop or keyboard is sitting on.
    // If you put one pencil pointing directly away from you, and then another pencil pointing to the
    // right so they form a "L" shape, the vector perpendicular to the plane made by these two pencils
    // points directly upwards.
    //
    // Whether the vector is perpendicularly pointing "up" or "down" depends on the "handedness" of the
    // coordinate system that you're using.
    //
    // Further reading: http://en.wikipedia.org/wiki/Cross_product
    //
    // Usage example: Vec3<double> crossVect = Vec3<double>::crossProduct(vectorA, vectorB);
    static Vec3 crossProduct(const Vec3 &vec1, const Vec3 &vec2)
    {
        return Vec3(vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x);
    }

    static T getDistance(const Vec3 &v1, const Vec3 &v2)
    {
        T dx = v2.x - v1.x;
        T dy = v2.y - v1.y;
        T dz = v2.z - v1.z;

        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Method to display the vector so you can easily check the values
    void display()
    {
        std::cout << '(' << this->x << ", " << this->y << ", " << this->z << ')' << std::endl;
    }
 
	 // ------------ ������������ ��������� ------------
 
    // ********** �������������� ��������� **********
	Vec3 operator +(const Vec3 &vector) const
    {
        return Vec3<T>(this->x + vector.x, this->y + vector.y, this->z + vector.z);
    }

    Vec3 operator -(const Vec3 &vector) const
    {
        return Vec3<T>(this->x - vector.x, this->y - vector.y, this->z - vector.z);
    }

    // ���������� �������� '+', ������ ���������� ������
	Vec3 operator +(void) const
	{
		return *this;
	}

	// ���������� �������� '-', ��������� ������� �� -1
	Vec3 operator -(void) const
	{
		return Vec3<T>(this->x * -1, this->y * -1, this->z * -1);
	}

	// ���������� ��������� '*'
    Vec3 operator *(const Vec3 &vector) const
    {
        return Vec3<T>(this->x * vector.x, this->y * vector.y, this->z * vector.z);
    }

    // ���������� ��������� '*', ���������� ������ �� ������
    Vec3 operator *(const T &value) const
    {
        return Vec3<T>(this->x * value, this->y * value, this->z * value);
    }

    // ���������� ��������� '/'
    Vec3 operator /(const Vec3 &vector) const
    {
        return Vec3<T>(this->x / vector.x, this->y / vector.y, this->z / vector.z);
    }

    // ���������� ��������� '/', ������� ������� �� ������
    Vec3 operator/(const T &value) const
    {
        return Vec3<T>(this->x / value, this->y / value, this->z / value);
    }

    // ���������� ��������� '%' (������� �� ������� ����� �����)
    Vec3 operator %(const Vec3 &vector) const
    {
        return Vec3<T>(this->x % vector.x, this->y % vector.y, this->z % vector.z);
    }

	// ���������� ����������� ���������� '++var'
	Vec3 operator ++()
	{
		return Vec3<T>(++this->x, ++this->y, ++this->z);
	}

	// ���������� ������������ ���������� 'var++'
	Vec3 operator ++(int)
	{
		return Vec3<T>(this->x++, this->y++, this->z++);
	}

	// ���������� ����������� ���������� '--var'
	Vec3 operator --()
	{
		return Vec3<T>(--this->x, --this->y, --this->z);
	}

	// ���������� ������������ ���������� 'var--'
	Vec3 operator --(int)
	{
		return Vec3<T>(this->x--, this->y--, this->z--);
	}

    // ********** ��������� ��������� **********
	// �������� ���������
	const bool operator ==(const Vec3 &vector)
	{
		if ((this->x == vector.x) && (this->y == vector.y) && (this->z == vector.z))
			return true;
		return false;
	}

	// �������� �����������
	const bool operator !=(const Vec3 &vector)
	{
		return !(*this == vector);
	}

	// �������� ������ '>'
	const bool operator >(const Vec3 &vector)
	{
		double vTemp1(sqrt(pow((double)this->x, 2) + pow((double)this->y, 2) + pow((double)this->z, 2)));
		double vTemp2(sqrt(pow((double)vector.x, 2) + pow((double)vector.y, 2) + pow((double)vector.z, 2)));

		return vTemp1 > vTemp2;
	}

	// �������� ������ '<'
	const bool operator <(const Vec3 &vector)
	{
		double vTemp1(sqrt(pow((double)this->x, 2) + pow((double)this->y, 2) + pow((double)this->z, 2)));
		double vTemp2(sqrt(pow((double)vector.x, 2) + pow((double)vector.y, 2) + pow((double)vector.z, 2)));

		return vTemp1 < vTemp2;
	}

	// �������� ������ ��� ����� '>='
	const bool operator >=(const Vec3 &vector)
	{
		if ((*this > vector) || (*this == vector))
			return true;
		return false;
	}

	// �������� ������ ��� ����� '<='
	const bool operator <=(const Vec3 &vector)
	{
		if ((*this < vector) || (*this == vector))
			return true;
		return false;
	}

    // ********** ���������� ��������� **********
	// ���������� ��������� '��'
	const bool operator !()
	{
		return !(bool)*this;
	}

	// ���������� ��������� '�'
	const bool operator &&(Vec3 &vector)
	{
		return (bool)*this && (bool)vector;
	}

	// ���������� �������� '���'
	const bool operator ||(Vec3 &vector)
	{
		return (bool)*this || (bool)vector;
	}

    // ********** ��������� ��������� **********
	// ��������� ��������
	const Vec3 operator ~()
	{
		return Vec3<T>(~(this->x), ~(this->y), ~(this->z));
	}

	// ��������� �
	const Vec3 operator &(const Vec3 &vector)
	{
		return Vec3<T>(this->x & vector.x, this->y & vector.y, this->z & vector.z);
	}

	// ��������� ��� (or)
	const Vec3 operator |(const Vec3 &vector)
	{
		return Vec3<T>(this->x | vector.x, this->y | vector.y, this->z | vector.z);
	}

	// ��������� ����������� ��� (xor)
	const Vec3 operator ^(const Vec3 &vector)
	{
		return Vec3<T>(this->x ^ vector.x, this->y ^ vector.y, this->z ^ vector.z);
	}

    // ********** ��������� ���������� ������������ **********
	// ������� ����������� � �������������
	Vec3 operator +=(const Vec3 &vector)
	{
		return Vec3<T>(this->x += vector.x, this->y += vector.y, this->z += vector.z);
	}

	// ��������� ����������� � �������������
	Vec3 operator -=(const Vec3 &vector)
	{
		return Vec3<T>(this->x -= vector.x, this->y -= vector.y, this->z -= vector.z);
	}

	// ��������� ����������� � �������������
   Vec3 operator *=(const Vec3 &vector)
    {
		return Vec3<T>(this->x *= vector.x, this->y *= vector.y, this->z *= vector.z);
    }

	// ������� ����������� � �������������
    Vec3 operator /=(const Vec3 &vector)
    {
		return Vec3<T>(this->x /= vector.x, this->y /= vector.y, this->z /= vector.z);
    }

	// ��������� �� ������, ����������� � �������������
    Vec3 operator *=(const T &value)
    {
		return Vec3<T>(this->x *= value, this->y *= value, this->z *= value);
    }

	// ������� �� ������, ����������� � �������������
    Vec3 operator /=(const T &value)
    {
		return Vec3<T>(this->x /= value, this->y /= value, this->z /= value);
    }

	// ���������� �������, ����������� � �������������
	Vec3 operator %=(const Vec3 &vector)
	{
		return Vec3<T>(this->x %= vector.x, this->y %= vector.y, this->z %= vector.z);
	}

	// ��������� '�', ����������� � �������������
	Vec3 operator &=(const Vec3 &vector)
	{
		this->x = this->x & vector.x, this->y = this->y & vector.y, this->z = this->z & vector.z;
		return *this;
	}

	// ��������� '���', ����������� � �������������
	Vec3 operator |=(const Vec3 &vector)
	{
		this->x = this->x | vector.x, this->y = this->y | vector.y, this->z = this->z | vector.z;
		return *this;
	}

	// ��������� '����������� ���', ����������� � �������������
	Vec3 operator ^=(const Vec3 &vector)
	{
		this->x = this->x ^ vector.x, this->y = this->y ^ vector.y, this->z = this->z ^ vector.z;
		return *this;
	}

	// ��������� ����� �����, ����������� � �������������
	Vec3 operator <<=(const Vec3 &vector)
	{
		this->x <<= vector.x, this->y <<= vector.y, this->z <<= vector.z;
		return *this;
	}

	// ��������� ����� ������, ����������� � �������������
	Vec3 operator >>=(const Vec3 &vector)
	{
		this->x >>= vector.x, this->y >>= vector.y, this->z >>= vector.z;
		return *this;
	}

	//���� ������ �� ������� - ������� true
	operator bool() const
	{
		return this->x != 0 || this->y != 0 || this->z != 0;
	}

	//��� ���������� � ���� int - ���������� ����� ���� ����������
	operator int() const
	{
		return int(this->x + this->y + this->z);
	}

	operator long() const
	{
		return long(this->x + this->y + this->z);
	}

	operator double() const
	{
		return double(this->x + this->y + this->z);
	}

	//�������� ������ ��� 1 ������
	void* operator new(size_t v)
	{
		void *ptr = malloc(v);
		if (ptr == NULL)
			throw std::bad_alloc();
		return ptr;
	}

	//��������� ������ ��� ��������� ��������
	void* operator new[](size_t v)
	{
		void *ptr = malloc(sizeof(Vector3) * v);
		if (ptr == NULL)
			throw std::bad_alloc();
		return ptr;
	}

	void operator delete(void* v)
	{
		free(v);
	}

	void operator delete[](void* v)
	{
		free(v);
	}

	//�� ������� ���������! ����� ���������� [] ����� ������ � �����������, ��� ������ ������ ����������
	//���������� ����� ������� ��� ()
	int operator [](int n)
	{
		try
		{
			if (n < 3)
			{
				if (n == 0)
					return this->x;
				if (n == 1)
					return this->y;
				if (n == 2)
					return this->z;
			}
			else
				throw ("������: ����� �� ������� ����������� �������");
		}
		catch (char *str)
		{
			cerr << str << endl;
		}
		return NULL;
	}

	//���� ������ ����� �� ����� ������������� ������
	Vec3 operator ()(Vec3 &vector)
	{
		return Vec3(*this & vector);
	}
};

template <class T>
const Vec3<T> Vec3<T>::Zero = Vec3<T>();
