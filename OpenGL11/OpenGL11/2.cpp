#include <GL/glut.h>
#include <cmath>
using namespace std;

void Display(void)
{
	const GLfloat R = 0.5f;
	const int n = 100;
	const GLfloat Pi = 3.1415926f;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINT);
	glColor3f(1,0,0);
	for(int i=0; i<n; ++i)
        glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));
	glEnd();
	glFlush();
}
void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(200,200);
	glutCreateWindow("2");
	glutDisplayFunc(&Display);
	glutMainLoop();
	return;
}