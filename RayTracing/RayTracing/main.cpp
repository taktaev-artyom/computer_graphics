#pragma comment(lib, "opengl32.lib")
#include "ShaderWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ShaderWidget w;
	w.show();
	return a.exec();
}
