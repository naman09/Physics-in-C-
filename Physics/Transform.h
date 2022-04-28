#pragma once
#include "Component.h"
#include "Vector2.h"
class Transform :
    public Component {

public:
    Vector2 mPosition;
    Vector2 mScale;
    
    Transform(Vector2&, Vector2&);
};



