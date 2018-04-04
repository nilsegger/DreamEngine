uniform sampler2D texture;

void main()
{

	vec2 light_forward = vec2(0.707107f, 0.707107f);
	float range = 1.f;
	float dimmer = .9f;

	float textureWidth = 1148.f;
	float textureHeight = 811.f;

	float verticalPixelStep = 1.f / textureWidth;
	float horizontalPixelStep = 1.f /  textureHeight;

	vec2 pixelStep = vec2(horizontalPixelStep, verticalPixelStep);	

	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	
	vec2 shadowPixelCoord = gl_TexCoord[0].xy - (pixelStep * light_forward * range);


	vec4 shadowPixel =  texture2D(texture, shadowPixelCoord);
	/*shadowPixel.a = shadowPixel.a * dimmer;*/


	if(shadowPixel.rgb != pixel.rgb) {
		gl_FragColor = gl_Color * pixel * dimmer;
	} else {
		gl_FragColor = gl_Color * pixel; //* shadowPixel;
	}





   

	
}

/*

vec2 shadowPixelCoord =  gl_TexCoord[0].xy - (light_forward * range * pixelStep);

	vec4 shadowPixel = texture2D(texture, shadowPixelCoord.xy);

	gl_FragColor = gl_Color;

	if(shadowPixel.a > .2f) {
	
		if(shadowPixel != pixel) {
			//dimmer
			gl_FragColor = gl_FragColor * pixel * dimmer;
		} else {
			//no dimmer
			gl_FragColor = gl_FragColor * pixel;
		}
	
	} else {
		gl_FragColor = gl_FragColor * pixel;
	}

*/