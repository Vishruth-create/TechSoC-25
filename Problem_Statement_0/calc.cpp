#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    while (true)
    {
        vector<double> nums = {}; //My idea here to take input, specially for multiple numeriacals and operations
        vector<char> ops = {}; //was to store all numericals in oone vector named nums and operators in vector named ops
        double num;
        char op;

        cout << ">"; // printing my prompt
        while(cin >> num >> op)
        {
            nums.push_back(num); //Adding numbers to nums
            if(op=='=') break; // If an = is detected then stop taking input
            ops.push_back(op); //Adding operators to op (= will not be added)
        }

        int size = nums.size();
        double result;

        for (int i = 1; i < size; i++)
        {
            result = perform_op(nums[nums.size()-2], ops[ops.size()-1], nums[nums.size()-1]); //ONe by one passing values to perform_op function and also removing those values then
            nums.pop_back();
            nums.pop_back();
            nums.push_back(result); // Adding result as the last value for further calculations on it
            ops.pop_back(); // Removing the operator we are already done with
        }

        cout << result << endl; // Adding equals to at the end is necessary
        //Operation are performed from right to left

    }

    return 0;
}