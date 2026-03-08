#include <bits/stdc++.h>
using namespace std;
void BinarySearch(vector<int> arr, int key) {
    int cnt = 0;
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        cnt++;
        if (arr[mid] == key) {
            cout << "Present " << cnt << endl;
            return;
        }
        else if (arr[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << "Not Present " << cnt << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, key;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> key;
        BinarySearch(arr, key);
    }
    return 0;
}