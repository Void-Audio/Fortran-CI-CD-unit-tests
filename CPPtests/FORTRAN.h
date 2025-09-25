#pragma once
#include <cstddef>
#include <vector>

extern "C" {

    void ringpush(float* value);
         
    void ringpopall(float* outBuffer, size_t nFrames);

    void vprocess(const float* inBuffer, float* outBuffer);

}
