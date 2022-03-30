/*
	* Topic : Sparse Matrix
	* very few Non zero elements is present in such matrix
	* Store only nonzero elements and optimize space
	* Two methods :
		1. Three column representation/ Co-ordinate List Representation
		2. Compressed Sparse Row
	* Operations :
		1. Create => Compressed Sparse Row Representation
		2. Add  =>  Co-ordinate List Representation
*/

#include <iostream>

using namespace std;

class Element
{
public:
    int row;
    int col;
    int value;
};

class SparseMatrix
{
private:
    int m;
    int n;
    int noOfNonZeroElements;
    Element *eleArr;

public:
    SparseMatrix(int m,int n, int noOfNonZeroElements)
    {
        this->m = m;
        this->n = n;
        this->noOfNonZeroElements = noOfNonZeroElements;
        eleArr = new Element[this->noOfNonZeroElements];
    }
    ~SparseMatrix()
    {
        delete []eleArr;
    }

//    void read();
//    void display();

    SparseMatrix* operator+(SparseMatrix &s);

    // Read() and Display() using Operator overloading
    friend istream& operator>>(istream &is, SparseMatrix &s);
    friend ostream& operator<<(ostream &os, SparseMatrix &s);


};

SparseMatrix* SparseMatrix::operator+(SparseMatrix &s)
{
    if(m!=s.m || n!=s.n)
//        return SparseMatrix(0,0,0);
        return NULL;

    SparseMatrix *sum = new SparseMatrix(m,n,noOfNonZeroElements+s.noOfNonZeroElements);

    // 'i' for indexing 's1' , 'j' for 's2', 'k' for 'sum'

    int i,j,k;
    i=j=k=0;

    while(i<noOfNonZeroElements && j<s.noOfNonZeroElements)
    {
        // Comparing rows
        if(eleArr[i].row < s.eleArr[j].row)
        {
            sum->eleArr[k] = eleArr[i];
            k++,i++;
        }
        else if(eleArr[i].row > s.eleArr[j].row)
        {
            sum->eleArr[k] = s.eleArr[j];
            k++,j++;
        }
        else
        {
            // both have same row number
            // then Compare col number
            if(eleArr[i].col < s.eleArr[j].col)
            {
                sum->eleArr[k] = eleArr[i];
                k++,i++;
            }
            else if(eleArr[i].col > s.eleArr[j].col)
            {
                sum->eleArr[k] = s.eleArr[j];
                k++,j++;
            }
            else
            {
                // both have same row number && col number
                sum->eleArr[k] = eleArr[i];
                sum->eleArr[k].value = eleArr[i].value + s.eleArr[j].value;
                i++,j++,k++;
            }
        }
    }

    // Remaining elements in s1 sparse matrix
    for(;i<noOfNonZeroElements;i++)
        sum->eleArr[k++] = eleArr[i];

    // Remaining elements in s2 sparse matrix
    for(;j<s.noOfNonZeroElements;j++)
        sum->eleArr[k++] = s.eleArr[j];

    sum->noOfNonZeroElements = k;

    // as here sum is pointer but in fun declaration have to return only value
    // returning value of sum using dereferencing
    return sum;

}

//void SparseMatrix::read()
//{
//    cout<<"Enter Non Zero Elements :"<<endl;
//    for(int i=0; i<noOfNonZeroElements; i++)
//        cin>>eleArr[i].row>>eleArr[i].col>>eleArr[i].value;
//}
//
//void SparseMatrix::display()
//{
//    cout<<"Sparse Matrix:"<<endl;
//    int k=0; // keep track of non zero elements
//    for(int i=0; i<m; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            if(eleArr[k].row==i && eleArr[k].col==j)
//            {
//                cout<<eleArr[k].value<<" ";
//                k++;
//            }
//            else
//                cout<<"0 ";
//        }
//        cout<<endl;
//    }
//}


istream& operator>>(istream &is, SparseMatrix &s)
{
    cout<<"Enter Non-Zero Elements :"<<endl;
    for(int i=0; i<s.noOfNonZeroElements; i++)
    {
        cin>>s.eleArr[i].row;
        cin>>s.eleArr[i].col;
        cin>>s.eleArr[i].value;
    }

    return is;
}

ostream& operator<<(ostream &os, SparseMatrix &s)
{
    int k=0; // keep track of non zero elements
    for(int i=0; i<s.m; i++)
    {
        for(int j=0; j<s.n; j++)
        {
            if(s.eleArr[k].row==i && s.eleArr[k].col==j)
            {
                cout<<s.eleArr[k].value<<" ";
                k++;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}



int main()
{
//    SparseMatrix spm(5,5,5);
//    spm.read();
//    spm.display();

    SparseMatrix s1(4,4,4);
    SparseMatrix s2(4,4,4);

    cin>>s1;
    cin>>s2;

    SparseMatrix *sum = s1 + s2;

    cout<<"First Matrix"<<endl;
    cout<<s1<<endl;

    cout<<"Second Matrix"<<endl;
    cout<<s2<<endl;

    cout<<"Sum Matrix"<<endl;
    cout<<*sum<<endl;



    return 0;
}
