#include "ShaderWidget.h"

ShaderWidget::ShaderWidget(QWidget *parent) : QOpenGLWidget(parent)
{
	vert_data = new GLfloat[12];
	vert_data[0] = -1.0f;   vert_data[1] = -1.0f;    vert_data[2] = 0.0f;
	vert_data[3] = 1.0f;    vert_data[4] = -1.0f;    vert_data[5] = 0.0f;
	vert_data[6] = 1.0f;    vert_data[7] = 1.0f;     vert_data[8] = 0.0f;
	vert_data[9] = -1.0f;   vert_data[10] = 1.0f;    vert_data[11] = 0.0f;
}

ShaderWidget::~ShaderWidget()
{
	delete[] vert_data;
}


void ShaderWidget::initializeGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	QOpenGLShader vShader(QOpenGLShader::Vertex);
	vShader.compileSourceFile("raytracing.vert");

	QOpenGLShader fShader(QOpenGLShader::Fragment);
	fShader.compileSourceFile("raytracing.frag");

	m_program.addShader(&vShader);
	m_program.addShader(&fShader);
	if (!m_program.link())
	{
		qWarning("Error link program shader");
		return;
	}
	m_position = m_program.attributeLocation("vPosition");

	qDebug() << QString("Log programm");
	qDebug() << m_program.log();
}

void ShaderWidget::resizeGL(int nWidth, int nHeight)
{
	glViewport(0, 0, nWidth, nHeight);
}

void ShaderWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (!m_program.bind())
		return;
	m_program.enableAttributeArray(m_position);
	m_program.setAttributeArray(m_position, vert_data, 3);

	glDrawArrays(GL_QUADS, 0, 4);

	m_program.disableAttributeArray(m_position);

	m_program.release();
}

