#include "ZNDKVLCWidget.h"
#include <QDebug>

ZNDKVLCWidget::ZNDKVLCWidget(VlcMediaPlayer *player, QWidget *parent)
    : VlcWidgetVideo(player, parent)
{
    m_pixmap = NULL;

    setAutoFillBackground(false);
}

ZNDKVLCWidget::~ZNDKVLCWidget()
{

    if(m_pixmap != NULL)
    {
        delete m_pixmap;
        m_pixmap = NULL;
    }
}

void ZNDKVLCWidget::paintEvent(QPaintEvent*)
{
    QRect rect = this->rect();
    if(m_pixmap != NULL)
    {
        if(m_pixmap->width() != rect.width() || m_pixmap->height() != rect.height())
        {
            delete m_pixmap;
            m_pixmap = NULL;
        }
    }
    if(m_pixmap == NULL)
    {
        m_pixmap = new QPixmap(rect.size());
        if(m_pixmap == NULL) return;
    }

    QPainter painter(m_pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.drawImage(rect, m_image);
    QPen pen(QColor(Qt::green));
    painter.setPen(pen);
    painter.drawRect(50, 50, 100, 200);

    QPainter basePainter(this);
    basePainter.begin(this);
    basePainter.setRenderHint(QPainter::Antialiasing, true);
    basePainter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    basePainter.drawPixmap(rect, *m_pixmap);
    basePainter.end();
}

void ZNDKVLCWidget::getImage(QImage img)
{
    m_image = img;
    repaint();
}
