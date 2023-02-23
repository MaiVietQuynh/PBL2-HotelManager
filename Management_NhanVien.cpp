#include "Management_NhanVien.h"
NhanVienManager::NhanVienManager()
{
	ifstream input;
	input.open("NhanVien.txt", ios::in);
	if (input.fail())
	{
		cout << "Failed to open this file" << endl;
	}
	else
	{
		NhanVien data;
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
void NhanVienManager::read()
{
	ifstream input;
	input.open("NhanVien.txt", ios::in);
	if (input.fail())
	{
		cout << "Failed to open this file" << endl;
	}
	else
	{
		NhanVien data;
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
void NhanVienManager::removeall()
{
	while (this->list.getNodeCount() > 0)
	{
		this->list.removeAt(0);
	}
}
void NhanVienManager::menu()
{
	cout << "\t\t\t------------QUAN LY NHAN VIEN--------------\n";
	cout << "\t\t\t| 1. Them Nhan Vien vao dau ds            |\n";
	cout << "\t\t\t| 2. Them Nhan vien vao cuoi ds           |\n";
	cout << "\t\t\t| 3. Them Nhan vien vao vi tri nhap vao   |\n";
	cout << "\t\t\t| 4. Sua thong tin Nhan vien              |\n";
	cout << "\t\t\t| 5. Xoa thong tin Nhan vien              |\n";
	cout << "\t\t\t| 6. Tim kiem thong tin theo ma Nhan vien |\n";
	cout << "\t\t\t| 7. Hien thi toan bo danh sach Nhan vien |\n";
	cout << "\t\t\t| 0. Thoat                                |\n";
	cout << "\t\t\t------------------------------------------\n";
	cout << "\t\t\t\tLua chon = ";
}
void NhanVienManager::run()
{
	int luachon;
	string id;
	while (1)
	{
		system("cls");
		menu();
		cin >> luachon;
		NhanVien newKH;

		switch (luachon)
		{
		case 1:
		{
			cout << "\t\t\tTHEM NHAN VIEN VAO DAU DANH SACH\n";
			cout << "Nhap Ma Nhan vien: ";
			cin >> id;
			NhanVien T = this->list.findByID(id);

			while (T.getId() == id || id == "" || !NhanVien::isValidID(id))
			{
				cout << "Ma Nhan vien da ton tai hoac khong hop le vui long nhap lai\nNhap Ma Nhan vien: ";
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
			cout << "\t\t\tTHEM NHAN VIEN VAO CUOI DANH SACH\n";
			cout << "Nhap Ma nhan vien: ";
			cin >> id;
			NhanVien T = this->list.findByID(id);

			while (T.getId() == id || id == "" || !NhanVien::isValidID(id))
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
			cout << "\t\t\tTHEM NHAN VIEN VAO VI TRI NHAP VAO\n";
			cout << "Nhap Ma Nhan vien: ";
			cin >> id;
			NhanVien T = this->list.findByID(id);

			while (T.getId() == id || id == "" || !NhanVien::isValidID(id))
			{
				cout << "Ma Nhan vien da ton tai hoac khong hop le vui long nhap lai\nNhap Ma Nhan vien: ";
				cin >> id;
				T = this->list.findByID(id);
			}

			newKH.Input(id);
			cout << "Nhap vi tri them vao: ";
			int vt;
			cin >> vt;
			if (vt < 0)
				vt = 0;
			if (vt > this->list.getNodeCount())
				vt = this->list.getNodeCount();
			this->addAt(newKH, vt);

			system("pause");
			break;
		}
		case 4:
		{
			cout << "Nhap Ma Nhan vien muon cap nhat: ";
			cin >> id;
			NhanVien T = this->list.findByID(id);

			while (T.getId() != id)
			{
				cout << "Ma Nhan vien khong co trong danh sach\nNhap Ma Khach hang: ";
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
			cout << "Nhap Ma Nhan vien muon xoa \n";
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
			cout << "Nhap Ma Nhan vien muon tim kiem : ";
			cin >> id;
			NhanVien T;
			T = this->findByID(id);
			if (T.getId() != "")
			{
				Node<NhanVien> *ptr = this->list.getHead();
				cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << "|" << setw(10) << "Ma NV";
				cout << "|" << setw(20) << "Ten NV";
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
				cout << "KHong co thong tin ma phong vua nhap\n";
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
void NhanVienManager::save()
{
	// Ghi ra file
	Node<NhanVien> *ptr = this->list.getHead();
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
NhanVienManager::~NhanVienManager()
{
}
void NhanVienManager::Show()
{
	Node<NhanVien> *ptr = this->list.getHead();
	cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(10) << "Ma NV";
	cout << "|" << setw(20) << "Ten NV";
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
void NhanVienManager::add(NhanVien R)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
		this->list.Append(R);
	cout << "Them Thanh Cong !! " << endl;
}
void NhanVienManager::addhead(NhanVien R)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
		this->list.Prepend(R);
	cout << "Them Thanh Cong !! " << endl;
}
void NhanVienManager::addAt(NhanVien R, int vt)
{
	if (this->indexOf(R) != -1)
		cout << "ID da ton tai" << endl;
	else
		this->list.AppendAt(R, vt);
	cout << "Them Thanh Cong !! " << endl;
}
bool NhanVienManager::remove(const NhanVien R)
{
	int index = this->list.indexOf(R);
	if (index == -1)
		return false;
	return this->list.removeAt(index);
}
int NhanVienManager::indexOf(const NhanVien R)
{
	return this->list.indexOf(R);
}
void NhanVienManager::ShowByID(const string &ID)
{
	NhanVien temp = this->list.findByID(ID);
	temp.Output();
}
NhanVien NhanVienManager::findByID(const string &ID)
{
	// return this->list.findByID(ID);
	Node<NhanVien> *ptr = this->list.getHead();
	while (ptr)
	{
		if (ptr->getData().getId() == ID)
		{
			return ptr->getData();
		}
		ptr = ptr->getNext();
	}
	return NhanVien();
}
bool NhanVienManager::removeByID(const string &ID)
{
	NhanVien temp = this->list.findByID(ID);
	return this->remove(temp);
}
bool NhanVienManager::updateByID(const NhanVien R, const string &ID)
{
	Node<NhanVien> *ptr = this->list.getHead();
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
void NhanVienManager::listByName(const string &name)
{
	Node<NhanVien> *ptr = this->list.getHead();
	while (ptr != NULL)
	{
		if (ptr->getData().getName() == name)
			ptr->getData().Output();
		ptr = ptr->getNext();
	}
}
