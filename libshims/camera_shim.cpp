/*
 * Copyright (C) 2016 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>

//using namespace android;

// GraphicBuffer(uint32_t inWidth, uint32_t inHeight, PixelFormat inFormat,
//               uint32_t inUsage, std::string requestorName = "<Unknown>");
extern "C" void _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
    uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage,
    std::string requestorName);

extern "C" void _ZN7android13GraphicBufferC1Ejjij(
    uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage) {
  std::string requestorName = "<Unknown>";
  _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
      inWidth, inHeight, inFormat, inUsage, requestorName);
}

extern "C" void _ZN7android21SurfaceComposerClient17setDisplaySurfaceERKNS_2spINS_7IBinderEEENS1_INS_22IGraphicBufferProducerEEE(
    uint32_t token, uint32_t bufferProducer);
//    const sp<IBinder>& token, sp<IGraphicBufferProducer> bufferProducer);

extern "C" void _ZN7android21SurfaceComposerClient17setDisplaySurfaceERKNS_2spINS_7IBinderEEERKNS1_INS_22IGraphicBufferProducerEEE(
    uint32_t token, uint32_t bufferProducer) {
//    const sp<IBinder>& token, const sp<IGraphicBufferProducer>& bufferProducer) {
  _ZN7android21SurfaceComposerClient17setDisplaySurfaceERKNS_2spINS_7IBinderEEENS1_INS_22IGraphicBufferProducerEEE(
      token, bufferProducer);
}

extern "C" void _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEEb(
    void *outProducer, void *outConsumer, bool consumerIsSurfaceFlinger);

extern "C" void _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEERKNS1_INS_19IGraphicBufferAllocEEE(
    void *outProducer, void *outConsumer, void *allocator __unused) {
  _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEEb(
      outProducer, outConsumer, false);
}

extern "C" void _ZN7android18BufferItemConsumerC1ENS_2spINS_22IGraphicBufferConsumerEEEjib(
    uint32_t consumer, uint32_t consumerUsage, int bufferCount, bool controlledByApp) {
  _ZN7android18BufferItemConsumerC1ENS_2spINS_22IGraphicBufferConsumerEEEjib(
      consumer, consumerUsage, bufferCount, false);
}

extern "C" void _ZN7android18BufferItemConsumerC1ERKNS_2spINS_22IGraphicBufferConsumerEEEjib
(
     //   const sp<IGraphicBufferConsumer>&consumer, unsigned int, int, bool)
     uint64_t consumer, uint64_t consumerUsage, int bufferCount, bool controlledByApp){
     _ZN7android18BufferItemConsumerC1ERKNS_2spINS_22IGraphicBufferConsumerEEEjib(
     consumer, consumerUsage, bufferCount, false);
}

/*
sp<SurfaceControl> SurfaceComposerClient::createSurface(
        const String8& name,
	uint32_t w,
	uint32_t h,
	PixelFormat format,
	uint32_t flags)
sp<SurfaceControl> SurfaceComposerClient::createSurface(
        const String8& name,
        uint32_t w,
        uint32_t h,
        PixelFormat format,
        uint32_t flags,
        SurfaceControl* parent,
        uint32_t windowType,
        uint32_t ownerUid)
*/
/*#include <string>*/
#include <utils/RefBase.h>
#include <gui/SurfaceComposerClient.h>

extern "C" void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(
    android::String8 const & s, uint32_t w, uint32_t h,
    android::PixelFormat fmt, uint32_t flags, void *parent, uint32_t windowType,
    uint32_t ownerUid);

// sp<SurfaceControl> android::SurfaceComposerClient::createSurface(android::String8 const&, unsigned int, unsigned int, int, unsigned int)
extern "C" void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij(
    android::String8 const& s, uint32_t w, uint32_t h,
    android::PixelFormat fmt, uint32_t flags) {
  return _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(
      s, w, h, fmt, flags, NULL, 0, 0);
}

//    const sp<IBinder>& token, sp<IGraphicBufferProducer> bufferProducer);

#include <system/window.h>
#include <ui/PixelFormat.h>
#include <ui/Rect.h>
#include <gui/SurfaceControl.h>

namespace android {
extern "C" {

    status_t _ZN7android14SurfaceControl8setLayerEj( uint32_t layer)
    {
    return _ZN7android14SurfaceControl8setLayerEj ( (int32_t)layer);
    }
}
}

const char *_ZN7android20CameraParameters_EXT30KEY_SMILEINFO_BYFACE_SUPPORTEDE = "smileinfo-byface-supported";
