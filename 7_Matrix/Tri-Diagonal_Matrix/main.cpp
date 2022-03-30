//e.g. TriDiagonal Matrix of size 4 x 4
//    Dimension = 4
//    Elements of Matrix:
//        1 2 0 0
//        3 4 5 0
//        0 6 7 8
//        0 0 9 10

// total elements in matrix = n^2
// total NonZero elements in matrix = 3*n -2
// total Zero elements in matrix = n^2 - (3*n-2)

//    //Store only NonZero elements
//    if(i-j == 1) // lower diagonal
//        A[i-2] = value;
//    else if(i-j == 0) // middle diagonal
//        A[(n-1)+(i-1)] = value;
//    else if(i-j == -1) // upper diagonal
//        A[(n-1)+n+(i-1)] = value;

#include <iostream>

using namespace std;


class TriDiagonalMatrix
{
private:
    int n; // here n is n of matrix(m==n) for square matrix
    int *A;

public:
    TriDiagonalMatrix()
    {
        n = 2;
        A = new int[3*n-2];
    }

    TriDiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[3*n-2];
    }

    ~TriDiagonalMatrix()
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

    friend ostream& operator<<(ostream &optStreamObj, TriDiagonalMatrix &tdm);

};

void TriDiagonalMatrix::Set(int i, int j, int value)
{
    //Store only NonZero elements
    if(i-j == 1)
        A[i-2] = value;
    else if(i-j == 0)
        A[(n-1)+(i-1)] = value;
    else if(i-j == -1)
        A[(n-1)+n+(i-1)] = value;
}

int TriDiagonalMatrix::Get(int i,int j)
{
    if(i-j == 1)
        return A[i-2];
    else if(i-j == 0)
        return A[(n-1)+(i-1)];
    else if(i-j == -1)
        return A[(n-1)+n+(i-1)];
    else
        return 0;
}

void TriDiagonalMatrix::Display()
{
    cout<<endl<<"***** Matrix ****"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i-j == 1)
                cout<<A[i-2]<<" ";
            else if(i-j == 0)
                cout<<A[(n-1)+(i-1)]<<" ";
            else if(i-j == -1)
                cout<<A[(n-1)+n+(i-1)]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}


// Overloading insertion operator <<
ostream& operator<<(ostream &optStreamObj, TriDiagonalMatrix &tdm)
{
    cout<<endl<<"***** Displaying Matrix by overloading insertion operator << ***"<<endl;
    for(int i=1; i<=tdm.n; i++)
    {
        for(int j=1; j<=tdm.n; j++)
        {
            if(i-j == 1)
                cout<<tdm.A[i-2]<<" ";
            else if(i-j == 0)
                cout<<tdm.A[(tdm.n-1)+(i-1)]<<" ";
            else if(i-j == -1)
                cout<<tdm.A[(tdm.n-1)+tdm.n+(i-1)]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return optStreamObj;
}


int main()
{
    int dOftdm;
    cout<<"Enter Dimension = ";
    cin>>dOftdm;

    TriDiagonalMatrix tdm(dOftdm);

    int val;
    cout<<endl<<"Enter all Elements of Matrix:"<<endl;
    for(int i=1;i<=dOftdm;i++)
    {
        for(int j=1;j<=dOftdm;j++)
        {
            cin>>val;
            tdm.Set(i,j,val);
        }
    }

    cout<<"Element at (1,2) = "<<tdm.Get(1,2)<<endl;
    cout<<"Element at (2,1) = "<<tdm.Get(2,1)<<endl;


    cout<<"Dimension of matrix = "<<tdm.getDimension()<<endl;

    tdm.Display();

    // Displaying Matrix by overloading insertion operator <<
    cout<<endl<<tdm<<endl;

    return 0;
}
