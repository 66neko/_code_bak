#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#define ColoredVertex(c, v) do{ glColor3fv(c); glVertex3fv(v); }while(0)

static GLfloat angle = 0,yy1 = 25,y2 = 6,z1 = -02,z2 = 1;
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除颜色和深度缓存区
	glMatrixMode(GL_PROJECTION);//打开投影视图
	glLoadIdentity();//设置矩阵位置为屏幕中心
	gluPerspective(90,1300.0/680.0,1,80);//设置投影视图
	glMatrixMode(GL_MODELVIEW);//打开视口设置
	glLoadIdentity();//设置矩阵位置为屏幕中心
	gluLookAt(0,yy1,y2,
		0,0,0,
		0,z1,z2);//设置视口

	//设置太阳光属性
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
	GLfloat light_diffuse[] = {1,1,1,1};
	GLfloat light_specular[] = {1,1,1,1};
	GLfloat light_position[] = {120,20,20,1};
	glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular);
	glLightfv(GL_LIGHT1,GL_POSITION,light_position);
	//开启光照环境
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

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

	glutSolidSphere(2,80,80);

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
	glutSolidSphere(0.7, 85, 85);

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
	glutSolidSphere(0.3, 85, 85);
	glPopMatrix();
	
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
	glutSolidSphere(0.5, 80, 80);
	

	//qqqqqqqqqqqqqqqq
	glTranslatef(5,0,0);
	GLfloat
            PointA[] = { 0.5f, -sqrt(6.0f)/12, -sqrt(3.0f)/6},
            PointB[] = {-0.5f, -sqrt(6.0f)/12, -sqrt(3.0f)/6},
            PointC[] = { 0.0f, -sqrt(6.0f)/12,  sqrt(3.0f)/3},
            PointD[] = { 0.0f,   sqrt(6.0f)/4,             0};
        GLfloat
            ColorR[] = {1, 0, 0},
            ColorG[] = {0, 1, 0},
            ColorB[] = {0, 0, 1},
            ColorY[] = {1, 1, 0};

        glBegin(GL_TRIANGLES);
        // 平面ABC
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorB, PointC);
        // 平面ACD
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorB, PointC);
        ColoredVertex(ColorY, PointD);
        // 平面CBD
        ColoredVertex(ColorB, PointC);
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorY, PointD);
        // 平面BAD
        ColoredVertex(ColorG, PointB);
        ColoredVertex(ColorR, PointA);
        ColoredVertex(ColorY, PointD);
        glEnd();
	//交换缓存区
	glutSwapBuffers();
}

void myIdle(void)
{
	static GLfloat i = 1;
	angle += 1;
	if (angle >= 360)
	{
		angle = 0;
		
	}
	Sleep(20);
	myDisplay();
}


void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1300,680);
	glutCreateWindow("window");
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&myIdle);
	glutMainLoop();
	return;
}