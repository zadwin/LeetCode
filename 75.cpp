#include "header.h"
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.length() > s.length())
            return "";
        unordered_map<char, int> t_map, temp_map;
        for (int i = 0; i < t.length(); i++)
        {
            t_map[t[i]] += 1;
        }
        temp_map = t_map;
        int pre = 0, next = -1;
        int count = 0, low = 0, high = INT_MAX;
        int pre_next = pre + 1;
        bool flag = true;
        int count1 = 0;
        while (pre < s.length())
        {
            if (temp_map.count(s[pre]))
            {
                count++;
                count1++;
                temp_map[s[pre]] -= 1;
                next = pre + 1;
                while (count != t.length() && next < s.length())
                {
                    if (temp_map.count(s[next]) && count1 == 1)
                    {
                        flag = false;
                        pre_next = next;
                        count1++;
                    }
                    // 如何去记录t中的元素出现在了s中，且无重复。
                    if (temp_map.count(s[next]) && temp_map[s[next]] >= 1)
                    {
                        temp_map[s[next]] -= 1;
                        count++;
                    }
                    next++;
                }
                if (count == t.length() && high - low > (next - pre))
                {
                    low = pre;
                    high = next;
                }
                count1 = 0;
                temp_map = t_map;
            }
            if (!flag)
            {
                pre = pre_next;
                flag = true;
            }
            else
            {
                pre++;
                flag = true;
            }
            // pre++;
            count = 0;
        }
        if (high == INT_MAX)
            return "";
        // 返回字符串
        return s.substr(low, high - low); //之前最大的问题是处在提取字符串上面，因为提取第二个参数是字符的个数。
    }
};
int main(){
    Solution s;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    string s3 = s.minWindow(s1,s2);
    cout << s3 << endl;
}