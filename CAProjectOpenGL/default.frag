#version 330 core
out vec4 FragColor;
out vec4 FragColor1;
out vec4 FragColor2;

in vec3 color;

in vec2 texCoord;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
	FragColor = texture(tex0, texCoord) * texture(tex1, texCoord) * vec4(color, 1.0f);
	FragColor2 = vec4(color, 1.0f);
};