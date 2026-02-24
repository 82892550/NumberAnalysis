#include <iostream>
#include <vector>
#include <string>
using namespace std;

void max_num(int n, vector<int>& arr) {
    int mx = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    cout << "The maximum number : " << mx << endl;
}

void min_num(int n, vector<int>& arr) {
    int mn = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < mn) {
            mn = arr[i];
        }
    }

    cout << "The minimum number : " << mn << endl;
}

void is_prime(int n, vector<int>& arr) {

    int cn = 0;

    for (int j = 0; j < n; j++) {

        if (arr[j] <= 1) continue;

        bool isP = true;

        for (int i = 2; i * i <= arr[j]; i++) {
            if (arr[j] % i == 0) {
                isP = false;
                break;
            }
        }

        if (isP) cn++;
    }

    cout << "The number of prime numbers : " << cn << endl;
}

void is_plai(int n, vector<int>& arr) {

    int cn = 0;

    for (int j = 0; j < n; j++) {

        string s = to_string(arr[j]);

        bool isPali = true;

        int lf = 0;
        int rt = s.size() - 1;

        while (lf < rt) {
            if (s[lf] != s[rt]) {
                isPali = false;
                break;
            }
            lf++;
            rt--;
        }

        if (isPali) cn++;
    }

    cout << "The number of palindrome numbers : " << cn << endl;
}

void div_num(int n, vector<int>& arr) {

    int bestNum = arr[0];
    int bestDiv = 0;

    for (int j = 0; j < n; j++) {

        int cn = 0;

        for (int i = 1; i * i <= arr[j]; i++) {

            if (arr[j] % i == 0) {

                if (i * i == arr[j])
                    cn++;
                else
                    cn += 2;
            }
        }

        if (cn > bestDiv || (cn == bestDiv && arr[j] > bestNum)) {
            bestDiv = cn;
            bestNum = arr[j];
        }
    }

    cout << "The number that has the maximum number of divisors : " << bestNum << endl;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    max_num(n, arr);
    min_num(n, arr);
    is_prime(n, arr);
    is_plai(n, arr);
    div_num(n, arr);

    return 0;
}