#include <bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int>& arr, int &comp, int &shift) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            comp++;               
            arr[j + 1] = arr[j];  
            shift++;              
            j--;
        }
        arr[j + 1] = key;
        shift++;
        if (j >= 0)
            comp++;
    }
}
int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int comp = 0, shift = 0;
        InsertionSort(arr, comp, shift);
        for (auto it : arr) {
            cout << it << " ";
        }
        cout << endl;
        cout << "Comparisons: " << comp << endl;
        cout << "Shifts: " << shift << endl;
    }
    return 0;
}