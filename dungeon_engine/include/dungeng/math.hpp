#pragma once
#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

namespace dungeng
{
    namespace blas = ::boost::numeric::ublas;

    template <size_t N>
    using vec = blas::bounded_vector<double, N>;

    template <size_t M, size_t N>
    using mat = blas::bounded_matrix<double, M, N>;
    
    using vec2 = vec<2>;
    using vec3 = vec<3>;

    using mat33 = mat<3, 3>;

    mat33 rotate_matrix_ccw(double angle);
    mat33 translate_matrix(vec3 xy);
    mat33 translate_matrix(vec2 xy);
    mat33 scale_matrix(vec3 xy);
    mat33 scale_matrix(vec2 xy);
}