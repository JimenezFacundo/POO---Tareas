# Ejercicio 19 - Simulacro de Parcial: Gestión de Medicamentos por Obra Social

Desarrollar una aplicación de escritorio con C++ y Qt que permita gestionar las cajas de medicamentos entregadas a una única obra social (por ejemplo: "APROSS"), respetando un límite máximo de 1000 dosis en total.

La aplicación debe ser realizada únicamente con **QWidget** (no usar **QMainWindow**), y debe almacenar la información en una base de datos **SQLite**. La clase que gestiona la base de datos (**AdminDB**) debe implementarse como singleton.

---

## Requisitos

### Clase CajaMedicamento

**Atributos:**
- `int id` → autogenerado por la base de datos
- `float dosisTotales`

**Métodos:**
- Constructor para crear una nueva caja (sin ID)
- Constructor para cargar una caja desde la base (id, dosis)
- `CajaMedicamento operator+(const CajaMedicamento & otra) const` → suma de dosis
- `bool operator==(const CajaMedicamento & otra) const` → compara si tienen misma cantidad de dosis
- `QString toString() const` → retorna una cadena del estilo:  
  `CajaMedicamento [ID: 4, Dosis: 250.0]`

### Clase AdminDBMedicamentos (singleton)

**Métodos requeridos:**
- `void conectar();`
- `bool insertarCaja(float dosis);` → solo si la suma total no excede 1000
- `QList<CajaMedicamento> obtenerTodas();`
- `float obtenerTotalDosis();`

---

## Base de datos SQLite

Tabla `cajas_medicamentos` con la siguiente estructura:

```sql
CREATE TABLE cajas_medicamentos (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  dosis_totales REAL NOT NULL
);
