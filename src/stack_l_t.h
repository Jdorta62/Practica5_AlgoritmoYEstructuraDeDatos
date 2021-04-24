/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file stack_l_t.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 24 april 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 5 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  dll_t<T> l_;
};


/**
 * @brief método que permite la insersión de un elemento en la cima de la pila.
 * @param dato objeto a insertar en la pila.
 */
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

/**
 * @brief método que permite la extracción del elemento de la cima de la pila.
 */
template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

/**
 * @brief permite conocer el objeto que ocupa la cima de la pila sin extraerlo.
 */
template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

/**
 * @brief método que permite saber si una lista está vacía.
 */
template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

/**
 * @brief método que permite mostrar por pantalla el contenido de la pila.
 */
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}


#endif  // STACKL_H_
