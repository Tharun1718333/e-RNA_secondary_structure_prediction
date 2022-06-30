#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string input;
    cin >> input;
    int len = input.length();
    vector<int> input_modifed(len + 1, 0);
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
    vector<vector<int>> ans(len + 1, vector<int>(len + 1, 0));
    for (int k = 5; k <= len; k++)
    {
        for (int i = 1; i <= len - k; i++)
        {
            int j = i + k;
            ans[i][j] = ans[i][j - 1];
            for (int t = i; t <= j - 5; t++)
            {
                // cout << t << j << endl;
                if (input_modifed[t] + input_modifed[j] == 7)
                {
                    ans[i][j] = max(ans[i][j], 1 + ans[i][t - 1] + ans[t + 1][j - 1]);
                }
            }
        }
    }
    for (int i = 0; i < len + 1; i++)
    {
        for (int j = 0; j < len + 1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}