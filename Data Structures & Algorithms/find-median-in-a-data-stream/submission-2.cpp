class MedianFinder {
private:
    multiset<int> lset;
    multiset<int> rset;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(lset.empty() || num < *lset.rbegin()){
            lset.insert(num);
        } else {
            rset.insert(num);
        }

        if(lset.size() > rset.size() + 1){
            rset.insert(*lset.rbegin());
            lset.erase(prev(lset.end()));
        } else if(rset.size() > lset.size()) {
            lset.insert(*rset.begin());
            rset.erase(rset.begin());
        }
    }
    
    double findMedian() {
        if(lset.size() > rset.size()) {
            return *lset.rbegin()/1.0; 
        }
        return (*lset.rbegin() + *rset.begin()) / 2.0;
    }
};
