uniform sampler2D texture;
uniform vec2 light_point;

void main()
{
	float textureWidth = 1148.f;
	float textureHeight = 811.f;

	vec2 light_forward = normalize(gl_FragCoord.xy - light_point);

	float range = 25.f;
	float dimmer = .9f;

	float verticalPixelStep = 1.f / textureWidth;
	float horizontalPixelStep = 1.f /  textureHeight;

	vec2 pixelStep = vec2(horizontalPixelStep, verticalPixelStep);	

	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

	vec2 shadowPixelCoord = gl_TexCoord[0].xy - (pixelStep * light_forward * range);

	vec4 shadowPixel =  texture2D(texture, shadowPixelCoord);

	if(shadowPixel.rgb != pixel.rgb) {
		gl_FragColor = gl_Color * pixel * dimmer;
	} else {
		gl_FragColor = gl_Color * pixel;
	}
}