#include <bits/stdc++.h>
using namespace std;
void mergeArray(vector<int>& arr, int low, int mid, int high, int &comp, int &inv)
{
    int i = low;
    int j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= high)
    {
        comp++;
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            inv += (mid - i + 1);
            j++;
        }
    }
    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = 0; k < temp.size(); k++)
    {
        arr[low + k] = temp[k];
    }
}
void mergeSort(vector<int>& arr, int low, int high, int &comp, int &inv)
{
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid, comp, inv);
    mergeSort(arr, mid + 1, high, comp, inv);

    mergeArray(arr, low, mid, high, comp, inv);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int comparisons = 0;
        int inversions = 0;
        mergeSort(arr, 0, n - 1, comparisons, inversions);
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        cout << "comparisons = " << comparisons << endl;
        cout << "inversions = " << inversions << endl;
    }
    return 0;
}