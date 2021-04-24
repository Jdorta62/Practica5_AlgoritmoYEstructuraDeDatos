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
  * 
  */
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_;

 public:
  // constructor
  queue_l_t(void) : l_() {}

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;

  // E/S
  std::ostream& write(std::ostream& os = std::cout) const;
};


/**
 * @brief método que permite saber si la cola está vacía.
 */
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}

/**
 * @brief método que retorna el tamaño de la cola.
 */
template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

/**
 * @brief método que permite insertar en la cola un elemento.
 */
template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

/**
 * @brief método que permite la extracción del primer elemento de la cola.
 */
template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

/**
 * @brief método que permite conocer el valor del primer elemento de la cola sin extraerlo.
 */
template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

/**
 * @brief método que permite conocer el valor del último elemento de la cola sin extraerlo.
 */
template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

/**
 * @brief método que permite escribir por pantalla los elementos de una cola.
 */
template<class T> std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}
/**
 * @brief sobrecarda del operador de insersión <<.
 */
template<class T> std::ostream& operator<<(std::ostream& os, const queue_l_t<T>& q) {
  q.write(os);
  return os;
}


#endif  // QUEUE_H_
