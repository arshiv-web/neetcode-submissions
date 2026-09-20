class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans{0};
        uint32_t i{0};
        while(i < 32){
            uint32_t digit{n & 1};
            n = n >> 1;
            ans = (ans << 1) + digit;
            i++;
        }
        return ans;
    }
};
