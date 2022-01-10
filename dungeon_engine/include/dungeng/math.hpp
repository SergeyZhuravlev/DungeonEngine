#pragma once

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4996)
#endif
#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#ifdef _MSC_VER
#pragma warning( pop ) 
#endif

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
        using ArrayOfDouble = const double[N];

    public:
        using base::base;

        constexpr vec(ArrayOfDouble& src)
            : base(Initer(src))
        {
        }

    private:
        constexpr static base Initer(ArrayOfDouble& src)
        {
            base result;
            std::copy(std::cbegin(src), std::cend(src), std::begin(result));
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
        using ArrayOfDouble = const double[N];
        using ArrayWithArrayOfDouble = const ArrayOfDouble[M];

    public:
        using base::base;
        
        constexpr mat(ArrayWithArrayOfDouble& src)
            : base(Initer(src))
        {
        }

    private:
        constexpr static base Initer(ArrayWithArrayOfDouble& src)
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
    mat33 translate_matrix(const vec3& xy);
    mat33 translate_matrix(const vec2& xy);
    mat33 scale_matrix(const vec3& xy);
    mat33 scale_matrix(const vec2& xy);
}