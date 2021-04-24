/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file dll_t.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 24 april 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 5 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T> class dll_t {
 public:
  // constructor
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}

  // destructor
  ~dll_t(void); 

  // getters
  dll_node_t<T>* get_tail(void) const { return tail_; }
  dll_node_t<T>* get_head(void) const { return head_; }
  int get_size(void) const { return sz_; }

  bool empty(void) const;

  // operaciones
  void push_back(dll_node_t<T>*);
  void push_front(dll_node_t<T>*);

  dll_node_t<T>* pop_back(void);
  dll_node_t<T>* pop_front(void);

  dll_node_t<T>* erase(dll_node_t<T>*);

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};


/**
 * @brief destructor de la clase dll_t.
 */
template <class T> dll_t<T>::~dll_t(void) {
  while (head_ != NULL) {
    dll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

/**
 * @brief método que permite saber si la lista está vacía.
 */
template <class T> bool dll_t<T>::empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else
    return false;
}

/**
 * @brief método que permite la insersión por delante de un nodo en la lista.
 * @param nodo nodo a insertar en la lista.
 */
template <class T> void dll_t<T>::push_front(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

/**
 * @brief método que permite la insersión por detrás de un nodo en la lista.
 * @param nodo nodo a insertar en la lista.
 */
template <class T> void dll_t<T>::push_back(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

/**
 * @brief método que permite la extracción del último nodo de la lista.
 */
template <class T> dll_node_t<T>* dll_t<T>::pop_back(void) {
  assert(!empty());

  dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();
  if (tail_ != NULL)
    tail_->set_next(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

/**
 * @brief método que permite la extracción del nodo que encabeza la lista.
 */
template <class T> dll_node_t<T>* dll_t<T>::pop_front(void) {
  assert(!empty());

  dll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  if (head_ != NULL)
    head_->set_prev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

/**
 * @brief método que permite eliminar un nodo de la lista.
 * @param nodo nodo a eliminar.
 */
template <class T> dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL)
    nodo->get_prev()->set_next(nodo->get_next());
  else
    head_ = nodo->get_next();
  if (nodo->get_next() != NULL)
    nodo->get_next()->set_prev(nodo->get_prev());
  else
    tail_ = nodo->get_prev();
  sz_--;
  nodo->set_prev(NULL);
  nodo->set_next(NULL);
  return nodo;
}

/**
 * @brief método que permite escribir por pantalla una lista.
 */
template <class T> std::ostream& dll_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

#endif  // DLLT_H_
