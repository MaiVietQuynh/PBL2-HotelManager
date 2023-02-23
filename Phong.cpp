#include "Phong.h"


Phong::Phong()
{
    this->MaPhong = "";
    this->LoaiPhong = "";
    this->GiaPhong = 0;
    this->Trangthai = false;
}

Phong::Phong(string mp, string loaiphong,int Gia, bool TT)
{
    this->MaPhong = mp;
    this->LoaiPhong = loaiphong;
    this->GiaPhong = Gia;
   
    this->Trangthai = TT;
}

Phong::Phong(const Phong& s)
{
    this->MaPhong = s.MaPhong;
    this->LoaiPhong = s.LoaiPhong;
    this->GiaPhong = s.GiaPhong;
   
    this->Trangthai = s.Trangthai;
}

string Phong::getId()
{
	return this -> MaPhong;
}

string Phong::getLoaiPhong()
{
    return this->LoaiPhong;
}
int Phong::getGiaPhong()
{
    return this->GiaPhong;
}
bool Phong::getTrangthai()
{
    return this->Trangthai;
}
string Phong::getStrTrangThai(){
	if (this -> Trangthai == true) return "Da thue";
	else return "Chua thue";
}
void Phong::setMaPhong( string ma){
	this -> MaPhong = ma;
}
void Phong::setLoaiPhong(string loai)
{
    this->LoaiPhong = loai;
}
void Phong::setGiaPhong(int gia)
{
    this->GiaPhong = gia;
}
void Phong::setTrangthai(bool TT)
{
    this->Trangthai = TT;
}

bool Phong::isValidId(const string &str){
	if (str.length() != 4) return false;
	for (int i = 0;i < str.length();i++){
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}

void Phong::update(const Phong &newPhong){
	this -> MaPhong = newPhong.MaPhong;
	this -> LoaiPhong = newPhong.LoaiPhong;
	this -> GiaPhong = newPhong.GiaPhong;
	this -> Trangthai = newPhong.Trangthai;
}
bool Phong::checkMaPhong(DoubleLinkedList<Phong> list, string maphong)
{
	
	Phong p = list.findByID(maphong);
	if(p.getId() == maphong)
	{
		return true;
	}
	
	return false;
}
void Phong::Input(string mp)
{
	MaPhong = mp;
	fflush(stdin);
	cout << "Nhap Loai phong (Don, Doi): ";
	getline(cin,LoaiPhong);
	
	cout << "Nhap Gia Phong:";
	cin >> GiaPhong;	
	fflush(stdin);
	this -> Trangthai = false;

}
void Phong::Update(string mp)
{
	MaPhong = mp;
	fflush(stdin);
	cout << "Nhap Loai phong moi (Don, Doi): ";
	getline(cin,LoaiPhong);
	
	cout << "Nhap Gia Phong moi:";
	cin >> GiaPhong;	
	
	cout << "Nhap trang thai (0: chua thue, 1: da thue): ";
	cin >> this->Trangthai;
	fflush(stdin);
}
void Phong::Output()
{
	
	cout <<"|"<< setw(20) << MaPhong;
	cout <<"|"<< setw(20) << "Phong " + LoaiPhong;
	cout <<"|"<< setw(20) << GiaPhong;
	cout <<"|"<< setw(25) << getStrTrangThai()<<"|" << endl;
	//cout<<"Ma Phong: " << MaPhong <<endl;
	//cout<<"Loai Phong :	" << LoaiPhong <<endl;
	//cout<<"Gia:	"<< GiaPhong <<endl;
	//cout <<"Trang Thai :" << getStrTrangThai() << endl;
}

void Phong::ImportFromFile(ifstream& in)
{
	in >> this->MaPhong;
	in >> this->LoaiPhong;
	in >> this->GiaPhong;
	in >> this -> Trangthai;
}

void Phong::ExportToFile(ostream& os)
{
    os << this->MaPhong << " ";
	os << this->LoaiPhong << " ";
	os << this->GiaPhong << " ";
	os << this->Trangthai << " ";
	os << endl;
}

bool Phong::operator==(const Phong &S){
	return (this -> MaPhong == S.MaPhong && this -> LoaiPhong == S.LoaiPhong && this -> GiaPhong == S.GiaPhong && this -> Trangthai == S.Trangthai);
}

const Phong& Phong::operator=(const Phong &S){
	this -> MaPhong = S.MaPhong;
	this -> LoaiPhong = S.LoaiPhong;
	this -> GiaPhong = S.GiaPhong;
	this -> Trangthai = S.Trangthai;
	return (*this);
}
