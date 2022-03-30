

template<typename T>
class Vector
{
    // Data members
private:
    T *arr;
    int current_size;
    int max_size;

    // Methods,Constructor, destructor
public:
    Vector(int ms = 1)
    {
        current_size = 0;
        max_size = ms;
        arr = new T[max_size];
    }

    void Push_back(T element)
    {
        // 1st case - reallocation i.e. expand array
        if(current_size == max_size)
        {
            T *old_arr = arr;
            max_size = 2 * max_size;

            // create array of double size
            arr = new T[max_size];

            //copy elements
            for(int i=0;i<current_size;i++)
                arr[i] = old_arr[i];

            //delete old arr
            delete [] old_arr;
        }
        arr[current_size] = element;
        current_size++;
    }

    void Pop_back()
    {
        if(current_size>=0)
            current_size--;
    }

    bool isEmpty()
    {
        if(current_size==0)
            return true;

        return false;

    }

    T Front()
    {
        return arr[0];
    }

    T Back()
    {
        return arr[current_size-1];
    }

    T At(int index)
    {
        if(index<current_size && index>=0)
            return arr[index];

        return -1;
    }

    int Size()
    {
        return current_size;
    }

    int Capacity()
    {
        return max_size;
    }

    // below method is called when we write v[i]
    T operator[](int i)
    {
        return arr[i];
    }

};
