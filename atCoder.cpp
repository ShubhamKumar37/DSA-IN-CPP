#include <iostream>
#include <vector>
using namespace std;

int getMaximumPartitions(const vector<int>& performance) {
    int n = performance.size();
    int partitions = 0;
    int currentAND = -1;  // Start with all bits set (binary 111...111)

    for (int i = 0; i < n; ++i) {
        // Cumulative AND with the current element
        currentAND &= performance[i];

        // If currentAND becomes 0, mark a partition here
        if (currentAND == 0) {
            // Update the print statement to show where the partition ends
            cout << "Partition found ending at index " << i << " with performance value = " << performance[i] << endl;
            partitions++;       // Partition found, increase count
            currentAND = -1;    // Reset currentAND to start a new partition
        }
    }

    // Ensure the last partition is counted if there are remaining elements
    if (currentAND != -1) {
        partitions++;  // Count the last partition even if AND isn't 0
    }

    return partitions;
}

int main() {
    int n;
    cout << "Enter number of components: ";
    cin >> n;

    vector<int> performance(n);
    cout << "Enter performance values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> performance[i];
    }

    int maxPartitions = getMaximumPartitions(performance);
    cout << "Maximum number of partitions: " << maxPartitions << endl;

    return 0;
}
