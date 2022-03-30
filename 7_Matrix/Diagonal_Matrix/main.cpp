// Diagonal Matrix - it is a square matrix of size n i.e.(m==n),
// where diagonal elements are Non-Zero and all other elements are Zero

#include <iostream>

using namespace std;


class DiagonalMatrix
{
private:
    int dimension;
    int *A;

public:
    DiagonalMatrix()
    {
        dimension = 2;
        A = new int[dimension];
    }

    DiagonalMatrix(int dimension)
    {
        this->dimension = dimension;
        A = new int[this->dimension];
    }

    ~DiagonalMatrix()
    {
        delete []A;
    }

    void Create();
    void Set(int i, int j, int value);
    int Get(int i,int j);
    void Display();

    friend ostream& operator<<(ostream &os, DiagonalMatrix &dm);

};

void DiagonalMatrix::Create()
{
    int val;
    cout<<endl<<"Enter all Elements of Matrix:"<<endl;
    for(int i=1;i<=dimension;i++)
    {
        for(int j=1;j<=dimension;j++)
        {
            cin>>val;
            if(i==j)
                A[i-1]=val;
        }
    }
}

void DiagonalMatrix::Set(int i, int j, int value)
{
    if(i==j)
        A[i-1] = value;
}

int DiagonalMatrix::Get(int i,int j)
{
    if(i==j)
        return A[i-1];
    else
        return 0;
}

void DiagonalMatrix::Display()
{
    cout<<endl<<"***** Matrix ****"<<endl;
    for(int i=1;i<=dimension;i++)
    {
        for(int j=1;j<=dimension;j++)
        {
            if(i==j)
                cout<<A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}


// Overloading insertion operator <<
ostream& operator<<(ostream &optStreamObj, DiagonalMatrix &dm)
{
    cout<<endl<<"***** Displaying Matrix by overloading insertion operator << ***"<<endl;
    for(int i=1; i<=dm.dimension; i++)
    {
        for(int j=1; j<=dm.dimension; j++)
        {
            if(i==j)
                cout<<dm.A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return optStreamObj;
}


int main()
{
    int dimensionOfDiagonalMatrix = 6;
    DiagonalMatrix dmtx(dimensionOfDiagonalMatrix);

    dmtx.Set(0,0,11);
    dmtx.Set(1,1,22);
    dmtx.Set(2,2,33);
    dmtx.Set(3,3,44);
    dmtx.Set(4,4,55);
    dmtx.Set(5,5,66);

    cout<<"Element at (1,2) = "<<dmtx.Get(1,2)<<endl;
    cout<<"Element at (2,2) = "<<dmtx.Get(2,2)<<endl;
    cout<<"Element at (5,5) = "<<dmtx.Get(5,5)<<endl;

    dmtx.Display();

    // Displaying Matrix by overloading insertion operator <<
    cout<<endl<<dmtx<<endl;

    return 0;
}
