#include <GL/glut.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
double CalFrequency()
{
    static int count;
    static double save;
    static clock_t last, current;
    double timegap;

    ++count;
    if( count <= 50 )
        return save;
    count = 0;
    last = current;
    current = clock();
    timegap = (current-last)/(double)CLK_TCK;
    save = 50.0/timegap;
    return save;
}

static int day = 150; // day的变化：从0到359
void myDisplay(void)
{

	double FPS = CalFrequency();
	printf("FPS = %f\n", FPS);

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 20, 0, 0, 0, 0, 0, 0, 1);

    // 绘制红色的“太阳”
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(6.96, 20, 20);
    // 绘制蓝色的“地球”
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(15, 0.0f, 0.0f);
    glutSolidSphere(1.5945, 20, 20);
    // 绘制黄色的“月亮”
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day/30.0*360.0 - day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(3.8, 0.0f, 0.0f);
    glutSolidSphere(0.4345, 20, 20);

    glFlush();
	glutSwapBuffers();
}
void myIdle(void)
{
	++day;
	if(day >= 360)
	{
		day = 0;
	}
	myDisplay();
}
void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(200,200);
	glutCreateWindow("1");
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&myIdle);
	glutMainLoop();
	return;
}