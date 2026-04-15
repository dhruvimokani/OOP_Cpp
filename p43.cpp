#include<iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter size of array 1: ";
    cin >> n;
    cout << "Enter size of array 2: ";
    cin >> m;

    int *arr1 = new int[n];
    int *arr2 = new int[m];

    cout << "Enter sorted elements of array 1:\n";
    for (int i = 0; i < n; i++) cin >> arr1[i];

    cout << "Enter sorted elements of array 2:\n";
    for (int i = 0; i < m; i++) cin >> arr2[i];

    int *merge = new int[n + m];

    int i = 0, j = 0, k = 0;
    int comparisons = 0, moves = 0;

    while (i < n && j < m) {
        comparisons++;
        if (arr1[i] < arr2[j]) {
            merge[k++] = arr1[i++];
        } else {
            merge[k++] = arr2[j++];
        }
        moves++;
    }

    while (i < n) {
        merge[k++] = arr1[i++];
        moves++;
    }

    while (j < m) {
        merge[k++] = arr2[j++];
        moves++;
    }

    cout << "\nMerged array: ";
    for (int x = 0; x < n + m; x++) {
        cout << merge[x] << " ";
    }

    int *uniqueArr = new int[n + m];
    int u = 0;
    uniqueArr[u++] = merge[0];

    for (int x = 1; x < n + m; x++) {
        if (merge[x] != merge[x - 1]) {
            uniqueArr[u++] = merge[x];
        }
    }

    cout << "\nAfter removing duplicates: ";
    for (int x = 0; x < u; x++) {
        cout << uniqueArr[x] << " ";
    }

   cout << "\nDescending order: ";
    for (int x = (n + m - 1); x >= 0; x--) {
        cout << merge[x] << " ";
    }

    cout << "\nComparisons: " << comparisons;
    cout << "\nMoves: " << moves << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] merge;
    delete[] uniqueArr;

    return 0;
}
