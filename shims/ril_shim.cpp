#include <media/AudioSystem.h>


//uintptr_t AudioSystem::addErrorCallback(audio_error_callback cb)
extern "C" void * _ZN7android11AudioSystem16addErrorCallbackEPFviE(android::audio_error_callback cb);

// void AudioSystem::setErrorCallback(audio_error_callback cb)
extern "C" void _ZN7android11AudioSystem16setErrorCallbackEPFviE(android::audio_error_callback cb){
    _ZN7android11AudioSystem16addErrorCallbackEPFviE(cb);
}
