#include <iostream>

/*
 * Problem 2321 URI
 */

using namespace std;

int main() {
    int r1_x0, r1_y0, r1_x1, r1_y1;
    cin >> r1_x0;
    cin >> r1_y0;
    cin >> r1_x1;
    cin >> r1_y1;

    int r2_x0, r2_y0, r2_x1, r2_y1;
    cin >> r2_x0;
    cin >> r2_y0;
    cin >> r2_x1;
    cin >> r2_y1;

    if (
        ((r1_x1 >= r2_x0) && (r1_x0 <= r2_x1)) &&
        ((r1_y1 >= r2_y0) && (r1_y0 <= r2_y1))
       )
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}