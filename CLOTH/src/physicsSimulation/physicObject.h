#pragma once

#include <../utils/Transform.h>
#include <glm/glm.hpp>

#define DAMPING 0.02f // how much to damp the cloth simulation each frame
#define COLLISION_OFFSET_MULTIPLIER 1.15f

#define FIXED_TIME_STEP (1.0f / 30.0f)
#define FIXED_TIME_STEP2 (FIXED_TIME_STEP * FIXED_TIME_STEP)


class PhysicObject
{
private:
public:
    Transform* transform;
    glm::vec3 pos;
    glm::vec3 old_pos;
    glm::vec3 force;
    float mass;
    bool isStatic;
    PhysicObject(Transform* t, float objectMass, bool objectMovable){
        this->transform = t;
        this->pos = t->GetTranslationVector();
        this->force = glm::vec3(0.0f);
        this->mass = objectMass;
        this->old_pos = t->GetTranslationVector();
        this->isStatic = objectMovable;
    };
    ~PhysicObject(){};

    void FixedTimeStep(){
        if(!isStatic){
			this->force = glm::vec3(0.0f);
			return;
		}

		glm::vec3 now_pos = pos;
		glm::vec3 accel = force/mass;
		pos = ((2.0f - DAMPING) * now_pos) - ( (1.0f - DAMPING) * old_pos) + (accel * FIXED_TIME_STEP2);
		old_pos = now_pos;
		this->force = glm::vec3(0.0f);

        this->transform->Transformation(
            glm::vec3(1.0f, 1.0f, 1.0f),
            0.0f, glm::vec3(0.0f, 1.0f, 0.0f),
            pos
        );
    }

    void AddForce(glm::vec3 forceToAdd){
        this->force += forceToAdd;
    }
};