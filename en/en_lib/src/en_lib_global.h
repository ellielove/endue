#ifndef EN_LIB_GLOBAL_H
#define EN_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EN_LIB_LIBRARY)
#  define EN_LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define EN_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EN_LIB_GLOBAL_H
