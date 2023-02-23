#include "Management_KhachHang.h"
KhachHangManager::KhachHangManager()
{
	ifstream input;
	input.open("KhachHang.txt", ios::in);
	if (input.fail())
	{
		cout << "Failed to open this file" << endl;
	}
	else
	{
		KhachHang data;
		int n;
		input >> n;
		for (int i = 1; i <= n; i++)
		{
			data.ImportFromFile(input);
			this->list.Append(data);
		}
		input.close();
	}
}
KhachHangManager::~KhachHangManager()
{
}
void KhachHangManager::read()
{
	ifstream input;
	input.open("KhachHang.txt", ios::in);
	if (input.fail())
	{
		cout << "Failed to open this file" << endl;
	}
	else
	{
		KhachHang data;
		int n;
		input >> n;
		for (int i = 1; i <= n; i++)
		{
			data.ImportFromFile(input);
			this->list.Append(data);
		}
		input.close();
	}
}
void KhachHangManager::removeall()
{
	while (this->list.getNodeCount() > 0)
	{
		this->list.removeAt(0);
	}
}
void KhachHangManager::menu()
{
	cout << "\t\t\t------------------------------------------\n";
	cout << "\t\t\t| 1. Them Khach hang vao dau danh sach    |\n";
	cout << "\t\t\t| 2. Them khach hang vao cuoi danh sach   |\n";
	cout << "\t\t\t| 3. Them khach hang vao vi tri nhap vao  |\n";
	cout << "\t\t\t| 4. Sua thong tin khach hang             |\n";
	cout << "\t\t\t| 5. Xoa thong tin khach hang             |\n";
	cout << "\t\t\t| 6. Tim kiem thong tin theo ma KH        |\n";
	cout << "\t\t\t| 7. Hien thi toan bo danh sach KH        |\n";
	cout << "\t\t\t| 0. Thoat                                |\n";
	cout << "\t\t\t------------------------------------------\n";
	cout << "\t\t\t\tLua chon = ";
}
void KhachHangManager::run()
{
	int luachon;
	string id;
	while (1)
	{
		system("cls");
		menu();
		cin >> luachon;
		KhachHang newKH;

		switch (luachon)
		{
		case 1:
		{
			cout << "\t\t\tTHEM KHACH HANG VAO DAU DANH SACH\n";
			cout << "Nhap Ma Khach hang: ";
			cin >> id;
			KhachHang T = this->list.findByID(id);

			while (T.getId() == id || id == "" || !KhachHang::isValidID(id))
			{
				cout << "Ma Khach hang da ton tai hoac khong hop le vui long nhap lai\nNhap Ma Khach hang: ";
				cin >> id;
				T = this->list.findByID(id);
			}

			newKH.Input(id);

			this->addhead(newKH);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "\t\t\tTHEM KHACH HANG VAO CUOI DANH SACH\n";
			cout << "Nhap Ma Khach hang: ";
			cin >> id;
			KhachHang T = this->list.findByID(id);

			while (T.getId() == id || id == "" || !KhachHang::isValidID(id))
			{
				cout << "Ma Khach hang da ton tai hoac khong hop le vui long nhap lai\nNhap Ma Khach hang: ";
				cin >> id;
				T = this->list.findByID(id);
			}

			newKH.Input(id);

			this->add(newKH);

			system("pause");
			break;
		}
		case 3:
		{
			cout << "\t\t\tTHEM KHACH HANG VAO VI TRI NHAP VAO\n";
			cout << "Nhap Ma Khach hang: ";
			cin >> id;
			KhachHang T = this->list.findByID(id);

			while (T.getId() == id || id == "" || !KhachHang::isValidID(id))
			{
				cout << "Ma Khach hang da ton tai hoac khong hop le vui long nhap lai\nNhap Ma Khach hang: ";
				cin >> id;
				T = this->list.findByID(id);
			}

			newKH.Input(id);
			cout << "Nhap vi tri them vao: ";
			int vt;
			cin >> vt;
			while ( vt <0 || vt > this->list.getNodeCount() )
			{
				cout<< "Nhap sai vi tri\nNhap vi tri them vao: ";
				cin >> vt;
			}
			this->addAt(newKH, vt);

			system("pause");
			break;
		}
		case 4:
		{
			cout << "Nhap Ma Khach hang muon cap nhat: ";
			cin >> id;
			KhachHang T = this->list.findByID(id);

			while (T.getId() != id)
			{
				cout << "Ma Khach Hang khong co trong danh sach\nNhap Ma Khach hang: ";
				cin >> id;
				T = this->list.findByID(id);
			}

			newKH.update(id);

			this->updateByID(newKH, id);
			cout << "Cap nhat thanh cong\n";
			system("pause");
			break;
		}
		
		case 5:
		{
			cout << "Nhap Ma Khach Hang muon xoa \n";
			cin >> id;
			if (this->removeByID(id))
				cout << "xoa thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Nhap Ma Khach hang muon tim kiem : ";
			cin >> id;
			KhachHang T;
			T = this->findByID(id);
			if (T.getId() != "")
			{
				Node<KhachHang> *ptr = this->list.getHead();
				cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << "|" << setw(10) << "Ma KH";
				cout << "|" << setw(20) << "Ten KH";
				cout << "|" << setw(20) << "Gioi tinh";
				cout << "|" << setw(27) << "Ngay Sinh";
				cout << "|" << setw(20) << "Dia chi";
				cout << "|" << setw(15) << "So DT";
				cout << "|" << setw(17) << "CCCD|\n";
				cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
				T.Output();
				cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
			}
			else
			{
				cout << "KHong co thong tin ma khach hang vua nhap\n";
			}
			system("pause");
			break;
		}
		case 7:
		{
			this->Show();
			system("pause");
			break;
		}
		case 0:
		{
			this->save();
			return;
		}
		}
	}
}
void KhachHangManager::save() // Ghi ra file
{
	Node<KhachHang> *ptr = this->list.getHead();
	ofstream out;
	out.open("KhachHang.txt");
	out << this->list.getNodeCount() << endl;
	while (ptr != NULL)
	{
		ptr->getData().ExportToFile(out);
		ptr = ptr->getNext();
	}
	out.close();
}
void KhachHangManager::Show()
{
	Node<KhachHang> *ptr = this->list.getHead();
	cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(10) << "Ma KH";
	cout << "|" << setw(20) << "Ten KH";
	cout << "|" << setw(20) << "Gioi tinh";
	cout << "|" << setw(27) << "Ngay Sinh";
	cout << "|" << setw(20) << "Dia chi";
	cout << "|" << setw(15) << "So DT";
	cout << "|" << setw(17) << "CCCD|\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
	while (ptr != NULL)
	{
		ptr->getData().Output();
		ptr = ptr->getNext();
		cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
	}
}
void KhachHangManager::add(KhachHang R)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
		this->list.Append(R);
	cout << "Them Thanh Cong !! " << endl;
}
void KhachHangManager::addhead(KhachHang R)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
	{
		this->list.Prepend(R);
		cout << "Them Thanh Cong !! " << endl;
	}
}
void KhachHangManager::addAt(KhachHang R, int vt)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
		this->list.AppendAt(R, vt);
	cout << "Them Thanh Cong !! " << endl;
}
bool KhachHangManager::remove(const KhachHang R)
{
	int index = this->list.indexOf(R);
	if (index == -1)
		return false;
	return this->list.removeAt(index);
}
int KhachHangManager::indexOf(const KhachHang R)
{
	return this->list.indexOf(R);
}
void KhachHangManager::ShowByID(const string &ID)
{
	KhachHang temp = this->list.findByID(ID);
	temp.Output();
}
KhachHang KhachHangManager::findByID(const string &ID)
{
	// return this->list.findByID(ID);
	Node<KhachHang> *ptr = this->list.getHead();
	while (ptr)
	{
		if (ptr->getData().getId() == ID)
		{
			return ptr->getData();
		}
		ptr = ptr->getNext();
	}
	return KhachHang();
}
bool KhachHangManager::removeByID(const string &ID)
{
	KhachHang temp = this->list.findByID(ID);
	return this->remove(temp);
}
bool KhachHangManager::updateByID(const KhachHang R, const string &ID)
{
	Node<KhachHang> *ptr = this->list.getHead();
	while (ptr != NULL)
	{
		if (ptr->getData().getId() == ID)
		{
			ptr->setData(R);
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;
}
void KhachHangManager::listByName(const string &name)
{
	Node<KhachHang> *ptr = this->list.getHead();
	while (ptr != NULL)
	{
		if (ptr->getData().getName() == name)
			ptr->getData().Output();
		ptr = ptr->getNext();
	}
}
