// Link: https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

class Solution {
    public:
      // Function to check if Kth bit is set or not.
      bool checkKthBit(int n, int k) {
          // Your code here
          // It can be a one liner logic!! Think of it!!
          return (n & (1 << k));
      }
  };