
#include <string>
#include <cmath>
#include <iostream>
#include <stdexcept>

class TemperatureSensor {
    std::string factory_id;
    int set_id;
    double temperature;
    double* history;

    const int unique_id;
    static int count;
    static const std::string class_name;

    static std::string check_factory_id(const std::string& value);
    static double normalize_temperature(double value);

public:
    TemperatureSensor();
    TemperatureSensor(std::string factory_id, int set_id, double temperature);
    TemperatureSensor(const TemperatureSensor& other);
    TemperatureSensor& operator=(const TemperatureSensor& other);
    ~TemperatureSensor();

    const std::string& getFactoryId() const;
    int getSetId() const;
    double getTemperature() const;
    double getHistory(int index) const;
    const int getUniqueId() const;

    void setSetId(int value);
    void setTemperature(double value);
    void print() const;
    void print_count() const;
};

int TemperatureSensor::count = 0;
const std::string TemperatureSensor::class_name = "Temperature sensor";

std::string TemperatureSensor::check_factory_id(const std::string& value)
{
    if (value.empty())
    {
        throw std::invalid_argument("поле factory_id не должно быть пустым");
    }
    return value;
}

double TemperatureSensor::normalize_temperature(double value)
{
    if (value < -273.0) return -273.0;
    if (value > 1000.0) return 1000.0;
    return value;
}

TemperatureSensor::TemperatureSensor()
    : factory_id("abc_01"), set_id(0), temperature(0.0), history(new double[10]{}), unique_id(++count) {
    std::cout << "конструктор по умолчанию\n";
}

TemperatureSensor::TemperatureSensor(std::string factory_id, int set_id, double temperature)
    : factory_id(check_factory_id(factory_id)), set_id(set_id), temperature(normalize_temperature(temperature)), history(new double[10]{}), unique_id(++count) {
    std::cout << "инициализирующий конструктор\n";
}

TemperatureSensor::TemperatureSensor(const TemperatureSensor& other)
    : factory_id(other.factory_id), set_id(other.set_id), temperature(other.temperature), history(new double[10]), unique_id(++count) {
    for (int i = 0; i < 10; ++i)
    {
        history[i] = other.history[i];
    }
    std::cout << "конструктор копирования\n";
}

TemperatureSensor& TemperatureSensor::operator=(const TemperatureSensor& other)
{
    if (this != &other)
    {
        set_id = other.set_id;
        temperature = other.temperature;

        for (int i = 0; i < 10; ++i)
        {
            history[i] = other.history[i];
        }
    }
    std::cout << "оператор присваивания\n";
    return *this;
}

TemperatureSensor::~TemperatureSensor()
{
    delete[] history;
    --count;
}

const std::string& TemperatureSensor::getFactoryId() const
{
    return factory_id;
}

int TemperatureSensor::getSetId() const
{
    return set_id;
}

double TemperatureSensor::getTemperature() const
{
    return temperature;
}

double TemperatureSensor::getHistory(int index) const
{
    if (index < 0 || index >= 10)
    {
        throw std::out_of_range("Неверный индекс (0..9)");
    }
    return history[index];
}

const int TemperatureSensor::getUniqueId() const
{
    return unique_id;
}

void TemperatureSensor::setSetId(int value)
{
    set_id = value;
}

void TemperatureSensor::setTemperature(double value)
{
    const double new_temperature = normalize_temperature(value);

    for (int i = 9; i > 0; --i)
    {
        history[i] = history[i - 1];
    }

    history[0] = temperature;
    temperature = new_temperature;
}

void TemperatureSensor::print() const
{
    std::cout << "factory_id: " << factory_id << ", set_id: " << set_id << ", unique_id:" << unique_id << ", temperature: " << temperature << " C\n";
}

void TemperatureSensor::print_count() const
{
    std::cout << "count: " << count;
}
