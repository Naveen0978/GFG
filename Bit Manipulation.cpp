class Solution {
  public:
    
    void Get(int n,int i)
    {   bool ans = 0;
        n = n>>i;
        if(n&1 == 1)
            ans = 1;
        cout<<ans<<" ";
    }
    void Set(int n,int m)
    {
        cout<<(n|m)<<" ";
    }
    void Clear(int n,int m)
    {
        cout<<(n & (~m));
    }
    void bitManipulation(int num, int i) {
        // your code here
        int mask = 1<<(i-1);
        Get(num,i-1);
        Set(num,mask);
        Clear(num,mask);
        
    }
};
