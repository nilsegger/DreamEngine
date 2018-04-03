uniform sampler2D texture;

void main()
{

	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	
	
	gl_FragColor = gl_Color;
	gl_FragColor.a = 1.f / vec2(1280.f, 720.f) * gl_FragCoord.xy;


	gl_FragColor = gl_FragColor * gl_Color * pixel;


	/*if(gl_PointCoord.x > .1f) {
	 gl_FragColor = vec4(1.f,1.f,1.f,1.f);
	} else {
		gl_FragColor = gl_Color;
	}*/


   



   

	
}