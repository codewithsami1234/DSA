class Solution {
public:
  int countSoliders(const vector<int> &row ){
    int low = 0, high = row.size();
    while(low < high){
        int mid = (low + high)/2;
        if (row[mid] == 1){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    return low;
  }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> strength;
        for(int i = 0; i<mat.size(); ++i){
            int soliders = countSoliders(mat[i]);
            strength.push_back({soliders,i});
        }
        sort(strength.begin(), strength.end());
        vector<int>result;
        for(int i=0; i<k ; ++i){
            result.push_back(strength[i].second);
        }
        return result;
    }
};