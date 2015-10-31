#include "stdafx.h"
#include "TwoD.h"

#include <GL/glut.h>
#include <windows.h>
#include <math.h>

TwoD::TwoD()
{
	
	x = 0.0f;  //x轴坐标原点
	y = 0.0f;  //y轴坐标原点
	z = 0.0f; //z轴坐标原点
	init();
}

TwoD::TwoD(GLfloat x0, GLfloat y0, GLfloat z0)
{
	x = x0;  //x轴坐标原点
	y = y0;  //y轴坐标原点
	z = z0; //z轴坐标原点
	init();
}

void TwoD::init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //设置背景为白色
	n = 1000;
	RB = 0.43f; //身体半径
	Pi = 3.1415926536f; //圆周率
	RE = 0.039f; //眼睛半径
	RM = 0.1f; //嘴巴半径
	RA = 0.13f;//角半径
	RF = 0.0966667;//翅膀半
	site = 1;

	 sx = 1.0f; //x轴缩放参数
	 sy = 1.0f; //y轴缩放参数
	 sz = 1.0f; //z轴缩放参数

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

}

void TwoD::display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //设置背景为白色


	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(4.5);

	//左翅
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 234; i < 387; ++i)
		glVertex2f((2.155172414*RF*cos(2 * Pi / n*i) - 0.541666667)*site, 2.931034483*RF*sin(2 * Pi / n*i) - 0.29);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 440; i < 512; ++i)
		glVertex2f((1.862068966*RF*cos(2 * Pi / n*i) - 0.516666667)*site, 3.189655172*RF*sin(2 * Pi / n*i) - 0.075);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 315; i < 397; ++i)
		glVertex2f((4.206896552*RF*cos(2 * Pi / n*i) - 0.516666667)*site, 2.672413793*RF*sin(2 * Pi / n*i) - 0.205);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 339; i < 493; ++i)
		glVertex2f((5 * RF*cos(2 * Pi / n*i) - 0.346666667)*site, 4.172413793*RF*sin(2 * Pi / n*i) - 0.073333333);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 441; i < 739; ++i)
		glVertex2f((1 * RF*cos(2 * Pi / n*i) - 0.506666667)*site, 1.517241379*RF*sin(2 * Pi / n*i) + 0.23);
	glEnd();

	//右翅
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = -239; i < 59; ++i)
		glVertex2f((1 * RF*cos(2 * Pi / n*i) + 0.506666667)*site, 1.517241379*RF*sin(2 * Pi / n*i) + 0.23);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 7; i < 161; ++i)
		glVertex2f((5 * RF*cos(2 * Pi / n*i) + 0.346666667)*site, 4.172413793*RF*sin(2 * Pi / n*i) - 0.073333333);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 103; i < 185; ++i)
		glVertex2f((4.206896552*RF*cos(2 * Pi / n*i) + 0.516666667)*site, 2.672413793*RF*sin(2 * Pi / n*i) - 0.205);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = -12; i < 60; ++i)
		glVertex2f((1.862068966*RF*cos(2 * Pi / n*i) + 0.516666667)*site, 3.189655172*RF*sin(2 * Pi / n*i) - 0.075);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 113; i < 266; ++i)
		glVertex2f((2.155172414*RF*cos(2 * Pi / n*i) + 0.541666667)*site, 2.931034483*RF*sin(2 * Pi / n*i) - 0.29);
	glEnd();

	//左角
	glColor3f(232.0 / 255, 48.0 / 255, 21.0 / 255);
	glBegin(GL_POLYGON);
	glVertex2f(-0.28, 0.38);
	for (int i = 2.5 / 8 * n; i < n*4.5 / 8; ++i)
		glVertex2f(-0.31 + RA*cos(2 * Pi / n*i), 0.36 + RA * 2 * sin(2 * Pi / n*i));

	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.28, 0.38);
	for (int i = 2.5 / 8 * n; i < n*4.5 / 8; ++i)
		glVertex2f(-0.31 + RA*cos(2 * Pi / n*i), 0.36 + RA * 2 * sin(2 * Pi / n*i));
	glEnd();



	//右角
	glColor3f(232.0 / 255, 48.0 / 255, 21.0 / 255);
	glBegin(GL_POLYGON);

	for (int i = -0.5 / 8 * n; i < n*1.5 / 8; ++i)
		glVertex2f(0.31 + RA*cos(2 * Pi / n*i), 0.36 + RA * 2 * sin(2 * Pi / n*i));
	glVertex2f(0.28, 0.38);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);

	for (int i = -0.5 / 8 * n; i < n*1.5 / 8; ++i)
		glVertex2f(0.31 + RA*cos(2 * Pi / n*i), 0.36 + RA * 2 * sin(2 * Pi / n*i));
	glVertex2f(0.28, 0.38);
	glEnd();
	//身体
	glColor3f(120.0 / 255, 120.0 / 255, 120.0 / 255);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n / 2; ++i)
		glVertex2f(RB*1.2*cos(2 * Pi / n*i), RB*1.1*sin(2 * Pi / n*i));
	for (int i = n / 2; i < n; ++i)
		glVertex2f(RB*1.2*cos(2 * Pi / n*i), RB*sin(2 * Pi / n*i));
	glEnd();


	//左眼
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n / 2; ++i)
		glVertex2f(-0.27 + RE*cos(2 * Pi / n*i), 0.15 + RE * 2 * sin(2 * Pi / n*i));
	for (int i = n / 2; i < n; ++i)
		glVertex2f(-0.27 + RE*cos(2 * Pi / n*i), 0.15 + RE * 1.7 * sin(2 * Pi / n*i));
	glEnd();

	//右眼  
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n / 2; ++i)
		glVertex2f(0.27 + RE*cos(2 * Pi / n*i), 0.15 + RE * 2 * sin(2 * Pi / n*i));
	for (int i = n / 2; i < n; ++i)
		glVertex2f(0.27 + RE*cos(2 * Pi / n*i), 0.15 + RE * 1.7 * sin(2 * Pi / n*i));
	glEnd();

	//左牙齿
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);

	for (int i = n * 4 / 8; i < n * 6 / 8; ++i)
		glVertex2f(-0.19 + RE*cos(2 * Pi / n*i), -0.178 + RE*1.6*sin(2 * Pi / n*i));
	glVertex2f(-0.18, -0.18);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);

	for (int i = n * 4 / 8; i < n * 6 / 8; ++i)
		glVertex2f(-0.19 + RE*cos(2 * Pi / n*i), -0.178 + RE*1.6*sin(2 * Pi / n*i));
	glVertex2f(-0.18, -0.18);
	glEnd();

	//右牙齿
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);

	glVertex2f(0.10, -0.19);
	for (int i = n * 6 / 8; i < n * 8 / 8; ++i)
		glVertex2f(0.12 + RE*cos(2 * Pi / n*i), -0.178 + RE*1.6*sin(2 * Pi / n*i));
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);

	glVertex2f(0.10, -0.19);
	for (int i = n * 6 / 8; i < n * 8 / 8; ++i)
		glVertex2f(0.12 + RE*cos(2 * Pi / n*i), -0.178 + RE*1.6*sin(2 * Pi / n*i));
	glEnd();
	//嘴巴
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	for (int i = n * 5 / 8; i < n * 3.0 / 4; ++i)
		glVertex2f(RM*3.4*cos(2 * Pi / n*i), -0.1 + RM *sin(2 * Pi / n*i));
	for (int i = n * 3.0 / 4; i < n * 7 / 8; ++i)
		glVertex2f(RM * 2.5* cos(2 * Pi / n*i), -0.1 + RM * sin(2 * Pi / n*i));
	glEnd();



	//左脚
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.35, -0.31);
	glVertex2f(-0.44, -0.35);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.44, -0.35);
	glVertex2f(-0.43, -0.43);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.44, -0.35);
	glVertex2f(-0.53, -0.34);
	glEnd();

	//右脚
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.35, -0.31);
	glVertex2f(0.44, -0.35);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0.44, -0.35);
	glVertex2f(0.43, -0.43);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0.44, -0.35);
	glVertex2f(0.53, -0.34);
	glEnd();

	//身体轮廓

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < n / 2; ++i)
		glVertex2f(RB*1.2*cos(2 * Pi / n*i), RB*1.1*sin(2 * Pi / n*i));
	for (int i = n / 2; i < n; ++i)
		glVertex2f(RB*1.2*cos(2 * Pi / n*i), RB*sin(2 * Pi / n*i));
	glEnd();


	glFlush();

}

void TwoD::moveLeft()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	x = x - 0.01;
	display();
	glFlush();
}

void TwoD::moveRight()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	x += 0.01;
	display();
	glFlush();
}

void TwoD::moveDown()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	y -= 0.01;
	display();
	glFlush();
}

void TwoD::moveUp()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	y += 0.05;
	site = 0.95;

	display();
	Sleep(500);
	site = 1;

	display();
	Sleep(500);

	y -= 0.05;
	site = 0.95;

	display();
	Sleep(500);
	site = 1;

	display();
	Sleep(500);
	glFlush();
}

void TwoD::fly()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	sx = 0.99;
	sy = 0.99;
	sz = 0.99;
	glScalef(sx, sy, 0.0);
	glPushMatrix();
	display();
	Sleep(255);
	glPopMatrix();

	for (int i = 0;i <= 2;i++)
	{
		sx += 0.01;
		sy += 0.01;
		sz += 0.01;
		site = 0.90;

		glScalef(sx, sy, 0.0);
		glPushMatrix();
		display();
		Sleep(255);
		glPopMatrix();

		sx += 0.01;
		sy += 0.01;
		sz += 0.01;
		site = 1;
		glScalef(sx, sy, 0.0);
		glPushMatrix();
		display();
		Sleep(255);
		glPopMatrix();
	}

	sx = 1;
	sy = 1;
	sz = 1;
	glFlush();

}

void TwoD::bigger()
{
	sx += 0.05;
	sy += 0.05;
	sz += 0.05;
	glScalef(sx, sy, 0.0);
	glPushMatrix();
	display();
	glPopMatrix();
}

void TwoD::smaller()
{

	sx -= 0.05;
	sy -= 0.05;
	sz -= 0.05;
	glScalef(sx, sy, 0.0);
	glPushMatrix();
	display();
	glPopMatrix();
}

void TwoD::mouse(int a, int b)
{
	glViewport(a - 300, 300 - b, 600, 600);
	display();
	glFlush();
   
}




