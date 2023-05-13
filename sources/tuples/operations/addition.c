#include <minirt.h>

t_tuple addition(t_tuple point, t_tuple vector)
{
    t_tuple result;

    float x = point[0] + vector[0];
    float y = point[1] + vector[1];
    float z = point[2] + vector[2];
    float w = point[3] + vector[3];

    result = tuple(x, y, z, w);
    return (result);
}