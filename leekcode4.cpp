#include<iostream>
#include<vector>
#include<algorithm>
#define LOCAL

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        int SIZE = n + m;
        int flag = SIZE%2 == 0 ? true : false;
        int even,odd;
        int i = 0,j = 0;
        for(int k = 0;k < SIZE/2+1;k++)
        {
            even = odd;
            if(i == n) { //如果nums1到最后的话那么就弄nums2
                odd = nums2[j++];
                continue;
            }
            else if(j == m) {
                odd = nums1[i++];
                continue;
            }
            if(nums1[i] < nums2[j]) odd = nums1[i++];
            else odd = nums2[j++];
        }
        if(flag) return (odd+even)/2.0;
        else return odd*1.0;
    }
};

int main()
{
#ifdef LOCAL
    freopen("../VScode/in.txt","r",stdin);
    freopen("../VScode/out.txt","w",stdout);
#endif
    int n,m;
    while(cin >> n >> m)
    {
        vector<int> num1,num2;
        int temp;
        for(int i = 0;i < n;i++)
        {
            cin >> temp;
            num1.push_back(temp);
        }
        for(int i = 0;i < m;i++)
        {
            cin >> temp;
            num2.push_back(temp);
        }
        Solution s;
        cout << s.findMedianSortedArrays(num1,num2) << endl;
    }
    
    return 0;
}