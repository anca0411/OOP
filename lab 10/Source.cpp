#include <iostream>
#include <exception>
using namespace std;
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    T** ptr; // mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator() : ptr(nullptr) {}
    ArrayIterator(T** p) : ptr(p) {}
    ArrayIterator& operator ++ ()
    {
        ptr++;
        return this;
    }
    ArrayIterator& operator -- ()
    {
        ptr--;
        return this;
    }
    ArrayIterator<T>& operator=(const ArrayIterator<T>& other)
    {
        if (this != &other)
            this->ptr = other.ptr;
        return *this;
    }
    bool operator!=(ArrayIterator<T>& other) 
    {
        return ptr != other.ptr;
    }
    T* GetElement()
    {
        return *ptr;
    }
};

class IndexOutOfRange : public exception
{
public:

    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};
class CapacityExcess : public exception
{
public:

    virtual const char* what() const throw()
    {
        return "Capacitatea maxima a fost depasita";
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array()// Lista nu e alocata, Capacity si Size = 0
    {
        Capacity = 0;
        Size = 0;
        List = nullptr;
    }
    ~Array() // destructor
    {
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        Capacity = capacity;
        Size = 0;
        List = new T*[Capacity];
        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;
    }
    Array(const Array<T>& otherArray) // constructor de copiere
    {
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
        List = new T*[Capacity];
        for (int i = 0; i <= Size; i++)
            List[i] = otherArray.List[i];
    }
    T& operator[] (int index)
    { 
            if (index >= Size || index < 0)
                throw IndexOutOfRange();  
            return *List[index];
        
    }
    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        if (Size >= Capacity)
            throw CapacityExcess();
        List[Size++] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size || Size >= Capacity)
            throw IndexOutOfRange();
        for (int i = Size; i > index; i--)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size || index+otherArray.Size >= Capacity)
            throw IndexOutOfRange();
        for (int i = Size - 1; i >= index; i--)
            List[i + otherArray.Size] = List[i];
        for (int j = 0; j < otherArray.Size; j++)
            List[index + j] = new T(*otherArray.List[j]);
        Size += otherArray.Size;
            return *this;
    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size || Size >= Capacity)
            throw IndexOutOfRange();
        for (int j = index; j < Size; j++)
            List[j] = List[j + 1];
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this == &otherArray)
            return true;
        for (int i = 0; i < Size; i++)
                delete List[i];
        delete[] List;
        List = new T*[Capacity];
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        for (int i = 0; i < Size; i++)
            List[i] = new T(*otherArray.List[i]);
        return true;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        for (int i = 0; i < Size-1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i],List[j]);
    }
    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i] , *List[j])>0)
                    swap(List[i], List[j]);
    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i],List[j]) > 0)
                    swap(List[i], List[j]);
    }
    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int m = (st + dr) / 2;
            if (*List[m] == elem) return m;
            else if (*List[m] < elem) st = m + 1;
            else dr = m - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int m = (st + dr) / 2;
            int cmp =  compare(*List[m], elem);
            if (cmp == 0) return m;
            else if (cmp < 0) st = m + 1;
            else dr = m - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int m = (st + dr) / 2;
            int cmp = comparator->CompareElements(List[m], (void*)&elem);
            if (cmp == 0) return m;
            else if (cmp < 0) st = m + 1;
            else dr = m - 1;
        }
        return -1;
    }
    int Find(const T& elem) // cauta un element in Array
    {
        for (int i = 0; i < Size; i++)
        {
            if (*List[i] == elem);
            return i;
        }
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for (int i = 0; i < Size; i++)
        {
            int cmp = compare(*List[i], elem);
            if (cmp==0)
            return i;
        }
        return -1;
    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        for (int i = 0; i < Size; i++)
        {
            if(comparator->CompareElements(List[i],(void*)&elem)==0)
                return i;
        }
        return -1;
    }
    int GetSize()
    {
        return Size;
    }
    int GetCapacity()
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(List); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(List + Size); }
};
template<class T>
class CompareT : public Compare
{
    int CompareElements(void* e1, void* e2)
    {
        int a = *(int*)e1;
        int b = *(int*)e2;
        return a - b;
    }
};
// Comparator pentru int
int compareInts(const int& a, const int& b) {
    return a - b;
}

int main() {
    try {
        Array<int> arr(3);  // Array cu capacitate 3

        // Adaugă 3 elemente
        arr += 10;
        arr += 20;
        arr += 30;

        cout << "Array initial: ";
        for (int i = 0; i < arr.GetSize(); i++)
            cout << arr[i] << " ";
        cout << endl;

        // EXCEPTIE: depasire capacitate
        try {
            arr += 40; // depaseste capacitatea
        }
        catch (const exception& e) {
            cout << "Exceptie CapacityExcess: " << e.what() << endl;
        }

        // EXCEPTIE: acces invalid
        try {
            cout << arr[5] << endl; // index invalid
        }
        catch (const exception& e) {
            cout << "Exceptie IndexOutOfRange (acces): " << e.what() << endl;
        }

        // EXCEPTIE: inserare pe pozitie invalida
        try {
            arr.Insert(-1, 50); // index invalid
        }
        catch (const exception& e) {
            cout << "Exceptie IndexOutOfRange (inserare): " << e.what() << endl;
        }

        // EXCEPTIE: stergere pe pozitie invalida
        try {
            arr.Delete(10); // index invalid
        }
        catch (const exception& e) {
            cout << "Exceptie IndexOutOfRange (stergere): " << e.what() << endl;
        }

    }
    catch (const exception& e) {
        cout << "Exceptie generala: " << e.what() << endl;
    }

    return 0;
}

