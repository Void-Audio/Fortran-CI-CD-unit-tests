#pragma once
#include <cstddef>
#include <vector>

extern "C" {

    void ringpush(float* value);
         
    void ringpopall(float* , size_t nFrames);

}
