class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
    int num = 0;
    int two_count = n / 2;
    
    for (int i = 0; i < two_count; i++) {
        num = num * 2;//finding the product of all the multiples of 2
    }

    int j = 5;
    while (j <= n) {
        int temp = j; // Store the value of j in a temporary variable
        while (temp % 5 == 0) {
            num = num * temp;  //multiply the multiples of 5 only
            if (num % 10 == 0) {
                count++;
                num = num / 10;
            }
            temp = temp / 5;
        }
        j = j + 5;
    }

    return count;
    }
};

/*
Optimised Code 

 int count = 0;
        
        while (n > 0) {
            n /= 5; // Count how many multiples of 5 are in n
            count += n;
        }
        
        return count;
    }


*/