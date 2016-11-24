#include "StdAfx.h"
#include "gl.h"
#include <fstream>
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"opengl32.lib")
gl::gl(void)
{
}

gl::~gl(void)
{
}
void gl::EnableOpenGL(HDC *hDC,HGLRC *hRC)
{
	PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );
	glEnable(GL_DEPTH_TEST);
}

void gl::DisableOpenGL(HDC *hDC,HGLRC *hRC)
{
	wglMakeCurrent(NULL,NULL);
	wglDeleteContext(*hRC);
}

GLuint gl::ReadBitmap(HDC *hDC)
{
	
	static GLuint ID;
	static int m = 1;
	if (m == 1)
	{
		ID = gl::LoadTexture("test.bmp");
		m = 0;
	}
	/*
	GLbyte* PixelData;
	GLint imageWitdh;
	GLint imageHeight;
	GLint imageAll;
	std::fstream file;
	file.open("test.bmp",std::ios_base::binary|std::ios_base::in);
	file.seekg(0x0012,std::ios::beg);
	file.read((char*)&imageWitdh,sizeof(int));
	file.seekg(0x0016,std::ios::beg);
	file.read((char*)&imageHeight,sizeof(int));
	imageAll = imageWitdh * 3;
	while(imageAll%4 != 0)
		imageAll++;
	imageAll *= imageHeight;
	PixelData = new GLbyte[imageAll];
	file.seekg(54);
	file.read((char*)PixelData,imageAll);
	*/
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glRasterPos2f(0.4,0);
	//glPixelZoom(0.2,0.3);
	//glDrawPixels(imageWitdh,imageHeight,GL_BGR_EXT,GL_UNSIGNED_BYTE,PixelData);
	//SwapBuffers(*hDC);
	//return PixelData;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,1,1,90);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2,0,0,0,0,0,0,0,1);
	glMatrixMode(GL_MODELVIEW);
	/*
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1,&ID);
	glBindTexture(GL_TEXTURE_2D,ID);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,imageWitdh,imageHeight, 0,GL_BGR_EXT, GL_UNSIGNED_BYTE, PixelData);
	*/
	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	
	//glMatrixMode(GL_MODELVIEW);
	
	//glTranslatef(0,0,-1);
	static GLfloat a = 0;
	//glRotatef(a++,0,0,1);
	glTranslatef(a+=0.01,0,0);
	//glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D,ID);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex3f(-2,-2,-1);
	glTexCoord2f(0,10); glVertex3f(-2,2,-1);
	glTexCoord2f(10,10); glVertex3f(2,2,-1);
	glTexCoord2f(10,0); glVertex3f(2,-2,-1);
	glEnd();
	
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	//SwapBuffers(*hDC);
	return ID;

}

GLuint gl::LoadTexture(char *_Filename)
{
	GLint Width;
	GLint Height;
	GLubyte *PixelData;
	GLint PixelLenght;
	GLuint Texture_ID;
	std::fstream file;
	file.open(_Filename,std::ios_base::in|std::ios_base::binary);
	file.seekg(0x0012);
	file.read((char*)&Width,sizeof(Width));
	file.read((char*)&Height,sizeof(Height));
	PixelLenght = Width * 3;
	while(PixelLenght%4 != 0)
		PixelLenght++;
	PixelLenght *= Height;
	PixelData = new GLubyte[PixelLenght];
	file.seekg(54);
	file.read((char*)PixelData,PixelLenght);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1,&Texture_ID);
	glBindTexture(GL_TEXTURE_2D,Texture_ID);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,Width,Height,0,GL_BGR_EXT,GL_UNSIGNED_BYTE,PixelData);
	//gluBuild2DMipmaps(GL_TEXTURE_2D,GL_RGB,256,256,GL_BGR_EXT,GL_UNSIGNED_BYTE,PixelData);
	delete PixelData;
	return Texture_ID;
}

void gl::DrawPv(GLfloat point1[3],GLfloat point2[3],GLfloat point3[3],GLfloat point4[3],GLuint Texture_ID)
{
	glBindTexture(GL_TEXTURE_2D,Texture_ID);
	glBegin(GL_QUADS);
		glTexCoord2f(0,0); glVertex3f(point1[0],point1[1],point1[2]);
		glTexCoord2f(1,0); glVertex3f(point2[0],point2[1],point2[2]);
		glTexCoord2f(1,1); glVertex3f(point3[0],point3[1],point3[2]);
		glTexCoord2f(0,1); glVertex3f(point4[0],point4[1],point4[2]);
	glEnd();
	//glDeleteTextures(1,&Texture_ID);
	return;
}
void gl::DrawCube(HDC *hDC)
{
	GLfloat point0[3] = {-0.25,-0.25,-0.25};
	GLfloat point1[3] = {0.25,-0.25,-0.25};
	GLfloat point2[3] = {0.25,0.25,-0.25};
	GLfloat point3[3] = {-0.25,0.25,-0.25};
	GLfloat point4[3] = {-0.25,-0.25,0.25};
	GLfloat point5[3] = {0.25,-0.25,0.25};
	GLfloat point6[3] = {0.25,0.25,0.25};
	GLfloat point7[3] = {-0.25,0.25,0.25};
	static GLfloat angle = 0;
	static int cheak = 1;
	static GLuint Texture_ID[8];
	static float hh = 0;
	static float hx = 0.05f;
	glPushMatrix();
	glTranslatef(xx,yy,hh+=hx);
	if (hh >= 1 || hh <= 0)
		hx = -hx;
	glRotatef(angle+=1,0,0,1);
	glRotatef(angle+=1,1,0,0);
	if (cheak == 1)
	{
		Texture_ID[0] = gl::LoadTexture("1.bmp");
		Texture_ID[1] = gl::LoadTexture("2.bmp");
		Texture_ID[2] = gl::LoadTexture("3.bmp");
		Texture_ID[3] = gl::LoadTexture("4.bmp");
		Texture_ID[4] = gl::LoadTexture("5.bmp");
		Texture_ID[5] = gl::LoadTexture("6.bmp");
		cheak = 0;
	}
	gl::DrawPv(point0,point1,point2,point3,Texture_ID[0]);
	gl::DrawPv(point0,point3,point7,point4,Texture_ID[1]);
	gl::DrawPv(point0,point1,point5,point4,Texture_ID[2]);
	gl::DrawPv(point1,point2,point6,point5,Texture_ID[3]);
	gl::DrawPv(point2,point3,point7,point6,Texture_ID[4]);
	gl::DrawPv(point4,point5,point6,point7,Texture_ID[5]);
	glPopMatrix();
	SwapBuffers(*hDC);
}