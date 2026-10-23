#include <iostream>
using namespace std;

void allocate(int blocks[], int b, int p[], int n, int type)
{
    int a[10], used = 0, count = 0;
    int total = 0, freeMemory = 0;

    for (int i = 0; i < n; i++)
        a[i] = -1;

    for (int i = 0; i < b; i++)
        total += blocks[i];

    for (int i = 0; i < n; i++)
    {
        int k = -1;

        for (int j = 0; j < b; j++)
        {
            if (blocks[j] >= p[i])
            {
                if (type == 1)
                {
                    k = j;
                    break;
                }
                else if (k == -1 ||
                    (type == 2 && blocks[j] < blocks[k]) ||
                    (type == 3 && blocks[j] > blocks[k]))
                {
                    k = j;
                }
            }
        }

        if (k != -1)
        {
            a[i] = k;
            blocks[k] -= p[i];
            used += p[i];
            count++;
        }
    }

    cout << "\nProcess\tSize\tBlock\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << p[i] << "\t";

        if (a[i] == -1)
            cout << "Not Allocated";
        else
            cout << "B" << a[i] + 1;

        cout << endl;
    }

    for (int i = 0; i < b; i++)
        freeMemory += blocks[i];

    cout << "Allocated Processes: " << count << endl;
    cout << "Free Memory: " << freeMemory << " KB" << endl;
    cout << "Memory Utilization: "
         << used * 100.0 / total << "%" << endl;
}

int main()
{
    int blocks[] = {100, 500, 200, 300, 600};
    int p[] = {212, 417, 112, 426};

    cout << "\nFIRST FIT";
    allocate(blocks, 5, p, 4, 1);

    int b2[] = {100, 500, 200, 300, 600};
    cout << "\nBEST FIT";
    allocate(b2, 5, p, 4, 2);

    int b3[] = {100, 500, 200, 300, 600};
    cout << "\nWORST FIT";
    allocate(b3, 5, p, 4, 3);

    return 0;
}