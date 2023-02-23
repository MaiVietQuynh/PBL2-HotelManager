 #include "BookRoom.h"

 BookRoom::BookRoom()
 {
 }

 BookRoom::~BookRoom()
 {
 }
 void  BookRoom::setId(string id)
 {
 	this->Id = id;
 }

void  BookRoom::setngaythue(Date ngay)
{
    	this->ngaythue= ngay;
}
void  BookRoom::setngaytra( Date ngay)
{
    	this->ngaytra = ngay;
}
void BookRoom::setMaKH(string ma)
{
	this->MaKH = ma;
}
string BookRoom::getMaKH()
{
	return MaKH;
}
void BookRoom::ExportToFile(ostream& os)
{
    
    os << MaKH << endl;
    os << MaNV << endl;
    os << Id<<" " << ngaythue.Get_day() << " " << ngaythue.Get_month() << " " << ngaythue.Get_year() << " ";
    os << ngaytra.Get_day() << " " << ngaytra.Get_month() << " " << ngaytra.Get_year() << " ";
    os << "\n-------------------------------\n";
	
}

void BookRoom::ImportFromFile(ifstream &in)
{
    int month, day, year;
    string str;
    getline(in >> ws, this->MaKH);
	getline(in >> ws, this->MaNV);
	in >> this->Id;
	in >> day >> month >> year;
    this -> ngaythue = Date(day, month, year);
	in >> day >> month >> year;
    this -> ngaytra = Date(day, month, year);
	getline(in, str);
	getline(in, str);
    
}
void BookRoom::setMaNV(string ma)
{
	this->MaNV = ma;
}
string BookRoom::getMaNV()
{
	return MaNV;
}
    
string BookRoom::getId()
{
	return Id;
}



void BookRoom::out(ostream& os)
{
	KhachHangManager KH;
	PhongManager PH;
	NhanVienManager NV;
	
	KhachHang khachhang = KH.findByID(MaKH);
	Phong  phong = PH.findByID(Id);
	NhanVien nhanvien = NV.findByID(MaNV);
	

	os<<"|" << setw(12) << MaKH;
	os<<"|" << setw(17) << khachhang.getName();
	os<<"|"<< setw(12) << MaNV;
	os<<"|" << setw(17) << nhanvien.getName();
	os<<"|" << setw(12) << Id;
	os<<"|" << setw(12) << phong.getGiaPhong();
	os<<"|" << setw(12) << ngaythue;
	os<<"|" << setw(12) << ngaytra;

	int songay = ngaytra.daysBetweenDates(ngaythue);
	os<<"|" << setw(12) <<songay; 
	int tongtien = songay * phong.getGiaPhong();
	os<<"|" << setw(12) << tongtien << " |" << endl;
}
void BookRoom::Show()
{
	KhachHangManager KH;
	PhongManager PH;
	NhanVienManager NV;
	
	KhachHang khachhang = KH.findByID(MaKH);
	Phong  phong = PH.findByID(Id);
	NhanVien nhanvien = NV.findByID(MaNV);
	

	cout<<"|" << setw(12) << MaKH;
	cout<<"|" << setw(17) << khachhang.getName();
	cout<<"|"<< setw(12) << MaNV;
	cout<<"|" << setw(17) << nhanvien.getName();
	cout<<"|" << setw(12) << Id;
	cout<<"|" << setw(12) << phong.getGiaPhong();
	cout<<"|" << setw(12) << ngaythue;
	cout<<"|" << setw(12) << ngaytra;

	int songay = ngaytra.daysBetweenDates(ngaythue);
	cout<<"|" << setw(12) <<songay; 
	int tongtien = songay * phong.getGiaPhong();
	cout<<"|" << setw(12) << tongtien << " |" << endl;

}
