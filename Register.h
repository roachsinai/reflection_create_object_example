#ifndef __REGISTER_H__
#define __REGISTER_H__
#include "DynamicObjectBase.h"

#define REGISTER_DYNAMICOBJECT(name)                                                                                   \
    DynamicObjectBase * Create_##name() { return new name; }                                                  \
    struct Register##name {                                                                                            \
        Register##name() { DynamicObjectFactory::Instance()->Register(#name, Create_##name); }                         \
    } Register_##name;
#endif
