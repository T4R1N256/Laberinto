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

void reconstruirCamino(Linked_List<Coord> &camino, Coord padre[ROWS][COLS],
                       Coord entrada, Coord salida) {
  Coord p = salida;

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
        cout << "|";
      } else if (curr == 2) {
        cout.width(4);
        cout << "o";
      } else if (curr == 3) {
        cout.width(4);
        cout << "*";
      } else {
        cout.width(4);
        cout << " ";
      }
    }
    cout << '\n';
  }
}

void resolverDFS(int arr[ROWS][COLS]) {
  Coord entrada = {0, 0}; // Entrada en la esquina superior izquierda
  Coord salida = {ROWS - 1, COLS - 1}; // Salida en la esquina inferior derecha
  bool visitado[ROWS][COLS];
  Coord padre[ROWS][COLS];

  // Inicializar visitado y padre
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      visitado[i][j] = false;
      padre[i][j] = {-1, -1};
    }
  }

  Stack<Coord> pila;

  pila.Push(entrada);

  visitado[entrada.row][entrada.col] = true;

  // Vectores para verificar vecinos
  int move_row[4] = {-1, 0, 1, 0};
  int move_col[4] = {0, 1, 0, -1};

  while (!pila.isEmpty()) {
    Coord actual = pila.Pop();

    if (actual == salida) {
      cout << "Salida encontrada!" << endl;

      Linked_List<Coord> camino;

      reconstruirCamino(camino, padre, entrada, salida);

      for (int i = 0; i < camino.getSize(); i++) {
        Coord v_pos = camino.get(i)->getData();
        arr[v_pos.row][v_pos.col] = 2;
      }

      cout << "Longitud del camino: " << camino.getSize() << endl;

      mostrarCamino(camino);
      mostrarLaberinto(arr);

      return;
    }

    Linked_List<Coord> vecinos;

    // Verificar vecinos validos
    for (int i = 0; i < 4; i++) {
      Coord vecino = {actual.row + move_row[i], actual.col + move_col[i]};

      if (esCaminable(vecino, arr, visitado)) {
        vecinos.insertLast(vecino);
      }
    }

    int n = vecinos.getSize();

    // Caminar por vecinos
    for (int i = 0; i < n; i++) {
      Coord vecino = vecinos.get(i)->getData();
      pila.Push(vecino);
      visitado[vecino.row][vecino.col] = true;
      padre[vecino.row][vecino.col] = actual;
    }
  }

  cout << "No existe camino con DFS" << endl;
}

void resolverBFS(int arr[ROWS][COLS]) {
  Coord entrada = {0, 0};
  Coord salida = {ROWS - 1, COLS - 1};
  bool visitado[ROWS][COLS];
  Coord padre[ROWS][COLS];

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      visitado[i][j] = false;
      padre[i][j] = {-1, -1};
    }
  }

  Queue<Coord> cola;

  cola.Insert(entrada);

  visitado[entrada.row][entrada.col] = true;

  int move_row[4] = {-1, 0, 1, 0};
  int move_col[4] = {0, 1, 0, -1};

  while (!cola.isEmpty()) {
    Coord actual = cola.Dequeue();

    if (actual == salida) {
      cout << "Salida encontrada!" << endl;

      Linked_List<Coord> camino;

      reconstruirCamino(camino, padre, entrada, salida);

      for (int i = 0; i < camino.getSize(); i++) {
        Coord v_pos = camino.get(i)->getData();

        arr[v_pos.row][v_pos.col] = 2;
      }

      cout << "Longitud del camino: " << camino.getSize() << endl;

      mostrarCamino(camino);

      mostrarLaberinto(arr);

      return;
    }

    Linked_List<Coord> vecinos;

    for (int i = 0; i < 4; i++) {
      Coord vecino = {actual.row + move_row[i], actual.col + move_col[i]};

      if (esCaminable(vecino, arr, visitado)) {
        vecinos.insertLast(vecino);
      }
    }

    int n = vecinos.getSize();

    for (int i = 0; i < n; i++) {
      Coord vecino = vecinos.get(i)->getData();

      cola.Insert(vecino);

      visitado[vecino.row][vecino.col] = true;

      padre[vecino.row][vecino.col] = actual;
    }
  }

  cout << "No existe camino con BFS!" << endl;
}

int main() {
  int laberinto[ROWS][COLS] = {
{0,1,0,0,0,1,0,1,1,1,0,1},
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

  cout << "Especifica el algoritmo con el que deseas resolver el laberinto: "
          "DFS(1) BFS(2)"
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
