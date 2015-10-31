//main.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include"TwoD.h"
#include"ThreeD.h"

#include <GL/glut.h>
#include <windows.h>
#include <math.h>



GLint mx; //���x������
GLint my; //���y������
ThreeD animal(0, 0, 0);
ThreeD animal2(600, 0, 0);
int mode = 1;

void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT );

	glViewport(0, 0, 600, 600);
	animal.display();
	glViewport(600, 0, 600, 600);
	animal2.display();
	glFlush();
}


void mouse(int x,int y)
{
	animal.mouse(x,y);
}
	

void mykey(unsigned char key, int ax, int ay)
{
	if (key == 'A')
	{
		animal.moveLeft(1);
	}
	if (key =='D')
	{
		animal.moveRight(1);
	}
	if (key =='W')
	{
		animal.moveUp(1);
	}
	if (key =='S')
	{
		animal.moveDown(1);
	}

}

void mymenu(int id)
{
	switch (id)
	{
	case 1:exit(0);
		break;
	case 2:
		mode = 1;
		break;
	case 3:
		mode = 2;
		break;

	case 4:
		
		break;

	case 5:
		animal.moveUp(1);
		break;
	case 6:
		animal.fly();
		break;
	case 7:
		animal.bigger();
		break;
	case 8:
		animal.smaller();
		break;
	case 9:

		break;
	default:
		break;
	}
}

void reshape(int w, int h)
{
	glViewport(0,0,600,600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(600.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1200,1200);
	glutCreateWindow("����");
	glutDisplayFunc(display);

	glutKeyboardFunc(mykey);
	glRotatef(0, 0, 1, 0);
	//glRotatef(40, 1, 0, 0);
	//glRotatef(20, 0, 0, 1);
	glutMotionFunc(mouse);
	
	int menue_id = glutCreateMenu(mymenu); //�Ҽ��˵�
	glutAddMenuEntry("����ĻΪ�ο�ϵ", 2);
	glutAddMenuEntry("�Զ���Ϊ�ο�ϵ", 3);
	glutAddMenuEntry("��ֻ����ͬʱ�˶�", 4);
	glutAddMenuEntry("��ֻ����ֿ��˶�", 9);

	glutAddMenuEntry("��Ծ", 5);
	glutAddMenuEntry("��", 6);
	glutAddMenuEntry("�Ŵ�", 7);
	glutAddMenuEntry("��С", 8);
	glutAddMenuEntry("��ǰ�˶�", 10);
	glutAddMenuEntry("����˶�", 11);

	glutAddMenuEntry("�رմ���", 1);
	//glutReshapeFunc(reshape);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
    return 0;
}

