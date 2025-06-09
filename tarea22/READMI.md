# Ejercicio 22: Inline en acción — Simulador de Sensor Inteligente

## Descripción

Implementar una clase que simule un sensor, aplicando funciones frecuentes tanto en versión inline como offline, y comparar el rendimiento al ejecutar esas funciones millones de veces.

---

## Parte 1: Diseño de la clase Sensor

### Atributos

- `int valorActual`  
  Puede inicializarse con un valor aleatorio entre 0 y 1023.

### Métodos

- `int getValorBruto()`  
  Devuelve el valor actual sin modificar. Definir dentro de la clase (inline implícito).

- `int getValorBrutoOffline()`  
  Igual que el anterior, pero definir fuera de la clase sin usar inline (función normal).

- `double getValorNormalizado()`  
  Devuelve `valorActual / 1023.0`. Definir como inline explícito.

- `double getValorNormalizadoOffline()`  
  Igual que el anterior, pero sin inline.

---

## Parte 2: Benchmark de rendimiento (Prueba de rendimiento)

Utilizar `QElapsedTimer` para medir el tiempo de ejecución de:

- Ejecutar 10 millones de veces la llamada a `getValorBruto()`.
- Ejecutar 10 millones de veces la llamada a `getValorBrutoOffline()`.
- Ejecutar 10 millones de veces la llamada a `getValorNormalizado()`.
- Ejecutar 10 millones de veces la llamada a `getValorNormalizadoOffline()`.

Mostrar los tiempos en consola con `qDebug()`.
