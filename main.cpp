#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct gra
{
	string gracz1;
	string gracz2;
	char zawartosc_planszy[6][6];
	int licznik;
	char czesc_planszy;
	char zeton1;
	char zeton2;
	int puste_miejsce;
	int punkt_gracz1;
	int punkt_gracz2;
	bool koniec;
	bool pentago;
};

void inicjacja(gra tab[]);
void rysowanie_planszy(gra tab[]);
void pentago(gra tab[]);
void pisz_menu(gra tab[]);
void help(gra tab[]);
void pauza(gra tab[]);
void wstawianie(gra tab[]);
void warunek_wygranej(gra tab[]);
void wpisywanie_imion(gra tab[]);
void komunikat(gra tab[]);
void wczyt_plansz(gra tab[]);
void opcje(gra tab[]);
void wybor_zetonow(gra tab[]);
void zapis_planszy(gra tab[]);
void undo(gra tab[]);
void historia_gry(gra tab[]);
void obrot(gra tab[]);
void kolko_i_krzyzyk(gra tab[]);

int main()
{
	gra tab[37];
	pisz_menu(tab);
}


void rysowanie_planszy(gra tab[])
{
	const char lgr = (char)201;							//Lewy, górny róg
	const char poz = (char)205;							//Poziom
	const char pzd = (char)203;							//Z poziomu w dół
	const char pgr = (char)187;							//Prawy, górny róg
	const char pip = (char)204;							//Z pionu w prawo
	const char krz = (char)206;							//Krzyż
	const char pil = (char)185;							//Z pionu w lewo
	const char pon = (char)186;							//Pion
	const char ldr = (char)200;							//Lewy, dolny róg
	const char pzg = (char)202;							//Z poziomu w górę
	const char pdr = (char)188;							//Prawy dolny róg

	for (int d = 0; d < 4; d = d + 3)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << lgr << poz << poz << poz << pzd << poz << poz << poz
				<< pzd << poz << poz << poz << pgr;
			if (i == 0) cout << char(186);
		}
		if (d == 0)																		//Dodanie napisów informacyjnych obok planszy - tura gracza
		{
			cout << "       Teraz ruch gracza: ";
			if (tab[0].licznik % 2 == 0) cout << tab[0].gracz1;
			else cout << tab[0].gracz2;

		}
		if (d == 3 && tab[2].pentago == false)																		//Dodanie napisów informacyjnych obok planszy - undo
		{
			cout << "       u - undo (cofniecie ruchu): ";

		}
		cout << endl;
		for (int i = 0; i < 4; i = i + 3)
		{
			cout << pon << " " << tab[0].zawartosc_planszy[d][i] << " " << pon << " " << tab[0].zawartosc_planszy[d][i + 1]
				<< " " << pon << " " << tab[0].zawartosc_planszy[d][i + 2] << " " << pon;
			if (i == 0) cout << char(186);
		}
		if (d == 0)																		//Dodanie napisów informacyjnych obok planszy - żeton gracza
		{
			cout << "       Zeton gracza: ";
			if (tab[0].licznik % 2 == 0) cout << tab[0].zeton1;
			else cout << tab[0].zeton2;
		}
		cout << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << pip << poz << poz << poz << krz << poz << poz << poz
				<< krz << poz << poz << poz << pil;
			if (i == 0) cout << char(186);
		}
		cout << endl;
		for (int i = 0; i < 4; i = i + 3)
		{
			cout << pon << " " << tab[0].zawartosc_planszy[d + 1][i] << " " << pon << " " << tab[0].zawartosc_planszy[d + 1][i + 1]
				<< " " << pon << " " << tab[0].zawartosc_planszy[d + 1][i + 2] << " " << pon;
			if (i == 0) cout << char(186);
		}
		if (d == 0)																		//Dodanie napisów informacyjnych obok planszy - informacje1
		{
			cout << "       Nacisnij :";
		}
		cout << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << pip << poz << poz << poz << krz << poz << poz << poz << krz
				<< poz << poz << poz << pil;
			if (i == 0) cout << char(186);
		}
		if (d == 0 && tab[2].pentago == false)													//Dodanie napisów informacyjnych obok planszy - wczytanie predefiniowanej planszy
		{
			cout << "       o - wczytanie domyslnej planszy";
		}
		if (d == 0 && tab[2].pentago == true)
		{
			cout << "       s - wczytanie nastepnej planszy";
		}
		cout << endl;
		for (int i = 0; i < 4; i = i + 3)
		{
			cout << pon << " " << tab[0].zawartosc_planszy[d + 2][i] << " " << pon << " " << tab[0].zawartosc_planszy[d + 2][i + 1]
				<< " " << pon << " " << tab[0].zawartosc_planszy[d + 2][i + 2] << " " << pon;
			if (i == 0) cout << char(186);
		}
		if (d == 0 && tab[2].pentago == false)																		//Dodanie napisów informacyjnych obok planszy - help
		{
			cout << "       h - pomoc";
		}
		if (d == 0 && tab[2].pentago == true)
		{
			cout << "       a - wczytanie poprzedniej planszy";
		}
		cout << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << ldr << poz << poz << poz << pzg << poz << poz << poz << pzg
				<< poz << poz << poz << pdr;
			if (i == 0) cout << char(186);

		}
		if (d == 0 && tab[2].pentago == false)																//Dodanie napisów informacyjnych obok planszy - pauza
		{
			cout << "       p - pauza             "  << endl;
			for (int r = 0; r < 13; r++) cout << poz;
			cout << krz;
			for (int r = 0; r < 13; r++) cout << poz;
			cout << "       m - opcje";
		}
		if (d == 0 && tab[2].pentago == true)
		{
			cout << "       e - wyjscie             " << endl;
			for (int r = 0; r < 13; r++) cout << poz;
			cout << krz;
			for (int r = 0; r < 13; r++) cout << poz;
		}
		cout << endl;
	}
}

void inicjacja(gra tab[])
{
	for (int k = 0; k < 6; k++)
	{
		for (int w = 0; w < 6; w++)
			tab[0].zawartosc_planszy[w][k] = ' ';
	}
	for (int k = 0; k < 6; k++)
	{
		for (int w = 0; w < 6; w++)
			tab[36].zawartosc_planszy[w][k] = ' ';
	}
	tab[0].gracz1 = "gracz1";
	tab[0].gracz2 = "gracz2";
	tab[0].licznik = 0;
	tab[0].puste_miejsce = 1;
	tab[0].zeton1 = 'X';
	tab[0].zeton2 = 'O';
	tab[0].koniec = false;
	tab[0].punkt_gracz1 = 0;
	tab[0].punkt_gracz2 = 0;
	tab[0].pentago = 1;		//Pomijanie czynności wynikających z gry - obracanie i zapis
	tab[1].pentago = 1;		//Pomijanie czynności wynikających z gry - wstawianie i zapis
	tab[2].pentago = false; //Przegląd (wyświetlanie na planszy)
}

void pentago(gra tab[])
{
	inicjacja(tab);
	wpisywanie_imion(tab);
	wybor_zetonow(tab);
	for (int k = 0; tab[0].koniec == false; k++)
	{
		system("cls");
		if (tab[1].pentago == 1)
		{
			rysowanie_planszy(tab);
			wstawianie(tab);
			cin.clear();
			cin.ignore(1000, '\n');
		}
		system("cls");
		if (tab[0].pentago == 1)
		{
			rysowanie_planszy(tab);
			obrot(tab);
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (tab[1].pentago == 1 && tab[0].pentago == 1)
			zapis_planszy(tab);
		warunek_wygranej(tab);
		tab[0].licznik++;
	}
	komunikat(tab);
}

void pisz_menu(gra tab[])
{
	int wybor;
	for (;;)
	{
		system("cls");
		cout << "MENU" << endl;
		for (int i = 0; i < 20; i++) cout << (char)196;
		cout << endl << "1. Pentago" << endl << "2. Kolko i krzyzyk" << endl << "3. Pomoc" << endl << "4. Wyjscie" << endl;
		for (int i = 0; i < 20; i++) cout << (char)196;
		cout << endl << endl;
		cin >> wybor;
		cin.clear();
		cin.ignore(1000, '\n');
		switch (wybor)
		{
		case 1:
			pentago(tab);
			break;
		case 2:
			kolko_i_krzyzyk(tab);
			break;
		case 3:
			help(tab);
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Nie ma takiej opcji - wcisnij 'enter', aby wybrac ponownie" << endl;
			getchar();
			pisz_menu(tab);
		}
	}
}

void help(gra tab[])
{
	system("cls");
	cout << "ZASADY I OBSLUGA - kolko i krzyzyk/pentago" << endl;
	for (int i = 0; i < 40; i++) cout << (char)196;
	cout << endl 
		<< "1. q,w,a,s - wybor czesci planszy odpowiednio: lewej gornej," << endl 
		<< "   prawej gornej, lewej dolnej, prawej dolnej" << endl
		<< "2. 1..9 - wybor pola na czesci planszy jak na klawiaturze numerycznej" << endl 
		<< "   tj. 1 to dolne lewe pole" << endl
		<< "3. z, x - obrot odpowiednio: zgodnie z ruchem wskazowek zegara, odwrotnie do" << endl 
		<< "   ruchu wskazowek" << endl
		<< "3. Reszta opcji widoczna jest w trakcie gry, kolo planszy" << endl
		<< "4. Ruch to najpierw wyobr czesci planszy i pola (np. q5), a nastepnie wybor" << endl 
		<< "   czesci planszy i obrotu (np.az)" << endl
		<< "5. Aby wygrac gre nalezy na koncu swojego ruchu miec ustawione co najmniej" << endl 
		<< "5 zetonow w rzedzie (poziomo, pionowo lub na skos)" << endl
		<< "6. Ruch danego gracza sklada sie z dwoch czesci - wyboru pola polozenia" << endl 
		<< "   zetonu i wyboru czesci planszy oraz kierunku obrotu(ruch w" << endl
		<< "   kolku i krzyzyk sklada sie tylko z pierwszej czesci)" << endl
		<< "7. Wszystkie opcje wymienione obok planszy sa dostepne na poczatku ruchu," << endl 
		<< "   natomiast funkcja 'undo', 'opcje' (w ktorych mozna zmienic nazwy graczy" << endl 
		<< "   oraz zetony) oraz 'pauza' dostepne sa caly czas" << endl;
		for (int i = 0; i < 40; i++) cout << (char)196;
		cout << endl << "Wcisnij 'enter', aby kontynuowac..." << endl;
	tab[0].licznik--;
	getchar();
}

void wstawianie(gra tab[])
{
	int pole;
	char czesc_planszy;
	cout << "Wybierz pole, na ktorym chcesz postawic zeton:" << endl;
	cin >> czesc_planszy;
	int zmienna_y = 0;										//Zmienne pozawalające na sprowadzenie wyboru miejsca na planszy do krótkich funkcji
	int zmienna_x = 0;										//Y - wiersze ; X - kolumny
	int wiersz = 0;
	int kolumna = 0;
	switch (czesc_planszy)									//Funkcja switch manipulując zmiennymi pozwala ustalić położenie na planszy 
	{														//lub użycie innych opcji

	case 'q':												//Wybrano pierwszą część planszy
		zmienna_y = 0;
		zmienna_x = 0;
		tab[0].pentago = 1;
		break;
	case 'w':												//Wybrano drugą część planszy
		zmienna_y = 0;
		zmienna_x = 3;
		tab[0].pentago = 1;
		break;
	case 'a':												//Wybrano trzecią część planszy
		zmienna_y = 3;
		zmienna_x = 0;
		tab[0].pentago = 1;
		break;
	case 's':												//Wybrano czwartą część planszy
		zmienna_y = 3;
		zmienna_x = 3;
		tab[0].pentago = 1;
		break;
	case 'h':												//Pomoc - (help)
		help(tab);
		tab[0].pentago = 0;
		break;
	case 'p':												//Pauza
		pauza(tab);
		tab[0].pentago = 0;
		break;
	case 'o':												//Wczytanie predefiniowanej planszy
		wczyt_plansz(tab);
		tab[0].pentago = 0;
		break;
	case 'm':												//Menu opcji
		opcje(tab);
		tab[0].pentago = 0;
		break;
	case 'u':												//Menu opcji
		undo(tab);
		tab[0].pentago = 0;
		break;

	default:
		tab[0].licznik--;
		tab[0].pentago = 0;
	}

	if (czesc_planszy == 'q' || czesc_planszy == 'w' || czesc_planszy == 's' || czesc_planszy == 'a')
	{
		cin >> pole;
		switch (pole)
		{
		case 1:
			wiersz = 2;
			kolumna = 0;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				cout << "To pole jest zajete - wcisnij 'enter', aby wybrac ponownie" << endl;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		case 2:
			wiersz = 2;
			kolumna = 1;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				cout << "To pole jest zajete - wcisnij 'enter', aby wybrac ponownie" << endl;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		case 3:
			wiersz = 2;
			kolumna = 2;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				cout << "To pole jest zajete - wcisnij 'enter', aby wybrac ponownie" << endl;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		case 4:
			wiersz = 1;
			kolumna = 0;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				cout << "To pole jest zajete - wcisnij 'enter', aby wybrac ponownie" << endl;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		case 5:
			wiersz = 1;
			kolumna = 1;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				cout << "To pole jest zajete - wcisnij 'enter', aby wybrac ponownie" << endl;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		case 6:
			wiersz = 1;
			kolumna = 2;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				cout << "To pole jest zajete - wcisnij 'enter', aby wybrac ponownie" << endl;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		case 7:
			wiersz = 0;
			kolumna = 0;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				cout << "To pole jest zajete - wcisnij 'enter', aby wybrac ponownie" << endl;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		case 8:
			wiersz = 0;
			kolumna = 1;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				cout << "To pole jest zajete - wcisnij 'enter', aby wybrac ponownie" << endl;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		case 9:
			wiersz = 0;
			kolumna = 2;
			tab[0].pentago = 1;
			if (tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] == ' ')
			{
				if (tab[0].licznik % 2 == 0) tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton1;
				else tab[0].zawartosc_planszy[wiersz + zmienna_y][kolumna + zmienna_x] = tab[0].zeton2;
			}
			else
			{
				tab[0].licznik--;
				tab[0].pentago = 0;
				getchar();
			}
			break;
		default:
			tab[0].licznik--;
			tab[0].pentago = 0;
			getchar();
		}
	}

}

void warunek_wygranej(gra tab[])
{
	//Warunek wygranej z pętlą dla gracza nr 1
	for (int g = 0; g < 6; g++)
	{
		if
			((tab[0].zawartosc_planszy[g][4] == tab[0].zawartosc_planszy[g][3] && tab[0].zawartosc_planszy[g][3] == tab[0].zawartosc_planszy[g][2] &&	//Sprawdzanie wierszy
				tab[0].zawartosc_planszy[g][2] == tab[0].zawartosc_planszy[g][1] && tab[0].zawartosc_planszy[g][3] == tab[0].zeton1 &&
				(tab[0].zawartosc_planszy[g][0] == tab[0].zawartosc_planszy[g][4] || tab[0].zawartosc_planszy[g][5] == tab[0].zawartosc_planszy[g][4]))
				||
				(tab[0].zawartosc_planszy[4][g] == tab[0].zawartosc_planszy[3][g] && tab[0].zawartosc_planszy[3][g] == tab[0].zawartosc_planszy[2][g] &&	//Sprawdzanie kolumn
					tab[0].zawartosc_planszy[2][g] == tab[0].zawartosc_planszy[1][g] && tab[0].zawartosc_planszy[3][g] == tab[0].zeton1 &&
					(tab[0].zawartosc_planszy[0][g] == tab[0].zawartosc_planszy[4][g] || tab[0].zawartosc_planszy[5][g] == tab[0].zawartosc_planszy[4][g])))
		{
			tab[0].punkt_gracz1++;
		}
	}

	if
		(
			((tab[0].zawartosc_planszy[1][1] == tab[0].zawartosc_planszy[2][2] && tab[0].zawartosc_planszy[2][2] == tab[0].zawartosc_planszy[3][3] &&	//Sprawdzanie lewego skosu 5+1
				tab[0].zawartosc_planszy[3][3] == tab[0].zawartosc_planszy[4][4] && tab[0].zawartosc_planszy[3][3] == tab[0].zeton1 &&
				(tab[0].zawartosc_planszy[0][0] == tab[0].zawartosc_planszy[4][4] || tab[0].zawartosc_planszy[5][5] == tab[0].zawartosc_planszy[4][4]))
				||
				(tab[0].zawartosc_planszy[4][1] == tab[0].zawartosc_planszy[3][2] && tab[0].zawartosc_planszy[3][2] == tab[0].zawartosc_planszy[2][3] &&	//Sprawdzanie prawego skosu 5+1
					tab[0].zawartosc_planszy[2][3] == tab[0].zawartosc_planszy[1][4] && tab[0].zawartosc_planszy[3][2] == tab[0].zeton1 &&
					(tab[0].zawartosc_planszy[0][5] == tab[0].zawartosc_planszy[4][1] || tab[0].zawartosc_planszy[5][0] == tab[0].zawartosc_planszy[4][1]))
				||
				(tab[0].zawartosc_planszy[0][1] == tab[0].zawartosc_planszy[1][2] && tab[0].zawartosc_planszy[1][2] == tab[0].zawartosc_planszy[2][3] &&	//Sprawdzanie lewego skosu 5 (górnego)
					tab[0].zawartosc_planszy[2][3] == tab[0].zawartosc_planszy[3][4] && tab[0].zawartosc_planszy[3][4] == tab[0].zawartosc_planszy[4][5] &&
					tab[0].zawartosc_planszy[2][3] == tab[0].zeton1)
				||
				(tab[0].zawartosc_planszy[1][0] == tab[0].zawartosc_planszy[2][1] && tab[0].zawartosc_planszy[2][1] == tab[0].zawartosc_planszy[3][2] &&	//Sprawdzanie lewego skosu 5 (dolnego)
					tab[0].zawartosc_planszy[3][2] == tab[0].zawartosc_planszy[4][3] && tab[0].zawartosc_planszy[4][3] == tab[0].zawartosc_planszy[5][4] &&
					tab[0].zawartosc_planszy[3][2] == tab[0].zeton1)
				||
				(tab[0].zawartosc_planszy[5][1] == tab[0].zawartosc_planszy[4][2] && tab[0].zawartosc_planszy[4][2] == tab[0].zawartosc_planszy[3][3] &&	//Sprawdzanie prawego skosu 5 (dolnego)
					tab[0].zawartosc_planszy[3][3] == tab[0].zawartosc_planszy[2][4] && tab[0].zawartosc_planszy[2][4] == tab[0].zawartosc_planszy[1][5] &&
					tab[0].zawartosc_planszy[3][3] == tab[0].zeton1)
				||
				(tab[0].zawartosc_planszy[0][4] == tab[0].zawartosc_planszy[1][3] && tab[0].zawartosc_planszy[1][3] == tab[0].zawartosc_planszy[2][2] &&	//Sprawdzenie prawego skosu 5 (górnego)
					tab[0].zawartosc_planszy[2][2] == tab[0].zawartosc_planszy[3][1] && tab[0].zawartosc_planszy[3][1] == tab[0].zawartosc_planszy[4][0] &&
					tab[0].zawartosc_planszy[2][2] == tab[0].zeton1))
			)
	{
		tab[0].punkt_gracz1++;
	}

	//Warunek wygranej z pętlą dla gracza nr 2

	for (int g = 0; g < 6; g++)
	{
		if
			((tab[0].zawartosc_planszy[g][4] == tab[0].zawartosc_planszy[g][3] && tab[0].zawartosc_planszy[g][3] == tab[0].zawartosc_planszy[g][2] &&	//Sprawdzanie wierszy
				tab[0].zawartosc_planszy[g][2] == tab[0].zawartosc_planszy[g][1] && tab[0].zawartosc_planszy[g][3] == tab[0].zeton2 &&
				(tab[0].zawartosc_planszy[g][0] == tab[0].zawartosc_planszy[g][4] || tab[0].zawartosc_planszy[g][5] == tab[0].zawartosc_planszy[g][4]))
				||
				(tab[0].zawartosc_planszy[4][g] == tab[0].zawartosc_planszy[3][g] && tab[0].zawartosc_planszy[3][g] == tab[0].zawartosc_planszy[2][g] &&	//Sprawdzanie kolumn
					tab[0].zawartosc_planszy[2][g] == tab[0].zawartosc_planszy[1][g] && tab[0].zawartosc_planszy[3][g] == tab[0].zeton2 &&
					(tab[0].zawartosc_planszy[0][g] == tab[0].zawartosc_planszy[4][g] || tab[0].zawartosc_planszy[5][g] == tab[0].zawartosc_planszy[4][g])))
		{
			tab[0].punkt_gracz2++;
		}
	}

	if
		(
			((tab[0].zawartosc_planszy[1][1] == tab[0].zawartosc_planszy[2][2] && tab[0].zawartosc_planszy[2][2] == tab[0].zawartosc_planszy[3][3] &&	//Sprawdzanie lewego skosu 5+1
				tab[0].zawartosc_planszy[3][3] == tab[0].zawartosc_planszy[4][4] && tab[0].zawartosc_planszy[3][3] == tab[0].zeton2 &&
				(tab[0].zawartosc_planszy[0][0] == tab[0].zawartosc_planszy[4][4] || tab[0].zawartosc_planszy[5][5] == tab[0].zawartosc_planszy[4][4]))
				||
				(tab[0].zawartosc_planszy[4][1] == tab[0].zawartosc_planszy[3][2] && tab[0].zawartosc_planszy[3][2] == tab[0].zawartosc_planszy[2][3] &&	//Sprawdzanie prawego skosu 5+1
					tab[0].zawartosc_planszy[2][3] == tab[0].zawartosc_planszy[1][4] && tab[0].zawartosc_planszy[3][2] == tab[0].zeton2 &&
					(tab[0].zawartosc_planszy[0][5] == tab[0].zawartosc_planszy[4][1] || tab[0].zawartosc_planszy[5][0] == tab[0].zawartosc_planszy[4][1]))
				||
				(tab[0].zawartosc_planszy[0][1] == tab[0].zawartosc_planszy[1][2] && tab[0].zawartosc_planszy[1][2] == tab[0].zawartosc_planszy[2][3] &&	//Sprawdzanie lewego skosu 5 (górnego)
					tab[0].zawartosc_planszy[2][3] == tab[0].zawartosc_planszy[3][4] && tab[0].zawartosc_planszy[3][4] == tab[0].zawartosc_planszy[4][5] &&
					tab[0].zawartosc_planszy[2][3] == tab[0].zeton2)
				||
				(tab[0].zawartosc_planszy[1][0] == tab[0].zawartosc_planszy[2][1] && tab[0].zawartosc_planszy[2][1] == tab[0].zawartosc_planszy[3][2] &&	//Sprawdzanie lewego skosu 5 (dolnego)
					tab[0].zawartosc_planszy[3][2] == tab[0].zawartosc_planszy[4][3] && tab[0].zawartosc_planszy[4][3] == tab[0].zawartosc_planszy[5][4] &&
					tab[0].zawartosc_planszy[3][2] == tab[0].zeton2)
				||
				(tab[0].zawartosc_planszy[5][1] == tab[0].zawartosc_planszy[4][2] && tab[0].zawartosc_planszy[4][2] == tab[0].zawartosc_planszy[3][3] &&	//Sprawdzanie prawego skosu 5 (dolnego)
					tab[0].zawartosc_planszy[3][3] == tab[0].zawartosc_planszy[2][4] && tab[0].zawartosc_planszy[2][4] == tab[0].zawartosc_planszy[1][5] &&
					tab[0].zawartosc_planszy[3][3] == tab[0].zeton2)
				||
				(tab[0].zawartosc_planszy[0][4] == tab[0].zawartosc_planszy[1][3] && tab[0].zawartosc_planszy[1][3] == tab[0].zawartosc_planszy[2][2] &&	//Sprawdzenie prawego skosu 5 (górnego)
					tab[0].zawartosc_planszy[2][2] == tab[0].zawartosc_planszy[3][1] && tab[0].zawartosc_planszy[3][1] == tab[0].zawartosc_planszy[4][0] &&
					tab[0].zawartosc_planszy[2][2] == tab[0].zeton2))
			)
	{
		tab[0].punkt_gracz2++;
	}
	tab[0].puste_miejsce = 0;
	for (int k = 0; k < 6; k++)
	{
		for (int w = 0; w < 6; w++)
		{
			if (tab[0].zawartosc_planszy[k][w] == ' ')
				tab[0].puste_miejsce++;
		}
	}
	if (tab[0].punkt_gracz1 > 0 || tab[0].punkt_gracz2 > 0 || tab[0].puste_miejsce == 0)
	{
		tab[0].koniec = true;
	}
}

void pauza(gra tab[])
{
	system("cls");
	cout << "PAUZA" << endl;
	for (int l = 0; l < 45; l++)
		cout << char(196);
	cout << endl << "Nacisnij 'enter', aby kontynuowac..." << endl;
	tab[0].licznik--;
	getchar();
}

void wpisywanie_imion(gra tab[])
{
	system("cls");
	cout << "Wpisz nazwe gracza nr 1 (max. 20 znakow): " << endl;
	cin >> tab[0].gracz1;
	cin.clear();
	cin.ignore(1000, '\n');
	if (tab[0].gracz1.size() > 20)
	{
		for (; tab[0].gracz1.size() > 20;)
		{
			cout << "Nieprawidlowa nazwa - sprobuj ponownie..." << endl;
			cin >> tab[0].gracz1;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	cout << "Wpisz nazwe gracza nr 2 (max. 20 znakow): " << endl;
	cin >> tab[0].gracz2;
	cin.clear();
	cin.ignore(1000, '\n');
	if (tab[0].gracz2.size() > 20)
	{
		for (; tab[0].gracz2.size() > 20;)
		{
			cout << "Nieprawidlowa nazwa - sprobuj ponownie..." << endl;
			cin >> tab[0].gracz2;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void komunikat(gra tab[])
{
	char wybor;
	system("cls");
	rysowanie_planszy(tab);
	cout << "Koniec gry";
	if (tab[0].punkt_gracz1 > tab[0].punkt_gracz2)
		cout << endl << endl << "Gre wygral: " << tab[0].gracz1 << endl;

	if (tab[0].punkt_gracz2 > tab[0].punkt_gracz1)
		cout << endl << endl << "Gre wygral: " << tab[0].gracz2 << endl;

	if (tab[0].punkt_gracz2 > 0 && tab[0].punkt_gracz1 > 0 && tab[0].punkt_gracz2 == tab[0].punkt_gracz2)
		cout << endl << endl << "REMIS!!!" << endl;

	if (tab[0].punkt_gracz1 == 0 && tab[0].punkt_gracz2 == 0 && tab[0].puste_miejsce == 0)
		cout << endl << endl << "Nikt nie wygral - zabraklo wolnych miejsc na planszy --> REMIS" << endl;

	cout << "Wyswietlic historie gry? (Y|N)" << endl;
	cin >> wybor;
	cin.clear();
	cin.ignore(1000, '\n');
	if (wybor == 'y' || wybor == 'Y')
	{
		historia_gry(tab);
	}

}

void wczyt_plansz(gra tab[])
{
	system("cls");
	for (int k = 0; k < 6; k++)
	{
		for (int w = 0; w < 6; w++)
			tab[0].zawartosc_planszy[w][k] = ' ';
	}
	tab[0].zawartosc_planszy[1][0] = tab[0].zeton1;
	tab[0].zawartosc_planszy[1][1] = tab[0].zeton1;
	tab[0].zawartosc_planszy[1][3] = tab[0].zeton1;
	tab[0].zawartosc_planszy[0][4] = tab[0].zeton1;
	tab[0].zawartosc_planszy[2][1] = tab[0].zeton1;
	tab[0].zawartosc_planszy[3][1] = tab[0].zeton1;
	tab[0].zawartosc_planszy[3][1] = tab[0].zeton1;
	tab[0].zawartosc_planszy[4][2] = tab[0].zeton1;
	tab[0].zawartosc_planszy[3][0] = tab[0].zeton1;
	tab[0].zawartosc_planszy[0][1] = tab[0].zeton2;
	tab[0].zawartosc_planszy[1][2] = tab[0].zeton2;
	tab[0].zawartosc_planszy[1][4] = tab[0].zeton2;
	tab[0].zawartosc_planszy[4][0] = tab[0].zeton2;
	tab[0].zawartosc_planszy[5][1] = tab[0].zeton2;
	tab[0].zawartosc_planszy[4][4] = tab[0].zeton2;
	tab[0].zawartosc_planszy[5][4] = tab[0].zeton2;
	tab[0].zawartosc_planszy[5][5] = tab[0].zeton2;
	tab[0].licznik = -1;
}

void opcje(gra tab[])
{
	int wybor;
	system("cls");
	cout << "MENU OPCJI" << endl;
	for (int i = 0; i < 25; i++) cout << (char)196;
	cout << endl << "1. Zmiana nazw graczy" << endl << "2. Zmiana zetonow" << endl << "3. Powrot do gry" << endl;
	for (int i = 0; i < 25; i++) cout << (char)196;
	cout << endl << endl;
	cin >> wybor;
	cin.clear();
	cin.ignore(1000, '\n');
		switch (wybor)
		{
		case 1:
			wpisywanie_imion(tab);
			break;
		case 2:
			wybor_zetonow(tab);
			break;
		case 3:
			break;
		default:
			cout << "Nie ma takiej opcji - wcisnij 'enter', aby wybrac ponownie" << endl;
			getchar();
			opcje(tab);
	}
	tab[0].licznik--;
}

void wybor_zetonow(gra tab[])
{
	char bufor_zeton1 = tab[0].zeton1;
	char bufor_zeton2 = tab[0].zeton2;

	system("cls");
	cout << "Wprowadz pojedynczy znak z klawiatury, ktory bedzie zetonem gracza nr 1: " << endl;
	cin >> tab[0].zeton1;
	cin.clear();
	cin.ignore(1000, '\n');

	system("cls");
	cout << "Wprowadz pojedynczy znak z klawiatury, ktory bedzie zetonem gracza nr 2: " << endl;
	cin >> tab[0].zeton2;
	cin.clear();
	cin.ignore(1000, '\n');

	if (tab[0].zeton1 == tab[0].zeton2)
	{
		cout << "Podano takie same zetony - wcisnij 'enter', aby wybrac ponownie" << endl;
		getchar();
		wybor_zetonow(tab);
	}

	for (int k = 0; k < 6; k++)
	{
		for (int w = 0; w < 6; w++)
		{
			if (tab[0].zawartosc_planszy[k][w] == bufor_zeton1)
				tab[0].zawartosc_planszy[k][w] = tab[0].zeton1;
			if (tab[0].zawartosc_planszy[k][w] == bufor_zeton2)
				tab[0].zawartosc_planszy[k][w] = tab[0].zeton2;
		}
	}

}

void zapis_planszy(gra tab[])
{
	for (int w = 0; w < 6; w++)
	{
		for (int k = 0; k < 6; k++)
		{
			tab[35 - tab[0].licznik].zawartosc_planszy[k][w] = tab[0].zawartosc_planszy[k][w];
		}
	}
	tab[35 - tab[0].licznik].licznik = tab[0].licznik;
	tab[35 - tab[0].licznik].zeton1 = tab[0].zeton1;
	tab[35 - tab[0].licznik].zeton2 = tab[0].zeton2;
	tab[35 - tab[0].licznik].gracz1 = tab[0].gracz1;
	tab[35 - tab[0].licznik].gracz2 = tab[0].gracz2;
}

void undo(gra tab[])
{
	if (tab[0].licznik > 0)
	{
		for (int w = 0; w < 6; w++)
		{
			for (int k = 0; k < 6; k++)
			{
				tab[0].zawartosc_planszy[k][w] = tab[37 - tab[0].licznik].zawartosc_planszy[k][w];
			}
		}
		tab[0].zeton1 = tab[36 - tab[0].licznik].zeton1;
		tab[0].zeton2 = tab[36 - tab[0].licznik].zeton2;
		tab[0].gracz1 = tab[36 - tab[0].licznik].gracz1;
		tab[0].gracz2 = tab[36 - tab[0].licznik].gracz2;
		tab[0].licznik = tab[0].licznik - 2;
	}
	else
	{
		cout << "Nie mozna dalej cofnac - nacisnij 'enter', aby kontynuowac" << endl;
		tab[0].licznik--;
		getchar();
	}
}

void historia_gry(gra tab[])
{
	const int max = tab[0].licznik;
	char wybor;
	int koniec = 0;
	tab[2].pentago = true;
	for (; koniec == 0;)
	{
		system("cls");
		rysowanie_planszy(tab);
		cout << endl;
		cin >> wybor;
		cin.clear();
		cin.ignore(1000, '\n');
		switch (wybor)
		{
		case 'a':										//Cofanie
			if (tab[0].licznik > 0)
			{
				tab[0].licznik--;
				for (int w = 0; w < 6; w++)
				{
					for (int k = 0; k < 6; k++)
					{
						tab[0].zawartosc_planszy[k][w] = tab[36 - tab[0].licznik].zawartosc_planszy[k][w];
					}
				}
			}
			else
			{
				cout << "Nie mozna dalej cofnac - nacisnij 'enter', aby kontynuowac" << endl;
				getchar();
			}
			break;
		case 's':											//Naprzód
			if (tab[0].licznik < max)
			{
				tab[0].licznik++;
				for (int w = 0; w < 6; w++)
				{
					for (int k = 0; k < 6; k++)
					{
						tab[0].zawartosc_planszy[k][w] = tab[36 - tab[0].licznik].zawartosc_planszy[k][w];
					}
				}
			}
			else
			{
				cout << "Nie ma nic dalej - nacisnij 'enter', aby kontynuowac" << endl;
				getchar();
			}
			break;
		case 'e':											//Koniec
			koniec++;
		}
	}
}

void obrot(gra tab[])
{
	char kierunek;
	char czesc_planszy;
	cout << "Wybierz czesc planszy oraz kierunek obrotu:" << endl;
	cin >> czesc_planszy;
	int zmienna_y = 0;									//Zmienne pozawalające na sprowadzenie wyboru miejsca na planszy do krótkich funkcji
	int zmienna_x = 0;									//Y - wiersze ; X - kolumny
	switch (czesc_planszy)									//Funkcja switch manipulując zmiennymi pozwala ustalić położenie na planszy 
	{														//lub użycie innych opcji
	case 'q':												//Wybrano pierwszą część planszy
		zmienna_y = 0;
		zmienna_x = 0;
		tab[1].pentago = 1;
		break;
	case 'w':												//Wybrano drugą część planszy
		zmienna_y = 0;
		zmienna_x = 3;
		tab[1].pentago = 1;
		break;
	case 'a':												//Wybrano trzecią część planszy
		zmienna_y = 3;
		zmienna_x = 0;
		tab[1].pentago = 1;
		break;
	case 's':												//Wybrano czwartą część planszy
		zmienna_y = 3;
		zmienna_x = 3;
		tab[1].pentago = 1;
		break;
	case 'h':												//Pomoc - (help)
		help(tab);
		tab[1].pentago = 0;
		break;
	case 'p':												//Pauza
		pauza(tab);
		tab[1].pentago = 0;
		break;
	case 'm':												//Menu opcji
		opcje(tab);
		tab[1].pentago = 0;
		break;
	default:
		cout << "Nie ma takiej czesci planszy - wcisnij 'enter', aby wybrac ponownie" << endl;
		tab[1].pentago = 0;
		tab[0].licznik--;
		getchar();
	}
	if (czesc_planszy == 'q' || czesc_planszy == 'w' || czesc_planszy == 's' || czesc_planszy == 'a')
	{
		char bufor;
		cin >> kierunek;
		switch (kierunek)
		{
		case 'x':									//Lewo
			bufor = tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x];
			tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x] = tab[0].zawartosc_planszy[zmienna_y][zmienna_x];
			tab[0].zawartosc_planszy[zmienna_y][zmienna_x] = tab[0].zawartosc_planszy[zmienna_y][zmienna_x + 2];
			tab[0].zawartosc_planszy[zmienna_y][zmienna_x + 2] = tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x + 2];
			tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x + 2] = bufor;
			bufor = tab[0].zawartosc_planszy[zmienna_y + 1][zmienna_x];
			tab[0].zawartosc_planszy[zmienna_y + 1][zmienna_x] = tab[0].zawartosc_planszy[zmienna_y][zmienna_x + 1];
			tab[0].zawartosc_planszy[zmienna_y][zmienna_x + 1] = tab[0].zawartosc_planszy[zmienna_y + 1][zmienna_x + 2];
			tab[0].zawartosc_planszy[zmienna_y + 1][zmienna_x + 2] = tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x + 1];
			tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x + 1] = bufor;

			break;
		case 'z':									//Prawo
			bufor = tab[0].zawartosc_planszy[zmienna_y][zmienna_x];
			tab[0].zawartosc_planszy[zmienna_y][zmienna_x] = tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x];
			tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x] = tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x + 2];
			tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x + 2] = tab[0].zawartosc_planszy[zmienna_y][zmienna_x + 2];
			tab[0].zawartosc_planszy[zmienna_y][zmienna_x + 2] = bufor;
			bufor = tab[0].zawartosc_planszy[zmienna_y + 1][zmienna_x];
			tab[0].zawartosc_planszy[zmienna_y + 1][zmienna_x] = tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x + 1];
			tab[0].zawartosc_planszy[zmienna_y + 2][zmienna_x + 1] = tab[0].zawartosc_planszy[zmienna_y + 1][zmienna_x + 2];
			tab[0].zawartosc_planszy[zmienna_y + 1][zmienna_x + 2] = tab[0].zawartosc_planszy[zmienna_y + 0][zmienna_x + 1];
			tab[0].zawartosc_planszy[zmienna_y + 0][zmienna_x + 1] = bufor;
			break;
		default:
			cout << "Nie wprowadzono poprawnych danych - wcisnij 'enter', aby wybrac ponownie" << endl;
			tab[1].pentago = 0;
			tab[0].licznik--;
			getchar();
		}
	}
}

void kolko_i_krzyzyk(gra tab[])
{
	inicjacja(tab);
	wpisywanie_imion(tab);
	wybor_zetonow(tab);
	for (int k = 0; tab[0].koniec == false; k++)
	{
		system("cls");
		rysowanie_planszy(tab);
		wstawianie(tab);
		warunek_wygranej(tab);
		zapis_planszy(tab);
		tab[0].licznik++;
	}
	komunikat(tab);
}

