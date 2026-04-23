class Solution {
public:

    // This function finds the exact digit when:
    // - n  = position of digit inside the current k-digit range
    // - k  = number of digits each number has in this range
    // - start = number just BEFORE the beginning of the range
    int find_it(int n, int k, long start) {

        int d = k;          // store original digit length (used later)
        k--;                // reduce k for range calculations (10^(k))

        // This loop narrows down the exact number inside the k-digit range
        // Idea: skip chunks of numbers until the digit position fits
        while (n > d) {

            // digits contributed by one full sub-range
            // pow(10, k-1) numbers × d digits each
            if (n > pow(10, k-1) * d) {
                n -= pow(10, k-1) * d;   // skip this sub-range
                start += pow(10, k-1);  // move start forward
            }
            else {
                k--;    // reduce range size when n fits in smaller block
            }
        }

        // Now we are at the exact number containing the nth digit
        start++;

        // Extract digits of the number into a vector
        vector<int> v(d);
        for (int i = d - 1; i >= 0; i--) {
            v[i] = start % 10;   // take last digit
            start /= 10;         // remove last digit
        }

        // return the required digit (1-based indexing)
        return v[n - 1];
    }

    int findNthDigit(int n) {

        // Base case: first 9 digits are 1–9
        if (n <= 9) return n;

        int k = 1;          // number of digits per number in current range
        long lo, hi;
        long digit_sum = 0; // total digits contributed by the current range

        // Find the digit-length range where nth digit lies
        while (true) {

            lo = pow(10, k - 1); // smallest k-digit number
            hi = pow(10, k);     // first (k+1)-digit number

            long numbers = hi - lo;   // count of k-digit numbers
            digit_sum = numbers * k; // total digits in this range

            // if nth digit lies in this range, stop
            if (n <= digit_sum) break;

            // otherwise skip this range
            n -= digit_sum;
            k++;
        }

        // Now n lies inside the k-digit range
        // Call helper to locate exact digit
        return find_it(n, k, pow(10, k - 1) - 1);
    }
};