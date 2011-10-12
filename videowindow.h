#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

#include <opencv2/opencv.hpp>

#define MAX_USER_NUM 12

class QNamedFrame;

class VideoWindow: public QDialog
{
	Q_OBJECT

public:
	VideoWindow();
	~VideoWindow();
	int openCamera(int device);

private slots:
	void refreshImage();

private:
	cv::VideoCapture cap; 
	QVBoxLayout *layout;
	QNamedFrame *selfImage;
};

class QNamedFrame : public QWidget {
	private:
		QLabel *nameLabel;
		QLabel *imageLabel;
		QVBoxLayout *layout;
	public:
		QNamedFrame();
		~QNamedFrame();
		void setName(QString name);
		void setImage(QImage image);
};

#endif
