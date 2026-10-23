#include <iostream>
using namespace std;

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5};
    int n = 7, size = 3;
    int frames[3], faults, hits;

    // FIFO Algorithm
    cout << "\nFIFO PAGE REPLACEMENT\n";
    for (int i = 0; i < size; i++)
        frames[i] = -1;

    int pointer = 0;
    faults = hits = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < size; j++)
            if (frames[j] == pages[i])
                found = 1;

        if (found) {
            hits++;
        } else {
            frames[pointer] = pages[i];
            pointer = (pointer + 1) % size;
            faults++;
        }

        cout << pages[i] << " : ";
        for (int j = 0; j < size; j++)
            if (frames[j] == -1) cout << "- ";
            else cout << frames[j] << " ";

        cout << (found ? "Hit" : "Fault") << endl;
    }
    cout << "Page Faults = " << faults;
    cout << "\nPage Hits = " << hits << endl;


    // LRU Algorithm
    cout << "\nLRU PAGE REPLACEMENT\n";
    for (int i = 0; i < size; i++)
        frames[i] = -1;

    int last[6];
    for (int i = 0; i < 6; i++)
        last[i] = -1;

    faults = hits = 0;

    for (int i = 0; i < n; i++) {
        int found = 0, pos = -1;

        for (int j = 0; j < size; j++)
            if (frames[j] == pages[i]) {
                found = 1;
                pos = j;
            }

        if (found) {
            hits++;
        } else {
            faults++;
            int empty = -1;

            for (int j = 0; j < size; j++)
                if (frames[j] == -1)
                    empty = j;

            if (empty != -1) {
                pos = empty;
            } else {
                pos = 0;
                for (int j = 1; j < size; j++)
                    if (last[frames[j]] < last[frames[pos]])
                        pos = j;
            }

            frames[pos] = pages[i];
        }

        last[pages[i]] = i;

        cout << pages[i] << " : ";
        for (int j = 0; j < size; j++)
            if (frames[j] == -1) cout << "- ";
            else cout << frames[j] << " ";

        cout << (found ? "Hit" : "Fault") << endl;
    }
    cout << "Page Faults = " << faults;
    cout << "\nPage Hits = " << hits << endl;


    // Optimal Algorithm
    cout << "\nOPTIMAL PAGE REPLACEMENT\n";
    for (int i = 0; i < size; i++)
        frames[i] = -1;

    faults = hits = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < size; j++)
            if (frames[j] == pages[i])
                found = 1;

        if (found) {
            hits++;
        } else {
            faults++;
            int pos = -1;

            for (int j = 0; j < size; j++)
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }

            if (pos == -1) {
                int farthest = -1;

                for (int j = 0; j < size; j++) {
                    int k;
                    for (k = i + 1; k < n; k++)
                        if (pages[k] == frames[j])
                            break;

                    if (k == n) {
                        pos = j;
                        break;
                    }

                    if (k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
        }

        cout << pages[i] << " : ";
        for (int j = 0; j < size; j++)
            if (frames[j] == -1) cout << "- ";
            else cout << frames[j] << " ";

        cout << (found ? "Hit" : "Fault") << endl;
    }

    cout << "Page Faults = " << faults;
    cout << "\nPage Hits = " << hits << endl;

    return 0;
}