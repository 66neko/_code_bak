#include <GL/glut.h>

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1,0,0);
	glVertex2f(1,0);
	glColor3f(0,0,1);
	glVertex2f(0,0);
	glColor3f(1,1,0);
	glVertex2f(0,1);
	glEnd();
	glFlush();
}
void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(400,400);
	glutCreateWindow("first");
	glutDisplayFunc(&Display);
	glutMainLoop();
	return;
}