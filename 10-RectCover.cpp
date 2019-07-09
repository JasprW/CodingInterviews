class Solution {
   public:
    int rectCover(int number) {
        if (number <= 2) {
            return number;
        } else {
            int pre = 2;
            int prePre = 1;
            int result = 0;
            for (int i = 3; i <= number; i++) {
                result = pre + prePre;
                prePre = pre;
                pre = result;
            }
            return result;
        }
    }
};