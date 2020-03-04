#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

void wyswietl(vector<char> wektor){
	for(int i=0; i<wektor.size(); i++){
		cout<<wektor.at(i)<<" ";
	}
}

void wyswietl_s(vector<string> wektor){
	for(int i=0; i<wektor.size(); i++){
		cout<<wektor.at(i)<<" ";
	}
}

/*void pobierz_z_pliku(vector<string> & tab, string nazwa){ //pobieranie danych z pliku txt
	string wyraz;
	fstream plik("zwierzeta.txt");
	while(plik>>wyraz){
		tab.push_back(wyraz);
	}
	plik.close();
}*/

void losuj_indeks(vector<string> tab, int & indeks){ //losowanie indeksu
	srand(time(0));
	indeks = rand()%(tab.size());
}

int main(){
	
	string wyraz, podpowiedz, nazwa;
	int dlugosc, indeks, wybor, wybor2;
	char el, el2, litera, czy;
	vector<string> tab;
	vector<char> wyraaz;
	vector<char> pomocniczy;
	int szansa = 0, zgadnieta = 0, proba = 0;
	
	cout<<"Witaj w grze wisielec."<<endl;
	cout<<"Wybierz tryb gry:"<<endl;
	cout<<"1 - gracz vs gracz."<<endl;
	cout<<"2 - gracz vs komputer."<<endl;
	cin>>wybor;
	cout<<endl;
	
	system("cls");
	
	if(wybor == 1){
		cout<<"Jako gracz pierwszy musisz podac wyraz ktory twoj przeciwnik musi odgadnac."<<endl;
		cout<<"PAMIETAJ BEZ POLSKICH ZNAKOW I DUZYCH LITER!"<<endl;
		cout<<"Podaj wyraz."<<endl;
		cin>>wyraz;
		cout<<"Podaj kategorie."<<endl;
		cin>>podpowiedz;
		
		dlugosc = wyraz.length();
		
		for(int i=0; i<dlugosc; i++){
			el=wyraz.at(i);
			wyraaz.push_back(el);
		}
		
		for(int i =0; i<dlugosc; i++){
			el2= '_';
			pomocniczy.push_back(el2);
		}
		
		Sleep(3000);
		system("cls");
		
		cout<<"Jako gracz drugi musisz zgadnac wyraz podany przez twojego przeciwnika."<<endl;
		cout<<"Kategoria wyrazu to: "<<podpowiedz<<endl;
		cout<<"Wyraz sklada sie z "<<dlugosc<<" liter."<<endl;
		wyswietl(pomocniczy);
		cout<<endl;
		
		do {
			cout<<"Podaj litere."<<endl;
			cin>>litera;
			proba++;
			for(int i=0; i<=dlugosc; i++){
				if(litera == wyraaz[i]){
					cout<<"Litera "<<litera<<" jest w danym wyrazie na "<<i+1<<" miejscu."<<endl;
					swap(pomocniczy[i], wyraaz[i]);
					wyswietl(pomocniczy);
					cout<<endl;
					zgadnieta++;
					cout<<"Ilosc zgadnietych: "<<zgadnieta;
					cout<<endl<<endl;
				}
					
				int pozycja = wyraz.find(litera);
				if(pozycja == string::npos){
					cout<<"BLEDNA LITERA!"<<endl;
					szansa++;
					cout<<"Pozostala liczba szans: "<<(10-szansa)<<endl;
					if(szansa==10){
						cout<<"--------------------------"<<endl<<endl;
						cout<<"PRZEGRALES! :C"<<endl;
						exit(0);
					}
					break;
					}
				}
			} while(zgadnieta != dlugosc);
			
		cout<<"----------------------------------"<<endl;
		cout<<"BRAWO WYGRALES!"<<endl;
		cout<<"Slowo ktore zgadles to: "<<wyraz<<"."<<endl;
		cout<<"Liczba prob: "<<proba<<endl;
		cout<<"Pozostala liczba szans: "<<10-szansa<<endl;
	} else if (wybor == 2){
		cout<<"Grasz z komputerem. Wybierz kategorie z jakiej chcesz otrzymac wyraz."<<endl;
		cout<<"1- Zwierzeta, 2- Kraje, 3- Imiona, 4- Rzeczy, 5-Sport"<<endl;
		cin>>wybor2;
		while(wybor2>5){
			cout<<"Podaj prawidlowa liczbe!"<<endl;
			cin>>wybor2;
		}
		string wy;
		
		switch(wybor2){
			case 1:{
				fstream plik("zwierzeta.txt");
				while(plik>>wyraz){
					tab.push_back(wy);
				}
				plik.close();
				break;
			}
			case 2:{
				fstream plik("kraje.txt");
				while(plik>>wyraz){
					tab.push_back(wy);
				}
				plik.close();
				break;
			}
			case 3:{
				fstream plik("imiona.txt");
				while(plik>>wyraz){
					tab.push_back(wy);
				}
				plik.close();
				break;
			}
			case 4:{
				fstream plik("rzeczy.txt");
				while(plik>>wyraz){
					tab.push_back(wy);
				}
				plik.close();
				break;
			}
			case 5:{
				fstream plik("sport.txt");
				while(plik>>wyraz){
					tab.push_back(wy);
				}
				plik.close();
				break;
			}	
		}
		
		losuj_indeks(tab, indeks);
		cout<<endl;
		tab.at(indeks) = wyraz;
		
		dlugosc = wyraz.length();
		
		for(int i=0; i<dlugosc; i++){
			el=wyraz.at(i);
			wyraaz.push_back(el);
		}
		
		for(int i =0; i<dlugosc; i++){
			el2= '_';
			pomocniczy.push_back(el2);
		}
		
		Sleep(3000);
		system("cls");
		
		cout<<"Wyraz zostal wylosowany, teraz musisz go zgadnac."<<endl;
		cout<<"Wyraz sklada sie z "<<dlugosc<<" liter."<<endl;
		wyswietl(pomocniczy);
		cout<<endl;
		
		do {
			cout<<"Podaj litere."<<endl;
			cin>>litera;
			proba++;
			for(int i=0; i<=dlugosc; i++){
				if(litera == wyraaz[i]){
					cout<<"Litera "<<litera<<" jest w danym wyrazie na "<<i+1<<" miejscu."<<endl;
					swap(pomocniczy[i], wyraaz[i]);
					wyswietl(pomocniczy);
					cout<<endl;
					zgadnieta++;
					cout<<"Ilosc zgadnietych: "<<zgadnieta;
					cout<<endl<<endl;
				}
					
				int pozycja = wyraz.find(litera);
				if(pozycja == string::npos){
					cout<<"BLEDNA LITERA!"<<endl;
					szansa++;
					cout<<"Pozostala liczba szans: "<<(10-szansa)<<endl;
					if(szansa==10){
						cout<<"--------------------------"<<endl<<endl;
						cout<<"PRZEGRALES! :C"<<endl;
						exit(0);
					}
					break;
					}
				}
			} while(zgadnieta != dlugosc);
			
		cout<<"----------------------------------"<<endl;
		cout<<"BRAWO WYGRALES Z KOMPUTEREM!"<<endl;
		cout<<"Slowo ktore zgadles to: "<<wyraz<<"."<<endl;
		cout<<"Liczba prob: "<<proba<<endl;
		cout<<"Pozostala liczba szans: "<<10-szansa<<endl;
	} else cout<<"Bledna liczba!!!"<<endl;
}
