#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
    T* arr;
    int topIndex;
    int capacity;

public:

    Stack(int size = 10)
    {
        try
        {
            arr = new T[size];
        }
        catch (bad_alloc&)
        {
            throw runtime_error("Memory allocation failed for stack");
        }

        capacity = size;
        topIndex = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool IsFull() const
    {
        return topIndex == capacity - 1;
    }

    bool IsEmpty() const
    {
        return topIndex == -1;
    }

    void Push(const T& elem)
    {
        if (IsFull())
            throw overflow_error("Stack overflow");

        arr[++topIndex] = elem;
    }

    T Pop()
    {
        if (IsEmpty())
            throw underflow_error("Pop from empty stack");

        return arr[topIndex--];
    }

    T Peek() const
    {
        if (IsEmpty())
            throw runtime_error("Peek from empty stack");

        return arr[topIndex];
    }

    int GetCount() const
    {
        return topIndex + 1;
    }

    void Clear()
    {
        topIndex = -1;
    }

    void Print() const
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    try
    {
        Stack<int> s(5);

        s.Push(10);
        s.Push(20);
        s.Push(30);

        s.Print();

        cout << "Pop: " << s.Pop() << endl;
        cout << "Peek: " << s.Peek() << endl;

        s.Clear();

        s.Pop();
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    }
}
