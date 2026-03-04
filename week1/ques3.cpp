#include <iostream>
#include <vector>
using namespace std;

bool modifiedJumpSearch(const vector<int>& arr, int key, int& comparisons) {
    int n = arr.size();
    comparisons = 0;

    int i = 0;

    // Jumping at indices 0, 2, 4, 6 ...
    while (i < n) {
        comparisons++;

        if (arr[i] == key)
            return true;

        if (arr[i] > key)
            break;

        i += 2;
    }

    // Determine starting point for linear search
    int start = i - 2;
    if (start < 0)
        start = 0;

    // Linear search in identified interval
    for (int j = start; j < n && j <= i; j++) {
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
        for (int i = 0; i < n; i++)
            cin >> arr[i];

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