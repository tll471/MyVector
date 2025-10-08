#include <iostream>
using namespace std;

class MyVector
{
	int size;
	int* arr;

public:
	MyVector() : arr(nullptr), size(0) {}
	MyVector(int s) : size(s), arr(new int[size]) {}
	void Init()
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 50 + 1;
		}
	}
	void Print()
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << ", ";
		}
		cout << endl;
	}
	~MyVector()
	{
		delete[] arr;
		size = 0;
	}
	int GetSize() const
	{
		return size;
	}
	int operator[](int index)
		{
			if (index >= 0 && index < size)
			{
				return arr[index];
			}
			return -1;
		}
	MyVector(const MyVector& obj)
	{
		size = obj.size;
		arr = new int[size];

		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	MyVector(MyVector&& obj)
	{
		size = obj.size;
		arr = obj.arr;
		obj.arr = nullptr;
		obj.size = 0;
	}
	MyVector& operator = (MyVector& obj2)
	{
		if (this == &obj2)
		{
			return *this;
		}
		if (arr != nullptr)
		{
			delete[] arr;
		}
		size = obj2.size;
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj2.arr[i];
		}
		return *this;
	}
	MyVector operator++()
	{
		int* newArr = new int[size + 1]; 

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		newArr[size] = 0;

		arr = newArr;
		size += 1;

		return *this;
	}
	MyVector operator--()
	{
		int* newArr = new int[size + 1];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		arr = newArr;
		size -= 1;

		return *this;
	}
};
int main()
{
	srand(time(NULL));
	MyVector vec1(10);
	vec1.Init();
	vec1.Print();

	//for (size_t i = 0; i < vec1.GetSize(); i++)
	//{
	//	cout << vec1[i] << ", ";
	//}
	//cout << endl;
	cout << "Копирование: " << endl;
	MyVector vec2 = vec1;
	vec2.Print();
	vec1.Print();

	cout << "Перенос: " << endl;
	MyVector vec3 = move(vec2);
	vec3.Print();

	cout << "= с копированием: " << endl;
	MyVector vec4(10), vec5(10), vec6(10);
	vec4.Init();
	vec5.Init();
	vec6.Init();

	vec4 = vec5 = vec6;
	vec4.Print();
	vec5.Print();
	vec6.Print();
	cout << "operator++" << endl;
	MyVector vec7 = ++vec5;
	vec7.Print();
	vec5.Print();

	cout << "operator--" << endl;
	MyVector vec8 = --vec4;
	vec8.Print();
	vec4.Print();
	


}