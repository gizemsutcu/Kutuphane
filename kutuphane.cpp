//Gizem SÜTÇÜ

#include<iostream>
#include<fstream>
#include<sstream> 
#include<string>
using namespace std;
int selection;
int kitapNumarasi;
int kitapId;
int adet = 0;
int adet1 = 0;
int adet2 = 0;
int static sayac = 0;
int static sayac2 = 0;
int static sayac3 = 0;
int static sayac4 = 0;
int static sayac5 = 0;
string kitapNumarasii;
string aranilanYazarAdi;
string aranilanKitapAdi;
string kitapAdi;
string yazarAdi;
string girilenKitapAdi;
string girilenYazarAdi;
string index[180];
string books[300];
string gecici[187];
string gecici2[300];
string kitap[150];
string yazar[150];
string a;
string okunanKayit;

int f(int x) {
	return x % 30;
}

bool varmý(int kitapNumarasi) {
	bool varmý = false;
	for (int d = 0; d < 30; d++) {
		for (int e = (d * 6) + 1; e < (d * 6) + 6; e++) {
			kitapNumarasii = to_string(kitapNumarasi);
			if (index[e] == kitapNumarasii) {
				varmý = true;
			}
		}
	}
	return varmý;
}

int main() {

	/*ofstream dosyaYaz;
dosyaYaz.open("index.dat");
ofstream dosya1("index.dat");
dosya1 << "Raf Numarasi" << "   " << " B1 " << " " << " B2 " << " " << " B3 " << " " << " B4 " << " " << " B5 " << endl;
for (int i = 0; i < 30; i++) {
	index[i * 6] = to_string(i);
}
for (int i = 0; i < 10; i++) {
	dosya1 << "       " << index[i * 6] << "      " << " " << "NULL" << "  " << "NULL" << "  " << "NULL" << "  " << "NULL" << "  " << "NULL" << endl;
}
for (int i = 10; i < 30; i++) {
	dosya1 << "      " << index[i * 6] << "      " << " " << "NULL" << "  " << "NULL" << "  " << "NULL" << "  " << "NULL" << "  " << "NULL" << endl;
}

ofstream dosyaYaz2;
dosyaYaz2.open("books.dat");
ofstream dosya2("books.dat");
for (int i = 0; i < 30; i++) {
	dosya2 << "NULL" << " " << "NULL" << "  " << "NULL" << " " << "NULL" << "  " << "NULL" << " " << "NULL" << "  " << "NULL" << " " << "NULL" << "  " << "NULL" << " " << "NULL" << endl;
}*/
    ifstream okumaDosyasi("index.dat");
	for (int i = 0; i < 187; i++) {
		okumaDosyasi >> a;
		gecici[i] = a;
	}
    for (int i = 7; i < 187; i++) {
		index[i - 7] = gecici[i];
	}
    ifstream okumaDosyasi2("books.dat");
	for (int i = 0; i < 300; i++) {
		okumaDosyasi2 >> a;
		gecici2[i] = a;
	}
    for (int i = 0; i < 300; i++) {
		books[i] = gecici2[i];
	}

	ofstream dosyaYaz;
	dosyaYaz.open("index.dat");
	ofstream dosya1("index.dat");
	if (dosya1.is_open()) {
		ofstream dosyaYaz21("index.dat");
		if (dosyaYaz21.is_open()) {
			dosyaYaz21 << "Raf Numarasi" << "   " << " B1 " << "  " << " B2 " << "  " << " B3 " << "  " << " B4 " << "  " << " B5 " << endl;
			for (int i = 0; i < 30; i++) {
				index[i * 6] = to_string(i);
			}
			for (int i = 0; i < 10; i++) {
				dosyaYaz21 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
			}
			for (int i = 10; i < 30; i++) {
				dosyaYaz21 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
			}
		}
		else {
			cout << "Basarisiz!" << endl;
		}
	}
	else {
		cout << "Dosya acilamadi!!" << endl;
	}

	ofstream dosyaYaz2;
	dosyaYaz2.open("books.dat");
	ofstream dosya2("books.dat");
	if (dosya2.is_open()) {
		ofstream dosyaYaz22("books.dat");
		if (dosyaYaz22.is_open()) {
			for (int i = 0; i < 30; i++) {
				dosyaYaz22 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
			}
		}
		else {
			cout << "Basarisiz!" << endl;
		}
	}
	else {
		cout << "Dosya acilamadi!!" << endl;
	}

	while (1) {
		cout << "MENU" << endl;
		cout << "Islem secenekleriniz:" << endl;

		cout << "1-Yeni bir kitap yerlestirme" << endl;
		cout << "2-Varolan bir kitabi arama" << endl;
		cout << "3-Varolan bir kitabin silinmesi" << endl;
		cout << "4-Dosyalardaki verileri goster" << endl;
		cout << "5-Sistemden cikis" << endl << endl;

		cout << "Yapmak istediginiz islemi seciniz" << endl;
		cout << "*************************************" << endl;
		cin >> selection;

		if (selection < 0 && selection>6) {
			cout << "Yanlis secim!!" << endl;
			cout << "Tekrardan yapmak istediginiz islemi seciniz" << endl;
			cin >> selection;
		}

		switch (selection)
		{
		case 1:
			cout << "Kitap Ekleme" << endl << endl;
			cout << "Eklemekmek istediginiz kitabin id sini giriniz" << endl;
			cin >> kitapNumarasi;
			//kitapNumarasii = to_string(kitapNumarasi);
			varmý(kitapNumarasi);
			if (!varmý(kitapNumarasi)) {
				if (kitapNumarasi < 0 || kitapNumarasi > 500) {
					cout << "Girilen kitap numarasi hatalidir!" << endl;
				}
				else {
					kitapId = f(kitapNumarasi);
					kitapNumarasii = to_string(kitapNumarasi);
					cout << "Ekleyecegimiz kitabin hash fonksiyonunun sonuc degeri:" << " " << kitapId << " " << "dir" << endl;
					cout << "Eklemekmek istediginiz kitabin adini giriniz" << endl;
					cout << "Kitap adi birden fazla kelime icerirse kelimelerin arasina (_) koyunuz!" << endl;
					cin >> kitapAdi;
					cout << "Eklemekmek istediginiz kitabin yazar adini giriniz" << endl;
					cout << "Yazar adi birden fazla kelime icerirse kelimelerin arasina (_) koyunuz!" << endl;
					cin >> yazarAdi;
					if ((index[(kitapId * 5) + kitapId + 1]) == "///") {
						(index[(kitapId * 5) + kitapId + 1]) = kitapNumarasii;
						books[(kitapId * 10)] = yazarAdi;
						books[(kitapId * 10) + 1] = kitapAdi;
						cout << "Eklenen kayit (///) tombstone yerine eklendi" << endl;
						if (dosya1.is_open()) {
							ofstream dosyaYaz1("index.dat");
							if (dosyaYaz1.is_open()) {
								dosyaYaz << "Raf Numarasi" << "   " << " B1 " << "  " << " B2 " << "  " << " B3 " << "  " << " B4 " << "  " << " B5 " << endl;
								for (int i = 0; i < 30; i++) {
									index[i * 6] = to_string(i);
								}
								for (int i = 0; i < 10; i++) {
									dosyaYaz << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
								}
								for (int i = 10; i < 30; i++) {
									dosyaYaz << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
								}
							}
							else {
								cout << "Kayit ekleme islemi dosyaya aktarilamadi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}

						if (dosya2.is_open()) {
							ofstream dosyaYaz2("books.dat");
							if (dosyaYaz2.is_open()) {
								for (int i = 0; i < 30; i++) {
									dosyaYaz2 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
								}
							}
							else {
								cout << "Eklenen kayit yazar-kitap dosyasina eklenemedi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}
					}

					else if ((index[(kitapId * 5) + kitapId + 1]) == "NULL") {
						(index[(kitapId * 5) + kitapId + 1]) = kitapNumarasii;
						books[(kitapId * 10)] = yazarAdi;
						books[(kitapId * 10) + 1] = kitapAdi;
						cout << "Kayit basarili bir sekilde eklendi" << endl;

						if (dosya1.is_open()) {
							ofstream dosyaYaz1("index.dat");
							if (dosyaYaz1.is_open()) {
								dosyaYaz << "Raf Numarasi" << "   " << " B1 " << "  " << " B2 " << "  " << " B3 " << "  " << " B4 " << "  " << " B5 " << endl;
								for (int i = 0; i < 30; i++) {
									index[i * 6] = to_string(i);
								}
								for (int i = 0; i < 10; i++) {
									dosyaYaz << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
								}
								for (int i = 10; i < 30; i++) {
									dosyaYaz << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
								}
							}
							else {
								cout << "Kayit ekleme islemi dosyaya aktarilamadi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}

						if (dosya2.is_open()) {
							ofstream dosyaYaz2("books.dat");
							if (dosyaYaz2.is_open()) {
								for (int i = 0; i < 30; i++) {
									dosyaYaz2 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
								}
							}
							else {
								cout << "Eklenen kayit yazar-kitap dosyasina eklenemedi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}
					}

					else if ((index[(kitapId * 5) + kitapId + 1]) != "///") {
						int i = 0;
					basla2:
						if (index[(kitapId * 5) + kitapId + 1 + i] != "NULL") {
							if (index[(kitapId * 5) + kitapId + 1 + i] == "///")
							{
								index[(kitapId * 5) + kitapId + 1 + i] = kitapNumarasii;
								books[(kitapId * 10) + 2 * i] = yazarAdi;
								books[(kitapId * 10) + 1 + 2 * i] = kitapAdi;
								cout << "Eklenen kayit (///) tombstone yerine eklendi" << endl;
							}
							else
							{
								if (i == 0 || i == 1 || i == 2 || i == 3) {
									i++;
									goto basla2;
								}
								else { cout << "Kitaplari koydugumuz 5 Raf da doldu, daha fazla kitap eklenemez!" << endl; }
							}
						}
						else if (index[(kitapId * 5) + kitapId + 1 + i] == "NULL") {
							index[(kitapId * 5) + kitapId + 1 + i] = kitapNumarasii;
							books[(kitapId * 10) + 2 * i] = yazarAdi;
							books[(kitapId * 10) + 1 + 2 * i] = kitapAdi;
							cout << "Kayit basarili bir sekilde eklendi" << endl;
						}
						else {
							cout << "Kitaplari koydugumuz 5 Raf da doldu, daha fazla kitap eklenemez!" << endl;
						}
						//yapilan degisiklikleri dosyalarda guncelleme isleme
						if (dosya1.is_open()) {
							ofstream dosyaYaz3("index.dat");
							dosyaYaz3 << "Raf Numarasi" << "   " << " B1 " << "  " << " B2 " << "  " << " B3 " << "  " << " B4 " << "  " << " B5 " << endl;
							for (int i = 0; i < 30; i++) {
								index[i * 6] = to_string(i);
							}
							for (int i = 0; i < 10; i++) {
								dosyaYaz3 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
							for (int i = 10; i < 30; i++) {
								dosyaYaz3 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}

						if (dosya2.is_open()) {
							ofstream dosyaYaz4("books.dat");
							if (dosyaYaz4.is_open()) {
								for (int i = 0; i < 30; i++) {
									dosyaYaz4 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
								}
							}
							else {
								cout << "Eklenen kayit yazar-kitap dosyasina eklenemedi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}
					}

					else if ((index[(kitapId * 5) + kitapId + 1]) != "NULL") {
						int i = 0;
					basla:
						if (index[(kitapId * 5) + kitapId + 1 + i] != "NULL") {
							if ((index[(kitapId * 5) + kitapId + 1 + i] == "///"))
							{
								index[(kitapId * 5) + kitapId + 1 + i] = kitapNumarasii;
								books[(kitapId * 10) + 2 * i] = yazarAdi;
								books[(kitapId * 10) + 1 + 2 * i] = kitapAdi;
								cout << "Eklenen kayit (///) tombstone yerine eklendi" << endl;
							}
							else
							{
								if (i == 0 || i == 1 || i == 2 || i == 3) {
									i++;
									goto basla;
								}
								else { cout << "Kitaplari koydugumuz 5 Raf da doldu, daha fazla kitap eklenemez!" << endl; }
							}
						}
						else if (index[(kitapId * 5) + kitapId + 1 + i] == "NULL") {
							index[(kitapId * 5) + kitapId + 1 + i] = kitapNumarasii;
							books[(kitapId * 10) + 2 * i] = yazarAdi;
							books[(kitapId * 10) + 1 + 2 * i] = kitapAdi;
							cout << "Kayit basarili bir sekilde eklendi" << endl;
						}
						else {
							cout << "Kitaplari koydugumuz 5 Raf da doldu, daha fazla kitap eklenemez!" << endl;
						}
						//yapilan degisiklikleri dosyalarda guncelleme isleme
						if (dosya1.is_open()) {
							ofstream dosyaYaz3("index.dat");
							dosyaYaz3 << "Raf Numarasi" << "   " << " B1 " << "  " << " B2 " << "  " << " B3 " << "  " << " B4 " << "  " << " B5 " << endl;
							for (int i = 0; i < 30; i++) {
								index[i * 6] = to_string(i);
							}
							for (int i = 0; i < 10; i++) {
								dosyaYaz3 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
							for (int i = 10; i < 30; i++) {
								dosyaYaz3 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}

						if (dosya2.is_open()) {
							ofstream dosyaYaz4("books.dat");
							if (dosyaYaz4.is_open()) {
								for (int i = 0; i < 30; i++) {
									dosyaYaz4 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
								}
							}
							else {
								cout << "Eklenen kayit yazar-kitap dosyasina eklenemedi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}
					}

					else {
						cout << "Kitaplari koydugumuz 5 Raf da doldu, daha fazla kitap eklenemez!" << endl;
					}
				}
			}
			else {
			cout << "Eklemek istediginiz kitap onceden eklenmistir!" << endl;
			    break;
            }
			cout << "Baska bir islem yapmak isterseniz yeni bir islem secenegi seciniz" << endl;
			cout << "Baska bir islem yapmak istemezseniz secenek besi seciniz" << endl;
			break;

		case 2:
			cout << "Kitap Arama" << endl;
			cout << "Islem secenekleriniz:" << endl;
			cout << "1-Kitap numarasi ile arama" << endl;
			cout << "2-Kitap adi ile arama" << endl;
			cout << "3-Yazar adi ile arama" << endl;
			cout << "Yapmak istediginiz islemi seciniz" << endl;
			cout << "*************************************" << endl;
			cin >> selection;

			if (selection < 0 && selection>3) {
				cout << "Yanlis secim!!" << endl;
				cout << "Tekrardan yapmak istediginiz islemi seciniz" << endl;
				cin >> selection;
			}
			switch (selection)
			{
			case 1:
				cout << "Aramak istediginiz kitabin id sini giriniz" << endl;
				cin >> kitapNumarasi;
				if (0 < kitapNumarasi <= 500) {
					kitapId = f(kitapNumarasi);
					kitapNumarasii = to_string(kitapNumarasi);
				}
				else {
					cout << "Girilen kitap id si hatalidir!" << endl;
				}
				if (index[(kitapId * 5) + kitapId + 1] == kitapNumarasii) {
					aranilanYazarAdi = books[kitapId * 10];
					aranilanKitapAdi = books[(kitapId * 10) + 1];
					cout << "Aradiginiz kitap, kitap id lerini tuttugumuz kitaplikta " << kitapId << " numarali rafta B1(ilk bolumde) bulundu." << endl;
					cout << "Kitap aramasi sirasinda 0 bolum ve 0 adet tombstone(///) atlandi." << endl;
					cout << "Aradiginiz kitabin adi:" << aranilanKitapAdi << " dir." << endl;
					cout << "Aradiginiz kitabin yazar adi:" << aranilanYazarAdi << " dir." << endl;
				}
				else if (index[(kitapId * 5) + kitapId + 1 + 1] == kitapNumarasii) {
					aranilanYazarAdi = books[(kitapId * 10) + 2];
					aranilanKitapAdi = books[(kitapId * 10) + 3];
					cout << "Aradiginiz kitap, kitap id lerini tuttugumuz kitaplikta " << kitapId << " numarali rafta B2(ikinci bolumde) bulundu." << endl;
					for (int x = 0; x < 1; x++) {
						if (index[(kitapId * 5) + kitapId + 1 + x] == "///") {
							adet++;
						}
						else {}
					}
					cout << "Kitap aramasi sirasinda 1 bolum ve " << adet << " adet tombstone(///) atlandi." << endl;
					cout << "Aradiginiz kitabin adi:" << aranilanKitapAdi << " dir." << endl;
					cout << "Aradiginiz kitabin yazar adi:" << aranilanYazarAdi << " dir." << endl;
				}
				else if (index[(kitapId * 5) + kitapId + 1 + 2] == kitapNumarasii) {
					aranilanYazarAdi = books[(kitapId * 10) + 4];
					aranilanKitapAdi = books[(kitapId * 10) + 5];
					cout << "Aradiginiz kitap, kitap id lerini tuttugumuz kitaplikta " << kitapId << " numarali rafta B3(ucuncu bolumde) bulundu." << endl;
					for (int x = 0; x < 2; x++) {
						if (index[(kitapId * 5) + kitapId + 1 + x] == "///") {
							adet++;
						}
						else {}
					}
					cout << "Kitap aramasi sirasinda 2 bolum ve " << adet << " adet tombstone(///) atlandi." << endl;
					cout << "Aradiginiz kitabin adi:" << aranilanKitapAdi << " dir." << endl;
					cout << "Aradiginiz kitabin yazar adi:" << aranilanYazarAdi << " dir." << endl;
				}
				else if (index[(kitapId * 5) + kitapId + 1 + 3] == kitapNumarasii) {
					aranilanYazarAdi = books[(kitapId * 10) + 6];
					aranilanKitapAdi = books[(kitapId * 10) + 7];
					cout << "Aradiginiz kitap, kitap id lerini tuttugumuz kitaplikta " << kitapId << " numarali rafta B4(dorduncu bolumde) bulundu." << endl;
					for (int x = 0; x < 3; x++) {
						if (index[(kitapId * 5) + kitapId + 1 + x] == "///") {
							adet++;
						}
						else {}
					}
					cout << "Kitap aramasi sirasinda 3 bolum ve " << adet << " adet tombstone(///) atlandi." << endl;
					cout << "Aradiginiz kitabin adi:" << aranilanKitapAdi << " dir." << endl;
					cout << "Aradiginiz kitabin yazar adi:" << aranilanYazarAdi << " dir." << endl;
				}
				else if (index[(kitapId * 5) + kitapId + 1 + 4] == kitapNumarasii) {
					aranilanYazarAdi = books[(kitapId * 10) + 8];
					aranilanKitapAdi = books[(kitapId * 10) + 9];
					cout << "Aradiginiz kitap, kitap id lerini tuttugumuz kitaplikta " << kitapId << " numarali rafta B5(besinci bolumde) bulundu." << endl;
					for (int x = 0; x < 4; x++) {
						if (index[(kitapId * 5) + kitapId + 1 + x] == "///") {
							adet++;
						}
						else {}
					}
					cout << "Kitap aramasi sirasinda 4 bolum ve " << adet << " adet tombstone(///) atlandi." << endl;
					cout << "Aradiginiz kitabin adi:" << aranilanKitapAdi << " dir." << endl;
					cout << "Aradiginiz kitabin yazar adi:" << aranilanYazarAdi << " dir." << endl;
				}
				else {
					cout << "Aradiginiz kitap bulunamadi!!!" << endl;
				}
				break;
			case 2:
				if (dosya2.is_open()) {
					ifstream dosyaOkuma22("books.dat");
					for (int i = 0; i < 30; i++) {
						for (int j = (i * 5); j < (i * 5) + 5; j++) {
							dosyaOkuma22 >> okunanKayit;
							yazar[j] = okunanKayit;
							dosyaOkuma22 >> okunanKayit;
							kitap[j] = okunanKayit;
						}
					}
				}
				else {
					cout << "Books.dat dosyasi acilamadigi icin goruntuleme islemi basarisiz!!" << endl;
				}				
				cout << "Aramak istediginiz kitabin adini giriniz" << endl;
				cin >> girilenKitapAdi;

				for (int i = 0; i < 150; i++) {
					if (kitap[i] == girilenKitapAdi) {
						aranilanKitapAdi = girilenKitapAdi;
						aranilanYazarAdi = yazar[i];
						int b = i / 5;
						int c = i - (5 * b);
						int a = (c + 1) / 2;
						cout << "Aradiginiz kitap, kitap adi-yazar adi bilgilerini tuttugumuz kitaplikta " << b + 1 << ". rafta " << c + 1 << ". bolumde bulundu." << endl;
						for (int x = 1; x < c + 1; x++) {
							if (index[(b * 6) + x] == "///") {
								adet1++;
							}
							else {}
						}
						cout << "Kitap aramasi sirasinda " << c << " bolum ve " << adet1 << " adet tombstone(///) atlandi." << endl;
						cout << "Aradiginiz kitabin id si:" << index[(b * 6) + (c + 1)] << endl;
						cout << "Aradiginiz kitabin adi:" << aranilanKitapAdi << " dir." << endl;
						cout << "Aradiginiz kitabin yazar adi:" << aranilanYazarAdi << " dir." << endl;
					}
					else {
						sayac++;
					}
				}
			    if(sayac==150){cout << "Girilen kitap adinda kitaplikta kayit bulunmamaktadir!!" << endl;}
				break;
			case 3:
				if (dosya2.is_open()) {
					ifstream dosyaOkuma23("books.dat");
					for (int i = 0; i < 30; i++) {
						for (int j = (i * 5); j < (i * 5) + 5; j++) {
							dosyaOkuma23 >> okunanKayit;
							yazar[j] = okunanKayit;
							dosyaOkuma23 >> okunanKayit;
							kitap[j] = okunanKayit;
						}
					}
				}
				else {
					cout << "Books.dat dosyasi acilamadigi icin goruntuleme islemi basarisiz!!" << endl;
				}				
				cout << "Aramak istediginiz kitabin yazar adini giriniz" << endl;
				cin >> girilenYazarAdi;

				for (int i = 0; i < 150; i++) {
					if (yazar[i] == girilenYazarAdi) {
						aranilanYazarAdi = girilenYazarAdi;
						aranilanKitapAdi = kitap[i];
						int b = (i / 5);
						int c = (i + 1) - (5 * b);
						int a = (c + 1) / 2;
						cout << "Aradiginiz kitap, kitap adi-yazar adi bilgilerini tuttugumuz kitaplikta " << b + 1 << ". rafta " << c << ". bolumde bulundu." << endl;
						for (int x = 1; x < c; x++) {
							if (index[(b * 6) + x] == "///") {
								adet2++;
							}
							else {}
						}
						cout << "Kitap aramasi sirasinda " << c - 1 << " bolum ve " << adet2 << " adet tombstone(///) atlandi." << endl;
						cout << "Aradiginiz kitabin id si:" << index[(b * 6) + c] << endl;
						cout << "Aradiginiz kitabin adi:" << aranilanKitapAdi << " dir." << endl;
						cout << "Aradiginiz kitabin yazar adi:" << aranilanYazarAdi << " dir." << endl;
					}
					else {
						sayac2++;
					}
				}
				if (sayac2 == 150) { cout << "Girilen yazar adinda kitaplikta kayit bulunmamaktadir!!" << endl; }
				break;
			default:
				cout << "Arama islemini yanlis gerceklestirdiniz" << endl;
				break;
			}
			cout << "Baska bir islem yapmak isterseniz yeni bir islem secenegi seciniz" << endl;
			cout << "Baska bir islem yapmak istemezseniz secenek besi seciniz" << endl;
			break;
		case 3:
			cout << "Kitap Silme" << endl;
			cout << "Islem secenekleriniz:" << endl;
			cout << "1-Kitap id ile silme" << endl;
			cout << "2-Kitap adi ile silme" << endl;
			cout << "3-Yazar adi ile silme" << endl;
			cout << "Yapmak istediginiz islemi seciniz" << endl;
			cout << "*************************************" << endl;
			cin >> selection;

			if (selection < 0 && selection>3) {
				cout << "Yanlis secim!!" << endl;
				cout << "Tekrardan yapmak istediginiz islemi seciniz" << endl;
				cin >> selection;
			}

			switch (selection) {
			case 1:
				cout << "Silmek istediginiz kitabin id sini giriniz" << endl;
				cin >> kitapNumarasi;
				if (0 < kitapNumarasi <= 500) {
					kitapId = f(kitapNumarasi);
					kitapNumarasii = to_string(kitapNumarasi);
				}
				else {
					cout << "Girilen kitap id hatalidir!" << endl;
				}

				if (index[(kitapId * 5) + kitapId + 1] == kitapNumarasii) {
					index[(kitapId * 5) + kitapId + 1] = "///";
					books[kitapId * 10] = "///";
					books[(kitapId * 10) + 1] = "///";
					cout << "Silmek istediginiz kitap silindi" << endl;
					if (dosya1.is_open()) {
						ofstream dosyaYaz5("index.dat");
						if (dosyaYaz5.is_open()) {
							dosyaYaz5 << "Raf Numarasi" << "   " << " B1 " << " " << " B2 " << " " << " B3 " << " " << " B4 " << " " << " B5 " << endl;
							for (int i = 0; i < 10; i++) {
								dosyaYaz5 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
							for (int i = 10; i < 30; i++) {
								dosyaYaz5 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

					if (dosya2.is_open()) {
						ofstream dosyaYaz6("books.dat");
						if (dosyaYaz6.is_open()) {
							for (int i = 0; i < 30; i++) {
								dosyaYaz6 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}
				}
				else if (index[(kitapId * 5) + kitapId + 1 + 1] == kitapNumarasii) {
					index[(kitapId * 5) + kitapId + 1 + 1] = "///";
					books[kitapId * 10 + 2] = "///";
					books[(kitapId * 10) + 3] = "///";
					cout << "Silmek istediginiz kitap silindi" << endl;
					if (dosya1.is_open()) {
						ofstream dosyaYaz7("index.dat");
						if (dosyaYaz7.is_open()) {
							dosyaYaz7 << "Raf Numarasi" << "   " << " B1 " << " " << " B2 " << " " << " B3 " << " " << " B4 " << " " << " B5 " << endl;
							for (int i = 0; i < 10; i++) {
								dosyaYaz7 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
							for (int i = 10; i < 30; i++) {
								dosyaYaz7 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

					if (dosya2.is_open()) {
						ofstream dosyaYaz8("books.dat");
						if (dosyaYaz8.is_open()) {
							for (int i = 0; i < 30; i++) {
								dosyaYaz8 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

				}
				else if (index[(kitapId * 5) + kitapId + 1 + 2] == kitapNumarasii) {
					index[(kitapId * 5) + kitapId + 1 + 2] = "///";
					books[kitapId * 10 + 4] = "///";
					books[(kitapId * 10) + 5] = "///";
					cout << "Silmek istediginiz kitap silindi" << endl;
					if (dosya1.is_open()) {
						ofstream dosyaYaz9("index.dat");
						if (dosyaYaz9.is_open()) {
							dosyaYaz9 << "Raf Numarasi" << "   " << "B1" << " " << "B2" << " " << "B3" << " " << "B4" << " " << "B5" << endl;
							for (int i = 0; i < 10; i++) {
								dosyaYaz9 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
							for (int i = 10; i < 30; i++) {
								dosyaYaz9 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

					if (dosya2.is_open()) {
						ofstream dosyaYaz10("books.dat");
						if (dosyaYaz10.is_open()) {
							for (int i = 0; i < 30; i++) {
								dosyaYaz10 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

				}
				else if (index[(kitapId * 5) + kitapId + 1 + 3] == kitapNumarasii) {
					index[(kitapId * 5) + kitapId + 1 + 3] = "///";
					books[kitapId * 10 + 6] = "///";
					books[(kitapId * 10) + 7] = "///";
					cout << "Silmek istediginiz kitap silindi" << endl;
					if (dosya1.is_open()) {
						ofstream dosyaYaz11("index.dat");
						if (dosyaYaz11.is_open()) {
							dosyaYaz11 << "Raf Numarasi" << "   " << "B1" << " " << "B2" << " " << "B3" << " " << "B4" << " " << "B5" << endl;
							for (int i = 0; i < 10; i++) {
								dosyaYaz11 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
							for (int i = 10; i < 30; i++) {
								dosyaYaz << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

					if (dosya2.is_open()) {
						ofstream dosyaYaz12("books.dat");
						if (dosyaYaz12.is_open()) {
							for (int i = 0; i < 30; i++) {
								dosyaYaz12 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

				}
				else if (index[(kitapId * 5) + kitapId + 1 + 4] == kitapNumarasii) {
					index[(kitapId * 5) + kitapId + 1 + 4] = "///";
					books[kitapId * 10 + 8] = "///";
					books[(kitapId * 10) + 9] = "///";
					cout << "Silmek istediginiz kitap silindi" << endl;
					if (dosya1.is_open()) {
						ofstream dosyaYaz13("index.dat");
						if (dosyaYaz13.is_open()) {
							dosyaYaz << "Raf Numarasi" << "   " << "B1" << " " << "B2" << " " << "B3" << " " << "B4" << " " << "B5" << endl;
							for (int i = 0; i < 10; i++) {
								dosyaYaz13 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
							for (int i = 10; i < 30; i++) {
								dosyaYaz13 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

					if (dosya2.is_open()) {
						ofstream dosyaYaz14("books.dat");
						if (dosyaYaz14.is_open()) {
							for (int i = 0; i < 30; i++) {
								dosyaYaz14 << books[i * 10] << " " << books[i * 10 + 1] << "   " << books[i * 10 + 2] << " " << books[i * 10 + 3] << "   " << books[i * 10 + 4] << " " << books[i * 10 + 5] << "   " << books[i * 10 + 6] << " " << books[i * 10 + 7] << "   " << books[i * 10 + 8] << " " << books[i * 10 + 9] << endl;
							}
						}
						else {
							cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
						}
					}
					else {
						cout << "Dosya acilamadi!!" << endl;
					}

				}
				else {
					cout << "Silmek istediginiz kitap bulunamadi!!!" << endl;
				}
				break;

			case 2:
				if (dosya2.is_open()) {
					ifstream dosyaOkuma22("books.dat");
					for (int i = 0; i < 30; i++) {
						for (int j = (i * 5); j < (i * 5) + 5; j++) {
							dosyaOkuma22 >> okunanKayit;
							yazar[j] = okunanKayit;
							dosyaOkuma22 >> okunanKayit;
							kitap[j] = okunanKayit;
						}
					}
				}
				else {
					cout << "Books.dat dosyasi acilamadigi icin goruntuleme islemi basarisiz!!" << endl;
				}				
				cout << "Silmek istediginiz kitabin adini giriniz" << endl;
				cin >> girilenKitapAdi;

				for (int i = 0; i < 150; i++) {
					if (kitap[i] == girilenKitapAdi) {
						cout << kitap[i] << endl << yazar[i] << endl;
						kitap[i] = "///";
						yazar[i] = "///";
						int b = i / 5;
						int c = i - (5 * b);
						int a = (c + 1) / 2;
						cout << index[(b * 6) + (c + 1)] << endl;
						index[(b * 6) + (c + 1)] = "///";
						cout << index[(b * 6) + (c + 1)] << endl;
						cout << "Silmek istediginiz kitap silindi" << endl;
						if (dosya1.is_open()) {
							ofstream dosyaYaz13("index.dat");
							if (dosyaYaz13.is_open()) {
								dosyaYaz << "Raf Numarasi" << "   " << "B1" << " " << "B2" << " " << "B3" << " " << "B4" << " " << "B5" << endl;
								for (int i = 0; i < 10; i++) {
									dosyaYaz13 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
								}
								for (int i = 10; i < 30; i++) {
									dosyaYaz13 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
								}
							}
							else {
								cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}

						if (dosya2.is_open()) {
							ofstream dosyaYaz14("books.dat");
							if (dosyaYaz14.is_open()) {
								for (int i = 0; i < 30; i++) {
									dosyaYaz14 << yazar[i * 5] << " " << kitap[i * 5] << "   " << yazar[(i * 5) + 1] << " " << kitap[(i * 5) + 1] << "   " << yazar[(i * 5) + 2] << " " << kitap[(i * 5) + 2] << "   " << yazar[(i * 5) + 3] << " " << kitap[(i * 5) + 3] << "   " << yazar[(i * 5) + 4] << " " << kitap[(i * 5) + 4] << endl;
								}
							}
							else {
								cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}
					}
					else {
						sayac3++;
					}
				}
				if (sayac3 == 150) { cout << "Girilen kitap adinda kitaplikta kayit bulunmamaktadir!!" << endl; }
				break;

			case 3:
				if (dosya2.is_open()) {
					ifstream dosyaOkuma22("books.dat");
					for (int i = 0; i < 30; i++) {
						for (int j = (i * 5); j < (i * 5) + 5; j++) {
							dosyaOkuma22 >> okunanKayit;
							yazar[j] = okunanKayit;
							dosyaOkuma22 >> okunanKayit;
							kitap[j] = okunanKayit;
						}
					}
				}
				else {
					cout << "Books.dat dosyasi acilamadigi icin goruntuleme islemi basarisiz!!" << endl;
				}				
				cout << "Silmek istediginiz kitabin yazar adini giriniz" << endl;
				cin >> girilenYazarAdi;

				for (int i = 0; i < 150; i++) {
					if (yazar[i] == girilenYazarAdi) {
						cout << yazar[i] << endl << kitap[i] << endl;
						yazar[i] = "///";
						kitap[i] = "///";
						int b = i / 5;
						int c = (i + 1) - (5 * b);
						int a = (c + 1) / 2;
						index[(b * 6) + c] = "///";

						cout << "Silmek istediginiz kitap silindi" << endl;
						if (dosya1.is_open()) {
							ofstream dosyaYaz13("index.dat");
							if (dosyaYaz13.is_open()) {
								dosyaYaz << "Raf Numarasi" << "   " << "B1" << " " << "B2" << " " << "B3" << " " << "B4" << " " << "B5" << endl;
								for (int i = 0; i < 10; i++) {
									dosyaYaz13 << "       " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
								}
								for (int i = 10; i < 30; i++) {
									dosyaYaz13 << "      " << index[i * 6] << "      " << " " << index[i * 6 + 1] << "  " << index[i * 6 + 2] << "  " << index[i * 6 + 3] << "  " << index[i * 6 + 4] << "  " << index[i * 6 + 5] << endl;
								}
							}
							else {
								cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}

						if (dosya2.is_open()) {
							ofstream dosyaYaz14("books.dat");
							if (dosyaYaz14.is_open()) {
								for (int i = 0; i < 30; i++) {
									dosyaYaz14 << yazar[i * 5] << " " << kitap[i * 5] << "   " << yazar[(i * 5) + 1] << " " << kitap[(i * 5) + 1] << "   " << yazar[(i * 5) + 2] << " " << kitap[(i * 5) + 2] << "   " << yazar[(i * 5) + 3] << " " << kitap[(i * 5) + 3] << "   " << yazar[(i * 5) + 4] << " " << kitap[(i * 5) + 4] << endl;
								}
							}
							else {
								cout << "Silme islemi basari ile sonuclanamadi!!" << endl;
							}
						}
						else {
							cout << "Dosya acilamadi!!" << endl;
						}
					}
					else {
						sayac4++;
					}
				}
				if (sayac4 == 150) { cout << "Girilen yazar adinda kitaplikta kayit bulunmamaktadir!!" << endl; }
				break;

			default:
				cout << "Silme islemini yanlis gerceklestirdiniz" << endl;
				break;
			}


			cout << "Baska bir islem yapmak isterseniz yeni bir islem secenegi seciniz" << endl;
			cout << "Baska bir islem yapmak istemezseniz secenek besi seciniz" << endl;
			break;

		case 4:
			cout << "Kitaplari Goruntuleme" << endl;
			cout << "******************************************" << endl;
			cout << "Kitap Listemiz" << endl << endl;
			cout << "Raf Numarasi" << "   " << "B1" << "  " << "B2" << "  " << "B3" << "  " << "B4" << "  " << "B5" << endl;
			if (dosya2.is_open()) {
				ifstream dosyaOkuma2("books.dat");
				for (int i = 0; i < 30; i++) {
					cout << "       " << i << "      ";
					for (int j = 0; j < 5; j++) {
						dosyaOkuma2 >> okunanKayit;
						dosyaOkuma2 >> okunanKayit;
						cout << okunanKayit;
						cout << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "Books.dat dosyasi acilamadigi icin goruntuleme islemi basarisiz!!" << endl;
			}
			cout << "Baska bir islem yapmak isterseniz yeni bir islem secenegi seciniz" << endl;
			cout << "Baska bir islem yapmak istemezseniz secenek besi seciniz" << endl;
			break;
		case 5:
			cout << "Cikis" << endl;
			cout << "Sistemden cikis yaptiniz" << endl;
			return(0);
			break;
		default:
			cout << "Boyle bir islem tanimli degil!!" << endl;
			cout << "Tekrardan yapmak istediginiz islemi seciniz" << endl;
			break;
		}
	}
	dosyaYaz.close();
	dosyaYaz2.close();

	system("pause");
	return 0;
}