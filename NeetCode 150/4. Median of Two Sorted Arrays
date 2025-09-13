class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int n = nums1.size(), m = nums2.size(), eleIdx = (n + m) / 2 - ((n + m) % 2 == 0);
        bool isEven = (n + m) & 1 ^ 1;
        if(n == 0 || (n > 0 &&  m > 0 && nums2[0] < nums1[0])) {
            swap(nums1, nums2);
            swap(n, m);
        }

        int l=0, r = min(n - 1, eleIdx), ans1, ans2;
        while(l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = eleIdx - mid1 -1;

            if(mid2 == -1) {
                ans1 = mid1, ans2 = mid2;
                break;
            }
            if((mid2 >= m) || (mid1 + 1 < n && nums1[mid1 + 1] < nums2[mid2])) {
                l = mid1 + 1;
            } else if(mid2 + 1 < m && nums2[mid2 + 1] < nums1[mid1]) {
                r = mid1 - 1;
            } else {
                ans1 = mid1, ans2 = mid2;
                break;
            }
        }

        double cur = max((double) nums1[ans1], ans2 == -1 ? -1e7 : (double) nums2[ans2]);
        if(!isEven) {
            return cur;
        } else {
            double nxt = min(ans1 + 1 >= n ? 1e7 : nums1[ans1 + 1], ans2 + 1 >= m ? 1e7 : nums2[ans2 + 1]);
            return (cur + nxt) / 2;
        }
    }
};
