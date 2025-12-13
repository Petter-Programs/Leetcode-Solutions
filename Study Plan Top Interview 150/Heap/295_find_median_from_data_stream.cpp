class MedianFinder {
private:
    std::priority_queue<int> left_side; // max heap
    std::priority_queue<int, vector<int>, greater<int>> right_side; // min heap
public:
    MedianFinder() {
        // two heaps
        // left side right side

        // left side is a max heap
        // right side is a min heap
        // keep them balanced within 1 element

        // at any one time, the median is either the mean of both parents
        // or the top in the side with 1 more element
    }
    
    void addNum(int num) {
        if(left_side.empty() || left_side.top()>=num)
        {
            left_side.push(num);
        }
        else
        {
            right_side.push(num);
        }

        if(left_side.size()>right_side.size()+1)
        {
            int elem = left_side.top();
            left_side.pop();
            right_side.push(elem);
        }

        else if(right_side.size()>left_side.size()+1)
        {
            int elem = right_side.top();
            right_side.pop();
            left_side.push(elem);
        }
    }
    
    double findMedian() 
    {
        // the sum of any 2 same numbers is always even
        if(right_side.size() == left_side.size())   
            return (left_side.top() + right_side.top())/2.0;

        // must be odd because we keep them 1 element apart and they are not the same
        if(left_side.size()>right_side.size())
            return left_side.top();
        
        return right_side.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */