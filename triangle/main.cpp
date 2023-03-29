#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/Shaders/VertexColor.h>

using namespace Magnum;
using namespace Math::Literals;

struct TriangleVertex {
    Vector2 position;
    Color3 color;
};
const TriangleVertex vertices[]{
        {{-0.5f, -0.5f}, 0xff0000_rgbf},    /* Left vertex, red color */
        {{ 0.5f, -0.5f}, 0x00ff00_rgbf},    /* Right vertex, green color */
        {{ 0.0f,  0.5f}, 0x0000ff_rgbf}     /* Top vertex, blue color */
};
class TriangleExample: public Platform::Application {
public:
    explicit TriangleExample(const Arguments& arguments) :
            Platform::Application{arguments, Configuration{}
                    .setTitle("Magnum Triangle Example")}{
        _mesh.setCount(Containers::arraySize(vertices))
                .addVertexBuffer(GL::Buffer{vertices}, 0,
                                 Shaders::VertexColor2D::Position{},
                                 Shaders::VertexColor2D::Color3{});
    }

private:
    void drawEvent() override {
        GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);
        _shader.draw(_mesh);
        swapBuffers();
    }

    GL::Mesh _mesh;
    Shaders::VertexColor2D _shader;
};



MAGNUM_APPLICATION_MAIN(TriangleExample)
