
#include <GL/glut.h>
#include <windows.h>
#include <math.h>

class TwoD {
public :
	 TwoD();
	 TwoD(GLfloat x0, GLfloat y0, GLfloat z0);
	 void init();
	void display();
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();
	void fly();
	void bigger();
	void smaller();
	void mouse(int a, int b);
private:

	int n;
	GLfloat RB; //身体半径
	GLfloat Pi; //圆周率
	GLfloat RE; //眼睛半径
	GLfloat  RM; //嘴巴半径
	GLfloat RA;//角半径
	GLfloat  RF;//翅膀半径
	GLfloat x;  //x轴坐标原点
	GLfloat y;  //y轴坐标原点
	GLfloat z; //z轴坐标原点
	GLfloat sx ; //x轴缩放参数
	GLfloat sy ; //y轴缩放参数
	GLfloat sz ; //z轴缩放参数
	GLfloat site;
};