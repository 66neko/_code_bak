
#include <GL/glut.h>
#include <GL/glaux.h> 
#pragma comment(lib, "glaux.lib")
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
}

void palette(void)
{
    GLint i;
    static GLfloat rgb[8][3]={{1,0,0},{1,0,0.5},{1,0,1},
{0,0,1},{0,1,1},{0,1,0},{1,1,0},{1,0.5,0}};

    for(i = 0;i<8;i++)
    {
        auxSetOneColor(i+1,rgb[i][0],rgb[i][1],rgb[i][2]);//设置颜色
    }
}

void DrawColorFans(void)
{
    GLint j;

    glTranslatef(-15,-15,0);
    for(j = 0;j<8;j++)
    {
        glIndexd(j+1);//设置当前颜色索引
        /*在不同位置绘制球体*/
        glTranslatef(j,j-1,0);
        glutSolidSphere(1,20,20);
    }
}

void CALLBACK display(void)
{
    palette();
    DrawColorFans();
    glFlush();
}

void CALLBACK reshape(GLsizei w,GLsizei h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,1,1,20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-15);
}
void main()
{
    auxInitDisplayMode(AUX_SINGLE|AUX_INDEX);
    auxInitPosition(100,100,500,500);
    auxInitWindow("draw the color sphere");
    init();
    auxReshapeFunc(reshape);
    auxMainLoop(display);
}