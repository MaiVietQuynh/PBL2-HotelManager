#ifndef MANAGERBORROW_H
#define MANAGERBORROW_H
#include <string>
#include <iostream>
#include "BookRoom.h"
#include "Double_Link_List.h"
#include "Management_KhachHang.h"
#include "Management_NhanVien.h"
#include "Management_Phong.h"

using namespace std;

class BookRoomManager: public  Manager<BookRoom>
{
    private:
    	DoubleLinkedList<BookRoom> list;
    public:
    	BookRoomManager();
        void Show();
        void ShowByID(const string&) ; // Hiển thị bằng ID
        BookRoom findByID(const string&) ; // Tìm bằng ID
        bool removeByID(const string&) ;
        void add(BookRoom); // Thêm vào danh sách
        bool remove(const BookRoom) ; // Xóa
        bool updateByID(const BookRoom, const string&) ;
        
        int countBorrow(const string&);
        bool DatPhong();
    	bool TraPhong();
    	int getVT(string id);
    	int getvtidPhong(string id, string ds[], int n);
    	void run();
    	void Menu();
    	void save();
    	bool update();
};

#endif
