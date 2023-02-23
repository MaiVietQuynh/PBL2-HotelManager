#include "KhachHang.h"
#include <iostream>
using namespace std;
#include <algorithm>

KhachHang::KhachHang()
{
    this->Id = "";
    this->name = "";
    this->gender = "";
    this->birthday = Date();
    this->address = "";
    this->sdt = "";
}
KhachHang::KhachHang(const string &Id, const string &name, const string &gender, const Date &birthday, const string &address, const string &sdt, const string &cccd)
{
    this->Id = (KhachHang::isValidID(Id)) ? Id : "";
    this->name = (KhachHang::isValidName(name)) ? name : "";
    this->gender = gender;
    this->birthday = (Date(birthday).IsValidDate()) ? birthday : Date();
    this->address = address;
    this->sdt = sdt;
    this->cccd = cccd;
}

KhachHang::KhachHang(const KhachHang &R)
{
    this->Id = R.Id;
    this->name = R.name;
    this->gender = R.gender;
    this->birthday = R.birthday;
    this->address = R.address;
    this->sdt = R.sdt;
    this->cccd = R.cccd;
}

KhachHang::~KhachHang()
{
}
string KhachHang::getcccd()
{
    return cccd;
}
void KhachHang::setcccd(string cc)
{
    this->cccd = cc;
}
string KhachHang::getId()
{
    return this->Id;
}

string KhachHang::getName()
{
    return this->name;
}

string KhachHang::getGender()
{
    return this->gender;
}
Date KhachHang::getBirthday()
{
    return this->birthday;
}
string KhachHang::getAddress()
{
    return this->address;
}
string KhachHang::getsdt()
{
    return this->sdt;
}
void KhachHang::setterId(const string &ID)
{
    this->Id = (KhachHang::isValidID(Id)) ? Id : "";
}
void KhachHang::setterName(const string &Name)
{
    this->name = (KhachHang::isValidName(name)) ? name : "";
}
void KhachHang::setterGender(const string &Gender)
{
    this->gender = Gender;
}
void KhachHang::setterBirthday(const Date &birthday)
{
    this->birthday = (Date(birthday).IsValidDate()) ? birthday : Date();
}
void KhachHang::setterAddress(const string &Address)
{
    this->address = Address;
}
void KhachHang::settersdt(const string &sdt)
{
    this->sdt = sdt;
}

bool KhachHang::isValidID(const string &str)
{
    // if (str.size() != 9)
    //     return false; // ID có độ dài là 9 số
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool KhachHang::isValidName(const string &str)
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

void KhachHang::Show()
{
    cout << "ID khach hang: " << this->Id << endl;
    cout << "Ten khach hang: " << this->name << endl;
    cout << "Gioi tinh: " << this->gender << endl;
    cout << "Ngay sinh: " << this->birthday << endl;
    cout << "Dia chi khach hang: " << this->address << endl;
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
const KhachHang &KhachHang::operator=(const KhachHang &R)
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
bool KhachHang::operator==(const KhachHang &newReader)
{
    if (this->Id == newReader.Id && this->name == newReader.name && this->gender == newReader.gender && this->birthday == newReader.birthday && this->address == newReader.address && this->sdt == newReader.sdt && this->cccd == newReader.cccd)
    {
        return true;
    }
    return false;
}
void KhachHang::Update(const KhachHang &R)
{

    this->name = R.name;
    this->gender = R.gender;
    this->birthday = R.birthday;
    this->address = R.address;
    this->sdt = R.sdt;
    this->cccd = R.cccd;
}

void KhachHang::Input(string id)
{
    this->Id = id;
    cout << "Ten cua khach hang     : ";
    fflush(stdin);
    getline(cin, this->name);
    while (!KhachHang::isValidName(this->name))
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
void KhachHang::update(string id)
{
    this->Id = id;
    cout << "Ten cua khach hang     : ";
    fflush(stdin);
    getline(cin, this->name);
    while (!KhachHang::isValidName(this->name))
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
void KhachHang::Output()
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

void KhachHang::ImportFromFile(ifstream &in)
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
    getline(in >> ws, this->cccd);
    string str;
    getline(in >> ws, str);
}

void KhachHang::ExportToFile(ofstream &os)
{
    os << Id << endl;
    os << name << endl;
    os << gender << endl;
    // os << birthday << endl; -> chưa đa năng hoa
    os << birthday.Get_day() << " " << birthday.Get_month() << " " << birthday.Get_year() << endl;
    os << address << endl;
    os << sdt << endl;
    os << cccd << endl;
    os << "=========================\n";
}
