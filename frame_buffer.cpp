#include "frame_buffer.h"

void FrameBuffer::clear()
{
    for (size_t i = 0; i < width * height * 4; i += 4)
    {
        data[i + 0] = clear_color.get_x();
        data[i + 1] = clear_color.get_y();
        data[i + 2] = clear_color.get_z();
        data[i + 3] = clear_color.get_w();
    }
}

void FrameBuffer::set_pixel(int p_x, int p_y, const Vector4 &p_color)
{
    int index = (p_x + p_y * width) * 4;

    data[index + 0] = p_color.get_x();
    data[index + 1] = p_color.get_y();
    data[index + 2] = p_color.get_z();
    data[index + 3] = p_color.get_w();
}

FrameBuffer::FrameBuffer(int p_width, int p_height) : clear_color(Vector4(0.0f, 0.0f, 0.0f, 255.0f)),
                                                      width(p_width),
                                                      height(p_height)
{
    data = new unsigned char[p_width * p_height * 4];
    clear();
}

FrameBuffer::~FrameBuffer()
{
    delete data;
}
