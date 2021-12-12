#pragma once
#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <array>

namespace dungeng
{
    namespace blas = ::boost::numeric::ublas;

    /*template <size_t N>
    using vec = blas::bounded_vector<double, N>;*/

    template <size_t N>
    class vec : public blas::bounded_vector<double, N>
    {
    public:
        using bounded_vector::bounded_vector;

        constexpr vec(const std::array<const double, N>& src)
            : bounded_vector<double, N>(Initer(src))
        {
        }

    private:
        constexpr static bounded_vector Initer(const std::array<const double, N>& src)
        {
            blas::bounded_vector<double, N> result;
            std::copy(std::cbegin(src), std::cend(src), result.begin());
            return result;
        }
    };

    /*template <size_t M, size_t N>
    using mat = blas::bounded_matrix<double, M, N>;*/

    template <size_t M, size_t N>
    class mat : public blas::bounded_matrix<double, M, N>
    {
        using dN = const double[N];//std::array<const double, N>;
        using dNM = const dN[M];

    public:
        using bounded_matrix::bounded_matrix;
        
        constexpr mat(dNM& src)
            : bounded_matrix<double, M, N>(Initer(src))
        {
        }

    private:
        constexpr static bounded_matrix Initer(dNM& src)
        {
            blas::bounded_matrix<double, M, N> result;
            for (size_t i = 0; i < std::size(src); ++i)
                for (size_t j = 0; j < std::size(src[i]); ++j)
                    result(i, j) = src[i][j];
            return result;
        }
    };
    
    using vec2 = vec<2>;
    using vec3 = vec<3>;

    using mat33 = mat<3, 3>;

    mat33 rotate_matrix_ccw(double angle);
    mat33 translate_matrix(vec3 xy);
    mat33 translate_matrix(vec2 xy);
    mat33 scale_matrix(vec3 xy);
    mat33 scale_matrix(vec2 xy);
}