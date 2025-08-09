#include <iostream>
#include <vector>
using namespace std;

string str;
bool simple = true; //Whether the operation being performed is simple like +-*/ or complex like sqrt, sin etc.
double input=0;

double perform_op(double lhv, char ch, double rhv) //As the name of the function suggests, it takes a left hand value
                                                   // a character and a right hand value and returns the calculated answer
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

double advanced_ops()
{
    if (str == "sqrt")
    {
        long double left = 0, right = input, ans = 0;
        while (left <= right)
        {
            long double mid = left + (right - left) / 2;  //Used binary search for square root
            if (mid * mid <= input)
            {
                ans = mid;
                left = mid + 0.0001;
            }
            else
            {
                right = mid - 0.0001;
            }
        }
        ans *= 100;              //Rounding off to 2 decimal places because JEE mai utna hi required hota hai
        double floor = int(ans);
        if ((ans - floor) >= 0.5)
            floor += 1;
        else
            floor -= 1;
        return floor/100;
    }
    return 0;
}

void take_input(vector<double> &nums, vector<char> &ops)
{
    char op;
    double num;
    while (cin >> num >> op)
    {
        simple = true;
        nums.push_back(num); // pushing back numbers to nums
        if (op == '=')
            break;         // If an = is detected then stop taking input
        ops.push_back(op); // Adding operators to op (= will not be added)
    }
    if (!cin) //Different method for inputs like sqrt, sin etc.
    {
        simple = false;
        cin.clear();        //operation in being stored in str and numerical value in input
        cin >> str >> input;
    }
}

double deal_with_vectors(vector<double> nums,vector<char> ops)
{
    int size = nums.size();
    double result;

    for (int i = 1; i < size; i++)
    {
        result = perform_op(nums[0], ops[0], nums[1]); //ONe by one passing values to perform_op function and also removing those values then
        nums.erase(nums.begin() + 1);
        nums[0]=result; // Adding result as the last value for further calculations on it
        ops.erase(ops.begin()+0); // Removing the operator we are already done with
    }
    return result;
}

int main()
{
    while (true)
    {
        vector<double> nums = {}; //My idea here to take input, specially for multiple numeriacals and operations
        vector<char> ops = {}; //was to store all numericals in oone vector named nums and operators in vector named ops

        cout << ">"; // printing my prompt
        take_input(nums, ops);
        if (simple == true) //If operation simple hai
        {
            double result = deal_with_vectors(nums, ops);
            cout << result << endl;
        }
        else 
        {
            double result = advanced_ops();
            cout << result << endl;
        }

        // Adding equals to at the end is necessary
        //Operation are performed from right to left

    }

    return 0;
}