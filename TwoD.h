
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
	GLfloat RB; //����뾶
	GLfloat Pi; //Բ����
	GLfloat RE; //�۾��뾶
	GLfloat  RM; //��Ͱ뾶
	GLfloat RA;//�ǰ뾶
	GLfloat  RF;//���뾶
	GLfloat x;  //x������ԭ��
	GLfloat y;  //y������ԭ��
	GLfloat z; //z������ԭ��
	GLfloat sx ; //x�����Ų���
	GLfloat sy ; //y�����Ų���
	GLfloat sz ; //z�����Ų���
	GLfloat site;
};