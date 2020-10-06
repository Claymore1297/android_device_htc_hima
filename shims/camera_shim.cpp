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

#include <gui/BufferQueue.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/ISurfaceComposer.h>
#include <utils/Errors.h>
#include <utils/String8.h>
#include <utils/StrongPointer.h>

#include <private/gui/ComposerService.h>

#include <string>

using android::sp;
using android::status_t;
using android::IBinder;
using android::IGraphicBufferConsumer;
using android::IGraphicBufferProducer;
using android::PixelFormat;
using android::SurfaceControl;
using android::SurfaceComposerClient;

android::SurfaceComposerClient::Transaction *t = nullptr;
void* sc = nullptr;

// BufferItemConsumer(const sp<IGraphicBufferConsumer& consumer,
//                    uint64_t consumerUsage,
//                    int bufferCount = DEFAULT_MAX_BUFFERS,
//                    bool controlledByApp = false)

extern "C" void _ZN7android18BufferItemConsumerC1ERKNS_2spINS_22IGraphicBufferConsumerEEEyib(
    const sp<IGraphicBufferConsumer>& consumer, uint64_t consumerUsage,
    int bufferCount, bool controlledByApp);

extern "C" void _ZN7android18BufferItemConsumerC1ERKNS_2spINS_22IGraphicBufferConsumerEEEjib(
    const sp<IGraphicBufferConsumer>& consumer, uint32_t consumerUsage,
    int bufferCount, bool controlledByApp) {
  _ZN7android18BufferItemConsumerC1ERKNS_2spINS_22IGraphicBufferConsumerEEEyib(
      consumer, static_cast<uint64_t>(consumerUsage), bufferCount, controlledByApp);
}

extern "C" void _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEERKNS1_INS_19IGraphicBufferAllocEEE(
    sp<IGraphicBufferProducer>* outProducer,
    sp<IGraphicBufferConsumer>* outConsumer,
    void*) {
  // createBufferQueue is a static method, call it directly
  android::BufferQueue::createBufferQueue(outProducer, outConsumer);
}

// GraphicBuffer(uint32_t inWidth, uint32_t inHeight, PixelFormat inFormat,
//               uint32_t inUsage, std::string requestorName = "<Unknown>");
extern "C" void _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
    uint32_t inWidth, uint32_t inHeight, PixelFormat inFormat,
    uint32_t inUsage, std::string requestorName = "<Unknown>");

extern "C" void _ZN7android13GraphicBufferC1Ejjij(
    uint32_t inWidth, uint32_t inHeight, PixelFormat inFormat,
    uint32_t inUsage) {
  _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
      inWidth, inHeight, inFormat, inUsage);
}

//sp<SurfaceControl> SurfaceComposerClient::createSurface(const String8& name, uint32_t w, uint32_t h,
//                                                        PixelFormat format, uint32_t flags,
//                                                        SurfaceControl* parent,
//                                                        LayerMetadata metadata,
//                                                        uint32_t* outTransformHint)
extern "C" void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlENS_13LayerMetadataEPj(const android::String8& name, uint32_t w, uint32_t h,
                                                        PixelFormat format, uint32_t flags,
                                                        SurfaceControl* parent,
                                                        android::LayerMetadata metadata,
                                                        uint32_t* outTransformHint);



extern "C" void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij(
    const android::String8& name, uint32_t w, uint32_t h, PixelFormat format,
    uint32_t flags) {
  android::LayerMetadata metadata;
  sc = _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlENS_13LayerMetadataEPj(name, w, h, format, flags, nullptr, metadata, nullptr);
  return sc;
}

// status_t setLayer(uint32_t layer);
extern "C" status_t _ZN7android14SurfaceControl8setLayerEj(uint32_t layer) {
  t->setLayer((SurfaceControl*)sc, layer);
  return android::NO_ERROR;
}

// android::Fence::~Fence()
extern "C" void _ZN7android5FenceD1Ev() {
  // no-op, the explicit destructor was replaced with = default;
}

extern "C" void _ZN7android21SurfaceComposerClient21openGlobalTransactionEv() {
  t = new(android::SurfaceComposerClient::Transaction);
}

extern "C" void _ZN7android21SurfaceComposerClient17setDisplaySurfaceERKNS_2spINS_7IBinderEEERKNS1_INS_22IGraphicBufferProducerEEE(
    const sp<IBinder>& token, const sp<IGraphicBufferProducer>& bufferProducer) {
  t->setDisplaySurface(token, bufferProducer);
}

extern "C" void _ZN7android21SurfaceComposerClient20setDisplayProjectionERKNS_2spINS_7IBinderEEEjRKNS_4RectES8_(
    const sp<IBinder>& token,
    uint32_t orientation,
    const android::Rect& layerStackRect,
    const android::Rect& displayRect) {
  t->setDisplayProjection(token, static_cast<android::ui::Rotation>(orientation), layerStackRect, displayRect);
}

extern "C" void _ZN7android21SurfaceComposerClient20setDisplayLayerStackERKNS_2spINS_7IBinderEEEj(
    const sp<IBinder>& token, uint32_t layerStack){
  t->setDisplayLayerStack(token, layerStack);
}

extern "C" status_t _ZN7android14SurfaceControl7setSizeEjj(uint32_t w, uint32_t h){
  t->setSize((SurfaceControl*)sc, w, h);
  return android::NO_ERROR;
}

extern "C" status_t _ZN7android14SurfaceControl11setPositionEff(float x, float y){
  t->setPosition((SurfaceControl*)sc, x, y);
  return android::NO_ERROR;
}

extern "C" void _ZN7android21SurfaceComposerClient22closeGlobalTransactionEb(){
  t->apply();
  delete t;
  t = nullptr;
}

//<sp<IBinder> SurfaceComposerClient::getPhysicalDisplayToken(unsigned long long)
extern "C" void *_ZN7android21SurfaceComposerClient23getPhysicalDisplayTokenEy(unsigned long long);

//sp<IBinder> SurfaceComposerClient::getBuiltInDisplay(int32_t id); 
extern "C" void* _ZN7android21SurfaceComposerClient17getBuiltInDisplayEi(int32_t id){
  return _ZN7android21SurfaceComposerClient23getPhysicalDisplayTokenEy(static_cast<uint64_t>(id));
}


extern "C" void _ZN7android14SurfaceControlD0Ev(void);
extern "C" void _ZN7android14SurfaceControlD1Ev(void);
extern "C" void _ZN7android14SurfaceControlD2Ev(void);

extern "C" void _ZN7android14SurfaceControl5clearEv(void){
  _ZN7android14SurfaceControlD0Ev();
}

//android::GraphicBuffer::lock(uint32_t inUsage, void** vaddr, int32_t* outBytesPerPixel,
//                             int32_t* outBytesPerStride);
extern "C" status_t _ZN7android13GraphicBuffer4lockEjPPvPiS3_(uint32_t inUsage, void** vaddr, int32_t* outBytesPerPixel,
                             int32_t* outBytesPerStride);

//status_t GraphicBuffer::lock(uint32_t inUsage, void** vaddr)
extern "C" status_t _ZN7android13GraphicBuffer4lockEjPPv(uint32_t inUsage, void** vaddr){
  return _ZN7android13GraphicBuffer4lockEjPPvPiS3_(inUsage, vaddr, nullptr, nullptr);
}




