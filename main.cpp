//main.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"TwoD.h"
#include"ThreeD.h"

#include <GL/glut.h>
#include <windows.h>
#include <math.h>



GLint mx; //鼠标x轴坐标
GLint my; //鼠标y轴坐标
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
	glutCreateWindow("蝙蝠");
	glutDisplayFunc(display);

	glutKeyboardFunc(mykey);
	glRotatef(0, 0, 1, 0);
	//glRotatef(40, 1, 0, 0);
	//glRotatef(20, 0, 0, 1);
	glutMotionFunc(mouse);
	
	int menue_id = glutCreateMenu(mymenu); //右键菜单
	glutAddMenuEntry("以屏幕为参考系", 2);
	glutAddMenuEntry("以动物为参考系", 3);
	glutAddMenuEntry("两只动物同时运动", 4);
	glutAddMenuEntry("单只动物分开运动", 9);

	glutAddMenuEntry("跳跃", 5);
	glutAddMenuEntry("飞", 6);
	glutAddMenuEntry("放大", 7);
	glutAddMenuEntry("缩小", 8);
	glutAddMenuEntry("向前运动", 10);
	glutAddMenuEntry("向后运动", 11);

	glutAddMenuEntry("关闭窗口", 1);
	//glutReshapeFunc(reshape);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
    return 0;
}

