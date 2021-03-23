#include "rasterizer.h"
#include "frame_buffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cassert>
#include <cstdio>
#include <ctime>

int main()
{
    int screen_width = 800;
    int screen_height = 600;

    assert(glfwInit() == GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow *window = glfwCreateWindow(screen_width, screen_height, "Rock Renderer", NULL, NULL);
    assert(window != NULL);
    glfwMakeContextCurrent(window);
    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

    Rasterizer rasterizer;
    FrameBuffer frame_buffer(screen_width, screen_height);
    rasterizer.set_fram_buffer(&frame_buffer);

    appdata v1;
    v1.position = Vector3(-0.5f, 0.0f, 0.0f);
    v1.color = Vector4(255.0f, 0.0f, 0.0f, 255.0f);

    appdata v2;
    v2.position = Vector3(0.0f, 0.5f, 0.0f);
    v2.color = Vector4(0.0f, 255.0f, 0.0f, 255.0f);

    appdata v3;
    v3.position = Vector3(0.5f, 0.0f, 0.0f);
    v3.color = Vector4(0.0f, 0.0f, 255.0f, 255.0f);

    appdata v4;
    v4.position = Vector3(0.5f, 0.5f, 0.0f);
    v4.color = Vector4(255.0f, 0.0f, 0.0f, 255.0f);

    appdata v5;
    v5.position = Vector3(0.8f, 0.8f, 0.0f);
    v5.color = Vector4(0.0f, 255.0f, 0.0f, 255.0f);

    appdata v6;
    v6.position = Vector3(0.8f, 0.5f, 0.0f);
    v6.color = Vector4(0.0f, 0.0f, 255.0f, 255.0f);

    rasterizer.add_vertex(v1);
    rasterizer.add_vertex(v2);
    rasterizer.add_vertex(v3);
    rasterizer.add_vertex(v4);
    rasterizer.add_vertex(v5);
    rasterizer.add_vertex(v6);

    frame_buffer.set_clear_color(Vector4(255.0f, 255.0f, 255.0f, 255.0f));

    int frame_count = 0;
    clock_t start;
    clock_t end;
    start = clock();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        frame_buffer.clear();

        rasterizer.draw();

        glfwSwapBuffers(window);

        if (frame_count++ == 100)
        {
            end = clock();
            float fps = 100.0f / ((end - start) / CLOCKS_PER_SEC);
            printf("FPS: %f\n", fps);
            start = clock();
            frame_count = 0;
        }
    }

    glfwTerminate();

    return 0;
}
