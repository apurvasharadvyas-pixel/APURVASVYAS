#include <iostream>
using namespace std;

int main() {
    int process[] = {2500, 3700, 6100};
    int pageSize[] = {1024, 2048, 4096};

    for (int j = 0; j < 3; j++) {
        int totalAllocated = 0;
        int totalWasted = 0;

        cout << "\nPage Size: " << pageSize[j] << " bytes\n";
        cout << "Process\tPages\tAllocated\tWasted\n";

        for (int i = 0; i < 3; i++) {
            int pages = (process[i] + pageSize[j] - 1)
                        / pageSize[j];

            int allocated = pages * pageSize[j];
            int wasted = allocated - process[i];

            totalAllocated += allocated;
            totalWasted += wasted;

            cout << process[i] << "\t"
                 << pages << "\t"
                 << allocated << "\t\t"
                 << wasted << endl;
        }

        cout << "Total Allocated Memory: "
             << totalAllocated << " bytes\n";
        cout << "Total Internal Fragmentation: "
             << totalWasted << " bytes\n";
    }

    return 0;
}