#include "StdAfx.h"
#include "OpenGL.h"
#include <GL/glut.h>
#include <math.h>
COpenGL::COpenGL(void)
{
	angle = 30;
	eyex = 0;
	eyey = 20;
	eyez = 20;
	ridus = ( pow(eyex,2) + pow(eyey,2) + pow(eyez,2) );
	flags = 1;
	fla = 0.1;
	flaf = 1;
}

COpenGL::~COpenGL(void)
{
}
void COpenGL::EnableOpenGL(HDC *hDC, HGLRC *hRC)
{
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof (PIXELFORMATDESCRIPTOR), 
		1, 
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,           //标志
		PFD_TYPE_RGBA,       //颜色模式
		24,                  //颜色位数
		0, 0, 0, 0, 0, 0, 
		0, 
		0, 
		0, 
		0, 0, 0, 0, 
		32,   	             //深度位数
		0, 
		0, 
		PFD_MAIN_PLANE, 
		0, 
		0, 0, 0
	};
	GLint iPixelFormat;
	iPixelFormat = ChoosePixelFormat(*hDC,&pfd);
	SetPixelFormat(*hDC,iPixelFormat,&pfd);
	*hRC = wglCreateContext(*hDC);
	wglMakeCurrent(*hDC,*hRC);
}
void COpenGL::SetViewPort(CView *Client)
{
	glClearColor(0,0,0,1);
	GLfloat width,height;
	CRect rect;
	Client->GetClientRect(rect);
	width = (GLfloat)rect.Width();
	height = (GLfloat)rect.Height();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50,width/height,1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex,eyey,eyez,0,0,0,0,-1,1);
}

void COpenGL::SetLight()
{
	//设置太阳光属性
	glPushMatrix();
	GLfloat sun_light_ambient[] = {0,0,0,1};//环境光强度
	GLfloat sun_light_diffuse[] = {1,1,1,1};//漫反射强度
	GLfloat sun_light_specular[] = {1,1,1,1};//镜面反射强度
	GLfloat sun_light_position[] = {0,0,0,1};//光源位置
	glLightfv(GL_LIGHT0,GL_AMBIENT,sun_light_ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,sun_light_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,sun_light_specular);
	glLightfv(GL_LIGHT0,GL_POSITION,sun_light_position);
	//第二光源
	GLfloat light_ambient[] = {0.1,0.4,0.5,1};
	GLfloat light_diffuse[] = {0.9,0.9,0,1};
	GLfloat light_specular[] = {0.9,0.9,0,1};
	GLfloat light_position[] = {20,20,20,1};
	glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular);
	glLightfv(GL_LIGHT1,GL_POSITION,light_position);
	
	//开启光照环境
	//glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
}

void COpenGL::Draw(HDC *hDC)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//定义太阳材质并绘制太阳
	GLfloat sun_material_ambient[] = {0.5,0,0,1};
	GLfloat sun_material_diffuse[] = {0.5,0,0,1};
	GLfloat sun_material_specular[] = {0.5,0,0,1};
	GLfloat sun_material_emission[] = {0,0,0,1};
	GLfloat sun_material_shininess = 30;
	glMaterialfv(GL_FRONT,GL_AMBIENT,sun_material_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,sun_material_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,sun_material_specular);
	glMaterialfv(GL_FRONT,GL_EMISSION,sun_material_emission);
	glMaterialf(GL_FRONT,GL_SHININESS,sun_material_shininess);

	//glutSolidSphere(2,80,80);

	//定义地球材质并绘画
	glPushMatrix();
	GLfloat earth_mat_ambient[]  = {0.0f, 0.0f, 0.5, 1.0f};
	GLfloat earth_mat_diffuse[]  = {0, 0.0f, 0.5, 1.0f};
	GLfloat earth_mat_specular[] = {0.0f, 0.0f, 0.5, 1.0f};
	GLfloat earth_mat_emission[] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat earth_mat_shininess  = 30.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT,   earth_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   earth_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  earth_mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION,  earth_mat_emission);
	glMaterialf (GL_FRONT, GL_SHININESS, earth_mat_shininess);

	glRotatef(angle, 0.0f, 0.0f, 01.0f);
	glTranslatef(10.0f, 0.0f, 0.0f);
	//glutSolidSphere(0.7, 85, 85);

	//to draw moon
	GLfloat moon_mat_ambient[]  = {0.3, 0.3, 0.3, 1.0f};
	GLfloat moon_mat_diffuse[]  = {0.5, 0.5, 0.5, 1.0f};
	GLfloat moon_mat_specular[] = {0.7, 0.7, 0.7, 1.0f};
	GLfloat moon_mat_emission[] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat moon_mat_shininess  = 30.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT,   moon_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   moon_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  moon_mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION,  moon_mat_emission);
	glMaterialf (GL_FRONT, GL_SHININESS, moon_mat_shininess);

	glRotatef((GLfloat)((int)angle%30)*12, 0.0f, 0.0f, 1.0f);
	glTranslatef(2.0f, 0.0f, 0.0f);
	//glutSolidSphere(0.3, 85, 85);
	glPopMatrix();
	
	glPushMatrix();
	GLfloat o_mat_ambient[]  = {0.5, 0.5, 0.0, 1.0f};
	GLfloat o_mat_diffuse[]  = {0.5, 0.5, 0.0, 1.0f};
	GLfloat o_mat_specular[] = {0.7, 0.7, 0.0, 1.0f};
	GLfloat o_mat_emission[] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat o_mat_shininess  = 20.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT,   o_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   o_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  o_mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION,  o_mat_emission);
	glMaterialf (GL_FRONT, GL_SHININESS, o_mat_shininess);
	
	glRotatef((angle*2.0), 0.0, 0.0, 1.0);
	glTranslatef(15.0, 0.0, 0.0);
	//glutSolidSphere(0.5, 80, 80);
	glPopMatrix();

	SwapBuffers(*hDC);
}

void COpenGL::Angle()
{
	angle += 1;
	if (angle > 360)
	{
		angle = 0;
	}
}

void COpenGL::DisableOpenGL(HGLRC *hRC)
{
	wglMakeCurrent(NULL,NULL);
	wglDeleteContext(*hRC);

}

void COpenGL::DrawL(HDC *hDC)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat ambient[]  = {0.3, 0.3, 0.3, 1.0f};
	GLfloat diffuse[]  = {0.5, 0.5, 0.5, 1.0f};
	GLfloat specular[] = {0.7, 0.7, 0.7, 1.0f};
	GLfloat emission[] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat shininess  = 15.0f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  emission);
	glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	
	GLfloat point1[] = {-3,-3,-3};
	GLfloat point2[] = {3,-3,-3};
	GLfloat point3[] = {3,3,-3};
	GLfloat point4[] = {-3,3,-3};
	GLfloat point5[] = {-3,-3,3};
	GLfloat point6[] = {3,-3,3};
	GLfloat point7[] = {3,3,3};
	GLfloat point8[] = {-3,3,3};

	glPushMatrix();
	glRotatef(angle,0,0,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	ToDrawM(point1,point2,point3,point4);
	glNormal3f(0,-1,0);
	ToDrawM(point1,point2,point6,point5);
	glNormal3f(-1,0,0);
	ToDrawM(point1,point4,point8,point5);
	glNormal3f(1,0,0);
	ToDrawM(point2,point3,point7,point6);
	glNormal3f(0,1,0);
	ToDrawM(point3,point4,point8,point7);
	glNormal3f(0,0,1);
	ToDrawM(point5,point6,point7,point8);
	glEnd();
	glPopMatrix();
	SwapBuffers(*hDC);
}

void COpenGL::ToDrawM(GLfloat point1[],GLfloat point2[],GLfloat point3[],GLfloat point4[])
{
	glVertex3fv(point1);
	glVertex3fv(point2);
	glVertex3fv(point3);
	glVertex3fv(point4);
}

void COpenGL::ChangeView(int direction)
{
	if (eyey >= sqrt(ridus))
	{
		fla = -0.1;
	}
	if (eyey <= -sqrt(ridus))
	{
		fla = 0.1;
	}
	eyey += fla;
	
	if (abs(eyey - sqrt(ridus)) < 0.1)
		flags *= -1;
	eyez = flags * sqrt(ridus - eyey*eyey);
	if (abs(eyez) < 0.1)
		flaf *= -1;
	glLoadIdentity();
	gluLookAt(eyex,eyey,eyez,0,0,0,eyex*eyey*eyez,eyex*eyex*eyez,-1*(eyex*eyex+eyez*eyez));
}