class MedianFinder {
   public:
    priority_queue<int> large;
    priority_queue<int, vector<int>, greater<int>> small;

    MedianFinder() {}

    void addNum(int num) {
        if (large.empty() || num <= large.top()) {
            large.push(num);
        } else {
            small.push(num);
        }

        if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        } else if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
    }

    double findMedian() {
        if (large.size() == small.size()) {
            return (large.top() + small.top()) / 2.0;
        }

        return (large.size() > small.size()) ? large.top() : small.top();
    }
};