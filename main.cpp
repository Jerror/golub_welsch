#include <cstdlib>
#include <iostream>
using namespace std;

#include "GaussQuad.hpp"


int main(int argc, char *argv[])
{
    int next_arg = 1;
    int const method = argc>2 ? atoi(argv[next_arg++]) : LEGENDRE;
    int const N = atoi(argv[next_arg++]);
    GaussQuad rule(method, N);

    for (int i = 0; i < N; i++) {
        cout<<rule.x(i)<<","<<rule.w(i)<<endl;
    }
}