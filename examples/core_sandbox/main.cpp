#include <iostream>
#include <projectV/core/shader.hpp>

void TestShader()
{
    projectv::core::Shader testShader;
    testShader.debugName = "TestShader";
}

int main() 
{
    std::cout << "Hello project-v";
    TestShader();
    return 0;
}