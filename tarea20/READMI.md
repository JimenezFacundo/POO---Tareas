# Ejercicio 20: Herencia y Polimorfismo con Instrumentos

## Descripción

Crear una clase base llamada **Instrumento** y las clases derivadas **Guitarra**, **Bateria** y **Teclado**.

## Requisitos

- La clase base **Instrumento** tiene una función virtual pura llamada `sonar()`.
- Definir una función virtual `verlo()` que publique la marca del instrumento.  
  Por defecto, todos los instrumentos son de la marca **Yamaha**.
- En la función `main()`, usar un `std::vector` para almacenar punteros a objetos del tipo **Instrumento**.  
  Instanciar 5 objetos y agregarlos al vector.  
  Publicar la marca de cada instrumento recorriendo el vector.
- En las clases derivadas agregar los datos miembro:  
  - `int cuerdas` para **Guitarra** (por defecto 6 cuerdas)  
  - `int teclas` para **Teclado** (por defecto 61 teclas)  
  - `int tambores` para **Bateria** (por defecto 5 tambores)
- La clase **Teclado** debe tener herencia múltiple, heredando además de una nueva clase **Electrico**.  
  Todos los equipos tipo "Electrico" tienen por defecto un voltaje de 220 volts.  
  La clase **Electrico** debe tener un destructor que al destruirse publique la leyenda `"Desenchufado"`.
- Al llamar a la función `sonar()` se debe publicar:  
  - `"Guitarra suena..."`  
  - `"Teclado suena..."`  
  - `"Batería suena..."` según corresponda.
- Incluir los métodos `get` y `set` que se consideren convenientes.
