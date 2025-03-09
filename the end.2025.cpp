#include <iostream>
using namespace std;

class Array
{
private:
    int size;
    int length;
    int* items;
public:
    Array(int arrsize)
    {
        size = arrsize;
        length = 0;
        items = new int[arrsize];
    }

    void fill()
    {
        int no_of_elements;
        cout << "Please enter the number of elements\n";
        cin >> no_of_elements;
        if (no_of_elements > size)
        {
            cout << "You cannot exceed the array size\n";
            return;
        }
        else
        {
            for (int i = 0; i < no_of_elements; i++)
            {
                cout << "Enter element number " << i + 1 << "\n";
                cin >> items[i];
                length++;
            }
        }
    }

    int getlength() const
    {
        return length;
    }

    int getsize() const
    {
        return size;
    }

    int search(int key) const
    {
        for (int i = 0; i < length; i++)
        {
            if (items[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    void Display() const
    {
        cout << "Hello, these are the array elements:\n";
        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }

    void Append(int newitem)
    {
        if (length < size)
        {
            items[length] = newitem;
            length++;
        }
        else
        {
            cout << "Sorry, the array is full\n";
        }
    }
   
    void insert(int index, int newItem)
    {
        if (index >= 0 && index < length)
        {
            for (int i = length; i > index; i--)
            {
                items[i] = items[i - 1];
            }
            items[index] = newItem;
            length++;
        }
        else
        {
            cout << "Sorry, index out of range\n";
        }
    }

    void Delete(int index)
    {
        if (index >= 0 && index < length)
        {
            for (int i = index; i < length - 1; i++)
            {
                items[i] = items[i + 1];
            }
            length--;
        }
        else
        {
            cout << "Sorry, index out of range.\n";
        }
    }

    void Enlarge(int newsize)
    {
        if (newsize <= size)
        {
            cout << "Sorry, the new size should be bigger than the current size.\n";
            return;
        }

        int* old = items;
        items = new int[newsize];

        for (int i = 0; i < length; i++)
        {
            items[i] = old[i];
        }

        delete[] old;
        size = newsize;
    }

    void Merge(Array& other)
    {
        int newsize = size + other.getsize();
        int* old = items;
        items = new int[newsize];

        for (int i = 0; i < length; i++)
        {
            items[i] = old[i];
        }

        int j = length;
        for (int i = 0; i < other.getlength(); i++)
        {
            items[j++] = other.items[i]; 
        }

        delete[] old;
        length += other.getlength();
        size = newsize;
    }
};

int main()
{
    cout << "Hello, this is the Array demo\n";
    int arrsize;
    cout << "Enter the array size\n";
    cin >> arrsize;
    Array myarray(arrsize);
    myarray.fill();

    cout << "The current length = " << myarray.getlength() << "\t" << "The size = " << myarray.getsize() << "\n";
    myarray.Display();

    cout << "Enter the value you want to search\n";
    int key;
    cin >> key;
    int index = myarray.search(key);
    if (index == -1)
    {
        cout << "Sorry, the value does not exist\n";
    }
    else
    {
        cout << "The value exists at index = " << index << endl;
    }

    int newitem;
    cout << "Enter the new item you want to add \n";
    cin >> newitem;
    myarray.Append(newitem);
    myarray.Display();

    cout << "Enter the index and the new item\n";
    cin >> index >> newitem;
    myarray.insert(index, newitem);
    cout << "The current length = " << myarray.getlength() << "\t" << "The size = " << myarray.getsize() << "\n";
    myarray.Display();

    cout << "Enter the index you want to delete\n";
    cin >> index;
    myarray.Delete(index);
    myarray.Display();

    int newsize;
    cout << "Enter the new size\n";
    cin >> newsize;
    myarray.Enlarge(newsize);
    cout << "The current length = " << myarray.getlength() << "\t" << "The size = " << myarray.getsize() << "\n";
    myarray.Display();

    Array other(3);
    other.fill();
    myarray.Merge(other);
    cout << "The current length = " << myarray.getlength() << "\t" << "The size = " << myarray.getsize() << "\n";
    myarray.Display();

    return 0;
}
