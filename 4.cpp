class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(); int n2 = nums2.size();
        int N = n1 + n2;
        bool odd = N % 2;
        int lo = min(n1 > 0 ? nums1[0] : INT_MAX, n2 > 0 ? nums2[0] : INT_MAX);
        int hi = max(n1 > 0 ? nums1[nums1.size()-1] : INT_MIN, n2 > 0 ? nums2[nums2.size()-1] : INT_MIN);

        double ans = lo; // for odd #

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2; // this is our test median

            int lt = lower_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
            int ltoe = upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
            int val = INT_MIN; if(lt > 0) val = nums1[lt-1];


            int lt2 = lower_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
            lt += lt2;
            ltoe += upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
            if(lt2 > 0) val = max(val, nums2[lt2-1]);

            if(lt <= N/2 && ltoe > N/2){
                if(odd || lt < N/2) ans = mid;
                else ans = mid/2.0 + val/2.0;
                break;
            } else if(lt > N/2){
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        return ans;
    }
};
