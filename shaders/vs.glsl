#version 410

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;

out vec3 outNorm;
out	vec3 passPos;

uniform mat4x4 world;
uniform mat4x4 view;
uniform mat4x4 proj;

void main() {
	vec4 tmp = vec4(pos, 1.f);
	tmp = world * tmp;
	tmp = view * tmp;
	tmp = proj * tmp;
	gl_Position = tmp;
	passPos = pos;
	outNorm = normalize(norm);
}
