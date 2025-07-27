#pragma once

#include "glrhi/core/ebo.hpp"
#include "glrhi/core/vao.hpp"
#include "glrhi/core/vbo.hpp"

#include <glm/glm.hpp>
#include <vector>

namespace glr {

    struct vertex {
        glm::vec3 position;
        glm::vec2 textureUV;
        glm::vec3 normal;
    };

    class mesh{
    public:

        mesh(const std::vector<vertex>& vertices, const std::vector<GLuint>& indices);
        ~mesh() = default;

        void draw();

    private:

        glrhi::vbo m_vbo;
        glrhi::vao m_vao;
        glrhi::ebo m_ebo;

        GLsizei m_numIndices = 3;

    };
}