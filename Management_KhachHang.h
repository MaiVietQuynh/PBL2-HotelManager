#ifndef KhachHang_Manager_H
#define KhachHang_Manager_H
#include"Manager.h"
#include"Double_Link_List.h"
#include"KhachHang.h"

class KhachHangManager : public Manager<KhachHang>
{
    private:
        DoubleLinkedList<KhachHang> list;
    public:
        KhachHangManager();
        ~KhachHangManager();

        void Show();
        void add(KhachHang);
        void addhead(KhachHang);
        void addAt(KhachHang, int);
        bool remove(const KhachHang);
        int indexOf(const KhachHang);
        void ShowByID(const string&); // Hiển thị bằng ID
        KhachHang findByID(const string&); // Tìm bằng ID
        bool removeByID(const string&);
        bool updateByID(const KhachHang, const string&);
        void listByName(const string&);
        void save();
        
       
	    void read();
	    void removeall();
	    void menu();
	    void run();
};
#endif
