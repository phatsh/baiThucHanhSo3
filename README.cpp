# baiThucHanhSo3
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

// count Sach
int demSach = 0 ;
// count TapChi
int demTapChi = 0;

class TaiLieu{
private:
    string maTL;
    string nhaXuatBan;
    int soPhatHanh;
public:
    TaiLieu(){
        maTL = "";
        nhaXuatBan = "";
        soPhatHanh = 0;
    }
    TaiLieu(string maTL, string nhaXuatBan, int soPhatHanh){
        this -> maTL = maTL;
        this -> nhaXuatBan = nhaXuatBan;
        this -> soPhatHanh = soPhatHanh;
    }
    void setMaTaiLieu(string maTL){
        this -> maTL = maTL;
    }
    string getMaTaiLieu(){
        return maTL;
    }
    void setNhaXuatBan(string nhaXuatBan){
        this -> nhaXuatBan = nhaXuatBan;
    }
    string getNhaXuatBan(){
        return nhaXuatBan;
    }
    void setSoPhatHanh(int soPhatHanh){
        this -> soPhatHanh = soPhatHanh;
    }
    int getSoPhatHanh(){
        return soPhatHanh;
    }
};


class Sach : public TaiLieu{
private:
    string tenTacGia;
    int soTrang;
public:
    Sach():TaiLieu(){
        tenTacGia ="";
        soTrang=0;
    }
    Sach(string maTL, string nhaXuatBan, int soPhatHanh, string tenTacGia, int soTrang) : TaiLieu(maTL, nhaXuatBan, soPhatHanh)
    {
        this -> tenTacGia = tenTacGia;
        this -> soTrang = soTrang;
    }
    void setTenTacGia(string tenTacGia)
    {
        this -> tenTacGia = tenTacGia;
    }
    string getTenTacGia()
    {
        return tenTacGia;
    }
    void setSoTrang(int soTrang)
    {
        this -> soTrang = soTrang;
    }
    int getSoTrang()
    {
        return soTrang;
    }
};

class TapChi : public TaiLieu
{
private:
    string date;
public:
    TapChi() : TaiLieu()
    {
        date = "";
    }
    TapChi (string maTL, string nhaXuatBan, int soPhatHanh, string date) : TaiLieu(maTL, nhaXuatBan, soPhatHanh)
    {
        this -> date = date;
    }
    void setDate(string date)
    {
        this -> date = date;
    }
    string getDate()
    {
        return date;
    }
};

void nhapSach(Sach ds1[], int n)
{
    for (int i=0;i<n;i++)
    {
        cin.ignore();
        string maTam1 = to_string(++demSach);
        cout << "Number:" << i+1 << endl;
        if (maTam1.length()==1)
        {
            maTam1="TL00" + maTam1;
            ds1[i].setMaTaiLieu(maTam1);
        }
        else if (maTam1.length()==2)
        {
            maTam1="TL0" + maTam1;
            ds1[i].setMaTaiLieu(maTam1);
        }
        else if (maTam1.length()==3)
        {
            maTam1="TL"+maTam1;
            ds1[i].setMaTaiLieu(maTam1);
        }
        cout << "Enter the publisher name:";
        string tenTam1;
        getline(cin, tenTam1);
        ds1[i].setNhaXuatBan(tenTam1);
        cout << "Enter issue number:";
        int issue1;
        cin >> issue1;
        ds1[i].setSoPhatHanh(issue1);
        cin.ignore();
        cout << "Enter author's name:";
        string author;
        getline(cin, author);
        ds1[i].setTenTacGia(author);
        cout << "Enter number page:";
        int page;
        cin >> page;
        ds1[i].setSoTrang(page);
    }
}

void xuatSach(Sach ds1[], int n)
{
    for (int i=0;i<n;i++)
    {
        cout << "Number:" << i+1 << endl;
        cout << "ID document:" << ds1[i].getMaTaiLieu() << endl;
        cout << "Publisher name:" << ds1[i].getNhaXuatBan() << endl;
        cout << "Issue number:" << ds1[i].getSoPhatHanh() << endl;
        cout << "Author's name:" << ds1[i].getTenTacGia() << endl;
        cout << "Number page:" << ds1[i].getSoTrang() << endl;
    }
}

void nhapTapChi(TapChi ds2[], int k)
{
    for (int i=0;i<k;i++)
    {
        cin.ignore();
        cout << "Number Book:" << i+1 << endl;
        string maTam2 = to_string(demTapChi);
        if (maTam2.length()==1)
        {
            maTam2 = "TL00" + maTam2;
        }
        else if (maTam2.length()==2)
        {
            maTam2 = "TL0" + maTam2;
        }
        else if (maTam2.length()==3)
        {
            maTam2 = "TL" + maTam2;
        }
        cout << "Enter the publisher name:";
        string tenTam2;
        getline(cin, tenTam2);
        ds2[i].setNhaXuatBan(tenTam2);
        cout << "Enter issue number:";
        int issue2;
        cin >> issue2;
        ds2[i].setSoPhatHanh(issue2);
        cin.ignore();
        cout << "Enter date release:";
        string day;
        getline(cin, day);
        if (day[2]!='/')
        {
            day.insert(day.begin(),'0');
        }
        else if (day[5]!='/')
        {
            day.insert(day.begin()+3, '0');
        }
        ds2[i].setDate(day);
    }
}

void xuatTapChi(TapChi ds2[], int k)
{
    for (int i=0;i<k;i++)
    {
        cout << "Number Magazine:" << i+1 << endl;
        cout << "ID Document:" << ds2[i].getMaTaiLieu() << endl;
        cout << "Name publisher:" << ds2[i].getNhaXuatBan() << endl;
        cout << "Issue Number:" << ds2[i].getSoPhatHanh() << endl;
        cout << "Date release:" << ds2[i].getDate() << endl;
    }
}

void timkiem_TacGia(Sach ds1[], int n)
{
    string name;
    cin.ignore();
    cout << "Enter Author's Name:";
    getline(cin, name);
    for (int i=0;i<n;i++)
    {
        if (ds1[i].getTenTacGia()==name)
        {
            cout << "Number Magazine:" << i+1 << endl;
            cout << "ID Document:" << ds1[i].getMaTaiLieu() << endl;
            cout << "Name publisher:" << ds1[i].getNhaXuatBan() << endl;
            cout << "Issue Number:" << ds1[i].getSoPhatHanh() << endl;
            cout << "Number page:" << ds1[i].getSoTrang() << endl;
        }
    }
}

void sapXepNXBSach(Sach ds1[], int n)
{
    Sach temp;
    for (int i=0;i<n;i++)
    {
        if (ds1[i].getNhaXuatBan() > ds1[i+1].getNhaXuatBan() )
        {
            temp = ds1[i+1];
            ds1[i+1] = ds1[i];
            ds1[i] = temp ;
        }
    }
}

void sapXepSoBanPhatHanhSach(Sach ds1[], int n)
{
    Sach temp;
    for (int i=0;i<n;i++)
    {
        if (ds1[i].getSoPhatHanh() > ds1[i].getSoPhatHanh() )
        {
            temp = ds1[i+1];
            ds1[i+1] =  ds1[i];
            ds1[i] = temp ;
        }
    }
}

void sapXepNXBTapChi(TapChi ds2[], int k)
{
    TapChi temp2;
    for (int i=0;i<k;i++)
    {
        if (ds2[i].getNhaXuatBan() > ds2[i+1].getNhaXuatBan() )
        {
            temp2 = ds2[i];
            ds2[i] = ds2[i+1];
            ds2[i+1] = temp2 ;
        }
    }
}

void sapXepSoBanPhatHanhTapChi(TapChi ds2[], int k)
{
    TapChi temp2;
    for (int i=0;i<k;i++)
    {
        if (ds2[i].getSoPhatHanh() > ds2[i+1].getSoPhatHanh() )
        {
            temp2 = ds2[i];
            ds2[i] = ds2[i+1];
            ds2[i+1] = temp2 ;
        }
    }
}

void ghiFileSach(Sach ds1[], int n, string nameFile)
{
   ofstream fileOut(nameFile, ios :: out | ios :: binary);
   if (!fileOut)
   {
       cout << "Not found file!!!" ; // file is not opened.
       exit(1);
   }
    for (int i=0;i<n;i++)
    {
        fileOut << "Number:" << i+1 << endl;
        fileOut << "ID document:" << ds1[i].getMaTaiLieu() << endl;
        fileOut << "Publisher name:" << ds1[i].getNhaXuatBan() << endl;
        fileOut << "Issue number:" << ds1[i].getSoPhatHanh() << endl;
        fileOut << "Author's name:" << ds1[i].getTenTacGia() << endl;
        fileOut << "Number page:" << ds1[i].getSoTrang() << endl;
    }
    fileOut.close();
}

void ghiFileTapChi(TapChi ds2[], int k, string nameFile2)
{
    ofstream fileOut2(nameFile2, ios :: out | ios :: binary);
    if (!fileOut2)
    {
        cout << "Not found file!!!";
        exit(1);
    }
    for (int i=0;i<k;i++)
    {
        fileOut2 << "Number Magazine:" << i+1 << endl;
        fileOut2 << "ID Document:" << ds2[i].getMaTaiLieu() << endl;
        fileOut2 << "Name publisher:" << ds2[i].getNhaXuatBan() << endl;
        fileOut2 << "Issue Number:" << ds2[i].getSoPhatHanh() << endl;
        fileOut2 << "Date release:" << ds2[i].getDate() << endl;
    }
    fileOut2.close();
}

void chuyenStringSangChar(string s)
{
    char *temp = new char (s.size()+1);
    for (int i=0;i<s.size()+1;i++)
    {
        temp[i] = s[i];
    }
    delete [] temp ;
    temp = NULL;
}


int timViTriSach(Sach ds1[], int n, string maTam)
{
    for (int i=0;i<n;i++)
    {
        if (ds1[i].getMaTaiLieu() == maTam);
        return i;
    }
    return -1;
}

void suaThongTinSach(Sach ds1[], int n)
{
     string maTam1;
     cin.ignore();
     cout << "Enter ID Document to change:";
     getline(cin, maTam1);
     int pos = timViTriSach(ds1, n, maTam1);
     if (pos == -1)
        cout << "Nope!!!";
     int chon;
     do
     {
         system("cls");
         cout << "\t\t 0.Exit." << endl;
         cout << "\t\t 1.Change ID." << endl ;
         cout << "\t\t 2.Change Publisher Name." << endl;
         cout << "\t\t 3.Change Issue Number." << endl;
         cout << "\t\t 4.Change Author's Name." << endl;
         cout << "\t\t 5.Change Number Page." << endl;
         cout << "Enter your choice:";
         cin >> chon ;
         switch(chon)
         {
            case 0:
            {
                cout << "\t\t 0.Exit." << endl;
                break;
            }
            case 1:
                {
                    string maMoi;
                    cin.ignore();
                    cout << "\t\t 1.Change ID." << endl ;
                    cout << "Old ID:" << ds1[pos].getMaTaiLieu();
                    cout << "New ID:";
                    getline(cin, maMoi);
                    ds1[pos].setMaTaiLieu(maMoi);
                    break;
                }
            case 2:
                {
                    string newName;
                    cin.ignore();
                    cout << "\t\t 2.Change Publisher Name." << endl;
                    cout << "Old Publisher Name:" << ds1[pos].getNhaXuatBan() << endl;
                    cout << "Enter New Publisher Name:";
                    getline(cin, newName);
                    ds1[pos].setNhaXuatBan(newName);
                    break;
                }
            case 3:
                {
                    int newNumber;
                    cout << "\t\t 3.Change Issue Number." << endl;
                    cout << "Old Issue Number:" << ds1[pos].getSoPhatHanh() << endl;
                    cout << "Enter New Issue Number:";
                    cin >> newNumber;
                    ds1[pos].setSoPhatHanh(newNumber);
                    break;
                }
            case 4:
                {
                    string newAuthor;
                    cin.ignore();
                    cout << "\t\t 4.Change Author's Name." << endl;
                    cout << "Old Author's Name:" << ds1[pos].getTenTacGia();
                    cout << "Enter New Author:";
                    getline(cin, newAuthor);
                    ds1[pos].setTenTacGia(newAuthor);
                    break;
                }
            case 5:
                {
                    int newPage;
                    cout << "\t\t 5.Change Number Page." << endl;
                    cout << "Old Number Page:" << ds1[pos].getSoTrang();
                    cout << "Enter New Number Page:";
                    cin >> newPage;
                    ds1[pos].setSoTrang(newPage);
                    break;
                }
            default:
                break;
         }
     }while(chon !=0);
}

int timVitriTapChi(TapChi ds2[], int k, string maTam2)
{
    for (int i=0;i<k;i++)
    {
        if (ds2[i].getMaTaiLieu()==maTam2);
        return i;
    }
    return -1;
}

void suaThongTinTapChi(TapChi ds2[], int k)
{
    string maTam2;
    cin.ignore();
    cout << "Enter ID Document to change:";
    getline(cin, maTam2);
    int pos2 = timVitriTapChi(ds2, k, maTam2);
    if (pos2==-1)
        cout << "Nope!!!" << endl ;
    int chon2;
    do
    {
        system("cls");
        cout << "\t\t 0.Exit." << endl;
        cout << "\t\t 1.Change ID Document." << endl;
        cout << "\t\t 2.Change Publisher Name." << endl;
        cout << "\t\t 3.Change Issue Number." << endl;
        cout << "\t\t 4.Change Date Release." << endl;
        cout << "Enter your choice:";
        cin >> chon2;
        switch(chon2)
        {
            case 0:
            {
                cout << "\t\t 0.Exit." << endl;
                break;
            }
            case 1:
            {
                string id2;
                cin.ignore();
                cout << "\t\t 1.Change ID Document." << endl;
                cout << "Old ID:" << ds2[pos2].getMaTaiLieu() << endl;
                cout << "Enter New ID:";
                getline(cin, id2);
                ds2[pos2].setMaTaiLieu(id2);
                break;
            }
            case 2:
            {
                string publisher2;
                cin.ignore();
                cout << "\t\t 2.Change Publisher Name." << endl;
                cout << "Old Publisher Name:" << ds2[pos2].getNhaXuatBan() << endl;
                cout << "Enter New Publisher Name:";
                getline(cin, publisher2);
                ds2[pos2].setNhaXuatBan(publisher2);
                break;
            }
            case 3:
            {
                int issue2;
                cout << "\t\t 3.Change Issue Number." << endl;
                cout << "Old Issue Number:" << ds2[pos2].getSoPhatHanh() << endl;
                cout << "Enter New Issue Number:";
                cin >> issue2;
                ds2[pos2].setSoPhatHanh(issue2);
                break;
            }
            case 4:
            {
                string dateTapChi;
                cin.ignore();
                cout << "\t\t 4.Change Date Release." << endl;
                cout << "Old Date Release:" << ds2[pos2].getDate() << endl;
                cout << "Enter New Date Release:";
                getline(cin, dateTapChi);
                break;
            }
            default:
                break;
        }

    }while(chon2!=0);
}

void xoaSach(Sach ds1[], int &n, int vitri)
{
    for (int i=vitri; i<n; i++)
    {
        ds1[i] = ds1[i+1];
    }
    n--;
}

void xoaSachTheoID(Sach ds1[], int &n)
{
    string delete1;
    cin.ignore();
    cout << "Enter ID you want delete:";
    getline(cin, delete1);
    int pos1 = timViTriSach(ds1, n, delete1);
    if (pos1==-1)
        cout << "Nope!!" << endl;
    xoaSach(ds1, n, pos1);
}

void xoaTapChi(TapChi ds2[], int &k, int vitri2)
{
    for (int i = vitri2; i<k; i++)
    {
        ds2[i]=ds2[i+1];
    }
    k--;
}

void xoaTapChiTheoID(TapChi ds2[], int &k)
{
    string delete2;
    cin.ignore();
    cout << "Enter ID you want delete:";
    getline(cin, delete2);
    int pos2 = timVitriTapChi(ds2, k, delete2);
    if (pos2==-1)
        cout << "Nope!!" << endl;
    xoaTapChi(ds2, k, pos2);
}

void timKiemTapChiTheoThang(TapChi ds2[], int k)
{
    string month;
    cin.ignore();
    cout << "Enter the month you want to find:";
    getline(cin, month);
    for (int i=0;i<k;i++)
    {
        string subTapChi = ds2[i].getDate().substr(3,9);
        if (month == subTapChi)
        {
            cout << "Number Magazine:" << i+1 << endl;
            cout << "ID Document:" << ds2[i].getMaTaiLieu() << endl;
            cout << "Name publisher:" << ds2[i].getNhaXuatBan() << endl;
            cout << "Issue Number:" << ds2[i].getSoPhatHanh() << endl;
            cout << "Date release:" << ds2[i].getDate() << endl;
        }
        else
        {
            cout << "Nope!!!";
            break;
        }
    }
}

int main()
{
    Sach ds1[100];
    int n;
    TapChi ds2[100];
    int k;
    int luachon;
    do
    {
        system("cls");
        cout << "\t\t 0.Exit."  << endl;
        cout << "\t\t 1.Enter the book list." << endl;
        cout << "\t\t 2.Enter the magazine list." << endl;
        cout << "\t\t 3.Export the book list." << endl;
        cout << "\t\t 4.Export the magazine list." << endl;
        cout << "\t\t 5.Export the book list follow Author's name." << endl;
        cout << "\t\t 6.Sort ascending follow Author's name." << endl;
        cout << "\t\t 7.Sort ascending follow Issue number." << endl;
        cout << "\t\t 8.Write in file with name entered from keyboard." << endl;
        cout << "\t\t 8.Change information follow ID document." << endl;
        cout << "\t\t 9.Delete Information follow ID document." << endl;
        cout << "\t\t 10.Find the magazine follow the date entered from keyboard." << endl;
        cout << "\t\t =======ENTER YOUR CHOICE=======" << endl;
        cin >> luachon;
        switch(luachon)
        {
            case 0:
            {
                cout << "\t\t 0.Exit." << endl;
                break;
            }
            case 1:
            {
                cout << "\t\t 1.Enter the book list." << endl;
                cout << "Enter amount book in the list:";
                cin >> n;
                nhapSach(ds1, n);
                break;
            }
            case 2:
            {
                cout << "\t\t 2.Enter the magazine list." << endl;
                cout << "Enter amount magazine the list:";
                cin >> k;
                nhapTapChi(ds2, n);
                break;
            }
            case 3:
            {
                cout << "\t\t 3.Export the book list." << endl;
                xuatSach(ds1, n);
                system("pause");
                break;
            }
            case 4:
            {
                cout << "\t\t 4.Export the magazine list." << endl;
                xuatTapChi(ds2, k);
                system("pause");
                break;
            }
            case 5:
            {
                cout << "\t\t 5.Export the book list follow Author's name." << endl;
                timkiem_TacGia(ds1, n);
                break;
            }
            case 6:
            {
                cout << "\t\t 6.Sort ascending follow Author's name." << endl;
                sapXepNXBSach(ds1, n);
                xuatSach(ds1, n);
                break;
            }
            case 7:
            {
                cout << "\t\t 7.Sort ascending follow Issue number." << endl;
                cout << "The book:" << endl;
                sapXepSoBanPhatHanhSach(ds1, n);
                xuatSach(ds1, n);
                cout << "The magazine:" << endl;
                sapXepSoBanPhatHanhTapChi(ds2, k);
                xuatTapChi(ds2, k);
                break;
            }
            case 8:
            {
                cout << "\t\t 8.Write in file with name entered from keyboard." << endl;
                string nameFile;
                cin.ignore();
                getline(cin, nameFile);
                ghiFileSach(ds1, n, nameFile);
                string nameFile2;
                cin.ignore();
                getline(cin, nameFile2);
                ghiFileTapChi(ds2, k, nameFile2);
                break;
            }
            case 9:
            {
                cout << "\t\t 9.Delete Information follow ID document." << endl;
                cout << "The book:" << endl;
                xoaSachTheoID(ds1, n);
                xuatSach(ds1, n);
                cout << endl;
                cout << "The magazine:" << endl;
                xoaTapChiTheoID(ds2, k);
                xuatTapChi(ds2, k);
                break;
            }
            case 10:
            {
                cout << "\t\t 10.Find the magazine follow the date entered from keyboard." << endl;
                timKiemTapChiTheoThang(ds2, k);
                break;
            }
        }
    }while(luachon!=0);
    cout << "Hello world";
    getchar();
    return 0;
}
