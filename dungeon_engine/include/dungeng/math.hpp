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
	private:
		using base = blas::bounded_vector<double, N>;
		
    public:
        using base::base;

        constexpr vec(const std::array<const double, N>& src)
            : base(Initer(src))
        {
        }

    private:
        constexpr static base Initer(const std::array<const double, N>& src)
        {
            base result;
            std::copy(std::cbegin(src), std::cend(src), result.begin());
            return result;
        }
    };

    /*template <size_t M, size_t N>
    using mat = blas::bounded_matrix<double, M, N>;*/

    template <size_t M, size_t N>
    class mat : public blas::bounded_matrix<double, M, N>
    {
	private:
		using base = blas::bounded_matrix<double, M, N>;
        using dN = const double[N];
        using dNM = const dN[M];

    public:
        using base::base;
        
        constexpr mat(dNM& src)
            : base(Initer(src))
        {
        }

    private:
        constexpr static base Initer(dNM& src)
        {
            base result;
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