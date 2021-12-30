#ifndef __BASE_H__
#define __BASE_H__
#include <string>
#include <map>

class DynamicObjectBase
{
public:
    DynamicObjectBase() {}
    virtual ~DynamicObjectBase() {}
    virtual void Initialise() {}
    virtual void Release() {}

  protected:
  private:
};

class DynamicObjectFactory
{
    typedef DynamicObjectBase *(*DynamicCreateObject)();

public:
    static DynamicObjectFactory *Instance();

    DynamicObjectBase *CreateObject(std::string ObjectName);

    void Register(std::string ObjectName, DynamicCreateObject Func);

    void UnRegister(std::string ObjectName);

protected:
    DynamicObjectFactory();
    ~DynamicObjectFactory();

    std::map<std::string, DynamicCreateObject> mCreateDynamicObjectFuncMap;
};
#endif
