// Toeplitz Matrix - it is a square matrix of size n i.e.(m==n),
// Toeplitz matrix means elements at A[i][j]=A[i-1][j-1].
// Actually we store only half of the matrix.

//store all the distinct elements in toeplitz matrix
//Toeplitz matrix is the mtrix having all the same diagonal elements.

//e.g. Toeplitz Matrix of size 4 x 4
//    Dimension = 4
//    Elements of Matrix:
//        2 3 4 5
//        7 2 3 4
//        8 7 2 3
//        9 8 7 2

// total elements in matrix = n^2
// total NonZero elements in matrix = 3*n -2
// total Zero elements in matrix = n^2 - (3*n-2)

//    //Store only one copy of elements
//      i.e. elements = 1st row + 1st column
//           elements = n + n-1
//        if(i<=j)
//            A[j-i] = value;
//        else if(i>j)
//            A[n+(i-j-1)] = value;

#include <iostream>

using namespace std;


class ToeplitzMatrix
{
private:
    int n; // here n is n of matrix(m==n) for square matrix
    int *A;

public:
    ToeplitzMatrix()
    {
        n = 2;
        A = new int[n + n-1];
    }

    ToeplitzMatrix(int n)
    {
        this->n = n;
        A = new int[n + n-1];
    }

    ~ToeplitzMatrix()
    {
        delete []A;
    }

    void Set(int i, int j, int value);
    int Get(int i,int j);
    void Display();
    int getDimension()
    {
        return n;
    }

    friend ostream& operator<<(ostream &optStreamObj, ToeplitzMatrix &tm);

};

void ToeplitzMatrix::Set(int i, int j, int value)
{
    //Store only NonZero elements
    if(i<=j)
        A[j-i] = value;
    else if(i>j)
        A[n+(i-j-1)] = value;
}

int ToeplitzMatrix::Get(int i,int j)
{
    if(i<=j)
        return A[j-i];
    else
        return A[n+(i-j-1)];
}

void ToeplitzMatrix::Display()
{
    cout<<endl<<"***** Matrix ****"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
                cout<<A[j-i]<<" ";
            else if(i>j)
                cout<<A[n+(i-j-1)]<<" ";
        }
        cout<<endl;
    }
}

// Overloading insertion operator <<
ostream& operator<<(ostream &optStreamObj, ToeplitzMatrix &tm)
{
    cout<<endl<<"***** Displaying Matrix by overloading insertion operator << ***"<<endl;
    for(int i=1; i<=tm.n; i++)
    {
        for(int j=1; j<=tm.n; j++)
        {
            if(i<=j)
                cout<<tm.A[j-i]<<" ";
            else if(i>j)
                cout<<tm.A[tm.n+(i-j-1)]<<" ";
        }
        cout<<endl;
    }
    return optStreamObj;
}


int main()
{
    int dOftm;
    cout<<"Enter Dimension = ";
    cin>>dOftm;

    ToeplitzMatrix tm(dOftm);

    int val;
    cout<<endl<<"Enter all Elements of Matrix:"<<endl;
    for(int i=1;i<=dOftm;i++)
    {
        for(int j=1;j<=dOftm;j++)
        {
            cin>>val;
            tm.Set(i,j,val);
        }
    }

    cout<<"Element at (1,2) = "<<tm.Get(1,2)<<endl;
    cout<<"Element at (2,1) = "<<tm.Get(2,1)<<endl;


    cout<<"Dimension of matrix = "<<tm.getDimension()<<endl;

    tm.Display();

    // Displaying Matrix by overloading insertion operator <<
    cout<<endl<<tm<<endl;

    return 0;
}
