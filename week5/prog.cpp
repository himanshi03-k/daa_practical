#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int count[26] = {0};
        for(char ch : str)
        {
            count[ch - 'a']++;
        }
        int maxFreq = 0;
        char result;
        for(int i = 0; i < 26; i++)
        {
            if(count[i] > maxFreq)
            {
                maxFreq = count[i];
                result = 'a' + i;
            }
        }
        if(maxFreq <= 1)
        {
            cout << "No Duplicates Present";
        }
        else
        {
            cout << result << "-" << maxFreq;
        }
        cout << endl;
    }
    return 0;
}