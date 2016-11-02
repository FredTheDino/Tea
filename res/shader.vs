#version 300 es

in highp vec3 position;


out highp vec2 texCoord;
highp vec4 out_pos;


uniform highp vec2 spriteDimensions;
uniform highp int subSprite;
uniform highp mat4 translationMatrix;
uniform highp sampler2D texture;

void main()
{
  out_pos = translationMatrix * vec4(position.x, position.y, position.z, 1.0);
  gl_Position = out_pos;
  
  texCoord = vec2(position.x + 0.5, position.y + 0.5);

  //Flip the texture vertically
  texCoord.y = 1.0 - texCoord.y;

  texCoord.x *= spriteDimensions.x;
  texCoord.y *= spriteDimensions.y;

  float numSprites = 1.0 / (spriteDimensions.x);
  float x = mod(float(subSprite), numSprites);
  float y = (float(subSprite) - float(x)) * float(spriteDimensions.x);
  //float y = (float(subSprite) - float(x)) / (1.0 / float(spriteDimensions.x));
	
  texCoord.x += spriteDimensions.x * x;
  texCoord.y += spriteDimensions.y * y;

  //texCoord.x = out_pos.x;
  //texCoord.y = out_pos.y;
	
  //texCoord.x = 1 - texCoord.x;
}
