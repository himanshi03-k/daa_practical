#include <iostream>
#include <vector>
using namespace std;
bool modifiedJumpSearch(const vector<int>& arr, int key, int& comparisons) {
    int n = arr.size();
    comparisons = 0;
    int i = 0;
    // Jump search on indexes 0,2,4,6...
    while (i < n) {
        comparisons++;
        if (arr[i] == key)
            return true;
        if (arr[i] > key)
            break;
        i += 2;
    }
    // Linear search in the block
    int start = i - 2;
    if (start < 0)
        start = 0;
    for (int j = start; j <= start + 1 && j < n; j++) {
        comparisons++;
        if (arr[j] == key)
            return true;
    }
    return false;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int key;
        cin >> key;
        int comparisons = 0;
        bool found = modifiedJumpSearch(arr, key, comparisons);
        if (found)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }
    return 0;
}