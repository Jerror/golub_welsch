#ifndef GAUSSQUAD_H
#define GAUSSQUAD_H

#include <vector>

enum {LEGENDRE = 0, HERMITE = 1};

class GaussQuad
{
    std::vector<double> m_x, m_w;
public:
    int const method;

    GaussQuad(int _method, int N);

    std::vector<double> const &x() const;
    std::vector<double> const &w() const;
    double const &x(int i) const;
    double const &w(int i) const;
};

#endif // GAUSSQUAD_H