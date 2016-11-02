#version 300 es

out highp vec4 color;

in highp vec2 texCoord;

uniform highp sampler2D texture;

void main()
{
  color = texture2D(texture, texCoord);//vec4(0.5, 0, 0.5, 1.0);
}
