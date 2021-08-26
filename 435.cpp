#include "header.h"

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int> > &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        return 0;
    }
};
int main()
{
    Solution s;
    vector<vector<int> > Matrix(4, vector<int>(2));
    for (size_t i = 0; i < Matrix.size(); i++)
    {
        cin >> Matrix[i][0] >> Matrix[i][1];
    }
    cout << endl <<  "####### " << endl;
    for (size_t i = 0; i < Matrix.size(); i++)
    {
        cout << Matrix[i][0] << " " << Matrix[i][1] <<endl;
    }
    s.eraseOverlapIntervals(Matrix);
    cout << endl <<  "####### " << endl;
    for (size_t i = 0; i < Matrix.size(); i++)
    {
        cout << Matrix[i][0] << " " << Matrix[i][1] << endl;
    }
    return 1;
}