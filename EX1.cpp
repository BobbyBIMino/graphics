
#include "stdafx.h"

#include <GL/glut.h>
#include <windows.h>
#include <math.h>


const int n = 1000;
const GLfloat RB = 0.43f; //����뾶
const GLfloat Pi = 3.1415926536f; //Բ����
const GLfloat RE = 0.04f; //�۾��뾶
const GLfloat  RM= 0.1f; //��Ͱ뾶
const GLfloat RA = 0.13f;//�ǰ뾶
const GLfloat  RF = 0.0966667;//���뾶
GLfloat site = 1; //�Ӷ����ʱ��ϵ��

GLfloat x = 0.0f;  //x������ԭ��
GLfloat y = 0.0f;  //y������ԭ��
GLfloat z = 0.0f; //z������ԭ��

GLint mx; //���x������
GLint my; //���y������

void myDisplay(void)
{
	glClearColor(1.0,1.0,1.0,1.0); //���ñ���Ϊ��ɫ


	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2.5);

	//���
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 234; i<387; ++i)
		glVertex2f((2.155172414*RF*cos(2 * Pi / n*i) + x - 0.541666667)*site, 2.931034483*RF*sin(2 * Pi / n*i) + y - 0.29);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 440; i<512; ++i)
		glVertex2f((1.862068966*RF*cos(2 * Pi / n*i) + x - 0.516666667)*site, 3.189655172*RF*sin(2 * Pi / n*i) + y - 0.075);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 315; i<397; ++i)
		glVertex2f((4.206896552*RF*cos(2 * Pi / n*i) + x - 0.516666667)*site, 2.672413793*RF*sin(2 * Pi / n*i) + y - 0.205);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 339; i<493; ++i)
		glVertex2f((5 * RF*cos(2 * Pi / n*i) + x - 0.346666667)*site, 4.172413793*RF*sin(2 * Pi / n*i) + y - 0.073333333);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 441; i<739; ++i)
		glVertex2f((1 * RF*cos(2 * Pi / n*i) + x - 0.506666667)*site, 1.517241379*RF*sin(2 * Pi / n*i) + y + 0.23);
	glEnd();

	//�ҳ�
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = -239; i<59; ++i)
		glVertex2f((1 * RF*cos(2 * Pi / n*i) + x + 0.506666667)*site, 1.517241379*RF*sin(2 * Pi / n*i) + y + 0.23);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 7; i<161; ++i)
		glVertex2f((5 * RF*cos(2 * Pi / n*i) + x + 0.346666667)*site, 4.172413793*RF*sin(2 * Pi / n*i) + y - 0.073333333);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 103; i<185; ++i)
		glVertex2f((4.206896552*RF*cos(2 * Pi / n*i) + x + 0.516666667)*site, 2.672413793*RF*sin(2 * Pi / n*i) + y - 0.205);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = -12; i<60; ++i)
		glVertex2f((1.862068966*RF*cos(2 * Pi / n*i) + x + 0.516666667)*site, 3.189655172*RF*sin(2 * Pi / n*i) + y - 0.075);
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int i = 113; i<266; ++i)
		glVertex2f((2.155172414*RF*cos(2 * Pi / n*i) + x + 0.541666667)*site, 2.931034483*RF*sin(2 * Pi / n*i) + y - 0.29);
	glEnd();

	//���
	glColor3f(189.0 / 255, 192.0 / 255, 186.0 / 255);
	glBegin(GL_POLYGON);
	glVertex2f(-0.28+x, 0.38+y);
	for (int i = 2.5 / 8 * n; i<n*4.5 / 8; ++i)
		glVertex2f(-0.31 + RA*cos(2 * Pi / n*i) + x, 0.36 + RA * 2 * sin(2 * Pi / n*i) + y);

	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.28+x, 0.38+y);
	for (int i = 2.5 / 8 * n; i<n*4.5 / 8; ++i)
		glVertex2f(-0.31 + RA*cos(2 * Pi / n*i) + x, 0.36 + RA * 2 * sin(2 * Pi / n*i) + y);
	glEnd();



	//�ҽ�
	glColor3f(189.0 / 255, 192.0 / 255, 186.0 / 255);
	glBegin(GL_POLYGON);

	for (int i = -0.5 / 8 * n; i<n*1.5 / 8; ++i)
		glVertex2f(0.31 + RA*cos(2 * Pi / n*i) + x, 0.36 + RA * 2 * sin(2 * Pi / n*i) + y);
	glVertex2f(0.28+x, 0.38+y);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);

	for (int i = -0.5 / 8 * n; i<n*1.5 / 8; ++i)
		glVertex2f(0.31 + RA*cos(2 * Pi / n*i) + x, 0.36 + RA * 2 * sin(2 * Pi / n*i) + y);
	glVertex2f(0.28+x, 0.38+y);
	glEnd();
	//����
	glColor3f(189.0/255, 192.0/255, 186.0/255);
	glBegin(GL_POLYGON);
	for (int i = 0; i<n/2; ++i)
		glVertex2f(RB*1.2*cos(2 * Pi / n*i) + x, RB*1.1*sin(2 * Pi / n*i) + y);
	for (int i =n/2; i<n; ++i)
		glVertex2f(RB*1.2*cos(2 * Pi / n*i) + x, RB*0.9*sin(2 * Pi / n*i) + y);
	glEnd();


	//����
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<n/2; ++i)
		glVertex2f(-0.27 + RE*cos(2 * Pi / n*i) + x, 0.15 + RE*2*sin(2 * Pi / n*i) + y);
	for (int i = n / 2; i<n; ++i)
		glVertex2f(-0.27 + RE*cos(2 * Pi / n*i) + x, 0.15 + RE * 1.7 * sin(2 * Pi / n*i) + y);
	glEnd();

	//����  
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i<n/2; ++i)
		glVertex2f(0.27 + RE*cos(2 * Pi / n*i) + x, 0.15 + RE*2*sin(2 * Pi / n*i) + y);
	for (int i = n / 2; i<n; ++i)
		glVertex2f(0.27+ RE*cos(2 * Pi / n*i) + x, 0.15 + RE * 1.7 * sin(2 * Pi / n*i) + y);
	glEnd();  

	//���
	glColor3f(0.0, 0.0, 0.0);
	
	glBegin(GL_LINE_STRIP);	
	for (int i = n * 5/8 ; i<n * 3.0/4; ++i)
		glVertex2f( RM*3.4*cos(2 * Pi / n*i) + x, -0.08+ RM *sin(2 * Pi / n*i) + y);
	for (int i = n * 3.0 / 4; i<n *7 / 8; ++i)
		glVertex2f(RM * 2.5* cos(2 * Pi / n*i) + x, -0.08 + RM * sin(2 * Pi / n*i) + y);
	glEnd();





	//��������
	
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i<n / 2; ++i)
		glVertex2f(RB*1.2*cos(2 * Pi / n*i) + x, RB*1.1*sin(2 * Pi / n*i) + y);
	for (int i = n / 2; i<n; ++i)
		glVertex2f(RB*1.2*cos(2 * Pi / n*i) + x, RB*0.9*sin(2 * Pi / n*i) + y);
	glEnd();


	glFlush();



}

void reshape(int w, int h)
{
	glViewport(0, 0, 600, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //���ñ���Ϊ��ɫ

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void mykey(unsigned char key, int ax, int ay)
{
	if (key == 'Q' || key == 'q')
		exit(0);
	if (key == 'A' || key == 'a')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		x = x - 0.01;
		myDisplay();
		glFlush();
	}
	if (key == 'D' || key == 'd')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		x += 0.01;
		myDisplay();
		glFlush();
	}
	if (key == 'W' || key == 'w')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		y += 0.01;
		myDisplay();
		glFlush();
	}
	if (key == 'S' || key == 's')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		
		
		site = 0.95;
		
		Sleep(500);
		myDisplay();
		site = 1;
		Sleep(300);
		myDisplay();
		
		Sleep(500);
		site = 0.95;
		y -= 0.025;
		myDisplay();
		

		site = 1;
		y -= 0.025;
		Sleep(500);
		myDisplay();
		glFlush();
	}
	if (key == 'Z' || key == 'z')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		glRotatef(30, 0.0, 0.0, 1.0);
		myDisplay();
		glFlush();
	}
	if (key == 'X' || key == 'x')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		glRotatef(-30, 0.0, 0.0, 1.0);
		myDisplay();
		glFlush();
	}
}

void myMouse(int a, int b)
{
	glViewport(a - 300, 300 - b, 600, 600);
	myDisplay();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("bianfu");
	glutDisplayFunc(myDisplay);

	glutKeyboardFunc(mykey); 
	glutMotionFunc(myMouse);
	//int menue_id = glutCreateMenu(mymenu); //�Ҽ��˵�

	//glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutReshapeFunc(reshape);

	glutMainLoop();
}