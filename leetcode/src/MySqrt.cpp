#include "def.h"
class Solution {
public:
    int mySqrt(int x) {
    	if (x == 0)
    		return 0;
    	double target = x;
    	const int MAX_INT = 2147483647;
        double low = 1;
        double high = MAX_INT - low;
        double mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2.0;
            //cout << mid << " " << low << " " << high << endl;
        	if (fabs(target / mid - mid) < 1e-6)
        	{
        		break;
        	}
        	else if (target / mid < mid)
        	{
        		high = mid;
        	}
        	else
        	{
        		low = mid;
        	}
        }
        int y = floor(mid);
        int z = ceil(mid);
        if (y * y == x)
        	return y;
        else if (z * z == x)
        	return z;
        //cout << mid << endl;
        return mid;
    }
};
