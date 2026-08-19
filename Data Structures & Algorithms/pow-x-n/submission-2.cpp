class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        if(n < 0) {
            if(n==INT_MIN) {
                return (1 / myPow(x, INT_MAX-1));
            } else {
                return (1 / myPow(x, n*-1));
            }
        }

        if(x == 1) return 1;
        if(x == -1) return n%2 == 0 ? 1 : -1;


        if(n%2 == 0) {
            double left = myPow(x, n/2);
            return left * left;
        }

        double left = myPow(x, (n-1)/2);
        return left * left * x;
    }
};
