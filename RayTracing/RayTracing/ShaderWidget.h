#pragma once

#include <QtOpenGL>
#include <QTimer>
#include <qimage.h>
#include <algorithm>

#include <QMatrix4x4>

class ShaderWidget : public QOpenGLWidget
{
private:
	QOpenGLShaderProgram m_program;

	GLfloat* vert_data;
	int m_position;

protected:
	void initializeGL() override;
	void resizeGL(int nWidth, int nHeight) override;
	void paintGL() override;
public:
	ShaderWidget(QWidget *parent = 0);
	~ShaderWidget();
};
