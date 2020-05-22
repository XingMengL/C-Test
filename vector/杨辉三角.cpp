class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv(numRows);
        for(size_t i = 0; i < vv.size(); i++)
        {
            //ÐÐ  
            vv[i].resize(i+1,1);
            //ÁÐ
            for(size_t j = 1; j < vv[i].size() - 1; j++ )
            {
                vv[i][j] = vv[i-1][j]+vv[i-1][j-1];
            }
        }
        return vv;
    }
};
