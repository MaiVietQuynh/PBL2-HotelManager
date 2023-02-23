#include <iostream>
#include "Phong.h"
#include "Management_Phong.h"
#include "Management_KhachHang.h"
#include "Management_NhanVien.h"
#include "Management_BookRoom.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

PhongManager PH;
KhachHangManager KH;
NhanVienManager NV;
BookRoomManager BR;
void Menu()
{
	cout << "\t\t\t===============QUAN LY KHACH SAN===============\n";
	cout << "\t\t\t|1. QUAN LY PHONG KHACH SAN                   |\n";
	cout << "\t\t\t|2. QUAN LY THONG TIN NHAN VIEN               |\n";
	cout << "\t\t\t|3. QUAN LY THONG TIN KHACH HANG              |\n";
	cout << "\t\t\t|4. QUAN LY DAT TRA PHONG KHACH SAN           |\n";
	cout << "\t\t\t|0. Thoat!!!                                  |\n";
	cout << "\t\t\t===============================================\n";

}
int main()
{
	int luachon;
	
	while(1)
	{
		system("cls");
		Menu();
		cout << "lua chon = ";
		cin >> luachon;
		cin.ignore();
		
		switch(luachon)
		{
			case 1:
				{
					PH.read();
					PH.run();
					break;
				}
			case 2:
				{
					NV.run();
					break;
				}
			case 3:
				{
					KH.run();
					break;
				}
			case 4:
				{
					BR.run();
				
					break;
				}
			case 0:
				{
					
				  	return 0;
				}
			
		}
	}

    return 0;
}
