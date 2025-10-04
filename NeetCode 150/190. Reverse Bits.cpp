class Solution {
public:
    int reverseBits(int n) {
        int l=0, r=31;
        while(l < r) {
            if(((n >> l) & 1) != ((n >> r) & 1)) {
                n ^= (1 << l);
                n ^= (1 << r);
            }
            l++, r--;
        }
        return n;
    }
};
