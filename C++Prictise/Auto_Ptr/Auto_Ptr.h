#include <iostream>
using namespace std;

template<class T>
class Auto_Ptr
{
    public:
        Auto_Ptr(T* _ptr)
            :ptr(_ptr)
        {}
        Auto_Ptr(Auto_Ptr<T>& p)
            :ptr(p.ptr)
        {
            ptr = NULL;
        }
        Auto_Ptr<T>& operator=(Auto_Ptr<T>& p)
        {
            if(this != &p)
            {
                delete ptr;
                ptr = p.ptr;
                p.ptr = NULL;
            }
            return *this;
        }
        T& operator*()
        {
            return *ptr;
        }
        T* operator->()
        {
            return ptr;
        }
        ~Auto_Ptr()
        {
            if(ptr != NULL)
            {
                delete ptr;
                cout<<"释放"<<endl;
            }
        }
    protected:
        T* ptr;
};
//template<class T>
//class Auto_Ptr
//{
//    public:
//        Auto_Ptr(T* _ptr)
//            :ptr(_ptr)
//             ,owner(true)
//        {}
//        Auto_Ptr(Auto_Ptr<T>& p)
//            :ptr(p.ptr)
//        {
//            owner = true;
//            p.owner = false;
//        }
//        Auto_Ptr<T>& operator=(Auto_Ptr<T>& p)
//        {
//            if(this != &p)
//            {
//                owner = true;
//                p.owner = false;
//            }
//            return *this;
//        }
//        T& operator*()
//        {
//            return *ptr;
//        }
//        T* operator->()
//        {
//            return ptr;
//        }
//        ~Auto_Ptr()
//        {
//            if(ptr != NULL && owner == true)
//            {
//                delete ptr;
//                cout<<"释放"<<endl;
//            }
//        }
//    protected:
//        T* ptr;
//        bool owner;
//};
