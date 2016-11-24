#pragma once
typedef float GLfloat;
enum D{UP,LEFT,DOWN,RIGHT};
class COpenGL
{
public:
	COpenGL(void);
	~COpenGL(void);
public:
	void EnableOpenGL(HDC *hDC,HGLRC *hRC);
	void SetViewPort(CView *Client);
	void SetLight();
	void Draw(HDC *hDC);
	void Angle();
	void DisableOpenGL(HGLRC *hRC);
	void DrawL(HDC *hDC);
	void ChangeView(int direction);
private:
	void ToDrawM(GLfloat point1[],GLfloat point2[],GLfloat point3[],GLfloat point4[]);
	float angle,flags,fla,flaf;
	float eyex,eyey,eyez,ridus;
};
