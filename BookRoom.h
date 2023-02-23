#pragma once
#include <string>
#include "Phong.h"
#include "KhachHang.h"
#include "Date.h"

#include "Management_KhachHang.h"
#include "Management_NhanVien.h"
#include "Management_Phong.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class BookRoom
{
private:
   string Id; // id phong
   Date ngaythue;
   Date ngaytra;
   string MaNV;
   string MaKH;
   int tongtien;

public:
   BookRoom();
   ~BookRoom();

   void setMaNV(string ma);
   string getMaNV();
   void setMaKH(string ma);
   string getMaKH();
   void setId(string id);

   void setngaythue(Date ngay);
   void setngaytra(Date ngay);
   void ImportFromFile(ifstream &in);
   void ExportToFile(ostream &);
   string getId();
   void out(ostream &os);
   void Show();

   void removeat(int vt);
};

