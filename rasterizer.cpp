#include "rasterizer.h"

#include "math/math_utility.h"
#include "math/math_utility_triangle.h"
#include "frame_buffer.h"

#include <glad/glad.h>

v2f vertex_shader_default(const appdata &in)
{
    v2f out;
    out.position = in.position;
    out.color = in.color;
    return out;
}

Vector4 fragment_shader_default(const v2f &in)
{
    return in.color;
}

void Rasterizer::draw() const
{
    v2f v2fs[vertices.size()];

    for (size_t i = 0; i < vertices.size(); ++i)
    {
        v2fs[i] = vertex_shader(vertices[i]);

        int frame_buffer_width_half = frame_buffer->get_width() / 2;
        int frame_buffer_height_half = frame_buffer->get_height() / 2;

        v2fs[i].position.set_x(v2fs[i].position.get_x() * frame_buffer_width_half + frame_buffer_width_half);
        v2fs[i].position.set_y(v2fs[i].position.get_y() * frame_buffer_height_half + frame_buffer_height_half);
    }

    for (size_t i = 0; i < vertices.size(); i += 3)
    {
        v2f v1 = v2fs[i + 0];
        v2f v2 = v2fs[i + 1];
        v2f v3 = v2fs[i + 2];

        Vector2 v1_pos(v1.position.get_x(), v1.position.get_y());
        Vector2 v2_pos(v2.position.get_x(), v2.position.get_y());
        Vector2 v3_pos(v3.position.get_x(), v3.position.get_y());

        int x_min = min(v1_pos.get_x(), v2_pos.get_x(), v3_pos.get_x());
        int x_max = max(v1_pos.get_x(), v2_pos.get_x(), v3_pos.get_x());
        int y_min = min(v1_pos.get_y(), v2_pos.get_y(), v3_pos.get_y());
        int y_max = max(v1_pos.get_y(), v2_pos.get_y(), v3_pos.get_y());

        for (size_t screen_x = x_min; screen_x < x_max; ++screen_x)
        {
            for (size_t screen_y = y_min; screen_y < y_max; ++screen_y)
            {
                Vector2 pixel_position(screen_x + 0.5f, screen_y + 0.5f);

                if (point_in_triangle(pixel_position, v1_pos, v2_pos, v3_pos))
                {
                    v2f pixel;

                    Vector3 weights = get_barycentric_coordinate(pixel_position, v1_pos, v2_pos, v3_pos);

                    pixel.position = v1.position * weights.get_x() + v2.position * weights.get_y() + v3.position * weights.get_z();
                    pixel.color = v1.color * weights.get_x() + v2.color * weights.get_y() + v3.color * weights.get_z();

                    Vector4 color = fragment_shader(pixel);

                    frame_buffer->set_pixel(screen_x, screen_y, color);
                }
            }
        }
    }

    glDrawPixels(frame_buffer->get_width(), frame_buffer->get_height(), GL_RGBA, GL_UNSIGNED_BYTE, frame_buffer->get_data());
}

void Rasterizer::add_vertex(const appdata &p_vertex)
{
    vertices.push_back(p_vertex);
}

Rasterizer::Rasterizer() : vertex_shader(vertex_shader_default),
                           fragment_shader(fragment_shader_default),
                           frame_buffer(NULL)
{
}

Rasterizer::~Rasterizer()
{
}
