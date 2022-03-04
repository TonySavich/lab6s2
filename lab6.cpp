#include <iostream>
#include <random>

const int N = 10;

int search(int y, int n, int k, int* x) {
    if (k < x[y]) {
        return -1;
    }
    if (k == x[y]) {
        return y;
    }
    if (k > x[n]) {
        return -1;
    }
    int a = y;
    int b = n;
    int c;
    while (a + 1 < b) {
        c = (a + b) / 2;
        if (k > x[c]) {
            a = c;
        }
        else {
            b = c;
        }
    }
    if (x[b] == k) {
        return b;
    }
    else {
        return -1;
    }
}

void quicksort(int a, int b, int* x) {
    if (a >= b) {
        return;
    }
    int m, k, l, r;
    m = rand() % (b - a + 1) + a;
    k = x[m];
    l = a - 1;
    r = b + 1;
    while (1) {
        do {
            l = l + 1;
        } while (x[l] < k);

        do {
            r = r - 1;
        } while (x[r] > k);
        if (l >= r)
            break;

        std::swap(x[l], x[r]);
    }
    r = l;
    l = l - 1;
    quicksort(a, l, x);
    quicksort(r, b, x);
}




int main()
{
    int mas[N];
    for (int i = 0; i < N; i++) {
        mas[i] = rand() % 10;
    }

    for (int i = 0; i < N; i++) {
        std::cout << mas[i] << " ";
    }

    std::cout << std::endl;
    quicksort(0, N - 1, mas);

    for (int i = 0; i < N; i++) {
        std::cout << mas[i] << " ";
    }

    std::cout << std::endl;
    int z;
    std::cin >> z;

   int dd = search(0, N - 1, z, mas);
   std::cout << std::endl;
   std::cout << dd+1;
}
