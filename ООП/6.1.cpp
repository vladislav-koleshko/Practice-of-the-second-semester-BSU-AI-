#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class SpaceObject {
protected:
    float x, y, z;
    float vx, vy, vz;

public:
    SpaceObject(float x, float y, float z, float vx, float vy, float vz) {
        setCoordinates(x, y, z);
        setVelocity(vx, vy, vz);
    }

    /*virtual void save(std::ofstream& out) const {
        out.write(reinterpret_cast<const char*>(&x), sizeof(x));
        out.write(reinterpret_cast<const char*>(&y), sizeof(y));
        out.write(reinterpret_cast<const char*>(&z), sizeof(z));
        out.write(reinterpret_cast<const char*>(&vx), sizeof(vx));
        out.write(reinterpret_cast<const char*>(&vy), sizeof(vy));
        out.write(reinterpret_cast<const char*>(&vz), sizeof(vz));
    }

    virtual void load(std::ifstream& in) {
        in.read(reinterpret_cast<char*>(&x), sizeof(x));
        in.read(reinterpret_cast<char*>(&y), sizeof(y));
        in.read(reinterpret_cast<char*>(&z), sizeof(z));
        in.read(reinterpret_cast<char*>(&vx), sizeof(vx));
        in.read(reinterpret_cast<char*>(&vy), sizeof(vy));
        in.read(reinterpret_cast<char*>(&vz), sizeof(vz));
    }*/

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

    virtual std::string getType() const = 0;

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

    /*void save(std::ofstream& out) const override {
        SpaceObject::save(out);
        out.write(reinterpret_cast<const char*>(&maxSize), sizeof(maxSize));
    }

    void load(std::ifstream& in) override {
        SpaceObject::load(in);
        in.read(reinterpret_cast<char*>(&maxSize), sizeof(maxSize));
    }*/

    std::string getType() const override {
        return "Asteroid";
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

    /*void save(std::ofstream& out) const override {
        SpaceObject::save(out);
        size_t nameSize = name.size();
        out.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        out.write(name.c_str(), nameSize);
        out.write(reinterpret_cast<const char*>(&vmax), sizeof(vmax));
        out.write(reinterpret_cast<const char*>(&ammo), sizeof(ammo));
    }

    void load(std::ifstream& in) override {
        SpaceObject::load(in);
        size_t nameSize;
        in.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        name.resize(nameSize);
        in.read(&name[0], nameSize);
        in.read(reinterpret_cast<char*>(&vmax), sizeof(vmax));
        in.read(reinterpret_cast<char*>(&ammo), sizeof(ammo));
    }*/

    std::string getType() const override {
        return "Spaceship";
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

    /*void save(std::ofstream& out) const override {
        SpaceObject::save(out);
        out.write(reinterpret_cast<const char*>(&explosivePower), sizeof(explosivePower));
        out.write(reinterpret_cast<const char*>(&fuelTime), sizeof(fuelTime));
    }

    void load(std::ifstream& in) override {
        SpaceObject::load(in);
        in.read(reinterpret_cast<char*>(&explosivePower), sizeof(explosivePower));
        in.read(reinterpret_cast<char*>(&fuelTime), sizeof(fuelTime));
    }*/

    std::string getType() const override {
        return "Rocket";
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

    /*void save(std::ofstream& out) const override {
        SpaceObject::save(out);
        out.write(reinterpret_cast<const char*>(&ammoBonus), sizeof(ammoBonus));
        out.write(reinterpret_cast<const char*>(&existenceTime), sizeof(existenceTime));
    }

    void load(std::ifstream& in) override {
        SpaceObject::load(in);
        in.read(reinterpret_cast<char*>(&ammoBonus), sizeof(ammoBonus));
        in.read(reinterpret_cast<char*>(&existenceTime), sizeof(existenceTime));
    }*/

    std::string getType() const override {
        return "Bonus";
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
    void addObject(std::unique_ptr<SpaceObject> obj) {
        objects.push_back(std::move(obj));
    }

    void removeObject(size_t index) {
        if (index < objects.size()) {
            objects.erase(objects.begin() + index);
        }
        else {
            std::cerr << "Index out of range" << std::endl;
        }
    }

    /*void saveToFile(const std::string& filename) const {
        std::ofstream out(filename, std::ios::binary);
        if (!out) {
            std::cerr << "Failed to open file for writing: " << filename << std::endl;
            return;
        }

        size_t size = objects.size();
        out.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for (const auto& obj : objects) {
            std::string type = obj->getType();
            size_t typeSize = type.size();
            out.write(reinterpret_cast<const char*>(&typeSize), sizeof(typeSize));
            out.write(type.c_str(), typeSize);

            obj->save(out);
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream in(filename, std::ios::binary);
        if (!in) {
            std::cerr << "Failed to open file for reading: " << filename << std::endl;
            return;
        }

        size_t size;
        in.read(reinterpret_cast<char*>(&size), sizeof(size));

        for (size_t i = 0; i < size; ++i) {
            size_t typeSize;
            in.read(reinterpret_cast<char*>(&typeSize), sizeof(typeSize));

            std::string type(typeSize, '\0');
            in.read(&type[0], typeSize);

            if (type == "Asteroid") {
                auto obj = std::make_unique<Asteroid>(0, 0, 0, 0, 0, 0, 0);
                obj->load(in);
                addObject(std::move(obj));
            }
            else if (type == "Spaceship") {
                auto obj = std::make_unique<SpaceShip>("", 0, 0, 0, 0, 0, 0, 0, 0);
                obj->load(in);
                addObject(std::move(obj));
            }
            else if (type == "Rocket") {
                auto obj = std::make_unique<Rocket>(0, 0, 0, 0, 0, 0, 0, 0);
                obj->load(in);
                addObject(std::move(obj));
            }
            else if (type == "Bonus") {
                auto obj = std::make_unique<Bonus>(0, 0, 0, 0, 0, 0, 0, 0);
                obj->load(in);
                addObject(std::move(obj));
            }
            else {
                std::cerr << "Unknown type: " << type << std::endl;
                return;
            }
        }
    }*/

    void displayAll() const {
        for (const auto& obj : objects) {
            obj->display();
            std::cout << std::endl;
        }
    }
};

int main() {
    SpaceObjectArray spaceArray;
    //spaceArray.loadFromFile("space_objects.dat");


    spaceArray.addObject(std::make_unique<Asteroid>(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 5.0));
    spaceArray.addObject(std::make_unique<SpaceShip>("Apollo", 4.0, 5.0, 6.0, 0.4, 0.5, 0.6, 10.0, 100));
    spaceArray.addObject(std::make_unique<Rocket>(7.0, 8.0, 9.0, 0.7, 0.8, 0.9, 50.0, 20.0));
    spaceArray.addObject(std::make_unique<Bonus>(10.0, 11.0, 12.0, 1.0, 1.1, 1.2, 25, 300.0));

    spaceArray.displayAll();
    //spaceArray.saveToFile("space_objects.dat");
    return 0;
}