#include "src/Coord.h"
#include "src/Linked_List.h"
#include "src/Node.h"
#include "src/Queue.h"
#include "src/Stack.h"
#include <iostream>
using namespace std;

const int COLS = 12;
const int ROWS = 12;

void resolverBFS(int arr[ROWS][COLS]);
void resolverDFS(int arr[ROWS][COLS]);

bool esCaminable(Coord c, int arr[ROWS][COLS], bool visitado[ROWS][COLS]) {
  return c.row >= 0 && c.row < ROWS && c.col >= 0 && c.col < COLS &&
         arr[c.row][c.col] == 0 && !visitado[c.row][c.col];
}

void mostrarCamino(Linked_List<Coord> &camino) {
  int n = camino.getSize();

  cout << "[";

  for (int i = 0; i < n; i++) {
    cout << camino.get(i)->getData();

    if (i + 1 < n)
      cout << " -> ";
  }

  cout << "]" << endl;
}

// LABERINTO
// 0, 0 -> 0, 1 -> 0, 2 -> 1,2

// PADRE
// DIRECCION VALOR
// a[0][1]= {0, 0}
// 0, 2 = 0, 1
// 1, 2 = 0, 2

// CAMINO
// 0, 0
// 0, 1
// 0, 2
// 1, 2

// 

void reconstruirCamino(Linked_List<Coord> &camino, Coord padre[ROWS][COLS],
                       Coord entrada, Coord salida) {
  Coord p = salida;

  // Backtracking desde la salida hasta la entrada usando el arreglo padre
  while (!(p == entrada)) {
    camino.insertFirst(p);
    p = padre[p.row][p.col];
  }

  camino.insertFirst(entrada);
}

void mostrarLaberinto(int arr[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int curr = arr[i][j];
      if (curr == 1) {
        cout.width(4);
        cout << "|"; // No caminable
      } else if (curr == 2) {
        cout.width(4);
        cout << "o"; // Camino encontrado
      } else if (curr == 3) {
        cout.width(4);
        cout << "*"; // Visitado
      } else {
        cout.width(4);
        cout << " "; // Caminable no visitado
      }
    }
    cout << '\n';
  }
}

// DEEP FIRST SEARCH - Busqueda por profundidad
//      0
//   0    0
// 0  0   0 0
// 0         0

// X X X X X X X X X X X X
// X
// X
// X
// X
// X
// X 0

// pila [vecino 1]


// BFS vecinos del padre primero
// DFS vecino del vecino del vecino del vecino

void resolverDFS(int arr[ROWS][COLS]) {
  Coord entrada = {0, 0}; // Entrada en la esquina superior izquierda
  Coord salida = {ROWS - 1, COLS - 1}; // Salida en la esquina inferior derecha
  
  // visitado[0][0] = true / false;
  // padre[1][0] = {de donde viene}

  bool visitado[ROWS][COLS];
  Coord padre[ROWS][COLS];

  // Inicializar visitado y padre
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      visitado[i][j] = false;
      padre[i][j] = {-1, -1};
    }
  }

  // pila [ }{0,0,  ]
  Stack<Coord> pila;

  pila.Push(entrada);

  // Marcar como visitado antes de pop
  // visitado[entrada.row][entrada.col] = true;

  int recorridas = 0; // Contador de celdas recorridas

  // Vectores para verificar vecinos (ccw empezando por debajo)
  // 0 3 0
  // 4 X 2
  // 0 1 0
  int move_row[4] = {0, -1, 0, 1};
  int move_col[4] = {1, 0, -1, 0};

  while (!pila.isEmpty()) {
    // pila [
    // vecino1entrada
    //]
    Coord actual = pila.Pop();
    // actual = [vecino2, entrada2]

    // Marcar visitado al pop
    if (visitado[actual.row][actual.col]) continue;
    // visitados[vecino2] = true;
    visitado[actual.row][actual.col] = true;
    recorridas++;

    if (actual == salida) {
      cout << "Salida encontrada!" << endl;

      Linked_List<Coord> camino;

      reconstruirCamino(camino, padre, entrada, salida);

      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          if (visitado[i][j]) arr[i][j] = 3; // Marcar con * a todos los visitados
        }
      }

      for (int i = 0; i < camino.getSize(); i++) {
        Coord v_pos = camino.get(i)->getData();
        arr[v_pos.row][v_pos.col] = 2; // Marcar con o al camino encontrado
      }

      cout << "Longitud del camino: " << camino.getSize() << endl;
      cout << "Celdas recorridas: " << recorridas << endl;

      mostrarCamino(camino);
      mostrarLaberinto(arr);

      return;
    }

  //  A4 A A2
  //  1 A1
    Linked_List<Coord> vecinos;

    // vecinos = [1, 2]

    // Verificar vecinos validos
    for (int i = 0; i < 4; i++) {
      Coord vecino = {actual.row + move_row[i], actual.col + move_col[i]};

      if (esCaminable(vecino, arr, visitado)) {
        vecinos.insertLast(vecino);
      }
    }

    int n = vecinos.getSize();

    // pila
    // vecinoa4
    // vecinoa2
    // vecinoa1
    // vecino1

// A = vecino2
    // padre[vecino1] = entrada
    // padre[vecino2] = entrada
    // padre[vecinoa1] = A
    // padre[vecinoA2] = A
    // padre[vecinoA4] = A

    // Caminar por vecinos
    for (int i = 0; i < n; i++) {
      Coord vecino = vecinos.get(i)->getData();
      pila.Push(vecino);
      // Marcar vecinos como visitados tras comprobar su validez
      // visitado[vecino.row][vecino.col] = true;
      padre[vecino.row][vecino.col] = actual;
    }
  }

  cout << "No existe camino con DFS" << endl;
}

// BREADTH FIRST SEARCH - Busqueda por anchura
//      0
//   0    0
// 0  0   0 0
// 0         0
void resolverBFS(int arr[ROWS][COLS]) {
  Coord entrada = {0, 0};
  Coord salida = {ROWS - 1, COLS - 1};
  bool visitado[ROWS][COLS];
  Coord padre[ROWS][COLS];

  // Inicializar visitado y padre con valores por defecto
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      visitado[i][j] = false;
      padre[i][j] = {-1, -1};
    }
  }

  Queue<Coord> cola;

  cola.Insert(entrada);
  // cola [entrada, ]

  // Marcar como visitado tras insertar
  // visitado[entrada.row][entrada.col] = true;

  int recorridas = 0; // Contador de celdas recorridas

  int move_row[4] = {0, -1, 0, 1};
  int move_col[4] = {1, 0, -1, 0};

  // LABERINTO
  // X X X X X ................
  // X X X X
  // X X X
  // X X
  // X

  // VISITADO
  // true false ...
  // true false ....
  while (!cola.isEmpty()) {
    Coord actual = cola.Dequeue();
    // actual = vecino2
      // cola [ vecino21, vecino22, vecino23, vecino 211]

    // actual = entrada

    // Marcar como visitado al dequeue, saltar duplicados
    if (visitado[actual.row][actual.col]) continue;
    visitado[actual.row][actual.col] = true;
    // visitado [entrada.row][entrada.col] = true;
    // visitado [0][0] = true
    recorridas++;

    // 5, 5

    // 5, 5 -> 4, 4
    // 

    if (actual == salida) {
      cout << "Salida encontrada!" << endl;

      Linked_List<Coord> camino;

      reconstruirCamino(camino, padre, entrada, salida);

      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          if (visitado[i][j]) arr[i][j] = 3;
        }
      }

      // VISITADO
      // true false

      // LABERINTO
      // 2 2 1 0 3 
      // 3 2 1 0 3
      // 3 3 1 3 3
      // 3 3 2 2 2

      // CAMINO
     // 0,0 -> 0,1 -> 0, 2 -> 0, 3



      for (int i = 0; i < camino.getSize(); i++) {
        // posicion valida
        Coord v_pos = camino.get(i)->getData();

        arr[v_pos.row][v_pos.col] = 2;
      }

      cout << "Longitud del camino: " << camino.getSize() << endl;
      cout << "Celdas recorridas: " << recorridas << endl;

      mostrarCamino(camino);

      mostrarLaberinto(arr);

      return;
    }

    Linked_List<Coord> vecinos;

    for (int i = 0; i < 4; i++) {
      Coord vecino = {actual.row + move_row[i], actual.col + move_col[i]};

     // X 2
     // 1 0 

     // vecinos [vecino1, vecino2, vecino3]

      if (esCaminable(vecino, arr, visitado)) {
        vecinos.insertLast(vecino);
      }
    }

    int n = vecinos.getSize();

    for (int i = 0; i < n; i++) {
      Coord vecino = vecinos.get(i)->getData();

      // cola [ vecino2, vecino21, vecino22, vecino23]
      cola.Insert(vecino);
      // Marcar vecinos como visitados antes de dequeue
      // visitado[vecino.row][vecino.col] = true;
      padre[vecino.row][vecino.col] = actual;

      // padre[vecino1] = actual = X = entrada = 0,0
      // padre[vecino2] = actual

      // padre[vecino21] = vecino2
      // padre[vecino22] = vecino2
      
    }
  }

  cout << "No existe camino con BFS!" << endl;
}

int main() {
  int laberinto[ROWS][COLS] = {
{0,0,0,0,0,1,0,1,1,1,0,1},
{0,0,0,1,0,1,0,1,1,0,0,0},
{1,0,0,0,0,0,0,0,1,0,0,1},
{0,0,1,1,0,0,1,0,0,0,0,1},
{0,1,0,0,0,0,1,1,1,1,1,1},
{1,0,0,1,0,0,0,1,1,0,1,0},
{0,0,0,1,1,0,0,0,0,0,0,0},
{0,1,0,0,0,1,0,1,1,0,1,0},
{1,1,0,0,0,1,0,0,1,0,1,1},
{1,1,0,1,0,1,0,0,1,0,1,0},
{0,0,0,1,1,1,0,1,1,0,1,0},
{0,1,0,1,1,1,0,0,1,0,0,0}};

  int opt;

  cout << "Especifica el algoritmo con el que deseas resolver el laberinto "
          "DFS(1) BFS(2): "
       << endl;

  cin >> opt;

  switch (opt) {
  case 1:
    cout << "=== DFS ===" << endl;
    resolverDFS(laberinto);
    break;
  case 2:
    cout << "=== BFS ===" << endl;
    resolverBFS(laberinto);
    break;
  default:
    cout << "La opcion que ingresaste no existe!";
    break;
  }

  return 0;
}
