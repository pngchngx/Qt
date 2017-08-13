#include "MyWidget.h"
#include <QApplication>
#include <QDebug>
#include <QLabel>
#include <QIODevice>
#include <QFile>
#include <QBuffer>
#include <QTextStream>
#include <QDataStream>

#include "TcpServer.h"
#include "TcpClient.h"
#include "udp1.h"
#include "udp2.h"


//QFile
//QBuffer // memory file
//QTcpSocket
//QUdpSocket

//QDataStream  // io method
//QTextStream



MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
#if 0
    QFile file("../MyTest.txt");
    file.open(QIODevice::ReadWrite);

    file.write(QByteArray("abc"));
    // file.seek
   // file.write()

    file.close();
#endif
#if 0
    QByteArray ba("天天动听");
    QString str("天天动听");
    qDebug() << ba.size() << str.size(); // 12,4
#endif
#if 0
    QBuffer buf;
    buf.open(QIODevice::ReadWrite);

    buf.write("abc");
    buf.write("aabbcc");

    buf.close();

    qDebug() << buf.buffer();
#endif
#if 0
    // send side
    QBuffer buf;
    buf.open(QIODevice::ReadWrite);
    QPixmap pixmap("../aaa.png");
    pixmap.save(&buf, "PNG");
    buf.close();
    qDebug() << buf.buffer().size();

    // recv side
    QPixmap pixmap2;
    pixmap2.loadFromData(buf.buffer(), "PNG");

    QLabel* label = new QLabel(this);
    label->setPixmap(pixmap2);
#endif
#if 0
    QFile file("../teststream.txt");
    file.open(QIODevice::ReadWrite);

    QTextStream textStream(&file);
    textStream << 1 << "abc" << 1.2 << QString("abc");

    file.close();
#endif
#if 0
    QFile file("../datastream.txt");
    file.open(QIODevice::ReadWrite);

    QDataStream dataStream(&file);
    dataStream << 1 << "abc" << 1.2 << QString("abc") << QPoint(1, 1);

    file.close();
#endif
#if 0
    QFile file("../datastream.txt");
    file.open(QIODevice::ReadWrite);

    QDataStream dataStream(&file);

    int i;
    char* buf;
    double d;
    QString str;
    QPoint pt;
    dataStream >> i >> buf >> d >> str >> pt;
    //delete[] buf;
    qDebug() << i << buf << d << str << pt;
    file.close();
#endif
#if 0
    // virtual memory
    QFile file("../map.txt");

    file.open(QIODevice::ReadWrite);
    file.resize(64*1024);
//    file.seek(65535);
//    file.write("1");
//    file.close();
//    file.open(QIODevice::ReadWrite);

    uchar* ptr = file.map(0, 64*1024);
    // write file
    *ptr = 'a';
    ptr[1] = 'b';
    // read file
    //uchar ch = *ptr;
    file.unmap(ptr);

    file.close();
#endif
}



#if 0
// main() for file read and write
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    app.exec();
}
#endif

// main() for tcp and udp
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

#if 0
    TcpServer s;
    s.setWindowTitle("TCP server");
    s.show();
    TcpClient c;
    c.setWindowTitle("TCP client");
    c.show();
#endif

    Udp1 udp1;
    udp1.setWindowTitle("UDP1");
    udp1.show();
    Udp2 udp2;
    udp2.setWindowTitle("UDP2");
    udp2.show();

    return app.exec();
}
