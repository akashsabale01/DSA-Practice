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
    int getDimension()
    {
        return dimension;
    };
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

int main()
{

    int dOfMatrix, choice;
    cout<<"Enter dimension of Matrix = ";
    cin>>dOfMatrix;

    DiagonalMatrix dm(dOfMatrix);

    do
    {
         cout<<endl<<"**** Menu ****"<<endl;
         cout<<"1.Create"<<endl;
         cout<<"2.Set"<<endl;
         cout<<"3.Get"<<endl;
         cout<<"4.Get Dimension"<<endl;
         cout<<"5.Display"<<endl;
         cout<<"6.Exit"<<endl;

         cout<<endl<<"Enter you choice = "<<endl;
         cin>>choice;

         switch(choice)
         {
         case 1:
             dm.Create();
             break;

         case 2:
            int row,col,x;
            cout<<"Enter row & col number of element to set element = ";
            cin>>row>>col;
            cout<<"Enter value = ";
            cin>>x;
            dm.Set(row,col,x);
            break;

         case 3:
            cout<<"Enter row & col number of element to get element = ";
            cin>>row>>col;
            cout<<"Element at "<<row<<","<<col<<" is "<<dm.Get(row,col)<<endl;
            break;

         case 4:
            cout<<endl<<"Dimension of Matrix = "<<dm.getDimension()<<endl;
            break;

         case 5:
            dm.Display();
            break;
         }

    }while(choice<6);

    return 0;
}
