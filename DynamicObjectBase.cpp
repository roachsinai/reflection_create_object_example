#include "DynamicObjectBase.h"

DynamicObjectFactory::DynamicObjectFactory() {}
DynamicObjectFactory::~DynamicObjectFactory() {}

DynamicObjectFactory *DynamicObjectFactory::Instance()
{
    static DynamicObjectFactory Ins;

    return &Ins;
}

DynamicObjectBase *DynamicObjectFactory::CreateObject(std::string ObjectName)
{
    if (mCreateDynamicObjectFuncMap.find(ObjectName) != mCreateDynamicObjectFuncMap.end()) {
        DynamicCreateObject Func = mCreateDynamicObjectFuncMap[ObjectName];

        return Func();
    }

    return nullptr;
}

void DynamicObjectFactory::Register(std::string ObjectName, DynamicCreateObject Func)
{
    if (mCreateDynamicObjectFuncMap.find(ObjectName) == mCreateDynamicObjectFuncMap.end()) {
        mCreateDynamicObjectFuncMap[ObjectName] = Func;
    }
}

void DynamicObjectFactory::UnRegister(std::string ObjectName)
{
    if (mCreateDynamicObjectFuncMap.find(ObjectName) != mCreateDynamicObjectFuncMap.end()) {
        mCreateDynamicObjectFuncMap.erase(ObjectName);
    }
}
