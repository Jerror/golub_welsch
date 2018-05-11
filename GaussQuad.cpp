#include "GaussQuad.hpp"
#include <cmath>
#include <limits>
#include <vector>
#include <eigen3/Eigen/Dense>
using namespace Eigen;
using namespace std;


GaussQuad::GaussQuad(int _method, int N)
    : m_x(N)
    , m_w(N)
    , method(_method)
{
    double k0;
    ArrayXd a(N), b(N);
    switch(_method)
    {
        case GQ_HERMITE:
            k0 = pow(M_PI,-0.25);
            a.setZero();
            b = ArrayXd::LinSpaced(N,.5,N/2.0).sqrt();
            break;
        case GQ_LEGENDRE: default:
            k0 = sqrt(0.5);
            a.setZero();
            for (int i = 1; i < N+1; i++) {
                b[i-1] = i/sqrt(4*i*i - 1);
            }
    }

    SelfAdjointEigenSolver<MatrixXd> solver(N);
    solver.computeFromTridiagonal(a, b);
    if (solver.info() != Success) abort();

    for (int i = 0; i < N; i++)
    {
        m_x[i] = abs(solver.eigenvalues()[i]) 
                < 4*numeric_limits<double>::epsilon()
                ? 0 : solver.eigenvalues()[i];
        m_w[i] = solver.eigenvectors()(0,i);
        m_w[i] *= m_w[i]/k0/k0;
    }
}

vector<double> const &GaussQuad::x() const { return m_x; }
vector<double> const &GaussQuad::w() const { return m_w; }
double const &GaussQuad::x(int i) const { return m_x[i]; }
double const &GaussQuad::w(int i) const { return m_w[i]; }