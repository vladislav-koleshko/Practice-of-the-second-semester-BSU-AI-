#include <iostream>
#include <string>
#include <vector>

class SpaceObject {
protected:
    float x, y, z;
    float vx, vy, vz;

public:
    SpaceObject(float x, float y, float z, float vx, float vy, float vz) {
        setCoordinates(x, y, z);
        setVelocity(vx, vy, vz);
    }

    void setCoordinates(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void getCoordinates(float& x, float& y, float& z) const {
        x = this->x;
        y = this->y;
        z = this->z;
    }

    void setVelocity(float vx, float vy, float vz) {
        this->vx = vx;
        this->vy = vy;
        this->vz = vz;
    }

    void getVelocity(float& vx, float& vy, float& vz) const {
        vx = this->vx;
        vy = this->vy;
        vz = this->vz;
    }

    virtual void display() const {
        std::cout << "Coordinates: (" << x << ", " << y << ", " << z << ")\n";
        std::cout << "Velocity: (" << vx << ", " << vy << ", " << vz << ")\n";
    }

    virtual ~SpaceObject() = default;
};

class Asteroid : public SpaceObject {
private:
    float maxSize;

public:
    Asteroid(float x, float y, float z, float vx, float vy, float vz, float maxSize)
        : SpaceObject(x, y, z, vx, vy, vz), maxSize(maxSize) {}

    void setMaxSize(float maxSize) {
        this->maxSize = maxSize;
    }

    float getMaxSize() const {
        return maxSize;
    }

    void display() const override {
        std::cout << "Type: Asteroid\n";
        SpaceObject::display();
        std::cout << "Max Size: " << maxSize << "\n";
    }
};

class SpaceShip : public SpaceObject {
private:
    std::string name;
    float vmax;
    int ammo;

public:
    SpaceShip(const std::string& name, float x, float y, float z, float vx, float vy, float vz, float vmax, int ammo)
        : SpaceObject(x, y, z, vx, vy, vz), name(name), vmax(vmax), ammo(ammo) {}

    void setName(const std::string& name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }

    void setVmax(float vmax) {
        this->vmax = vmax;
    }

    float getVmax() const {
        return vmax;
    }

    void setAmmo(int ammo) {
        this->ammo = ammo;
    }

    int getAmmo() const {
        return ammo;
    }

    void display() const override {
        std::cout << "Type: SpaceShip\n";
        std::cout << "Name: " << name << "\n";
        SpaceObject::display();
        std::cout << "Max Speed: " << vmax << "\n";
        std::cout << "Ammo: " << ammo << "\n";
    }
};

class Rocket : public SpaceObject {
private:
    float explosivePower;
    float fuelTime;

public:
    Rocket(float x, float y, float z, float vx, float vy, float vz, float explosivePower, float fuelTime)
        : SpaceObject(x, y, z, vx, vy, vz), explosivePower(explosivePower), fuelTime(fuelTime) {}

    void setExplosivePower(float explosivePower) {
        this->explosivePower = explosivePower;
    }

    float getExplosivePower() const {
        return explosivePower;
    }

    void setFuelTime(float fuelTime) {
        this->fuelTime = fuelTime;
    }

    float getFuelTime() const {
        return fuelTime;
    }

    void display() const override {
        std::cout << "Type: Rocket\n";
        SpaceObject::display();
        std::cout << "Explosive Power: " << explosivePower << "\n";
        std::cout << "Fuel Time: " << fuelTime << "\n";
    }
};

class Bonus : public SpaceObject {
private:
    int ammoBonus;
    float existenceTime;

public:
    Bonus(float x, float y, float z, float vx, float vy, float vz, int ammoBonus, float existenceTime)
        : SpaceObject(x, y, z, vx, vy, vz), ammoBonus(ammoBonus), existenceTime(existenceTime) {}

    void setAmmoBonus(int ammoBonus) {
        this->ammoBonus = ammoBonus;
    }

    int getAmmoBonus() const {
        return ammoBonus;
    }

    void setExistenceTime(float existenceTime) {
        this->existenceTime = existenceTime;
    }

    float getExistenceTime() const {
        return existenceTime;
    }

    void display() const override {
        std::cout << "Type: Bonus\n";
        SpaceObject::display();
        std::cout << "Ammo Bonus: " << ammoBonus << "\n";
        std::cout << "Existence Time: " << existenceTime << "\n";
    }
};

class SpaceObjectArray {
private:
    std::vector<std::unique_ptr<SpaceObject>> objects;

public:
    // Добавление объекта в массив
    void addObject(std::unique_ptr<SpaceObject> obj) {
        objects.push_back(std::move(obj));
    }

    // Удаление объекта из массива по индексу
    void removeObject(size_t index) {
        if (index < objects.size()) {
            objects.erase(objects.begin() + index);
        }
        else {
            std::cerr << "Index out of range" << std::endl;
        }
    }

    // Вывод всех объектов в массиве
    void displayAll() const {
        for (const auto& obj : objects) {
            obj->display();
            std::cout << std::endl;
        }
    }
};

int main() {
    SpaceObjectArray spaceArray;

    spaceArray.addObject(std::make_unique<Asteroid>(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 5.0));
    spaceArray.addObject(std::make_unique<SpaceShip>("Apollo", 4.0, 5.0, 6.0, 0.4, 0.5, 0.6, 10.0, 100));
    spaceArray.addObject(std::make_unique<Rocket>(7.0, 8.0, 9.0, 0.7, 0.8, 0.9, 50.0, 20.0));
    spaceArray.addObject(std::make_unique<Bonus>(10.0, 11.0, 12.0, 1.0, 1.1, 1.2, 25, 300.0));

    spaceArray.displayAll();
    return 0;
}