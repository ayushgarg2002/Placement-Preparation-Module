
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        vector<int> hor;
        vector<int> ver;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int n= horizontalCuts.size();
        int m= verticalCuts.size();
        for(int i=0;i<horizontalCuts.size(); i++)
        {
            if(i==0)
                hor.push_back(horizontalCuts[i]);
            else{
                int k= horizontalCuts[i] - horizontalCuts[i-1];
                hor.push_back(k);
            }
        }
        
        for(int i=0; i<verticalCuts.size(); i++)
        {
            if(i==0)
                ver.push_back(verticalCuts[i]);
            else{
                int k= verticalCuts[i]- verticalCuts[i-1];
                ver.push_back(k);
            }
        }
        hor.push_back(h-horizontalCuts[n-1]);
        ver.push_back(w-verticalCuts[m-1]);
        
        sort(hor.begin(), hor.end(), greater<int>());
        sort(ver.begin(), ver.end(), greater<int>());
         
        //long long ans = (hor[0]*ver[0])%100000007;
        return (1LL* hor[0]*ver[0])%1000000007;
    }
};