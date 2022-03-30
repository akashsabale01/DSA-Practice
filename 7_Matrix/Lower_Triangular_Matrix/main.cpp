// lower triangular Matrix - it is a square matrix of size n i.e.(m==n),
// where i>=j elements are Non-Zero and all other elements are Zero

// total elements in matrix = n^2
// total NonZero elements in matrix = (n(n+1))/2
// total Zero elements in matrix = n^2 - (n(n+1))/2 = (n(n-1))/2

// Row major formula for lower triangular matrix = ((i*(i-1))/2) + (j-1)
// Column major formula for lower triangular matrix =
//    A[n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)]

// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/

#include <iostream>

using namespace std;


class LowerTriMatrix
{
private:
    int n; // here n is n of matrix(m==n) for square matrix
    int *A;

public:
    LowerTriMatrix()
    {
        n = 2;
        A = new int[(2*(2+1))/2];
    }

    LowerTriMatrix(int n)
    {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }

    ~LowerTriMatrix()
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

    friend ostream& operator<<(ostream &optStreamObj, LowerTriMatrix &ltm);

};

void LowerTriMatrix::Set(int i, int j, int value)
{
    //Store only NonZero elements
    if(i>=j)
    {
//        A[((i*(i-1))/2) + (j-1)] = value; // Row major formula
        A[n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)] = value; // Coulmn major formula
    }
}

int LowerTriMatrix::Get(int i,int j)
{
    if(i>=j)
    {
//        return A[((i*(i-1))/2) + (j-1)];
        return A[n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)];
    }
    else
        return 0;
}

void LowerTriMatrix::Display()
{
    cout<<endl<<"***** Matrix ****"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
            {
//                cout<<A[((i*(i-1))/2) + (j-1)]<<" ";
                cout<<A[n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)]<<" ";
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}


// Overloading insertion operator <<
ostream& operator<<(ostream &optStreamObj, LowerTriMatrix &ltm)
{
    cout<<endl<<"***** Displaying Matrix by overloading insertion operator << ***"<<endl;
    for(int i=1; i<=ltm.n; i++)
    {
        for(int j=1; j<=ltm.n; j++)
        {
            if(i>=j)
            {
//                cout<<ltm.A[((i*(i-1))/2) + (j-1)]<<" ";
                cout<<ltm.A[ltm.n*(j-1) - ( ((j-2)*(j-1)) /2) + (i-j)]<<" ";
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
    int dimensionOfLowerTriMatrix;
    cout<<"Enter Dimension = ";
    cin>>dimensionOfLowerTriMatrix;

    LowerTriMatrix ltmtx(dimensionOfLowerTriMatrix);

    int val;
    cout<<"Enter all Elements of Matrix:"<<endl;
    for(int i=1;i<=dimensionOfLowerTriMatrix;i++)
    {
        for(int j=1;j<=dimensionOfLowerTriMatrix;j++)
        {
            cin>>val;
            ltmtx.Set(i,j,val);
        }
    }


    cout<<"Element at (1,2) = "<<ltmtx.Get(1,2)<<endl;
    cout<<"Element at (2,1) = "<<ltmtx.Get(2,1)<<endl;


    cout<<"Dimension of matrix = "<<ltmtx.getDimension()<<endl;

    ltmtx.Display();

    // Displaying Matrix by overloading insertion operator <<
    cout<<endl<<ltmtx<<endl;

    return 0;
}
