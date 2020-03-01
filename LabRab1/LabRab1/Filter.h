#pragma once
#include <qimage.h>

class Filter
{
public:
	Filter() {};
	~Filter() {};

	virtual QImage calculateNewImagePixMap(const QImage& photo, int radius) = 0;
};

class InvertFilter : public Filter
{
public:
	InvertFilter() {};
	~InvertFilter() {};
	QImage calculateNewImagePixMap(const QImage& photo, int radius);
};

class Matrix_filter : public Filter
{
public:
	double* vector;
	int mRadius;
	Matrix_filter(int radius = 1) : mRadius(radius) {};
	QImage calculateNewImagePixMap(const QImage& photo, int radius);
	QColor calculateNewPixelColor(QImage photo, int x, int y, int radius);
};

class Blur_filter : public Matrix_filter
{
public:
	Blur_filter()
	{
		int size = 2 * mRadius + 1;
		vector = new double[size * size];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				vector[i * size + j] = 1.0f / (size * size);
	}
};

class Gaussian_blur_filter : public Matrix_filter
{
public:
	Gaussian_blur_filter()
	{
		createGaussianVector(3, 2);
	}
	~Gaussian_blur_filter() {};

	void createGaussianVector(int radius, int sigma);
};

class GrayScaleFilter : public Filter
{
public:
	GrayScaleFilter() {};
	~GrayScaleFilter() {};
	QImage calculateNewImagePixMap(const QImage& photo, int radius);
};

class SepiaFilter : public Filter
{
public:
	int k;
	SepiaFilter() { k = 20; }
	~SepiaFilter() {};
	QImage calculateNewImagePixMap(const QImage& photo, int radius);
};

class BrightnessFilter : public Filter
{
public:
	int k;
	BrightnessFilter() { k = 50; }
	~BrightnessFilter() {};
	QImage calculateNewImagePixMap(const QImage& photo, int radius);
};

class Sharpness_filter : public Matrix_filter
{
public:
	Sharpness_filter()
	{
		int size = 2 * mRadius + 1;
		vector = new double[size * size];
		vector[0] = vector[2] = vector[6] = vector[8] = 0;
		vector[1] = vector[3] = vector[5] = vector[7] = 0;
		vector[4] = -5;
	}
};