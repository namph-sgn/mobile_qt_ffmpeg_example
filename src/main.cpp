#include <QtGui>
#include <QtQml>
#include <iostream>
#include "dataentrymodel/dataentrymodel.h"
extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libavutil/pixdesc.h>
#include <libswscale/swscale.h>
}
#include <nx/build_info.h>

int main(int argc, char **argv)
{
  QGuiApplication app(argc, argv);

  qmlRegisterType<DataEntryModel>("nam.example", 1, 0, "DataEntryModel");

  const char *infile = "/home/oryza/Downloads/video.mp4";

  int ret;
  AVFormatContext *inctx = nullptr;
  ret = avformat_open_input(&inctx, infile, nullptr, nullptr);
  if (ret < 0)
  {
    std::cerr << "fail to avforamt_open_input(\"" << infile << "\"): ret=" << ret;
    return 2;
  }
  // retrive input stream information
  ret = avformat_find_stream_info(inctx, nullptr);
  if (ret < 0)
  {
    std::cerr << "fail to avformat_find_stream_info: ret=" << ret;
    return 2;
  }

  // find primary video stream
  AVCodec* vcodec = nullptr;
  ret = av_find_best_stream(inctx, AVMEDIA_TYPE_VIDEO, -1, -1, &vcodec, 0);
  if (ret < 0) {
    std::cerr << "fail to av_find_best_stream: ret=" << ret;
    return 2;
  }
  const int vstrm_idx = ret;
  AVStream* vstrm = inctx->streams[vstrm_idx];

  // print input video stream informataion
  std::cout
      << "infile: " << infile << "\n"
      << "format: " << inctx->iformat->name << "\n"
      << "vcodec: " << vcodec->name << "\n"
      << "size:   " << vstrm->codecpar->width << 'x' << vstrm->codecpar->height << "\n"
      << "length: " << av_rescale_q(vstrm->duration, vstrm->time_base, {1,1000}) / 1000. << " [sec]\n"
      << "frame:  " << vstrm->nb_frames << "\n"
      << std::flush;


  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
