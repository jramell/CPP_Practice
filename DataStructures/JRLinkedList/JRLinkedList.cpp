#include <stdexcept>

using jr::JRLinkedList;

template <typename T>
JRLinkedList<T>::JRLinkedListNode::JRLinkedListNode(T data) : data(data), next(nullptr) { }

template <typename T>
JRLinkedList<T>::JRLinkedList() : head(nullptr), tail(nullptr) { }

template <typename T>
JRLinkedList<T>::~JRLinkedList() {
    JRLinkedListNode* current = head;
    while (head) {
        head = current->next;
        delete current;
        current = head;
    }
}

template <typename T>
bool JRLinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
bool JRLinkedList<T>::empty() {
    return static_cast<const JRLinkedList<T>&>(*this).empty();
}

template <typename T>
void JRLinkedList<T>::insert(const T& object) {
    JRLinkedListNode* node = new JRLinkedListNode(object);
    node->next = head;
    head = node;
    if (!(node->next)) {
        tail = head;
    }
}

template <typename T>
void JRLinkedList<T>::push_back(const T& object) {
    JRLinkedListNode* node = new JRLinkedListNode(object);
    if(tail) {
        tail->next = node;
    }
    tail = node;
    if(!head) {
        head = tail;
    }
}

template <typename T>
void JRLinkedList<T>::remove(const T& value) {
    JRLinkedListNode* temp = nullptr;
    while(head->data == value) {
        temp = head->next;
        delete head;
        head = temp;
        if(!head) {
            tail = nullptr;
            return;
        }
    }
    JRLinkedListNode* current = head;
    while(current->next) {
        if(current->next->data == value) {
            temp = current->next->next;
            delete current->next;
            current->next = temp;
            if(!current->next) {
                current = tail;
            }
        }
        current = current->next;
    }
}

template <typename T>
const T& JRLinkedList<T>::front() const {
    return get(0);
}

template <typename T>
T& JRLinkedList<T>::front() {
    return const_cast<T&>(
            static_cast<const JRLinkedList<T>&>(*this).front()
    );
}

template <typename T>
const T& JRLinkedList<T>::get(int position) const {
    const JRLinkedListNode* current = head;
    int currentPosition = 0;
    while (current) {
        if (currentPosition == position) {
            return current->data;
        }
        currentPosition++;
        current = current->next;
    }
    throw std::out_of_range("No element at position " + std::to_string(position));
}

template <typename T>
T& JRLinkedList<T>::get(int position) {
    //avoid code duplication by having the non-const get call the const get (Item 3 of Effective C++)
    return const_cast<T&> (
            static_cast<const JRLinkedList<T>&>(*this).get(position)
    );
}

template <typename T>
const T& JRLinkedList<T>::back() const {
    if(!tail) {
        throw std::out_of_range("LinkedList is empty");
    }
    return tail->data;
}

template <typename T>
T& JRLinkedList<T>::back() {
    return const_cast<T&>(
            static_cast<const JRLinkedList<T>&>(*this).back()
    );
}

template <typename T>
JRLinkedList<T>::iterator::iterator(JRLinkedList<T>::JRLinkedListNode* startingNode) : current(startingNode) { }

template <typename T>
typename JRLinkedList<T>::iterator& JRLinkedList<T>::iterator::operator++() {
    current = current->next;
    return *this;
}

template <typename T>
typename JRLinkedList<T>::iterator JRLinkedList<T>::iterator::operator++(int) {
    JRLinkedList<T>::iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
T& JRLinkedList<T>::iterator::operator*() {
    if(!current) {
        throw std::out_of_range("invalid iterator");
    }
    return current->data;
}

template <typename T>
bool JRLinkedList<T>::iterator::operator==(const typename JRLinkedList<T>::iterator& other) {
    return current == other.current;
}

template <typename T>
bool JRLinkedList<T>::iterator::operator!=(const JRLinkedList<T>::iterator& other) {
    return current != other.current;
}

template <typename T>
JRLinkedList<T>::iterator::iterator(const typename JRLinkedList<T>::iterator& other) : current(other.current) { }

template <typename T>
typename JRLinkedList<T>::iterator JRLinkedList<T>::begin() {
    return iterator(head);
}

template <typename T>
typename JRLinkedList<T>::iterator JRLinkedList<T>::end() {
    JRLinkedListNode* tailCopy = tail;
    return iterator(nullptr);
}