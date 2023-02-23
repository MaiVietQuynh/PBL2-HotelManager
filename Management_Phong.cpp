#include "Management_Phong.h"
PhongManager::PhongManager()
{
    ifstream input;
    input.open("phong.txt", ios::in);
    if (input.fail())
    {
        cout << "Failed to open this file" << endl;
    }
    else
    {
        Phong data;
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
void PhongManager::read()
{
	
	this->list.setHead(NULL);
	this->list.setTail(NULL);
	this->list.setNodeCount(0);
	ifstream input;
    input.open("phong.txt", ios::in);
    if (input.fail())
    {
        cout << "Failed to open this file" << endl;
    }
    else
    {
        Phong data;
        int n;
        input >> n;
        for (int i = 1; i <=n; i++)
        {
            data.ImportFromFile(input);
            
            this->list.Append(data);
        }
        input.close();
    }
}
void PhongManager::menu()
{
	cout << "\t\t\t------------QUAN LY PHONG KS---------------\n";
	cout << "\t\t\t| 1. Them phong moi                       |\n";
	cout << "\t\t\t| 2. Sua thong tin phong                  |\n";
	cout << "\t\t\t| 3. Xoa thong tin phong                  |\n";
	cout << "\t\t\t| 4. Tim kiem phong theo ma phong         |\n";
	cout << "\t\t\t| 5. Hien thi danh sach phong             |\n";
	cout << "\t\t\t| 0. Thoat                                |\n";
	cout << "\t\t\t------------------------------------------\n";
	cout << "\t\t\t\tLua chon = ";
}
void PhongManager::run()
{
	int luachon;
	string id;
	while(1)
	{
		system("cls");
		menu();
		cin >> luachon;
		Phong newPhong;
		
		switch(luachon)
		{
			case 1:
				{
					
					cout << "Nhap Ma phong: ";
					cin >> id; 
					Phong T = this->list.findByID(id);
				
					
					while(T.getId()==id|| id == "")
					{
						cout << "Ma phong da ton tai vui long nhap lai\nNhap Ma phong: ";
						cin >> id; 
						 T = this->list.findByID(id);
					}
					
					newPhong.Input(id);
					
					this->add(newPhong);
					
					
					system("pause");
					break;
				}
			case 2:
				{
					cout << "Nhap Ma phong muon cap nhat: ";
					cin >> id; 
					Phong T = this->list.findByID(id);
				
					
					while(T.getId()!=id)
					{
						cout << "Ma phong khong co trong danh sach\nNhap Ma phong: ";
						cin >> id; 
						 T = this->list.findByID(id);
					}
					
					newPhong.Update(id);
					
					this->updateByID(newPhong, id);
					cout << "Cap nhat thanh cong\n";
					system("pause");
					break;
				}
			case 3:
				{
					cout << "Nhap Ma phong muon xoa \n";
					cin >> id;
					if(this->removeByID(id)) cout << "xoa thanh cong\n";
					else cout << "Xoa khong thanh cong\n";
					system("pause");
					break;
				}
			case 4:
				{
					cout << "Nhap Ma phong muon tim kiem : ";
					cin >> id;
					Phong T;
					T= this->findByID(id);
					if(T.getId()!="")
					{
						cout << "------------------------------------------------------------------------------------------\n";
						cout <<"|"<< setw(20) << "Ma phong";
						cout <<"|"<< setw(20) << "Loai phong";
						cout <<"|"<< setw(20) << "Gia phong";
						cout <<"|"<< setw(27) << "Trang thai|\n";
						cout << "------------------------------------------------------------------------------------------\n";
						T.Output();
						cout << "------------------------------------------------------------------------------------------\n";
					}
					else
					{
						cout << "KHong co thong tin ma phong vua nhap\n";
					}
					system("pause");
					break;
				}
			case 5:
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
void PhongManager::save()
{
	// Ghi ra file
    Node<Phong> *ptr = this->list.getHead();
    ofstream out;
    out.open("phong.txt");
    out << this->list.getNodeCount() << endl;
    while (ptr != NULL)
    {
        ptr->getData().ExportToFile(out);
        ptr = ptr->getNext();
    }
    out.close();
}
PhongManager::~PhongManager()
{
    
}
void PhongManager::Show()
{
	cout << "------------------------------------------------------------------------------------------\n";
	cout <<"|"<< setw(20) << "Ma phong";
	cout <<"|"<< setw(20) << "Loai phong";
	cout <<"|"<< setw(20) << "Gia phong";
	cout <<"|"<< setw(27) << "Trang thai|\n";
	cout << "------------------------------------------------------------------------------------------\n";
    Node<Phong> *ptr = this->list.getHead();
    while (ptr != NULL)
    {
    	
        ptr->getData().Output();
        cout << "------------------------------------------------------------------------------------------\n";
        ptr = ptr->getNext();
        //cout << "------------------------------" << endl;
    }
}
void PhongManager::add(Phong S)
{

    if (this->indexOf(S)!=-1) 
    {
    	
    	cout << "Phong da ton tai" << endl; 
	}
        
    else
    {
	
	
        this->list.Append(S);
        cout << "Them thanh cong\n";
    }
}

void PhongManager::removeall()
{
	 while(this->list.getNodeCount()> 0)
    	this->list.removeAt(0);
}
bool PhongManager::remove(const Phong S)
{
    int index = this->list.indexOf(S);
    if (index == -1)
        return false;
    return this->list.removeAt(index);
}

int PhongManager::indexOf(const Phong S)
{
    return this->list.indexOf(S);
}

Phong PhongManager::findByID(const string &ID)
{
    return this->list.findByID(ID);
}

void PhongManager::ShowByID(const string &ID)
{
    Phong temp = this->list.findByID(ID);
    temp.Output();
}

bool PhongManager::removeByID(const string &ID)
{
    Phong temp = this->list.findByID(ID);
    return this->remove(temp);
}

bool PhongManager::updateByID(const Phong S, const string &ID)
{
    Node<Phong> *ptr = this->list.getHead();
    while (ptr != NULL)
    {
        if (ptr->getData().getId() == ID)
        {
            //cout << "Test" << endl;
            ptr->setData(S);
            return true;
        }
        ptr = ptr->getNext();
    }
    return false;
}

void PhongManager::listByStatus(const bool &status)
{
    Node<Phong> *ptr = this->list.getHead();
    while (ptr != NULL)
    {
        if (ptr->getData().getTrangthai() == status)
            ptr->getData().Output();
        ptr = ptr->getNext();
    }
}

void PhongManager::listByName(const string &name){
    Node<Phong> *ptr = this->list.getHead();
    while (ptr != NULL) 
    {
        if (ptr->getData().getLoaiPhong() == name)
            ptr->getData().Output();
        ptr = ptr->getNext();
    }
}
