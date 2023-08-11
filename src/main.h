#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <iostream>
#include <vector>
// FFmpeg
extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libavutil/pixdesc.h>
#include <libswscale/swscale.h>
}

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget* parent=0);
    ~MainWindow();
public slots:
    void storeContent();
private:
    QPushButton *m_button;
};

#endif // MAINWINDOW_H
