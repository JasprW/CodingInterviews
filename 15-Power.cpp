#include <math.h>
class Solution {
public:
    double Power(double base, int exponent) {
        double result = 1.0;
        long long p = abs((long long)exponent);
        while (p) {
            if(p & 1) {
                result *= base;
            }
            base *= base;
            p = p >> 1;
        }
        return exponent < 0 ? 1/result : result;
    }
};