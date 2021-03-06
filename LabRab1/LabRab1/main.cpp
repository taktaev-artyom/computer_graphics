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
	QImage blurImage = blur->calculateNewImagePixMap(photo, 1);
	blurImage.save("Blur.PNG");
	Gaussian_blur_filter* gblur = new Gaussian_blur_filter();
	QImage gblurImage = gblur->calculateNewImagePixMap(photo, 3);
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
	QImage sharpImage = sharp->calculateNewImagePixMap(photo, 1);
	sharpImage.save("Sharp.PNG");
	Sobel_filterX* sobelx = new Sobel_filterX();
	QImage sobelxImage = sobelx->calculateNewImagePixMap(photo, 1);
	sobelxImage.save("SobelX.PNG");
	Sobel_filterY* sobely = new Sobel_filterY();
	QImage sobelyImage = sobely->calculateNewImagePixMap(photo, 1);
	sobelyImage.save("SobelY.PNG");
	Motion_blur* motion_blur = new Motion_blur();
	QImage motion_blurImage = motion_blur->calculateNewImagePixMap(photo, 8);
	motion_blurImage.save("Motion_blur.PNG");
	Sharpness_filter1* sharp1 = new Sharpness_filter1();
	QImage sharpImage1 = sharp1->calculateNewImagePixMap(photo, 1);
	sharpImage1.save("Sharp1.PNG");
	TransferFilter* transfer = new TransferFilter();
	QImage transferImage = transfer->calculateNewImagePixMap(photo, 0);
	transferImage.save("Transfer.PNG");
	TurnFilter* turn = new TurnFilter();
	QImage turnImage = turn->calculateNewImagePixMap(photo, 0);
	turnImage.save("Turn.PNG");
	WavesXFilter* wavex = new WavesXFilter();
	QImage wavexImage = wavex->calculateNewImagePixMap(photo, 0);
	wavexImage.save("WaveX.PNG");
	WavesYFilter* wavey = new WavesYFilter();
	QImage waveyImage = wavey->calculateNewImagePixMap(photo, 0);
	waveyImage.save("WaveY.PNG");
}
