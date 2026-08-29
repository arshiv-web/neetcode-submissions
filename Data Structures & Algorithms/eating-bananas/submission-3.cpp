class Solution {
public:
    int check(vector<int>& piles, int h, int l, int r) {
        if(l >= r) return l;
        int mid = l + (r - l)/2;
        int totalTime = 0;
        for(int i = 0; i < piles.size(); i++) {
            totalTime += (piles[i]%mid == 0) ? piles[i]/mid : (piles[i]/mid) + 1;
        }
        if(totalTime <= h) {
            return check(piles, h, l, mid);
        } else {
            return check(piles, h, mid+1, r);
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = piles[0];
        for(int i = 0; i < piles.size(); i++) {
            r = max(r, piles[i]);
        }
        return check(piles, h, l, r);
    }
};
