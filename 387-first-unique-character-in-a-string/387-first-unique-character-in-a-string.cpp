class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]-'a']++;
        }
        for(int i=0; i<s.size(); i++){
            if(mpp[s[i]-'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};


// class Solution {
// public:
//     int firstUniqChar(string s) {
//         map<char, int> mpp;
//         for(int i=0; i<s.size(); i++){
//             mpp[s[i]-'a']++;
//         }
//        int cnt=0;
//          map<char, int>:: iterator it;
//         int k=0;
//          for(it= mpp.begin(); it!=mpp.end(); it++)
//          {
//              if(mpp[s[k]-'a']==1)
//                  return k;
//              cnt++;
//                     k++;
//          }
    
       
//         return -1;
//     }
// };