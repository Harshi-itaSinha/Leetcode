class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int n= t.length();
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            q.push(t[i]);
        }
        
        n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(!q.empty())
            {
                if(q.front()==s[i])
                    q.pop();
            }
        }
        
        int ans = q.size();
        return ans;
    }
};