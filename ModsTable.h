#ifndef __MODSTABLE_H__
#define __MODSTABLE_H__

template <class T>
class ModsTable{
public:
    int positionValue;
    int version;
    T value;
    ModsTable():version(0){};
    ModsTable(int,int, T);
};

template <class T>
ModsTable<T>::ModsTable(int _version,int _positionValue,T _value){
    this->positionValue=_positionValue;
    this->version=_version;
    this->value=_value;

}

#endif