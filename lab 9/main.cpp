#include <cstdio>
#include <iostream>
using namespace std;
template<typename K, typename V>
class Map
{
private:
	struct Element {
		K key;
		V value;
		int index;
	};
	Element elements[100];
	int size = 0;
public:
	V& operator[](const K& key)
	{
		for (int i = 0; i != size; i++)
			if (elements[i].key == key)
				return elements[i].value;
		elements[size] = { key, V(), size };  //creeaza un nou element
		size++;
		return elements[size - 1].value;
	}
	void Set(const K& key, V& value)
	{
		(*this)[key] = value;
	}
	bool Get(const K& key, V& value)
	{
		for (int i = 0; i < size; i++)
			if (elements[i].key == key)
			{
				value = elements[i].value;
				return true;
			}
		return false;
	}
	int Count()
	{
		return size;
	}
	void Clear()
	{
		size = 0;
	}
	bool Delete(const K& key)
	{
		for (int i = 0; i < size; i++)
		{
			if (elements[i].key == key)
			{
				for (int j = i; j < size; j++)
				{
					elements[j] = elements[j + 1];
					elements[j].index = j;
				}
				size--;
				return true;
			}
		}
		return false;
	}
	bool Includes(const Map<K, V>& map)
	{
		bool found;
		for (int i = 0; i < map.size; i++)
		{
			found = false;
			for (int j = 0; j <= size; j++)
			{
				if (elements[j].key == map.elements[i].key)
				{
					found = true;
					break;
				}
			}
			if (found == false)
				return false;
		}
		return true;
	}
	struct Iterator
	{
		Element* ptr;
		Iterator(Element* p) : ptr(p) {};
		bool operator!=(Iterator& other)
		{
			return ptr != other.ptr;
		}
		Iterator& operator++()
		{
			ptr++;
			return *this;
		}
		auto operator*() const { return std::tuple <K, V, int>(ptr->key, ptr->value, ptr->index); }
	};
	Iterator begin()
	{
		return Iterator(elements);
	}
	Iterator end()
	{
		return Iterator(elements + size);
	}
};
int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}