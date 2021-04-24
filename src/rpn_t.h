/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file rpn_t.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 24 april 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 5 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */
#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const double evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


/**
 * @brief método que permite conocer el resultado de una serie de operaciones del estilo RPN
 * @param q objeto cola de la clase queue_l_t de tipo char del cual se van a extraer los digitos y operandos.
 */
template<class T> const double rpn_t<T>::evaluate(queue_l_t<char>& q) {

  while (!q.empty()) 	{
    char c = q.front(); 
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      double i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl << "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == 'r' || c == '^' || c == 'l' || c == 'c');

  double first_operand, second_operand, result;

  std::cout << "   Sacamos de la pila un operando: ";
  second_operand = stack_.top();
  stack_.pop();
  std::cout << second_operand << std::endl;
  if (c != 'r' && c != 'c' && c != 'l') {
    std::cout << "   Sacamos de la pila otro operando: ";
    first_operand = stack_.top();
    stack_.pop();
    std::cout << first_operand << std::endl;
  }
  switch (c) {
    case '+':
      result = first_operand + second_operand;
      break;

    case '-':
      result = first_operand - second_operand;
      break;
    
    case '*':
      result = first_operand * second_operand;
      break;
    
    case '/':
      result = first_operand / second_operand;
      break;

    case '^':
      result = pow(first_operand,second_operand);
      break;
    
    case 'r':
      result = sqrt(second_operand);
      break;

    case 'l':
      result = log2(second_operand);
      break;

    case 'c':
      result = second_operand*second_operand;
      break;
    
    default:
      std::cout << "Error: no se insertó ningún carácter válido." << std::endl;
      exit(EXIT_SUCCESS);

  }

  stack_.push(result);
  std::cout << "   Metemos en la pila el resultado: " << result << std::endl;
}

 
#endif  // RPNT_H_
