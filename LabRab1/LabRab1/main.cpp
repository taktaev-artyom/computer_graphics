#include <QImage>
#include <string>
#include "Filter.h"

using namespace std;

void main(int argc, char* argv[])
{
	string s;
	QImage photo;
	for (int i = 0; i < argc; i++)
	{
		if (!strcmp(argv[i], "-p") && (i + 1 < argc))
		{
			s = argv[i + 1];
		}
	}
	photo.load(QString(s.c_str()));
	photo.save("Starting.PNG");
	InvertFilter* invert = new InvertFilter();
	QImage invertImage = invert->calculateNewImagePixMap(photo, 0);
	invertImage.save("Invert.PNG");
	Blur_filter* blur = new Blur_filter();
	QImage blurImage = blur->calculateNewImagePixMap(photo, 0);
	blurImage.save("Blur.PNG");
	Gaussian_blur_filter* gblur = new Gaussian_blur_filter();
	QImage gblurImage = gblur->calculateNewImagePixMap(photo, 0);
	gblurImage.save("GBlur.PNG");
	GrayScaleFilter* grayscale = new GrayScaleFilter();
	QImage grayscaleImage = grayscale->calculateNewImagePixMap(photo, 0);
	grayscaleImage.save("GrayScale.PNG");
	SepiaFilter* sepia = new SepiaFilter();
	QImage sepiaImage = sepia->calculateNewImagePixMap(photo, 0);
	sepiaImage.save("Sepia.PNG");
	BrightnessFilter* bright = new BrightnessFilter();
	QImage brightImage = bright->calculateNewImagePixMap(photo, 0);
	brightImage.save("Bright.PNG");
	Sharpness_filter* sharp = new Sharpness_filter();
	QImage sharpImage = sharp->calculateNewImagePixMap(photo, 0);
	sharpImage.save("Sharp.PNG");
}
