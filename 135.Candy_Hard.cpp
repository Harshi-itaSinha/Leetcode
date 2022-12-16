class Solution {
public:


    int candy(vector<int>& ratings) {

        int n= ratings.size();

        vector<pair<int,int>>v;
        vector<int>candy(n,-1);


       

        for(int i=0;i<n;i++)
        {
            v.push_back({ratings[i],i});
        }


        sort(v.begin(),v.end());

        if(n==1)
        return 1;

        for(int i=0;i<n;i++)
        {
            int ind =v[i].second;

      


            if(ind==0)
            {
                if(candy[ind+1]==-1) 
                candy[ind]=1;
                else if(ratings[ind]==ratings[ind+1]) 
                candy[ind]=1;
                else
                candy[ind]=candy[ind+1]+1;

            }
            else if(ind == n-1)
            {
                if(candy[ind-1]==-1) 
                candy[ind]=1;
                else if(ratings[ind]==ratings[ind-1])
                candy[ind]=1;
                else
                candy[ind]=candy[ind-1]+1;


            }
            else
            {   
               
                int high = max(candy[ind+1],candy[ind-1]);
                if(high == -1)
                candy[ind]=1;
                else if(ratings[ind+1]==ratings[ind] && ratings[ind]==ratings[ind-1])  
                candy[ind]=1;
                else if(candy[ind+1]==-1 && ratings[ind-1]==ratings[ind])
                candy[ind]=1;
                else if(candy[ind-1]==-1 && ratings[ind+1]==ratings[ind])
                candy[ind]=1;
                else if(ratings[ind+1]==ratings[ind])
                candy[ind]=candy[ind-1]+1;
                else if(ratings[ind-1]==ratings[ind])
                candy[ind]=candy[ind+1]+1;
                else 
                candy[ind]=high+1;

            }

        }
        cout<<endl;


        long long sum=0;

        for(int i=0;i<n;i++)
        sum+=candy[i];



        for(int i=0;i<n;i++)
        cout<<candy[i]<<" ";


        return sum;




        
    }
};