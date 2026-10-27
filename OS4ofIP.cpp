#include <iostream>
#include <string>
using namespace std;

bool checkIP(string ip, int oct[]) {
    int i = 0, num = 0;

    for (int j = 0; j < 4; j++)
        oct[j] = 0;

    for (int j = 0; j < ip.length(); j++) {
        char c = ip[j];

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');

            if (num > 255)
                return false;

            oct[i] = num;
        }
        else if (c == '.') {
            if (j == 0 || ip[j-1] == '.' || i >= 3)
                return false;

            i++;
            num = 0;
        }
        else {
            return false;
        }
    }

    if (i != 3 || ip[ip.length()-1] == '.')
        return false;

    return true;
}

int main() {
    string ip1, ip2;
    int a[4], b[4];
    int mask, same = 1;

    cout << "Enter first IP address: ";
    cin >> ip1;

    cout << "Enter second IP address: ";
    cin >> ip2;

    cout << "Enter subnet prefix (0-32): ";
    cin >> mask;

    if (mask < 0 || mask > 32 ||
        !checkIP(ip1, a) || !checkIP(ip2, b)) {
        cout << "Invalid IP address or prefix!";
        return 0;
    }

    cout << "\nBoth IP addresses are valid.\n";

    int full = mask / 8;
    int rem = mask % 8;

    for (int i = 0; i < 4; i++) {
        int m;

        if (i < full)
            m = 255;
        else if (i == full && rem > 0)
            m = 256 - (1 << (8 - rem));
        else
            m = 0;

        if (a[i] != b[i] && i < full)
            same = 0;

        if (i == full && rem > 0) {
            if ((a[i] & m) != (b[i] & m))
                same = 0;
        }
    }

    cout << "Subnet mask: ";

    for (int i = 0; i < 4; i++) {
        int m;

        if (i < full)
            m = 255;
        else if (i == full && rem > 0)
            m = 256 - (1 << (8 - rem));
        else
            m = 0;

        cout << m;
        if (i < 3) cout << ".";
    }

    cout << "\n";

    if (same == 1)
        cout << "Both hosts belong to the same subnet.";
    else
        cout << "Hosts belong to different subnets.";

    return 0;
}