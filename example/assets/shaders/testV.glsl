#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;

out vec4 outColor;

uniform vec4 projection;

void main() {
    outColor = aColor;
    gl_Position = projection * vec4(aPos, 1.f);
}