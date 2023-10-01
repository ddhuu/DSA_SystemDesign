/*
 Find square root of given number without sqrt() function
 ----------------------------------------------------------------
 Time : O(logn)
*/




#include <iostream>


int mySqrt(int x) 
   {
    if ( x==0)
        {
            return x;
        }
        int start = 1;
        int end = x;
        long mid;
        int result = -1;
        while ( start <= end )
        {
            mid = start + (end- start) /2 ;
            if ( mid*mid == x)
                {
                    result = mid;
                    return result;
                }
            if ( mid*mid >= x)
            {
                end = mid-1;
            }
            else
            {
                start = mid +1 ;
            }
        }
        return end;
    }
   
int main() {
    int num = 16;
    int sqrtResult = mySqrt(num);
    
    std::cout << "Square root of " << num << " is: " << sqrtResult << std::endl;

    return 0;
}
