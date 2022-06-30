#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ///
    /// ......taking the input.....
    ///
    string input;
    cin >> input;
    ///
    /// storing the size in len
    ///
    int len = input.length();
    ///
    /// here we declare size as (len+1) to make everything 1-indexed
    ///
    vector<int> input_modifed(len + 1, 0);
    ///
    /// to identify matching pairs we construct a vector where we initilaze A as 3 and U as 4, C as 2 and G as %
    ///  we do this so that if a pair matches their sum is 7
    ///
    for (int i = 0; i < len; i++)
    {
        if (input[i] == 'A')
        {
            input_modifed[i + 1] = 3;
        }
        if (input[i] == 'U')
        {
            input_modifed[i + 1] = 4;
        }
        if (input[i] == 'C')
        {
            input_modifed[i + 1] = 2;
        }
        if (input[i] == 'G')
        {
            input_modifed[i + 1] = 5;
        }
    }
    ///
    /// itreating through the array
    /// the first for represents the window length
    /// the second for represents the start of the array
    /// the third for iterates through the possible window created by first and second for loops in search of new pairs
    ///
    vector<vector<int>> ans(len + 1, vector<int>(len + 1, 0));
    for (int k = 6; k <= len; k++)
    {
        for (int i = 1; i <= (len - k + 1); i++)
        {
            int j = i + k - 1;
            /// if no new pairs are found we reuse the old pairs
            ans[i][j] = ans[i][j - 1];
            for (int t = i; t <= j - 5; t++)
            {
                if ((input_modifed[t] + input_modifed[j]) == 7)
                {
                    ans[i][j] = max(ans[i][j], 1 + ans[i][t - 1] + ans[t + 1][j - 1]);
                }
            }
        }
    }
    cout << "NUMBER OF PAIRS POSSIBLE:" << ans[1][len] << endl;

    vector<vector<vector<pair<int, int>>>> koh(len + 1);
    ///
    /// we declare a 3-d vector
    /// we iterate th same way we did for the top
    /// except we just dont add up the numbers we add the possible pairs in each respective tiles
    ///
    for (int i = 0; i < len + 1; i++)
    {
        ///
        /// declaring each element of the 3-d vector as a 2d-vector
        ///
        koh[i] = vector<vector<pair<int, int>>>(len + 1);
    }
    for (int k = 6; k <= len; k++)
    {
        for (int i = 1; i <= len - k + 1; i++)
        {
            int j = i + k - 1;
            if (ans[i][j] == ans[i][j - 1])
            {
                koh[i][j] = koh[i][j - 1];
            }
            else
            {
                for (int t = i; t <= j - 5; t++)
                {
                    if ((ans[i][j] == (1 + ans[i][t - 1] + ans[t + 1][j - 1])) && (input_modifed[t] + input_modifed[j] == 7))
                    {
                        koh[i][j] = koh[i][t - 1];
                        koh[i][j].insert(koh[i][j].end(), koh[t + 1][j - 1].begin(), koh[t + 1][j - 1].end());
                        koh[i][j].push_back(make_pair(t, j));
                        ///
                        /// break because one possibility is enough
                        ///
                        break;
                    }
                }
            }
        }
    }
    cout << "Indexes of the pairs" << endl;
    for (int i = 0; i < koh[1][len].size(); i++)
    {
        cout << koh[1][len][i].first << "  " << koh[1][len][i].second << endl;
    }
}