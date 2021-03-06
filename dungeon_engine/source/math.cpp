#include <dungeng/math.hpp>
namespace dungeng
{
    mat33 rotate_matrix_ccw(double angle)
    {
        mat33 result(blas::identity_matrix<double>(3));
        const double cosa = cos(angle);
        const double sina = sin(angle);
        result(0, 0) = cosa;
        result(0, 1) = -sina;
        result(1, 0) = sina;
        result(1, 1) = cosa;
        return result;
    }

    mat33 translate_matrix(const vec3& xy)
    {
        mat33 result(blas::identity_matrix<double>(3));
        result(2, 0) = xy[0];
        result(2, 1) = xy[1];
        return result;
    }

    mat33 translate_matrix(const vec2& xy)
    {
        return translate_matrix(vec3(xy));
    }

    mat33 scale_matrix(const vec3& xy)
    {
        mat33 result (blas::identity_matrix<double>(3));
        result(0, 0) = xy[0];
        result(1, 1) = xy[1];
        return result;
    }

    mat33 scale_matrix(const vec2& xy)
    {
        return scale_matrix(vec3(xy));
    }



    vec2 f()
    {
        double a = rand() ? 0. : 1.;
        return vec2({ 1, a });
    }

    mat33 f1()
    {
        double a = rand() ? 0. : 1.;
        return mat33({ { 1, a, 1 }, { 1, a, 1 }, { 1, a, 1 } });
    }
}