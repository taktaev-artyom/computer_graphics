#include "Filter.h"

template<class T>
T clamp(T v, int max, int min)
{
	if (v > max)
		return max;
	else if (v < min)
		return min;
	return v;
}

QImage InvertFilter::calculateNewImagePixMap(const QImage& photo, int radius)
{
	QImage result_Image(photo);
	for (int x = 0; x < photo.width(); x++)
		for (int y = 0; y < photo.height(); y++)
		{
			QColor photo_color = photo.pixelColor(x, y);
			photo_color.setRgb(255 - photo_color.red(),
				255 - photo_color.green(),
				255 - photo_color.blue());
			result_Image.setPixelColor(x, y, photo_color);
		}
	return result_Image;
}

QImage Matrix_filter::calculateNewImagePixMap(const QImage& photo, int radius)
{
	QImage result_Image(photo);
	for (int x = 0; x < photo.width(); x++)
		for (int y = 0; y < photo.height(); y++)
		{
			QColor photo_color = calculateNewPixelColor(photo, x, y, radius);
			result_Image.setPixelColor(x, y, photo_color);
		}
	return result_Image;
}

QColor Matrix_filter::calculateNewPixelColor(QImage photo, int x, int y, int radius)
{
	int returnR = 0, returnG = 0, returnB = 0;
	int size = 2 * radius + 1;
	for (int i = -radius; i <= radius; i++)
		for (int j = -radius; j <= radius; j++)
		{
			int idx = (i + radius) * size + j + radius;
			QColor color = photo.pixelColor(clamp<int>(x + j, photo.width() - 1, 0),
				clamp<int>(y + i, photo.height() - 1, 0));
			returnR += color.red() * vector[idx];
			returnG += color.green() * vector[idx];
			returnB += color.blue() * vector[idx];
		}
	return QColor(clamp(returnR, 255, 0), clamp(returnG, 255, 0), clamp(returnB, 255, 0));
}

void Gaussian_blur_filter::createGaussianVector(int radius, int sigma)
{
	const unsigned int size = 2 * radius + 1;
	float norm = 0;
	vector = new double[size * size];
	for (int i = -radius; i <= radius; i++)
		for (int j = -radius; j <= radius; j++)
		{
			int idx = (i + radius) * size + j + radius;
			vector[idx] = exp(-(i * i + j * j) / (sigma * sigma));
			norm += vector[idx];
		}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			vector[i * size + j] /= norm;
		}
}

QImage GrayScaleFilter::calculateNewImagePixMap(const QImage& photo, int radius)
{
	QImage result_Image(photo);
	for (int x = 0; x < photo.width(); x++)
		for (int y = 0; y < photo.height(); y++)
		{
			QColor photo_color = photo.pixelColor(x, y);
			double Intensity = 0.36 * photo_color.red() + 0.53 * photo_color.green() + 0.11 * photo_color.blue();
			photo_color.setRgb(Intensity, Intensity, Intensity);
			result_Image.setPixelColor(x, y, photo_color);
		}
	return result_Image;
}

QImage SepiaFilter::calculateNewImagePixMap(const QImage& photo, int radius)
{
	QImage result_Image(photo);
	for (int x = 0; x < photo.width(); x++)
		for (int y = 0; y < photo.height(); y++)
		{
			QColor photo_color = photo.pixelColor(x, y);
			double Intensity = 0.36 * photo_color.red() + 0.53 * photo_color.green() + 0.11 * photo_color.blue();
			photo_color.setRgb(clamp<double>(Intensity + 2 * k, 255, 0), clamp<double>(Intensity + 0.5 * k, 255, 0), clamp<double>(Intensity - 1 * k, 255, 0));
			result_Image.setPixelColor(x, y, photo_color);
		}
	return result_Image;
}

QImage BrightnessFilter::calculateNewImagePixMap(const QImage& photo, int radius)
{
	QImage result_Image(photo);
	for (int x = 0; x < photo.width(); x++)
		for (int y = 0; y < photo.height(); y++)
		{
			QColor photo_color = photo.pixelColor(x, y);
			photo_color.setRgb(clamp<int>(photo_color.red() + k, 255, 0), clamp<int>(photo_color.green() + k, 255, 0), clamp<int>(photo_color.blue() + k, 255, 0));
			result_Image.setPixelColor(x, y, photo_color);
		}
	return result_Image;
}