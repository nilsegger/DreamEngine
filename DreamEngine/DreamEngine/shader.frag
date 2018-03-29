uniform sampler2D texture;

uniform float width;

void main()
{
	vec2 pos = gl_TexCoord[0].xy;
    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

	if(gl_TexCoord[0].xy.x != 0 && gl_TexCoord[0].xy.y != 0) {
		gl_FragColor = gl_Color * pixel / width * pos.x;
	 }
}