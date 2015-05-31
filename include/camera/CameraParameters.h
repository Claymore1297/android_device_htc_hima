#ifndef ANDROID_HARDWARE_CAMERA_PARAMETERS_EXT_H
#define ANDROID_HARDWARE_CAMERA_PARAMETERS_EXT_H

#include <utils/KeyedVector.h>
#include <utils/String8.h>
#include_next "camera/CameraParameters.h"

namespace android {

class CameraParameters_EXT: public CameraParameters
{
public:
    CameraParameters_EXT();
    CameraParameters_EXT(const String8 &params) { unflatten(params); }
    ~CameraParameters_EXT();

    String8 flatten() const;
    void unflatten(const String8 &params);

    void remove(const char *key);

#ifdef CAMERA_PARAMETERS_EXT_H
CAMERA_PARAMETERS_EXT_H
#endif

private:
    DefaultKeyedVector<String8,String8>    mMap;
};

}

#endif
