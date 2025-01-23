#include <iostream>
#include <vector>
#include <unordered_set>
#include <iostream>

//task_1
void converter(int sec) {
    int hours = sec / 3600;
    int minutes = (sec % 3600) / 60;
    int seconds = sec % 60;
    std::cout << hours << " : " << minutes << " : " << seconds << std::endl;
}

int main() {
    int sec;
    std::cin >> sec;
    converter(sec);
    return 0;
}

//task_2 by pointers
void byPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// task_2 by byRef
void byRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int x;
    std::cin >> x;
    int y;
    std::cin >> y;

    std::cout << "x = " << x << ", y = " << y << std::endl;
//    byPointer(&x, &y);
    byRef(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    return 0;
}

#include <unordered_set>
// task_3
int main() {
    int N;
    std::cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::unordered_set<int> n;
    for (int i = 0; i < N; ++i) {
        n.insert(arr[i]);
    }

    for (const int &elem: n) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}

//task 3 by vectors
int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
    }
    std::unordered_set<int> set(vec.begin(), vec.end());
    for (const int& elem : set) {
        std::cout << elem << " ";
    }
    return 0;
}
