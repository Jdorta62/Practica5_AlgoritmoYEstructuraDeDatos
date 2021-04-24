/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file queue_l_t.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 24 april 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 5 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * Compilación:
  * g++ -g main_rpn_t.cc -o main_rpn_t
  * 
  * Ejecución:
  * ./main_rpn_t < data_rpn_t_1.txt  
  * ./main_rpn_t < data_rpn_t_3.txt
  * ./main_rpn_t < data_rpn_t_2.txt
  * 
  */

#include <iostream>

#include "stack_l_t.h"
#include "queue_l_t.h"
#include "rpn_t.h"

using namespace std;

int main(void) {
  rpn_t<stack_l_t<double>> calculadora;
  queue_l_t<char> cola;
	
  while (!cin.eof()) 	{
    cin >> ws; // lee los espacios en blanco, que dan problemas
    if (!cin.eof()) {
      char c;
      cin >> c;
      cola.push(c);
    }
  }

  cout << "Expresión a evaluar: ";	
  cola.write();

  double r = calculadora.evaluate(cola);
  cout << "Resultado: " << r << endl;

  return 0;
}

