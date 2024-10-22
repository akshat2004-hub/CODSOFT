#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n1, n2;
    cout<<"Enter first number : ";
    cin>>n1;
    cout<<"Enter second number : ";
    cin>>n2;
    char cal;
    cout<<"Enter the operation (+, -, *, /) : ";
    cin>>cal;
    switch(cal)
    {
        case '+':
                cout<<"Addition : " << n1 << cal << n2 << " = " << n1 + n2 <<endl;
                break;
        case '-':
                cout<<"Subtraction : " << n1 << cal << n2 << " = " << n1 - n2 <<endl;
                break;
        case '*':
                cout<<"Multiplication : " << n1 << cal << n2 << " = " << n1 * n2 <<endl;
                break;
        case '/':
                if(n2 == 0)
                {
                    cout<<"It is divided by zero. Please select another number."<<endl;
                }
                else
                {
                    cout<<"Divide: " << n1 << cal << n2 << " = " << n1 / n2 <<endl;
                }
                break;
        default :
                cout<<"Invalid Operator or Symbol. Please select appropriate symbol (+, -, *, /).";
    }
    return 0;
}
