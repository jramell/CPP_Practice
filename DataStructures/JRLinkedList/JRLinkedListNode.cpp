
template <typename T>
JRLinkedListNode<T>::JRLinkedListNode(T data) : data(data) { }

template <typename T>
const T& JRLinkedListNode<T>::getData() const {
    return data;
}

template <typename T>
T& JRLinkedListNode<T>::getData() {
    const_cast<T&>(
        static_cast<const JRLinkedListNode&> (*this).getData()
    );
}