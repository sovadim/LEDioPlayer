/****************************************************************************
** Meta object code from reading C++ file 'mediaplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LEDioPlayer/mediaplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MediaPlayer_t {
    QByteArrayData data[17];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayer_t qt_meta_stringdata_MediaPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MediaPlayer"
QT_MOC_LITERAL(1, 12, 4), // "play"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "filename"
QT_MOC_LITERAL(4, 27, 3), // "vol"
QT_MOC_LITERAL(5, 31, 5), // "pause"
QT_MOC_LITERAL(6, 37, 6), // "resume"
QT_MOC_LITERAL(7, 44, 4), // "stop"
QT_MOC_LITERAL(8, 49, 17), // "SetVolumeToStream"
QT_MOC_LITERAL(9, 67, 14), // "SetPosOfScroll"
QT_MOC_LITERAL(10, 82, 3), // "pos"
QT_MOC_LITERAL(11, 86, 15), // "GetTimeOfStream"
QT_MOC_LITERAL(12, 102, 14), // "GetPosOfStream"
QT_MOC_LITERAL(13, 117, 4), // "free"
QT_MOC_LITERAL(14, 122, 6), // "getFFT"
QT_MOC_LITERAL(15, 129, 6), // "float*"
QT_MOC_LITERAL(16, 136, 3) // "fft"

    },
    "MediaPlayer\0play\0\0filename\0vol\0pause\0"
    "resume\0stop\0SetVolumeToStream\0"
    "SetPosOfScroll\0pos\0GetTimeOfStream\0"
    "GetPosOfStream\0free\0getFFT\0float*\0fft"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x0a /* Public */,
       5,    0,   69,    2, 0x0a /* Public */,
       6,    0,   70,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x0a /* Public */,
       8,    1,   72,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,
      13,    0,   80,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    0x80000000 | 15, 0x80000000 | 15,   16,

       0        // eod
};

void MediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MediaPlayer *_t = static_cast<MediaPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->pause(); break;
        case 2: _t->resume(); break;
        case 3: _t->stop(); break;
        case 4: _t->SetVolumeToStream((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SetPosOfScroll((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { int _r = _t->GetTimeOfStream();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->GetPosOfStream();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->free(); break;
        case 9: { float* _r = _t->getFFT((*reinterpret_cast< float*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MediaPlayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MediaPlayer.data,
      qt_meta_data_MediaPlayer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
