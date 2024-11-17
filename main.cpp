#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <limits>
using namespace std;

#define inf 999
int indexTerkecil = 0;
int jumlahSimpul = 5;
int jarakSimpul[5] = {};

//Graf Latihan 9
string simpulGraf[5] = {"Grand Rapids", "Saginaw", "Detroit", "Tuledo", "Kalamazo"};
int graf[5][5] = {
			{0, 1, 1, 1, 1},
			{1, 0, 1, 1, 1},
			{1, 1, 0, 1, 1},
			{1, 1, 1, 0, 1},
			{1, 1, 1, 1, 0}};
vector<vector<int>> bobotGraf = {
		{0, 113, 147, 167, 56},
		{113, 0, 98, 142, 137},
		{147, 98, 0, 58, 135},
		{167, 142, 58, 0, 133},
		{56, 137, 135, 133, 0}};
vector<int> lintasan = {};

void resetGraf(){
    bobotGraf.resize(jumlahSimpul);
    for(int i = 0; i < jumlahSimpul; i++){
        bobotGraf[i].resize(jumlahSimpul);
    }
    for(int i = 0; i < jumlahSimpul; i++){
        for(int j = 0; j < jumlahSimpul; j++){
            bobotGraf[i][j] = inf;
        }
    }
}

void bikinGraf(){
    cout << "Masukkan jumlah simpul: ";
    while(!(cin >> jumlahSimpul)){
        cout << "Input salah!" << endl;
        cout << "Masukkan jumlah simpul: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    resetGraf();
        system("cls");
        for(int i = 0; i < jumlahSimpul; i++){
            for(int j = 0; j < jumlahSimpul; j++){
            cout << "Masukkan bobot sisi atau asal jika tidak bertetangga!" << endl;
            for(int k = 0; k < jumlahSimpul; k++){
                cout << "|";
                for(int l = 0; l < jumlahSimpul; l++){
                    if(l == j && k == i){
                        cout << " _ ";
                    }else if(bobotGraf[k][l] == inf){
                        cout << " inf ";
                    }else{
                        cout << " " << bobotGraf[k][l] << " ";
                    }
                }
                cout << "|" << endl;
            }
            cout << "Masukkan bobot: ";
            if(!(cin >> bobotGraf[i][j])){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                bobotGraf[i][j] = inf;
            }
            system("cls");
            }
        }
}

void dijkstra(){
    for(int i = 0; i < jumlahSimpul; i++){
        jarakSimpul[i] = inf;
	}

	for(int i = 0; i < jumlahSimpul; i++){
		for(int j = 0; j < jumlahSimpul; j++){
                jarakSimpul[j] = bobotGraf[indexTerkecil][j];
		}
		for(int j = 0; j < jumlahSimpul; j++){
            if(jarakSimpul[j] < jarakSimpul[indexTerkecil]){
				indexTerkecil = j;
			}
		}
		lintasan.push_back(indexTerkecil);
	}
}

int main()
{
	int menu;
	cout << "Dijkstrakinator!" << endl;
    cout << "1 = graf default, 2 = bikin sendiri, 3 = exit: ";
    while(!(cin >> menu)){
        cout << "Input salah!" << endl;
        cout << "1 = graf default, 2 = bikin sendiri, 3 = exit: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(menu == 1){
        cout << "ok" << endl;
    }else if(menu == 2){
        bikinGraf();
    }else{
        return 0;
    }

    dijkstra();

	for(int i = 0; i < jumlahSimpul; i++){
		cout << lintasan[i] << " ";
	}

	return 0;
}
