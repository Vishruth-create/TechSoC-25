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

void take_input(vector<double> &nums, vector<char> &ops)
{
    double num;
    char op;
    while(cin >> num >> op)
        {
            nums.push_back(num); //pushing back numbers to nums
            if(op=='=') break; // If an = is detected then stop taking input
            ops.push_back(op); //Adding operators to op (= will not be added)
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
        double result = deal_with_vectors(nums, ops);

        cout << result << endl; // Adding equals to at the end is necessary
        //Operation are performed from right to left

    }

    return 0;
}