#include <iostream>
#include <vector>
using namespace std;

double perform_op(double lhv, char ch, double rhv)
{
    switch (ch)
    {
        case '+':
        return (lhv+rhv);
        break;

        case '-':
        return (lhv-rhv);
        break;

        case '*':
        return(lhv*rhv);
        break;

        case '/':
        return(lhv/rhv);
        break;

        case '^':
        double result = 1;
        for(int i=0; i<rhv; i++)
        {
            result = result*lhv;
        }
        return result;
        break;

    }
    return 0;
}

int main()
{
    while (true)
    {
    double lhv=0, rhv=0;
    char ch;
    cout << "> ";
    cin >> lhv >> ch >> rhv;
    cout << perform_op(lhv, ch, rhv) << endl;
    }

    return 0;
}