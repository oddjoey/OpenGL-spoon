#include "cObjectManager.h"

cObjectManager::cObjectManager()
{

}

cObjectManager::~cObjectManager()
{

}

size_t cObjectManager::GetNumberOfObjects() const
{
    return _objects.size();
}

std::shared_ptr<Object> cObjectManager::GetObject(const unsigned int& index) const
{
    return _objects[index];
}

template <class T>
std::shared_ptr<T> cObjectManager::CreateObject()
{
    auto newObject = std::make_shared<T>(_objects.size());

    _objects.push_back(newObject);

    return newObject;
}

template std::shared_ptr<Object>    cObjectManager::CreateObject<Object>();
template std::shared_ptr<Cube>      cObjectManager::CreateObject<Cube>  ();