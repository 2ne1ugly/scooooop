#version 410

in vec4 position;
uniform mat4 world;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	vec4 val;

	val =  world * position;
	val = view * val;
	gl_Position = proj * val;
}
