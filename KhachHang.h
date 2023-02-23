#ifndef KHACHHANG_H
#define KHACHHANG_H
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class KhachHang
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
    KhachHang();
    KhachHang(const string&, const string&, const string&, const Date&, const string&, const string&, const string&);
    KhachHang(const KhachHang&);
    ~KhachHang();

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
    void Update(const KhachHang &);
    void update(string id);

    const KhachHang &operator=(const KhachHang &);
    bool operator==(const KhachHang &);
    friend ostream &operator<<(ostream &, const KhachHang &);
    friend istream &operator>>(istream &, KhachHang);
    void Input(string id);
    void Output();
    void ImportFromFile(ifstream &);
    void ExportToFile(ofstream &);

    // ==, <<, >>
};
#endif
