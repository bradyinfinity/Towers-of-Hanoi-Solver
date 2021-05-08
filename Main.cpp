#include <iostream>
#include <array>
#include <list>
using namespace std;

array<list<int>, 3> pegs;

void draw() {
    for (int i{ 0 }; i < 3; i++) {
        cout << "[" << i << "] ";
        for (auto x : pegs[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void move(int n, list<int>& source, list<int>& target, list<int>& auxiliary) {
    if (n > 0) {
        move(n - 1, source, auxiliary, target);
        target.push_back(source.back());
        source.pop_back();
        draw();
        move(n - 1, auxiliary, target, source);
    }
}

int main() {
    int discs;
    cout << "--Towers of Hanoi--" << endl << endl;
    cout << "How many discs?" << endl;
    cin >> discs;
    cout << endl;
    for (int disc{ discs }; disc > 0; disc--) {
        pegs[0].push_back(disc);
    }
    draw();
    move(discs, pegs[0], pegs[2], pegs[1]);
    system("pause");

    return 0;
}