# 🧾 Tarea 3 - Clase Inventada y Consumo Controlado de Memoria

## 📌 Descripción

Este ejercicio propone inventar una clase propia (diferente a `Persona`, `Cliente` o `Poste`), crear objetos de esa clase, y almacenarlos en un vector hasta alcanzar un consumo aproximado de **200 MB de memoria RAM**.

Se debe calcular cuántos objetos se pueden almacenar antes de superar el límite.

---

## 💡 Objetivos

- Inventar una clase con atributos adecuados para generar objetos con cierto peso en memoria.
- Usar constructores para inicializar objetos.
- Almacenar objetos en un `std::vector`.
- Calcular y controlar el uso de memoria de forma estimada.
- Mostrar la cantidad máxima de objetos almacenados sin superar los 200 MB.

---

## 🧱 Clase definida (Ejemplo: `Archivo`)

```cpp
class Archivo {
private:
    std::string nombre;
    char contenido[1024 * 50]; // 50 KB por objeto
public:
    Archivo(const std::string& nom);
    std::string getNombre() const;
};
