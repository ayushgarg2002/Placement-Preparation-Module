class Solution {
public:
    bool static sortcol(const vector<int>&v1, const vector<int>&v2)
    {
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int n= boxTypes.size();
        int m= boxTypes[0].size();
        //sort(boxTypes.begin(), boxTypes.end(), sortcol);
        sort(boxTypes.begin(), boxTypes.end(), sortcol);
        int sum=0, cnt=0;
        for(int i=0;i<n;i++){
                cnt+= boxTypes[i][0];
                if(cnt<=truckSize)
                {
                    sum+= (boxTypes[i][0]*boxTypes[i][1]);
                }
                else{
                    int k= truckSize- cnt+ boxTypes[i][0];
                    int val= k* boxTypes[i][1];
                    sum+=val;
                    break;          
                }
        }
       
      
        return sum;
    }
};