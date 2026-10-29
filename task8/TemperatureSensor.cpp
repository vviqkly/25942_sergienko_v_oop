#include <string>
#include <cmath>
#include <iostream>
#include <stdexcept>

template<typename NUMBER>
class TemperatureSensor {
    std::string factory_id;
    int set_id;
    NUMBER temperature;
    NUMBER* history;

    const int unique_id;
    static int count;
    static int uid;
    static const std::string class_name;

    static std::string check_factory_id(const std::string& value);
    static NUMBER normalize_temperature(NUMBER value);

public:
    TemperatureSensor();
    TemperatureSensor(std::string factory_id, int set_id, NUMBER temperature);
    TemperatureSensor(const TemperatureSensor& other);
    TemperatureSensor(TemperatureSensor&& other);
    TemperatureSensor& operator=(const TemperatureSensor& other);
    TemperatureSensor& operator=(TemperatureSensor && other);
    ~TemperatureSensor();

    const std::string& getFactoryId() const;
    int getSetId() const;
    NUMBER getTemperature() const;
    NUMBER getHistory(int index) const;
    int getUniqueId() const;

    static int getCount();
    static const std::string& getClassName();

    void setSetId(int value);
    void setTemperature(NUMBER value);
    void print() const;
    static void print_count();
};

template<typename NUMBER>
int TemperatureSensor<NUMBER>::count = 0;

template<typename NUMBER>
int TemperatureSensor<NUMBER>::uid = 0;

template<typename NUMBER>
const std::string TemperatureSensor<NUMBER>::class_name = "Temperature sensor";

template<typename NUMBER>
std::string TemperatureSensor<NUMBER>::check_factory_id(const std::string& value)
{
    if (value.empty())
    {
        throw std::invalid_argument("поле factory_id не должно быть пустым");
    }
    return value;
}

template<typename NUMBER>
NUMBER TemperatureSensor<NUMBER>::normalize_temperature(NUMBER value)
{
    if (!std::isfinite(static_cast<double>(value)) ||
        value < -273 || value > 1000)
    {
        throw std::out_of_range("Температура должна быть от -273 до 1000");
    }
    return value;
}

template<typename NUMBER>
TemperatureSensor<NUMBER>::TemperatureSensor()
    : factory_id("abc_01"), set_id(0), temperature(0), history(new NUMBER[10]{}), unique_id(++uid) {
    ++count;
    std::cout << "конструктор по умолчанию, count: " << count << "\n";
}

template<typename NUMBER>
TemperatureSensor<NUMBER>::TemperatureSensor(std::string factory_id, int set_id, NUMBER temperature)
    : factory_id(check_factory_id(factory_id)), set_id(set_id),
    temperature(normalize_temperature(temperature)), history(new NUMBER[10]{}), unique_id(++uid) {
    ++count;
    std::cout << "инициализирующий конструктор, count: " << count << "\n";
}

template<typename NUMBER>
TemperatureSensor<NUMBER>::TemperatureSensor(const TemperatureSensor& other)
    : factory_id(other.factory_id), set_id(other.set_id),
    temperature(other.temperature), history(new NUMBER[10]), unique_id(++uid)
{
    for (int i = 0; i < 10; ++i)
    {
        history[i] = other.history[i];
    }

    ++count;
    std::cout << "конструктор копирования, count: " << count << "\n";
}

template<typename NUMBER>
TemperatureSensor<NUMBER>& TemperatureSensor<NUMBER>::operator=(const TemperatureSensor& other)
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

    std::cout << "оператор присваивания, count: " << count << "\n";
    return *this;
}

// конструктор перемещения
template<typename NUMBER>
TemperatureSensor<NUMBER>::TemperatureSensor(TemperatureSensor&& other)
    : factory_id(other.factory_id), set_id(other.set_id),
    temperature(other.temperature), history(other.history), unique_id(++uid) {
    other.history = nullptr;
    other.set_id = 0;
    other.temperature = 0;
    ++count; 
    cout << "конструктор перемещения, count: " << count << "\n";
}

// оператор перемещающего присваивания
template<typename NUMBER>
TemperatureSensor<NUMBER>& TemperatureSensor<NUMBER>::operator=(TemperatureSensor&& other)
{
    if (this != &other)
    {
        delete[] history;
        set_id = other.set_id;
        temperature = other.temperature;
        history = other.history;

        other.history = nullptr;
        other.set_id = 0;
        other.temperature = 0;
    }

    std::cout << "оператор перемещающего присваивания, count: " << count << "\n";
    return *this;
}


template<typename NUMBER>
TemperatureSensor<NUMBER>::~TemperatureSensor()
{
    delete[] history;
    --count;
    std::cout << "деструктор, count: " << count << "\n";
}

template<typename NUMBER>
const std::string& TemperatureSensor<NUMBER>::getFactoryId() const
{
    return factory_id;
}

template<typename NUMBER>
int TemperatureSensor<NUMBER>::getSetId() const
{
    return set_id;
}

template<typename NUMBER>
NUMBER TemperatureSensor<NUMBER>::getTemperature() const
{
    return temperature;
}

template<typename NUMBER>
NUMBER TemperatureSensor<NUMBER>::getHistory(int index) const
{
    if (index < 0 || index >= 10)
    {
        throw std::out_of_range("Неверный индекс (0..9)");
    }
    return history[index];
}

template<typename NUMBER>
int TemperatureSensor<NUMBER>::getUniqueId() const
{
    return unique_id;
}

template<typename NUMBER>
int TemperatureSensor<NUMBER>::getCount()
{
    return count;
}

template<typename NUMBER>
const std::string& TemperatureSensor<NUMBER>::getClassName()
{
    return class_name;
}

template<typename NUMBER>
void TemperatureSensor<NUMBER>::setSetId(int value)
{
    set_id = value;
}

template<typename NUMBER>
void TemperatureSensor<NUMBER>::setTemperature(NUMBER value)
{
    const NUMBER new_temperature = normalize_temperature(value);

    for (int i = 9; i > 0; --i)
    {
        history[i] = history[i - 1];
    }

    history[0] = temperature;
    temperature = new_temperature;
}

template<typename NUMBER>
void TemperatureSensor<NUMBER>::print() const
{
    std::cout << "class: " << class_name << ", factory_id: " << factory_id << ", set_id: " << set_id
        << ", unique_id: " << unique_id << ", temperature: " << temperature << " C\n";
}

template<typename NUMBER>
void TemperatureSensor<NUMBER>::print_count()
{
    std::cout << "count: " << count << "\n";
}

template<typename NUMBER>
std::ostream& operator<<(std::ostream& out, const TemperatureSensor<NUMBER>& sensor)
{
    out << "class: " << TemperatureSensor<NUMBER>::getClassName() << ", count: " << TemperatureSensor<NUMBER>::getCount() << ", factory_id: " << sensor.getFactoryId()
        << ", set_id: " << sensor.getSetId() << ", unique_id: " << sensor.getUniqueId() << ", temperature: " << sensor.getTemperature() << " C";

    return out;
}

template<typename NUMBER>
std::istream& operator>>(std::istream& in, TemperatureSensor<NUMBER>& sensor)
{
    int set_id;
    NUMBER temperature;

    if (in >> set_id >> temperature)
    {
        sensor.setTemperature(temperature);
        sensor.setSetId(set_id);
    }

    return in;
}
