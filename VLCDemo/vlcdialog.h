#ifndef VLCDIALOG_H
#define VLCDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/YUVVideoFrame.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include "zndkvideostream.h"

class VLCDialog : public QDialog
{
    Q_OBJECT

public:
    VLCDialog(QWidget *parent = 0);
    ~VLCDialog();

protected:
    virtual void paintEvent(QPaintEvent*);

private slots:
    void    getImage(QImage);

private:
    QPixmap* m_pixmap;
    QImage   m_image;

    VlcInstance *m_instance;
    VlcMedia *m_media;
    VlcMediaPlayer *m_player;
    ZNDKVideoStream* m_stream;
};

#endif // VLCDIALOG_H
