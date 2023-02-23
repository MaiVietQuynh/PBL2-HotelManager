#ifndef Phong_Manager_H
#define Phong_Manager_H
#include "Manager.h"
#include "Double_Link_List.h"
#include "Phong.h"

class PhongManager : public Manager<Phong>
{
private:
    DoubleLinkedList<Phong> list;

public:
    PhongManager();
    
    ~PhongManager();
    void Show();
    void add(Phong);
    bool remove(const Phong);
    int indexOf(const Phong);
    void ShowByID(const string&);   // Hiển thị bằng ID
    Phong findByID(const string &); // Tìm bằng ID
    bool removeByID(const string &);
    bool updateByID(const Phong, const string &);
    void listByStatus(const bool &);
    void listByName(const string&);
    void save();
    void read();
    void removeall(); // ?????
    void menu();
    void run();
};
#endif
