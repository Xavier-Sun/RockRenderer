#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

#include "math/vector4.h"

class FrameBuffer
{
    unsigned char *data;

    Vector4 clear_color;

    int width;
    int height;

public:
    const unsigned char *get_data() const { return data; }

    Vector4 get_clear_color() const { return clear_color; }
    void set_clear_color(const Vector4 &p_color) { clear_color = p_color; }

    int get_width() const { return width; }
    int get_height() const { return height; }

    void clear();

    void set_pixel(int p_x, int p_y, const Vector4 &p_color);

    explicit FrameBuffer(int p_width, int p_height);
    ~FrameBuffer();
};

#endif
