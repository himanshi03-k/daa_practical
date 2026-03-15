#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());  
    if(k > 0 && k <= arr.size())
        return arr[k-1];

    return INT_MIN;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int k;
        cin >> k;
        int result = kthSmallest(arr, k);
        if(result == INT_MIN)
            cout << "not present";
        else
            cout << result;
        cout << endl;
    }
    return 0;
}