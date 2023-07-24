class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1 / x;
        } 

        double pow = 1;
        long num = labs(n);
        
        while (num) {
            if (num & 1) {
                pow = pow * x;
            }

            x *=x;
            num >>=1 ;

        }
        return pow;

    }
};