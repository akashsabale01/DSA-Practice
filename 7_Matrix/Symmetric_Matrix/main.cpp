// Symmetric Matrix - it is a square matrix of size n i.e.(m==n),
// Symmetric matrix means elements at A[i][j]=A[j][I]. they are equal.
// Actually we store only half of the matrix.

//e.g. Symmetric Matrix of size 4 x 4

// M = [ 2 2 2 2 ]
//     [ 2 3 3 3 ]      ,here M[i][j] == M[j][i]
//     [ 2 3 4 4 ]
//     [ 2 3 4 5 ]

// total elements in matrix = n^2
// total NonZero elements in matrix = (n(n+1))/2
// total Zero elements in matrix = n^2 - (n(n+1))/2 = (n(n-1))/2

// 1st way - Implement Symmetric Matrix by Lower triangular matrix
// Row major formula for lower triangular matrix = ((i*(i-1))/2) + (j-1)
// Column major formula for lower triangular matrix =
//    A[n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)]

// 2nd way - Implement Symmetric Matrix by Upper triangular matrix
// Row major formula for Upper triangular matrix =
//    n*(i-1) - ( ((i-2)*(i-1)) /2) + (j-i)
// Column major formula for Upper triangular matrix = ((j*(j-1))/2) + (i-1)

#include <iostream>

using namespace std;


class SymmetricMatrix
{
private:
    int n; // here n is n of matrix(m==n) for square matrix
    int *A;

public:
    SymmetricMatrix()
    {
        n = 2;
        A = new int[(2*(2+1))/2];
    }

    SymmetricMatrix(int n)
    {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }

    ~SymmetricMatrix()
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

    friend ostream& operator<<(ostream &optStreamObj, SymmetricMatrix &sm);

};

void SymmetricMatrix::Set(int i, int j, int value)
{
    //Store only NonZero elements
    if(i>=j)
    {
        A[((i*(i-1))/2) + (j-1)] = value; // Row major formula
//        A[n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)] = value; // Column major formula
    }
}

int SymmetricMatrix::Get(int i,int j)
{
    if(i>=j)
    {
        return A[((i*(i-1))/2) + (j-1)];
//        return A[n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)];
    }
    else
    {
        // interchange i & j
        return A[((j*(j-1))/2) + (i-1)];
    }
}

void SymmetricMatrix::Display()
{
    cout<<endl<<"***** Matrix ****"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            {
                cout<<A[((i*(i-1))/2) + (j-1)]<<" ";
//                cout<<A[n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)]<<" ";
            }
            else
            {
                // interchange i & j
                cout<<A[((j*(j-1))/2) + (i-1)]<<" ";
            }
        }
        cout<<endl;
    }
}


// Overloading insertion operator <<
ostream& operator<<(ostream &optStreamObj, SymmetricMatrix &sm)
{
    cout<<endl<<"***** Displaying Matrix by overloading insertion operator << ***"<<endl;
    for(int i=1; i<=sm.n; i++)
    {
        for(int j=1; j<=sm.n; j++)
        {
            if(i>=j)
            {
                cout<<sm.A[((i*(i-1))/2) + (j-1)]<<" ";
//                cout<<sm.A[sm.n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)]<<" ";
            }
            else
            {
                // interchange i & j
                cout<<sm.A[((j*(j-1))/2) + (i-1)]<<" ";
            }
        }
        cout<<endl;
    }
    return optStreamObj;
}


int main()
{
    int dOfSm;
    cout<<"Enter Dimension = ";
    cin>>dOfSm;

    SymmetricMatrix sm(dOfSm);

    int val;
    cout<<endl<<"Enter all Elements of Matrix:"<<endl;
    for(int i=1;i<=dOfSm;i++)
    {
        for(int j=1;j<=dOfSm;j++)
        {
            cin>>val;
            sm.Set(i,j,val);
        }
    }

    cout<<"Element at (1,2) = "<<sm.Get(1,2)<<endl;
    cout<<"Element at (2,1) = "<<sm.Get(2,1)<<endl;


    cout<<"Dimension of matrix = "<<sm.getDimension()<<endl;

    sm.Display();

    // Displaying Matrix by overloading insertion operator <<
    cout<<endl<<sm<<endl;

    return 0;
}
