class Solution {
   public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> B(len);
        for (int i = 0; i < len; i++) {
            B[i] = 1;
        }
        int ret = 1;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                B[i] *= (i == j ? 1 : A[i]);
            }
        }
        return B;
    }
};