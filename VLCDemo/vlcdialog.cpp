#include "vlcdialog.h"
#include <QDebug>

VLCDialog::VLCDialog(QWidget *parent)
    : QDialog(parent)
{
    setMinimumSize(800, 600);
    resize(800, 600);

    m_pixmap = NULL;

    setAutoFillBackground(false);

    m_instance = new VlcInstance(VlcCommon::args());
    m_player = new VlcMediaPlayer(m_instance);

    m_stream = new ZNDKVideoStream(Vlc::YUVFormat);
    connect(m_stream, SIGNAL(sendImage(QImage)),this,SLOT(getImage(QImage)), Qt::AutoConnection);
    m_stream->setCallbacks(m_player);

    QString url("rtsp://218.204.223.237:554/live/1/0547424F573B085C/gsfp90ef4k0a6iap.sdp");
    m_media = new VlcMedia(url, m_instance);

    m_player->open(m_media);
    m_stream->init(m_player);
}

VLCDialog::~VLCDialog()
{
    delete m_player;
    delete m_media;
    delete m_instance;
    if(m_pixmap != NULL)
    {
        delete m_pixmap;
        m_pixmap = NULL;
    }
}

void VLCDialog::paintEvent(QPaintEvent*)
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

    QPainter basePainter(this);
    basePainter.begin(this);
    basePainter.setRenderHint(QPainter::Antialiasing, true);
    basePainter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    basePainter.drawPixmap(rect, *m_pixmap);
    basePainter.end();
}

void VLCDialog::getImage(QImage img)
{
    m_image = img;
    repaint();
}
