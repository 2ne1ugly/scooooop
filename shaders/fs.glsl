#version 410

out vec4 color;
in vec3 outNorm;
in vec3 passPos;
uniform vec3 diffuse;
uniform vec3 ambient;
uniform vec3 specular;
uniform float spec_exponent;

uniform bool apply_tex;

uniform sampler2D tex;

const float PI = 3.14159265359;

vec3 direct = normalize(vec3(-1, -1, 0));

void main() {
	vec3 n = normalize(outNorm);
	// float NoL = dot(n, direct);
	// float cNoL = clamp(NoL, 0.0f, 1.0f);

	// vec3 diff = NoL * diffuse + (1 - cNoL) * ambient;
	// vec3 spec = pow(cNoL, spec_exponent) * specular;
	// color = vec4(vec3(diff + spec), 1.0f);
	if (apply_tex)
	{
		vec2 uv;
		uv.x = atan(passPos.z, passPos.x) / (2 * PI) + 0.5;
		uv.y = asin(passPos.y) / PI + 0.5;
		color = vec4(texture(tex, uv).rgb, 1);
	}
	else
	{
		float grey = dot(n, vec3(0.299, 0.587, 0.114));
		color = vec4(vec3(grey), 1.0);
	}
}