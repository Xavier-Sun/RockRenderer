#include "rasterizer.h"
#include "frame_buffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    int screen_width = 800;
    int screen_height = 600;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow *window = glfwCreateWindow(screen_width, screen_height, "Rock Renderer", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Rasterizer rasterizer;
    FrameBuffer frame_buffer(screen_width, screen_height);
    rasterizer.set_fram_buffer(&frame_buffer);

    appdata v1;
    v1.position = Vector3(-0.5f, -0.5f, 0.0f);
    v1.color = Vector4(255.0f, 0.0f, 0.0f, 255.0f);

    appdata v2;
    v2.position = Vector3(0.0f, 0.5f, 0.0f);
    v2.color = Vector4(0.0f, 255.0f, 0.0f, 255.0f);

    appdata v3;
    v3.position = Vector3(0.5f, -0.5f, 0.0f);
    v3.color = Vector4(0.0f, 0.0f, 255.0f, 255.0f);

    rasterizer.add_vertex(v1);
    rasterizer.add_vertex(v2);
    rasterizer.add_vertex(v3);

    frame_buffer.set_clear_color(Vector4(255.0f, 255.0f, 255.0f, 255.0f));
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        frame_buffer.clear();

        rasterizer.draw();

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
