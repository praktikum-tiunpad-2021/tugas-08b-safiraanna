#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data, priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head, tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> Q;
  Q.head = nullptr;
  Q.tail = nullptr;
  return Q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // ============= CREATING NEW ELEMENT =============
  ElementPtr<T> pNew = new Element<T>;
  pNew -> data = value;
  pNew -> priority = priority;
  pNew -> next = nullptr;
  // ================================================
  
  
  if (q.head == nullptr && q.tail == nullptr) {
    q.head = pNew;
    q.tail = pNew;
  }

  else {
    ElementPtr<T> curr = q.head;
    ElementPtr<T> pRev = nullptr;

    while (pNew -> priority <= curr -> priority) {
      if (curr -> next == nullptr) {
        break;
      }
      
      pRev = curr;
      curr = curr -> next;
    }
    
    // Insert First
    if (curr == q.head && pNew -> priority > curr -> priority) {
      pNew -> next = curr;
      q.head = pNew;
    }

    // Insert Last
    else if (curr == q.tail && pNew->priority < curr -> priority) {
      curr -> next = pNew;
      q.tail = pNew;
    }

    // Insert Middle
    else {
      pRev -> next = pNew;
      pNew -> next = curr;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head -> data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> pDel;
  if (q.head == nullptr && q.tail == nullptr) {
    pDel = nullptr;
  }

  else if (q.head -> next == nullptr) {
    pDel = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }

  else {
    pDel = q.head;
    q.head = q.head -> next;
    pDel -> next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
