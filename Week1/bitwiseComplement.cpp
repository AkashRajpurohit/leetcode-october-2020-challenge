class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        
        int bits = 0;
        int tmp = N;
        
        while(tmp > 0) {
            tmp >>= 1;
            bits++;
        }
        
        int maxNumberWithSameSetBits = pow(2, bits) - 1;
        
        return N ^ maxWithSameBits;
    }
};