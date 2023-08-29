#include <iostream>
using std::cout;
using std::endl;

int cnt = 100;

namespace audio {
    int cnt = 0;

    void Play() {++::cnt;}
}

int main()
{
    cout<< cnt << endl;
}