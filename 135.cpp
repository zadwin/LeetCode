#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::max;
using std::min;
int candy(vector<int> &ratings)
{
    vector<int> index, row_ratings, candy;
    int i = 0, j = 0;
    for (i = 0; i < ratings.size(); i++)
    {
        index.push_back(i);
        row_ratings.push_back(ratings[i]);
        candy.push_back(0);
    }
    int temp, temp_index;
    for (i = 1; i < ratings.size(); i++)
    {
        temp = ratings[i]; // 这里是待插入的元素，哪里是待插入元素一定要清楚以及边界条件。
        temp_index = index[i];
        if (ratings[i] < ratings[i - 1])
        {
            for (j = i - 1; ratings[j] > temp && j >= 0; j--)
            {
                ratings[j + 1] = ratings[j];
                index[j + 1] = index[j];
            }
            ratings[j + 1] = temp;
            index[j + 1] = temp_index;
        }
    }
    // 如果是一个元素，则直接返回。
    if (index.size() == 1)
    {
        return 1;
    }
    // 经过上面的操作，已经得到了相应的有序下标数组，因此就可以按照贪婪策略去寻找了。
    // 经过上面的操作，已经得到了相应的有序下标数组，因此就可以按照贪婪策略去寻找了。
    // 一开始的时候没有理顺思路。这里最关键的就是理清什么起决定因素。
    // 1、位于两端的元素和中间元素的分别需要怎么处理。2、最关键就是处于中间的元素该如何处理，这里就比较关键，分别讨论正在访问的元素左右的元素是否已经被分配糖果。
    for (int k = 0; k < index.size(); k++)
    {
        temp_index = index[k];
        if (temp_index - 1 < 0)
        {
            if (row_ratings[temp_index] <= row_ratings[temp_index + 1])
            {
                candy[temp_index] = candy[temp_index + 1] + 1;
            }
            else
            {
                candy[temp_index] = candy[temp_index + 1] + 1;
            }
        }
        else if (temp_index + 1 >= index.size())
        {
            if (row_ratings[temp_index] <= row_ratings[temp_index - 1])
            {
                candy[temp_index] = 1;
            }
            else
            {
                candy[temp_index] = candy[temp_index - 1] + 1;
            }
        }
        else
        {
            if (row_ratings[temp_index] < row_ratings[temp_index - 1] && row_ratings[temp_index] <= row_ratings[temp_index + 1])
            {
                candy[temp_index] = 1;
            }
            else if (row_ratings[temp_index] >= row_ratings[temp_index - 1] && row_ratings[temp_index] <= row_ratings[temp_index + 1])
            {
                if(row_ratings[temp_index] == row_ratings[temp_index - 1])
                {
                    candy[temp_index] = 1;
                }else
                {
                    candy[temp_index] = candy[temp_index - 1] + 1;
                }
            }
            else if (row_ratings[temp_index] < row_ratings[temp_index - 1] && row_ratings[temp_index] > row_ratings[temp_index + 1])
            {
                candy[temp_index] = candy[temp_index + 1] + 1;
            }
            else if (row_ratings[temp_index] >= row_ratings[temp_index - 1] && row_ratings[temp_index] > row_ratings[temp_index + 1])
            {
                if (row_ratings[temp_index] == row_ratings[temp_index - 1])
                {
                    candy[temp_index] = candy[temp_index + 1] + 1;
                }else{
                    candy[temp_index] = max(candy[temp_index -1 ], candy[temp_index + 1]) + 1;
                }
            }
        }
    }
    int sum = 0;
    for (i = 0; i < candy.size(); i++)
    {
        cout << candy[i];
        sum = sum + candy[i];
    }
    cout << endl;
    return sum;
}
int main()
{
    vector<int> a;
    int c;
    for (size_t i = 0; i < 19; i++)
    {
        cin >> c;
        a.push_back(c);
    }
    cout << candy(a) << endl;
    return 0;
}
