#include <gl/gl.h>
#include <gl/glu.h>

#pragma once
float xx = 0;
float yy = 0;
class gl
{
public:
	gl(void);
	virtual ~gl(void);
	void EnableOpenGL(HDC *hDC,HGLRC *hRC);
	void DisableOpenGL(HDC *hDC,HGLRC *hRC);
	GLuint ReadBitmap(HDC *hDC);
	GLuint LoadTexture(char *_Filename);
	void DrawPv(GLfloat point1[3],GLfloat point2[3],GLfloat point3[3],GLfloat point4[3],GLuint Texture_ID);
	void DrawCube(HDC *hDC);
};
