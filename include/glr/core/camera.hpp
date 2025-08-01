#pragma once

#include <glm/glm.hpp>
#include <glrhi/glrhi.hpp>

namespace glr {
    class camera {
    public:

        camera();
        ~camera() = default;

        void uploadData() const;
        
        void bind() const;

        glm::vec3 position = glm::vec3(0.0f);

        // Euler angle in degrees
        glm::vec3 direction = glm::vec3(0.0f);

        float near = 0.1f;
        float far = 100.0f;
        float fov = 60.0f;
        float aspectRatio = 16.0f / 9.0f;

    private:

        glrhi::ubo m_cameraData;

    };
}