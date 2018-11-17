#include "c_interface.h"
#include "cpp_interface.h"


// wrap c-struct into a real cpp-class
class InterfaceAdapter : public Interface{
private:
    CInterface *obj;
    bool object_owned;
public:
    InterfaceAdapter(CInterface *obj_, bool object_owned_=false):
        obj(obj_), object_owned(object_owned_)
    {}

    ~InterfaceAdapter() override
    {
        if(object_owned){
            obj->vt->dtor(obj);
        }
    }
    
    void foo() override
    {
        obj->vt->foo(obj);
    }

    int bar(int n) override
    {
        return obj->vt->bar(obj, n);
    }

};

void c_use_interface(CInterface *o){
    InterfaceAdapter adapter(o);
    use_interface(adapter);
}
