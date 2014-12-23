class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size() < 1) {
            return -1;
        }
        int start = 0, end = num.size() - 1, mid = 0;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(num[end] >= num[start]) {
                return num[start];
            }
            else {
                if (num[mid] > num[start]) {
                    start = mid;
                }
                else if (num[mid] == num[start]) {
                    start = mid + 1;
                }
                else {
                    end = mid ;
                }
            }
        }
        return num[start];
    }
};