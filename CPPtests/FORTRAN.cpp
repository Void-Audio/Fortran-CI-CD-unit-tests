#include "FORTRAN.h"

extern "C" {
.

    void VVerb_peek_ring_full(VOID_Verb_t* v, float* outBuffer, size_t nFrames) {
        if (!v || !outBuffer) return;

        extern void rb_peek_full_(VOID_Verb_t* vptr, float* outptr, size_t* nFrames);
        size_t n = nFrames;
        rb_peek_full_(v, outBuffer, &n);
    }
}
