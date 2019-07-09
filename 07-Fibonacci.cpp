class Solution {
   public:
    int Fibonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        int prePre = 0;
        int pre = 1;
        int result = 0;
        for (int i = 2; i <= n; i++) {
            result = prePre + pre;
            prePre = pre;
            pre = result;
        }
        return result;
    }
};