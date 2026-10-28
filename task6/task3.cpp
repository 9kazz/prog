#include <iostream>
using namespace std;

class Material {
public:
    virtual float getStress(float strain) = 0;
    // В примере материал удаляется через указатель на базовый класс.
    virtual ~Material() {}
};

class ElasticMaterial : public Material {
private:
    float elasticModulus;

public:
    ElasticMaterial(float elasticModulus) {
        this->elasticModulus = elasticModulus;
    }

    float getStress(float strain) {
        return elasticModulus * strain;
    }
};

class PlasticMaterial : public Material {
private:
    float elasticModulus;
    float strainLimit;

public:
    PlasticMaterial(float elasticModulus, float strainLimit) {
        this->elasticModulus = elasticModulus;
        this->strainLimit = strainLimit;
    }

    float getStress(float strain) {
        // После предела напряжение больше не растёт.
        if (strain > strainLimit) {
            return elasticModulus * strainLimit;
        }
        return elasticModulus * strain;
    }
};

int main() {
    Material* m;
    m = new ElasticMaterial(100);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    m = new PlasticMaterial(100, 0.01);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    return 0;
}
