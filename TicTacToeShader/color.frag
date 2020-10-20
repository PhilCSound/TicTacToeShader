#version 130
uniform sampler2D iChannel1;
uniform vec4 iColor;
uniform vec2 texSize;

void main()
{
    vec4 pixel = texture2D(iChannel1, gl_TexCoord[0].xy);
    
	pixel.a = .8f*abs(sin(9.0f*gl_TexCoord[0].y));
	gl_FragColor = pixel; 
}