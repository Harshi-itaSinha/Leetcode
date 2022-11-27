class Solution {
public:
    int pivotInteger(int n) {
        
        int f=-1;
        for(int i=1;i<=n;i++)
        {
            int s1 = (i*(i+1))/2;
            int s2 = (n*(n+1))/2;
            s2 =s2-s1+i;
            if(s1==s2)
            {
                f=i;
                break;
            }
        }
        
       
        return f;
        
    }
};