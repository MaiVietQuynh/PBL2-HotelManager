#include "NhanVien.h"
#include <iostream>
using namespace std;
#include <algorithm>

NhanVien::NhanVien()
{
    this -> Id = "";
    this -> name = "";
    this -> gender = "";
    this -> birthday = Date();
    this -> address = "";
    this -> sdt = "";
}
 string NhanVien::getcccd()
 {
 	return cccd;
 }
 void NhanVien::setcccd(string cc)
 {
 	this->cccd = cc;
 }
NhanVien::NhanVien(const string &Id, const string &name, const string &gender, const Date &birthday, const string &address, const string &sdt,const string &cccd)
{
    this->Id = (NhanVien::isValidID(Id)) ? Id : "";
    this->name = (NhanVien::isValidName(name)) ? name : "";
    this->gender = gender;
    this->birthday = (Date(birthday).IsValidDate()) ? birthday : Date();
    this->address = address;
    this->sdt = sdt;
    this->cccd = cccd;
}

NhanVien::NhanVien(const NhanVien &R)
{
    this->Id = R.Id;
    this->name = R.name;
    this->gender = R.gender;
    this->birthday = R.birthday;
    this->address = R.address;
    this->sdt = R.sdt;
    this->cccd = R.cccd;
}

NhanVien::~NhanVien()
{
}

string NhanVien::getId()
{
    return this->Id;
}

string NhanVien::getName()
{
    return this->name;
}

string NhanVien::getGender()
{
    return this->gender;
}
Date NhanVien::getBirthday()
{
    return this->birthday;
}
string NhanVien::getAddress()
{
    return this->address;
}
string NhanVien::getsdt()
{
    return this->sdt;
}
void NhanVien::setterId(const string &ID)
{
    this->Id = (NhanVien::isValidID(Id)) ? Id : "";
}
void NhanVien::setterName(const string &Name)
{
    this->name = (NhanVien::isValidName(name)) ? name : "";
}
void NhanVien::setterGender(const string &Gender)
{
    this->gender = Gender;
}
void NhanVien::setterBirthday(const Date &birthday)
{
    this->birthday = (Date(birthday).IsValidDate()) ? birthday : Date();
}
void NhanVien::setterAddress(const string &Address)
{
    this->address = Address;
}
void NhanVien::settersdt(const string &sdt)
{
    this->sdt = sdt;
}

bool NhanVien::isValidID(const string &str)
{
    if (str.size() != 9)
        return false; // ID có độ dài là 9 số
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool NhanVien::isValidName(const string &str)
{
    if (str.size() < 3)
        return false; // Tên có ít nhất 3 kí tự
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
            continue;
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return false;
    }
    return true;
}

void NhanVien::Show()
{
    cout << "ID Nhan vien: " << this->Id << endl;
    cout << "Ten Nhan vien: " << this->name << endl;
    cout << "Gioi tinh: " << this->gender << endl;
    cout << "Ngay sinh: " << this->birthday << endl;
    cout << "Dia chi Nhan vien: " << this->address << endl;
    cout << "So Dien thoai: " << this->sdt << endl;
    cout << "Can cuoc cong dan: " << this->cccd;
}
// ostream &operator<<(ostream &os, const Reader &R)
// {
//     os << "id nguoi doc la: " << R.Id << endl;
//     os << "Ten nguoi doc la: " << R.name << endl;
//     os << "Gioi tinh la: " << R.gender << endl;
//     os << "Dia chi nguoi doc: " << R.address << endl;
//     os << "So tuoi nguoi doc: " << R.age << endl;
//     return os;
// }
const NhanVien &NhanVien::operator=(const NhanVien &R)
{
    this->Id = R.Id;
    this->name = R.name;
    this->gender = R.gender;
    this->birthday = R.birthday;
    this->address = R.address;
    this->sdt = R.sdt;
    this->cccd = R.cccd;
    return (*this);
}
bool NhanVien::operator==(const NhanVien &newReader)
{
    if (this->Id == newReader.Id && this->name == newReader.name && this->gender == newReader.gender && this->birthday == newReader.birthday && this->address == newReader.address && this->sdt == newReader.sdt && this->cccd == newReader.cccd)
    {
        return true;
    }
    return false;
}
void NhanVien::Update(const NhanVien &R)
{

    this->name = R.name;
    this->gender = R.gender;
    this->birthday = R.birthday;
    this->address = R.address;
    this->sdt = R.sdt;
    this->cccd = R.cccd;
}

void NhanVien::Input(string id)
{
    this->Id = id;
    cout << "Ten cua Nhan vien     : ";
    fflush(stdin);
    getline(cin, this->name);
    while (!NhanVien::isValidName(this->name))
    {
        cout << "Nhap sai, nhap lai          :";
        fflush(stdin);
        getline(cin, this->name);
    }
    cout << "Gioi tinh             : ";
    fflush(stdin);
    getline(cin, this->gender);
    cout << "Ngay sinh             : ";
    cin >> this->birthday;
    cout << "Dia chi               : ";
    fflush(stdin);
    getline(cin, this->address);
    cout << "So dien thoai    : ";
    fflush(stdin);
    getline(cin, this->sdt);
    cout << "Nhap can cuoc cong dan    : ";
    fflush(stdin);
    getline(cin, this->cccd);
}
void NhanVien::update(string id)
{
    this->Id = id;
    cout << "Ten cua Nhan vien     : ";
    fflush(stdin);
    getline(cin, this->name);
    while (!NhanVien::isValidName(this->name))
    {
        cout << "Nhap sai, nhap lai          :";
        fflush(stdin);
        getline(cin, this->name);
    }
    cout << "Gioi tinh             : ";
    fflush(stdin);
    getline(cin, this->gender);
    cout << "Ngay sinh             : ";
    cin >> this->birthday;
    cout << "Dia chi               : ";
    fflush(stdin);
    getline(cin, this->address);
    cout << "So dien thoai    : ";
    fflush(stdin);
    getline(cin, this->sdt);
    cout << "Nhap can cuoc cong dan    : ";
    fflush(stdin);
    getline(cin, this->cccd);
}
void NhanVien::Output()
{
    cout << "|" << setw(10) << this->Id;
    cout << "|" << setw(20) << this->name;
    cout << "|" << setw(20) << this->gender;
    cout << "|" << setw(20) << this->birthday;
    cout << "|" << setw(20) << this->address;
    cout << "|" << setw(15) << this->sdt;
    cout << "|" << setw(15) << this->cccd << "|";
    cout << endl; //<< setfill(' ') << setw(50) <<' ' <<setfill(' ');
}

void NhanVien::ImportFromFile(ifstream &in)
{
    int month, day, year;
    getline(in >> ws, this->Id);
    getline(in >> ws, this->name);
    getline(in >> ws, this->gender);
    // getline(in >> ws, this->birthday);
    //  ImportFromFile(in, this -> birthday);
    in >> day >> month >> year;
    this->birthday = Date(day, month, year);
    getline(in >> ws, this->address);
    getline(in >> ws, this->sdt);
    getline(in>>ws,this->cccd);
    string str;
    getline(in>>ws,str);
}

void NhanVien::ExportToFile(ofstream &os)
{
    os << Id << endl;
    os << name << endl;
    os << gender << endl;
    // os << birthday << endl; -> chưa đa năng nì
    os << birthday.Get_day() << " " << birthday.Get_month() << " " << birthday.Get_year() << endl;
    os << address << endl;
    os << sdt << endl;
    os << cccd << endl;
    os << "=========================\n";
}
