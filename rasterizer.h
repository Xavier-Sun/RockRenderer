#ifndef RENDERER_H
#define RENDERER_H

#include "math/vector2.h"
#include "math/vector3.h"
#include "math/vector4.h"

#include <vector>

class FrameBuffer;

struct appdata
{
    Vector3 position;
    Vector3 normal;
    Vector3 tangent;
    Vector2 texcoord;
    Vector4 color;
};

struct v2f
{
    Vector3 position;
    Vector4 color;
};

v2f vertex_shader_default(const appdata &in);
Vector4 fragment_shader_default(const v2f &in);

class Rasterizer
{
public:
    typedef v2f (*vertex_shader_func)(const appdata &);
    typedef Vector4 (*fragment_shader_func)(const v2f &);

    void draw() const;

    void add_vertex(const appdata &p_vertex);

    FrameBuffer *get_frame_buffer() const { return frame_buffer; }
    void set_fram_buffer(FrameBuffer *p_frame_buffer) { frame_buffer = p_frame_buffer; }

    void set_vertex_shader(vertex_shader_func p_vertex_shader) { vertex_shader = p_vertex_shader; }
    void set_fragment_shader(fragment_shader_func p_fragment_shader) { fragment_shader = p_fragment_shader; }

    explicit Rasterizer();
    ~Rasterizer();

private:
    std::vector<appdata> vertices;

    FrameBuffer *frame_buffer;

    vertex_shader_func vertex_shader;
    fragment_shader_func fragment_shader;
};

#endif
