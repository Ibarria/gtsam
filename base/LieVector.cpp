/**
 * @file LieVector.cpp
 * @brief Implementations for LieVector functions
 * @author Alex Cunningham
 */

#include <stdarg.h>
#include <gtsam/base/LieVector.h>

using namespace std;

namespace gtsam {

/* ************************************************************************* */
LieVector::LieVector(size_t m, const double* const data)
: Vector(Vector_(m,data))
{
}

/* ************************************************************************* */
LieVector::LieVector(size_t m, ...)
: Vector(m)
{
    va_list ap;
    va_start(ap, m);
    for( size_t i = 0 ; i < m ; i++) {
      double value = va_arg(ap, double);
      (*this)(i) = value;
    }
    va_end(ap);
}

} // \namespace gtsam
