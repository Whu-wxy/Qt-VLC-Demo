#include "zndkvlcdialog.h"
#include <QDebug>

ZNDKVLCDialog::ZNDKVLCDialog()
{
    setMinimumSize(800, 600);
    resize(800, 600);

    m_instance = new VlcInstance(VlcCommon::args());
    m_player = new VlcMediaPlayer(m_instance);
    m_vlcWidget = new ZNDKVLCWidget(m_player);
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_vlcWidget);

    m_stream = new ZNDKVideoStream(Vlc::YUVFormat);
    connect(m_stream, SIGNAL(sendImage(QImage)),m_vlcWidget,SLOT(getImage(QImage)), Qt::AutoConnection);
    m_stream->setCallbacks(m_player);

    QString url("rtsp://218.204.223.237:554/live/1/0547424F573B085C/gsfp90ef4k0a6iap.sdp");
    m_media = new VlcMedia(url, m_instance);
   // m_media->setOption(":network-caching=30");

    m_player->open(m_media);
    m_stream->init(m_player);
}

ZNDKVLCDialog::~ZNDKVLCDialog()
{
    delete m_player;
    delete m_media;
    delete m_instance;
}
