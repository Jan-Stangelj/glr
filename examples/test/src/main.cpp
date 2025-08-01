#include <glrhi/glrhi.hpp>

#include <glr/glr.hpp>

#include <vector>

int main()
{
    glrhi::window window(1280, 720, "Hello Triangle");

    glrhi::shader shader("../examples/test/shaders/basic.vert", "../examples/test/shaders/basic.frag");
    shader.setVec3("color", glm::vec3(1.0f, 0.0f, 1.0f));

    std::vector<glr::vertex> vertices = {
         {glm::vec3(0.0f,  0.5f, 0.0f), glm::vec2(0.0f, 0.0f)},
         {glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)},
         {glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)}
    };
    std::vector<GLuint> indices = {
        0, 1, 2
    };
    
    glr::mesh triangle(vertices, indices);

    glr::camera cam;
    cam.position.z = 3.0f;

    cam.uploadData();
    cam.bind();

    while (!window.shouldClose())
    {
        window.poolEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        triangle.draw();
 
        window.swapBuffers();
    }

    return 0;
}