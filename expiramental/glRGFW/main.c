#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <emscripten.h>

GLFWwindow* window;

void render() {
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(0.45f,0.45,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f); glVertex3f(-0.5f,-0.5f,0.0f);
        glColor3f(0.0f,1.0f,0.0f); glVertex3f(0.5f,-0.5f,0.0f);
        glColor3f(0.0f,0.0f,1.0f); glVertex3f(0.0f,0.5f,0.0f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();

    if (glfwWindowShouldClose(window))
        emscripten_cancel_main_loop();
}

int main() {
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(640, 480, "GLFW WASM Legacy GL", NULL, NULL);
    if (!window) return -1;

    glfwMakeContextCurrent(window);

    emscripten_set_main_loop(render, 0, 1);

    glfwTerminate();
    return 0;
}