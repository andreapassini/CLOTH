#pragma once

#include <../utils/transform.h>
#include <../utils/model.h>

class GameObject
{
private:

public:
    Transform* transform;
    Model* model;

    GameObject(Transform* t, Model* m){
        this->transform = t;
        this->model = m;
    };
    ~GameObject();
};
