#ifndef ZNDKVLCWIDGET_H
#define ZNDKVLCWIDGET_H

#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QPen>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/YUVVideoFrame.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include "zndkvideostream.h"

class ZNDKVLCWidget : public VlcWidgetVideo
{
    Q_OBJECT

public:
    ZNDKVLCWidget(VlcMediaPlayer *player, QWidget *parent = 0);
    ~ZNDKVLCWidget();

    void requestImage();

protected:
    virtual void paintEvent(QPaintEvent*);

private slots:
    void    getImage(QImage);


private:
    QPixmap* m_pixmap;
    QImage   m_image;
};

#endif // ZNDKVLCWIDGET_H
