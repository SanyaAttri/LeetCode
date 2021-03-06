
//Accepted	228 ms	cpp
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        map<string,int> M;
        for(size_t i = 0;i < strs.size();i++)
        {
            string str = strs[i];
            sort(str.begin(),str.end());

            if(M.find(str) == M.end())
                M[str] = i;
            else
            {
                if(M[str] != -1)
                    ans.push_back(strs[M[str]]);
                ans.push_back(strs[i]);
                M[str] = -1;
            }
        }
        return ans;
    }
};
