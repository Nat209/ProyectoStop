#include <ctime>
#include <iostream>
#include <iomanip> //ordenar con setw las salidas de datos
#include <string>
using namespace std;

string findSubstr(string str, int n) {
  if (str.length() < n) {
    return str;
  }

  return str.substr(0, n);
}

string LetraAleatoria() { // esto es para lanzar una letra aleatoria
  string aleatoria[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
                        "j", "k", "l", "m", "n", "o", "p", "q", "r",
                        "s", "t", "u", "v", "w", "x", "y", "z"};
  string letra = aleatoria[rand() % 26];
  return (letra);
}

int main() {
  string str[7];
  string Jugador;
  int partidas;
  string pre1, pre2;
  int puntaje = 0;

  

  cout << "\nSumercé bienvenido al juego stop!\nDebe escribir  'si' o "
          "'no'\n¿Desea iniciar el juego? ";
  cin >> pre1;

  if (pre1 == "si") {

    cout << "\nTe explicamos como:" << endl;

    cout << "\nAl comienzo te pediremos tu nombre en ese momento aun no "
            "comenzara el juego, ya escrito tu nombre y al darle enter "
            "comenzara el contador y ahi si comienzra la partida, despues de "
            "eso el juego te arrojara una letra del abecedario al azar\n ¿En "
            "que consiste el juego?\n El juego te ira haciendo unas serie de "
            "preguntas como por ejemplo escribe un nombre de un pais y tendras "
            "que escribir el pais, pero con la regla de que ese nombre de ese "
            "pais se escriba con la letra que se te dio ya antes menciondo "
            "como por ejemplo: se te dio la letra c el nombre del pais seria "
            "colombia o canadá.\n";

    cout << "\nIngrese nombre del jugador : "; // esto es para ingresar datos
   // del jugador.

    string categorias[10] = {"RONDA", "NOMBRE", " APELLIDO", "ANIMAL",     "FRUTA",
                       "PAIS", " COLOR", "COSA",    "PUNTAJE"};

    
    cin >> Jugador;
    cout << "Cuantas partidas desea jugar: ";
    cin >> partidas;

    for (int i = 1; i <= partidas; i++) {
      string letra = LetraAleatoria();

      cout << "La letra a jugar es: " << letra << endl << endl;

      cout << "Ronda Número: " << i << endl << endl;

      srand(time(NULL));
      cout << "1) ingrese un nombre: ";
      cin >> str[0];
      cout << "2) ingrese un apellido: ";
      cin >> str[1];
      cout << "3) ingrese un animal: ";
      cin >> str[2];
      cout << "4) ingrese una fruta: ";
      cin >> str[3];
      cout << "5) ingrese un pais: ";
      cin >> str[4];
      cout << "6) ingrese un color: ";
      cin >> str[5];
      cout << "7) ingrese una cosa: ";
      cin >> str[6];

      int n = 1;
      
      for (int j = 0; j <= 6; j++) {
        string substr = findSubstr(str[j], n);
        cout << substr << ' ';
        if(substr == letra){
          puntaje = puntaje +100;
        }if(substr == ""){
          puntaje = puntaje +0;
        }if(substr != letra){
          puntaje = puntaje -100;
        }
      }
      cout << puntaje;
    }
    cout << Jugador << " este es el resultado del juego: " << endl;

    for (int i = 0; i <= 9; i++) {
    cout << setw(15) << categorias[i];
  }

    cout << "||" << 1 <<"";
    for (int i = 0; i <= 6; i++) {
      cout << setw(10) << str[i] << puntaje;
    }
  /*   
    cout << "||" << 1 << "    ";
    for (int i = 0; i <= 6; i++) {
      cout << "\t ||" << str[i] << puntaje;
      
    }
  */
    cout << endl
         << "------------------------------------------------------------------"
            "-------------------\n";

  } else {
    cout << "\nGracias por visitarnos sumercé!" << endl;
  }

  return 0;
}