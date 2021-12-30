#include "DynamicObjectBase.h"
#include "Register.h"

class TestDynamicObject : public DynamicObjectBase
{
public:
	virtual void Initialise();
	virtual void Release();
protected:
private:
};

REGISTER_DYNAMICOBJECT(TestDynamicObject)


void TestDynamicObject::Initialise()
{
	printf("TestDynamicObject Initialise\n");
}

void TestDynamicObject::Release()
{
	printf("TestDynamicObject Release\n");
	delete this;
}


class TestDynamicObject1 : public DynamicObjectBase
{
public:
	virtual void Initialise();
	virtual void Release();
protected:
private:
};

REGISTER_DYNAMICOBJECT(TestDynamicObject1)


void TestDynamicObject1::Initialise()
{
	printf("TestDynamicObject1 Initialise\n");
}

void TestDynamicObject1::Release()
{
	printf("TestDynamicObject1 Release\n");
	delete this;
}


class TestDynamicObject2 : public DynamicObjectBase
{
public:
	virtual void Initialise();
	virtual void Release();
protected:
private:
};

REGISTER_DYNAMICOBJECT(TestDynamicObject2)


void TestDynamicObject2::Initialise()
{
	printf("TestDynamicObject2 Initialise\n");
}

void TestDynamicObject2::Release()
{
	printf("TestDynamicObject2 Release\n");
	delete this;
}

int main()
{
	DynamicObjectBase* Obj1 = DynamicObjectFactory::Instance()->CreateObject("TestDynamicObject");

	Obj1->Initialise();
	Obj1->Release();

	Obj1 = DynamicObjectFactory::Instance()->CreateObject("TestDynamicObject1");

	Obj1->Initialise();
	Obj1->Release();

	Obj1 = DynamicObjectFactory::Instance()->CreateObject("TestDynamicObject2");

	Obj1->Initialise();
	Obj1->Release();

	return 0;
}
