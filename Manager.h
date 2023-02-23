#ifndef MANAGER_H
#define MANAGER_H
#include <string>
using namespace std;
template<class T>
class Manager
{
    private:
    public:
        virtual void Show() = 0;
        virtual void ShowByID(const string&) = 0; // Hiển thị bằng ID
        virtual T findByID(const string&) = 0; // Tìm bằng ID
        virtual bool removeByID(const string&) = 0;
        virtual void add(T) = 0; // Thêm vào danh sách
        virtual bool remove(const T) = 0; // Xóa
        virtual bool updateByID(const T, const string&) = 0;
};

#endif