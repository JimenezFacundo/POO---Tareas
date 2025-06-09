# 🧾 Tarea 1 - Clase Poste y Ordenamiento por Altura

## 📌 Descripción

Este ejercicio consiste en definir una clase `Poste` con atributos simples, almacenar varios objetos en un vector, ordenarlos por un criterio específico (altura), y mostrar los resultados antes y después del ordenamiento.

> Se trabajó exclusivamente con clases, funciones y estructuras básicas vistas hasta el momento en la asignatura.

---

## 💡 Objetivos

- Definir una clase simple con atributos privados.
- Crear y manipular un `std::vector` de objetos.
- Implementar una función de ordenamiento.
- Practicar el uso de `iostream` y `std::sort`.
- Reforzar el encapsulamiento y acceso a atributos mediante métodos.

---

## 📦 Archivos

- `main.cpp`: contiene la definición de la clase `Poste`, el vector de objetos, carga de datos, ordenamiento y salida por consola.

---

## 🧱 Clase definida

```cpp
class Poste {
private:
    int altura;        // Altura en metros
    float diametro;    // Diámetro en centímetros
public:
    Poste(int h, float d);
    int getAltura() const;
    float getDiametro() const;
    void mostrar() const;
};
