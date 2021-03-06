
//	Accepted	168 ms	cpp
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if(num.size() < 3) return ans;
        sort(num.begin(),num.end());
        int len = num.size();
        int fir,sec,sum;
        for(int i=0;i<len;i++)
        {
            if(i!=0 && num[i] == num[i-1]) continue;

            fir = i+1;
            sec = len-1;
            while(fir < sec)
            {
                sum = num[i] + num[fir] + num[sec];
                if(sum < 0) fir++;
                else if(sum > 0) sec--;
                else if(fir != i+1 && num[fir] == num[fir-1]) fir++;
                else if(sec != len-1 && num[sec] == num[sec+1]) sec--;
                else
                {
                    vector<int> tmp(3);
                    tmp[0] = num[i],tmp[1] = num[fir],tmp[2] = num[sec];
                    ans.push_back(tmp);
                    fir++,sec--;
                }
            }
        }
        return ans;
    }
};


