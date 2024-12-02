#include <iostream>
#include <vector>
using namespace std;

class Kendaraan {
    public :
        string nomorKendaraan;

        Kendaraan(string nomorKendaraan){
            this->nomorKendaraan = nomorKendaraan;
        }

        virtual void ctkStatus(){
            cout << "Generate Kendaraan Information" << endl;
        }
};

class Mobil : public Kendaraan {
    private :
        int waktuDatang;
        int waktuPergi;
        int lamaParkir;
    public :
        Mobil(string nomorKendaraan) : Kendaraan(nomorKendaraan){}

        void setWaktuDatang(int waktuDatang){
            this->waktuDatang = waktuDatang;
        }

        void setWaktuPergi(int waktuPergi){
            this->waktuPergi = waktuPergi;
        }

        void setLamaParkir(int lamaParkir){
            this->lamaParkir = lamaParkir;
        }

        int getWaktuDatang(){
            return this->waktuDatang;
        }

        int getWaktuPergi(){
            return this->waktuPergi;
        }

        int getLamaParkir(){
            return this->lamaParkir;
        }
        void ctkStatus() override {
            cout << "Mobil Information" << endl;
            cout << "Nomor Kendaraan: " << this->nomorKendaraan << endl;
            cout << "Waktu Datang: " << this->waktuDatang << endl;
            cout << "Waktu Pergi: " << this->waktuPergi << endl;
            cout << "Lama Parkir: " << this->waktuPergi - this->waktuDatang << " jam" << endl;
        }
};

class Motor : public Kendaraan {
    private :
        int waktuDatang;
        int waktuPergi;
        int lamaParkir;
    public :
        Motor(string nomorKendaraan) : Kendaraan(nomorKendaraan){}

        void setWaktuDatang(int waktuDatang){
            this->waktuDatang = waktuDatang;
        }

        void setWaktuPergi(int waktuPergi){
            this->waktuPergi = waktuPergi;
        }

        void setLamaParkir(int lamaParkir){
            this->lamaParkir = lamaParkir;
        }

        int getWaktuDatang(){
            return this->waktuDatang;
        }

        int getWaktuPergi(){
            return this->waktuPergi;
        }

        int getLamaParkir(){
            return this->lamaParkir;
        }
        void ctkStatus() override {
            cout << "Mobil Information" << endl;
            cout << "Nomor Kendaraan: " << this->nomorKendaraan << endl;
            cout << "Waktu Datang: " << this->waktuDatang << endl;
            cout << "Waktu Pergi: " << this->waktuPergi << endl;
            cout << "Lama Parkir: " << this->waktuPergi - this->waktuDatang << " jam" << endl;
        }
};

class Becak : public Kendaraan {
    private :
        int waktuDatang;
        int waktuPergi;
        int lamaParkir;
    public :
        Becak(string nomorKendaraan) : Kendaraan(nomorKendaraan){}

        void setWaktuDatang(int waktuDatang){
            this->waktuDatang = waktuDatang;
        }

        void setWaktuPergi(int waktuPergi){
            this->waktuPergi = waktuPergi;
        }

        void setLamaParkir(int lamaParkir){
            this->lamaParkir = lamaParkir;
        }

        int getWaktuDatang(){
            return this->waktuDatang;
        }

        int getWaktuPergi(){
            return this->waktuPergi;
        }

        int getLamaParkir(){
            return this->lamaParkir;
        }
        void ctkStatus() override {
            cout << "Mobil Information" << endl;
            cout << "Nomor Kendaraan: " << this->nomorKendaraan << endl;
            cout << "Waktu Datang: " << this->waktuDatang << endl;
            cout << "Waktu Pergi: " << this->waktuPergi << endl;
            cout << "Lama Parkir: " << this->waktuPergi - this->waktuDatang << " jam" << endl;
        }
};

class Mall {
    private :
        int jmlhKendaraan;
        int pendapatan;
        Kendaraan *kendaraan;

    public :
        vector<Mobil> list_mobil;
        vector<Motor> list_motor;
        vector<Becak> list_becak;
        
        Mall(){
            this->jmlhKendaraan = 0;
            this->pendapatan = 0;
            this->list_mobil = {};
            this->list_motor = {};
            this->list_becak = {};
        }

        void tmbhMobil(){
            string nomorKendaraan;
            cout << "Masukkan nomor kendaraan: ";
            cin >> nomorKendaraan;
            Mobil mobil(nomorKendaraan);
            this->list_mobil.push_back(mobil);
            this->jmlhKendaraan++;
        }
        
        void tmbhBecak(){
            string nomorKendaraan;
            cout << "Masukkan nomor kendaraan: ";
            cin >> nomorKendaraan;
            Becak becak(nomorKendaraan);
            this->list_becak.push_back(becak);
            this->jmlhKendaraan++;
        }
        
        void tmbhMotor(){
            string nomorKendaraan;
            cout << "Masukkan nomor kendaraan: ";
            cin >> nomorKendaraan;
            Motor motor(nomorKendaraan);
            this->list_motor.push_back(motor);
            this->jmlhKendaraan++;
        }

        void keluarMobil(){
            string nomorKendaraan;
            cout << "Masukkan nomor kendaraan: ";
            cin >> nomorKendaraan;
            for (int i = 0; i < this->list_mobil.size(); i++) {
                if (this->list_mobil[i].nomorKendaraan == nomorKendaraan) {
                    int waktuPergi;
                    cout << "Masukkan waktu pergi: ";
                    cin >> waktuPergi;
                    this->list_mobil[i].setWaktuPergi(waktuPergi);
                    this->list_mobil[i].ctkStatus();
                    if (this->list_mobil[i].getLamaParkir() > 10) {
                        this->pendapatan += 20000;
                    } else if (this->list_mobil[i].getLamaParkir() > 1) {
                        this->pendapatan += 10000;
                    } else {
                        this->pendapatan += 5000;
                    }
                    this->list_mobil.erase(this->list_mobil.begin() + i);
                    this->jmlhKendaraan--;
                    return;
                }
            }
            cout << "Kendaraan tidak ditemukan" << endl;
        }
    
};

int main(){
    Mall mall;
    int pilihan;
    while (true){
        cout << "1. Tambah Mobil" << endl;
        cout << "2. Tambah Motor" << endl;
        cout << "3. Tambah Becak" << endl;
        cout << "4. Keluar Mobil" << endl;
        cout << "5. Keluar Motor" << endl;
        cout << "6. Keluar Becak" << endl;
        cout << "7. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan){
            case 1:
                mall.tmbhMobil();
                break;
            case 2:
                mall.tmbhMotor();
                break;
            case 3:
                mall.tmbhBecak();
                break;
            case 4:
                mall.keluarMobil();
                break;
            case 7:
                return 0;
        }
    }
}