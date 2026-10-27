#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a[20] = {82, 170, 43, 140, 24, 16, 190};
    int n = 7, head = 50, disk = 200;
    int i, j, temp, pos, movement;
    int b[20], visited[20];

    // FCFS
    movement = 0;
    pos = head;

    for (i = 0; i < n; i++) {
        movement += abs(pos - a[i]);
        pos = a[i];
    }
    cout << "FCFS Head Movement = " << movement << endl;

    // SSTF
    movement = 0;
    pos = head;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++) {
        int minDist = 9999, k = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && abs(pos - a[j]) < minDist) {
                minDist = abs(pos - a[j]);
                k = j;
            }
        }

        visited[k] = 1;
        movement += abs(pos - a[k]);
        pos = a[k];
    }
    cout << "SSTF Head Movement = " << movement << endl;

    // Sort array for SCAN and C-SCAN
    for (i = 0; i < n; i++)
        b[i] = a[i];

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    // SCAN: move towards higher cylinders first
    movement = 0;
    pos = head;

    for (i = 0; i < n; i++) {
        if (b[i] >= head) {
            movement += abs(pos - b[i]);
            pos = b[i];
        }
    }

    movement += abs(pos - (disk - 1));
    pos = disk - 1;

    for (i = n - 1; i >= 0; i--) {
        if (b[i] < head) {
            movement += abs(pos - b[i]);
            pos = b[i];
        }
    }
    cout << "SCAN Head Movement = " << movement << endl;

    // C-SCAN: move towards higher cylinders only
    movement = 0;
    pos = head;

    for (i = 0; i < n; i++) {
        if (b[i] >= head) {
            movement += abs(pos - b[i]);
            pos = b[i];
        }
    }

    movement += abs(pos - (disk - 1));
    movement += disk - 1;
    pos = 0;

    for (i = 0; i < n; i++) {
        if (b[i] < head) {
            movement += abs(pos - b[i]);
            pos = b[i];
        }
    }
    cout << "C-SCAN Head Movement = " << movement << endl;

    return 0;
}