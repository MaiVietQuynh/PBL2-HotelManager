#ifndef NhanVien_Manager_H
#define NhanVien_Manager_H
#include "Manager.h"
#include"Double_Link_List.h"
#include"NhanVien.h"

class NhanVienManager : public Manager<NhanVien>
{
    private:
        DoubleLinkedList<NhanVien> list;
    public:
        NhanVienManager();
        ~NhanVienManager();

        void Show();
        void add(NhanVien);
        void addhead(NhanVien);
        void addAt(NhanVien, int);
        bool remove(const NhanVien);
        int indexOf(const NhanVien);
        void ShowByID(const string&); // Hiển thị bằng ID
        NhanVien findByID(const string&); // Tìm bằng ID
        bool removeByID(const string&);
        bool updateByID(const NhanVien, const string&);
        void listByName(const string&);
        void save();
        
       
	    void read();
	    void removeall();
	    void menu();
	    void run();
};
#endif
