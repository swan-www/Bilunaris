#include "../glue/ztf_bind_common.h"

#if ZTF_VERSION_GREATER_THAN_OR_EQUAL(1, 57)
#include "ztf_bind_verify_1_57.cpp";
#elif 
#error THE_FORGE_RELEASE_VER is too old to be verified.
#endif