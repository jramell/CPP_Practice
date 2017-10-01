#include <stdexcept>

template <typename T>
JRLinkedList<T>::JRLinkedList() {
    head =  nullptr;
    tail = head;
}

template <typename T>
JRLinkedList<T>::~JRLinkedList() {
    JRLinkedListNode<T>* current = head;
    while (head)
    {
        head = current->next;
        delete current;
        current = head;
    }
}

template <typename T>
JRLinkedList<T>::JRLinkedList(JRLinkedListNode<T> head) : head(&head), tail(this->head) { }

template <typename T>
void JRLinkedList<T>::insert(const T& object) {
    JRLinkedListNode<T>* node = new JRLinkedListNode<T>(object);
    node->next = head;
    head = node;
    if (!tail)
    {
        tail = node->next;
    }
}

template <typename T>
void JRLinkedList<T>::remove(int position) {
    if (!head) {
        throw std::out_of_range("No elements in list");
    }

    if (position == 0) {
        JRLinkedListNode<T>* newHead = head->next;
        delete head;
        head = newHead;
        return;
    }
    JRLinkedListNode<T>* current = head;
    JRLinkedListNode<T>* objectToDelete = 0;
    int currentPosition = 0;
    while (current)
    {
        currentPosition++;
        if (currentPosition == position)
        {
            objectToDelete = current->next;
            current->next = objectToDelete->next;
            delete objectToDelete;
            if (!current->next) {
                tail = current;
            }
            return;
        }
        current = current->next;
    }
    std::string exception = "No element at ";
    exception.append(std::to_string(position));
    throw std::out_of_range(exception);
}

template <typename T>
void JRLinkedList<T>::push_back(const T& object) {
    tail->next = new JRLinkedListNode<T>(object);
    tail = tail->next;
}

template <typename T>
const T& JRLinkedList<T>::get(int position) const {
    const JRLinkedListNode<T>* current = head;
    int currentPosition = 0;
    while (current)
    {
        if (currentPosition == position)
        {
            return current->getData();
        }
        currentPosition++;
        current = current->next;
    }
    throw std::out_of_range("No element at position " + position);
}

template <typename T>
T& JRLinkedList<T>::get(int position) {
    //avoid code duplication by having the non-const get call the const get (Item 3 of Effective C++)
    return const_cast<T&> (
            static_cast<const JRLinkedList<T>&>(*this).get(position)
    );
}

template <typename T>
const T& JRLinkedList<T>::getLastElement() const {
    return tail->getData();
}