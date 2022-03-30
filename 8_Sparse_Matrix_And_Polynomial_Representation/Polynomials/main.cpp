#include <iostream>

using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Polynomial
{
private:
    int n;
    Term *terms;

public:
    Polynomial()
    {
        n = 0;
        terms = nullptr;
    }

    Polynomial(int n)
    {
        this->n = n;
        terms = new Term[this->n];
    }

    Polynomial operator+(Polynomial &p);

    friend istream& operator>>(istream &is, Polynomial &p);
    friend ostream& operator<<(ostream &os, Polynomial &p);

};

istream& operator>>(istream &is, Polynomial &p)
{
    cout<<"Enter the number of Non Zero terms = ";
    cin>>p.n;

    cout<<"Enter terms (coefficient & exponent) :"<<endl;
    for(int i=0; i<p.n; i++)
    {
        cout<<"Enter "<<i+1<<" term = ";
        cin>>p.terms[i].coeff;
        cin>>p.terms[i].exp;
    }
    return is;
}

ostream& operator<<(ostream &os, Polynomial &p)
{
    for(int i=0; i<p.n; i++)
    {
        cout<<p.terms[i].coeff<<"x^"<<p.terms[i].exp;
        if (i + 1 != p.n)
            cout << " + ";
    }
    cout<<endl;
    return os;
}

Polynomial Polynomial::operator+(Polynomial &p)
{
    Polynomial *sum = new Polynomial(n + p.n);

    int  i,j,k;
    i=j=k=0;
    while(i<n && j<p.n)
    {
        if(terms[i].exp > p.terms[j].exp)
            sum->terms[k++] = terms[i++];

        else if(p.terms[j].exp > terms[i].exp)
            sum->terms[k++] = p.terms[j++];

        else
        {
            // equal exp
            sum->terms[k].exp = terms[i].exp;
            sum->terms[k++].coeff = terms[i++].coeff + p.terms[j++].coeff;
        }
    }

    // remaining terms
    for(;i<n;i++)
        sum->terms[k++] = terms[i];

    for(;j<p.n;j++)
        sum->terms[k++] = terms[j];

    sum->n = k; // no of terms in resultant sum polynomial

    return *sum;
}

int main()
{
    Polynomial p1(3);
    cin>>p1;

    Polynomial p2(3);
    cin>>p2;

    cout<<endl;

    cout<<"1st polynomial = "<<p1;
    cout<<"2nd polynomial = "<<p2;

    Polynomial p3 = p1+p2;

    cout<<endl<<"Sum Polynomial = "<< p3;

    return 0;
}
