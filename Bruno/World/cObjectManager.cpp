#include "cObjectManager.h"

cObjectManager::cObjectManager()
{

}

cObjectManager::~cObjectManager()
{
    for (auto i = 0; i < _objects.size(); i++)
        delete _objects[i];
}

size_t cObjectManager::GetNumberOfObjects() const
{
    return _objects.size();
}

Object* cObjectManager::GetObject(const unsigned int& index) const
{
    return _objects[index];
}

template <class T>
T* cObjectManager::CreateObject(const glm::vec3& position)
{
    T* newObject = new T(_objects.size());
    newObject->SetPosition(position);

    _objects.push_back(newObject);

    return newObject;
}

template Object* cObjectManager::CreateObject<Object>(const glm::vec3&);
template Cube* cObjectManager::CreateObject<Cube>(const glm::vec3&);