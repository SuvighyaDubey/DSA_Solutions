class Solution {
public:
    int pivotInteger(int n) {
        int xsq = ((n * n + n) / 2);
        int x = sqrt(xsq);
        if (x * x == xsq)
            return x;
        return -1;
    }
};
