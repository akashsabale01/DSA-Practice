// Upper triangular Matrix - it is a square matrix of size n i.e.(m==n),
// where i<=j elements are Non-Zero and all other elements are Zero

// total elements in matrix = n^2
// total NonZero elements in matrix = (n(n+1))/2
// total Zero elements in matrix = n^2 - (n(n+1))/2 = (n(n-1))/2

// Row major formula for Upper triangular matrix =
//    n*(i-1) - ( ((i-2)*(i-1)) /2) + (j-i)
// Column major formula for Upper triangular matrix = ((j*(j-1))/2) + (i-1)

#include <iostream>

using namespace std;

class UpperTriMatrix
{
private:
    int n; //dimension of upper triangular matrix
    int *A;

public:
    UpperTriMatrix()
    {
        n = 2;
        A = new int[(2*(2+1))/2];
    }

    UpperTriMatrix(int n)
    {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }

    ~UpperTriMatrix()
    {
        delete []A;
    }

    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    int getDimension()
    {
        return n;
    }

    friend ostream& operator<<(ostream &optStreamObj, UpperTriMatrix &utm);


};

void UpperTriMatrix::Set(int i, int j, int value)
{
    if(i<=j)
    {
//        A[( n*(i-1) - ( (i-2)*(i-1) / 2 ) ) + (j-i)] = value; // Row Major
        A[((j*(j-1))/2) + (i-1)] = value; // Column Major
    }
}

int UpperTriMatrix::Get(int i, int j)
{
    if(i<=j)
    {
//        return A[( n*(i-1) - ( (i-2)*(i-1) / 2 ) ) + (j-i)];
        return A[((j*(j-1))/2) + (i-1)];
    }
    else
        return 0;
}

void UpperTriMatrix::Display()
{
    cout<<endl<<"***** Matrix ****"<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i<=j)
            {
//                cout<<A[( n*(i-1) - ( (i-2)*(i-1) / 2 ) ) + (j-i)]<<" "; // Row major
                cout<<A[((j*(j-1))/2) + (i-1)]<<" "; // Column major
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

// Overloading insertion operator <<
ostream& operator<<(ostream &optStreamObj, UpperTriMatrix &utm)
{
    cout<<endl<<"***** Displaying Matrix by overloading insertion operator << ***"<<endl;
    for(int i=1; i<=utm.n; i++)
    {
        for(int j=1; j<=utm.n; j++)
        {
            if(i<=j)
            {
//                cout<<utm.A[( utm.n*(i-1) - ( (i-2)*(i-1) / 2 ) ) + (j-i)]<<" "; // Row major
                cout<<utm.A[((j*(j-1))/2) + (i-1)]<<" "; // Column major
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return optStreamObj;
}



int main()
{
    int dimension;
    cout<<"Enter dimension = ";
    cin>>dimension;

    UpperTriMatrix utmx(dimension);

    int val;
    cout<<endl<<"Enter all Elements of Matrix:"<<endl;
    for(int i=1; i<=dimension; i++)
    {
        for(int j=1; j<=dimension; j++)
        {
            cin>>val;
            utmx.Set(i,j,val);
        }
    }

    cout<<"Element at (1,2) = "<<utmx.Get(1,2)<<endl;
    cout<<"Element at (2,1) = "<<utmx.Get(2,1)<<endl;

    cout<<"Dimension of matrix = "<<utmx.getDimension()<<endl;

    utmx.Display();

    cout<<endl<<utmx<<endl;

    return 0;
}
