#include <gl/glut.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define FileName "Bliss.bmp"

static GLint    ImageWidth;
static GLint    ImageHeight;
static GLint    PixelLength;
static GLubyte* PixelData;



void display(void)
{
    // �����Ļ������Ҫ
    // ÿ�λ���ʱ�����涼����������Ļ
    // ��������Ƿ������Ļ�������һ��
    // glClear(GL_COLOR_BUFFER_BIT);

    // ��������
    glDrawPixels(ImageWidth, ImageHeight,
        GL_BGR_EXT, GL_UNSIGNED_BYTE, PixelData);

    // ��ɻ���
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	/*
    // ���ļ�
    FILE* pFile = fopen("Bliss.bmp", "rb");
    if( pFile == 0 )
        exit(0);

    // ��ȡͼ��Ĵ�С��Ϣ
    fseek(pFile, 0x0012, SEEK_SET);
    fread(&ImageWidth, sizeof(ImageWidth), 1, pFile);
    fread(&ImageHeight, sizeof(ImageHeight), 1, pFile);

    // �����������ݳ���
    PixelLength = ImageWidth * 3;
    while( PixelLength % 4 != 0 )
        ++PixelLength;
    PixelLength *= ImageHeight;

    // ��ȡ��������
    PixelData = (GLubyte*)malloc(PixelLength);
    if( PixelData == 0 )
        exit(0);

    fseek(pFile, 54, SEEK_SET);
    fread(PixelData, PixelLength, 1, pFile);

    // �ر��ļ�
    fclose(pFile);
	*/
	ifstream fin;
	fin.open(FileName,ios::binary);
	fin.seekg(0x0012,ios::beg);
	fin.read((char*)&ImageWidth,sizeof(ImageWidth));
	printf("%d\n",ImageWidth);
	fin.seekg(0x0016);
	fin.read((char *)&ImageHeight,sizeof(ImageWidth));
	printf("%d\n",ImageHeight);

	PixelLength = ImageWidth * 3;
	while (PixelLength%4 != 0) PixelLength++;
	PixelLength *= ImageHeight;

	PixelData = (GLubyte*)operator new(PixelLength);
	fin.seekg(54);
	fin.read((char *)PixelData,PixelLength);
	fin.close();
    // ��ʼ��GLUT������
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ImageWidth, ImageHeight);
    glutCreateWindow(FileName);
    glutDisplayFunc(&display);
    glutMainLoop();

    // �ͷ��ڴ�
    // ʵ���ϣ�glutMainLoop������Զ���᷵�أ�����Ҳ��Զ���ᵽ��
    // ����д�ͷ��ڴ�ֻ�ǳ���һ�ָ���ϰ��
    // ���õ����ڴ��޷��ͷš��ڳ������ʱ����ϵͳ���Զ����������ڴ�
    free(PixelData);

    return 0;
}