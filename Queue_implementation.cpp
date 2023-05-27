#include "Queue.cpp"

//explicit instantiation declarartions of queue class

//required in situations where the declaration and definition of template classes is in separate files.

template class Queue<int>;
template class Queue<double>;
template class Queue<char>;
template class Queue<string>;