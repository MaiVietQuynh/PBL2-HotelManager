#ifndef PHONG_H
#define PHONG_H
#include<fstream>
#include<string>
#include<iostream>
#include <iomanip>
#include "Double_Link_List.h"

using namespace std;
class Phong
{
    private:
       string MaPhong;
       string LoaiPhong;
       int GiaPhong;
       bool Trangthai;
    public:
       Phong();
       Phong(string mp, string loaiphong,int Gia, bool TT);
       Phong(const Phong& S);
 
    //Getter:
       string getId();
       string getLoaiPhong();
       int getGiaPhong();   
       bool getTrangthai();
       string getStrTrangThai();
    //Setter:
       void setMaPhong(string );
       void setLoaiPhong(string name);
       void setGiaPhong(int Gia);
       void setTrangthai(bool TT);

      static bool isValidId(const string&);
      void update(const Phong&);

       void Input(string mp);
       void Update(string mp);
       void Output();
       void ImportFromFile(ifstream&);
       void ExportToFile(ostream&);
       // Đa nang hóa cái ==, =
       // >>, << 
       bool operator==(const Phong&);
       const Phong& operator=(const Phong&);
       bool checkMaPhong(DoubleLinkedList<Phong> list, string maphong);
};
#endif
