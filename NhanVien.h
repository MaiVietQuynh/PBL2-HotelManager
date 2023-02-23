#ifndef NHANVIEN_H
#define NHANVIEN_H
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class NhanVien
{
private:
    string Id;
    string name;
    string gender;
    Date birthday;
    string address;
    string sdt; // uh de doi sau
    string cccd;

public:
    NhanVien();
    NhanVien(const NhanVien&);
    NhanVien(const string&, const string&, const string&, const Date&, const string&, const string&, const string&);
    ~NhanVien();

    // Getter
    string getId();
    string getName();
    string getGender();
    Date getBirthday();
    string getAddress();
    string getsdt();
    string getcccd();
    void setcccd(string);
    // Setter

    void setterId(const string&);
    void setterName(const string&);
    void setterGender(const string&);
    void setterBirthday(const Date&);
    void setterAddress(const string&);
    void settersdt(const string&);

    static bool isValidID(const string&);
    static bool isValidName(const string&);
	
    void Show();
    void Update(const NhanVien &);
    void update(string id);

    const NhanVien &operator=(const NhanVien &);
    bool operator==(const NhanVien &);
    friend ostream &operator<<(ostream &, const NhanVien &);
    friend istream &operator>>(istream &, NhanVien);
    void Input(string id);
    void Output();
    void ImportFromFile(ifstream &);
    void ExportToFile(ofstream &);

    // ==, <<, >>
};
#endif
