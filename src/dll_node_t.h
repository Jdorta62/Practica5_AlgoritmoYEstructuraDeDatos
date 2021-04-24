/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file dll_node_t.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 24 april 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 5 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */ 
 
#ifndef DLL_NODET_H_
#define DLL_NODET_H_

#include <iostream>

// Clase para nodos de listas doblemente enlazadas
template <class T> class dll_node_t {
 public:
  // constructores
  dll_node_t() : prev_(NULL), data_(), next_(NULL) {}  // por defecto
  dll_node_t(const T& data) : prev_(NULL), data_(data), next_(NULL) {}

  // destructor
  ~dll_node_t(void) {}

  // getters & setters
  dll_node_t<T>* get_next(void) const { return next_; }
  void set_next(dll_node_t<T>* next) { next_ = next; }
  
  dll_node_t<T>* get_prev(void) const { return prev_; }
  void set_prev(dll_node_t<T>* prev) { prev_ = prev; }
  
  const T& get_data(void) const { return data_; }
  void set_data(const T& data) { data_ = data; }

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  dll_node_t<T>* prev_;
  T data_;
  dll_node_t<T>* next_;
};

  
/**
 * @brief método que permite mostrar por pantalla un objeto de la clase dll_node_t.
 */
template <class T> std::ostream& dll_node_t<T>::write(std::ostream& os) const {
  os << data_;
  return os;
}

#endif  // DLL_NODET_H_