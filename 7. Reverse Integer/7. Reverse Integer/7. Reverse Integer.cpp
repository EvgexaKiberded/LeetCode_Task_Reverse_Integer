//Given a signed 32 - bit integer x, return x with its digits reversed.If reversing x causes the value to go outside the signed 32 - bit integer range[-231, 231 - 1], then return 0.
//
//Assume the environment does not allow you to store 64 - bit integers(signed or unsigned).
//
//Constraints : -231 <= x <= 231 - 1

#include <iostream>
#include <cmath>

class Solution {
public:
    static int reverse(int x) {
        int bit_depth = 0;
        return recursive_reversing_value(x, bit_depth);;
        
    }

    static int recursive_reversing_value(int value, int& bit_depth) {
        double resut_value = 0;
        double adding_value = 0;

        if (value / 10 != 0){
            adding_value = value % 10;
            value /= 10;
            resut_value = recursive_reversing_value(value, bit_depth);
        }
        else { // if(value /10 == 0)
            bit_depth = 1;
            resut_value = value % 10;
            return resut_value;
        }

        bit_depth *= 10;
        double result = resut_value + adding_value * bit_depth;
        if (result <= pow(-2, 31) ||  (pow(2, 31) - 1) <= result) {
            return 0;
        }
        return resut_value + adding_value * bit_depth;
    }
};

int main()
{
    
    std:: cout << Solution::reverse(1534236469) << '\n';
    std::cout << Solution::reverse(-123) << '\n';
    std::cout << Solution::reverse(1230678) << '\n';
    std::cout << Solution::reverse(5) << '\n';
    std::cout << Solution::reverse(0) << '\n';
}

