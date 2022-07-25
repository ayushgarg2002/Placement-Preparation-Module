class Solution {
public:
   vector<double> findCenter(vector<int> a, vector<int> b, int r){
        int dSqr=(a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
        double d=sqrt(dSqr);
        if (dSqr<=4*r*r) {
            double ex=(double)(b[0]-a[0])/d;
            double ey=(double)(b[1]-a[1])/d;
            double x=d/2;
            double y=sqrt(r*r-x*x);
            return vector<double>{a[0]+x*ex-y*ey, a[1]+x*ey+y*ex};
        }
        return vector<double>{0.0,0.0};
    }
    bool insideCircle(vector<double> center, int r, vector<int> a){
        return (center[0]-a[0])*(center[0]-a[0])+(center[1]-a[1])*(center[1]-a[1]) <= r*r + 1e-9;
    }
    int numPoints(vector<vector<int>>& points, int r) {
        int n=points.size(),ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                vector<double> center=findCenter(points[i],points[j],r);
                int cnt=0;
                for(int k=0;k<n;k++){
                    if(insideCircle(center,r,points[k])){
                        cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};