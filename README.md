# TDA-HASH-Algo2-FIUBA

TDA HASH
Se pide implementar una Tabla de Hash abierta (direccionamiento cerrado) en C. Para ello se brindan las firmas de las funciones públicas a implementar y se deja a criterio del alumno la creación de las estructuras y funciones privadas del TDA para el correcto funcionamiento de la Tabla de Hash cumpliendo con las buenas prácticas de programación. La función de Hash a utilizar será interna de la implementación y también debe ser decidida por el alumno. Para esta implementación las claves admitidas por la tabla serán solamente strings. Adicionalmente se pide la creación de un iterador interno que sea capaz de recorrer las claves almacenadas en la tabla.

El TDA entregado deberá compilar y pasar las pruebas dispuestas por la cátedra (Chanutron't) sin errores, adicionalmente estas pruebas deberán ser ejecutadas sin pérdida de memoria.

A modo de ejemplo, se brindará al alumno un archivo simple de ejemplo. Este archivo no es mas que un programa mínimo de ejemplo de utilización del TDA a implementar y es provisto sólo a fines ilustrativos como una ayuda extra para entender el funcionamiento del mismo. No es necesario modificar ni entregar el archivo de ejemplo, pero si la implementación es correcta, debería correr con valgrind sin errores de memoria.

Para la resolución de este trabajo se recomienda utilizar una metodología orientada a pruebas. A tal fin, se incluye un archivo pruebas.c que debe ser completado con las pruebas pertinentes de cada una de las diferentes primitivas del TDA. El archivo de pruebas forma parte de la entrega y por lo tanto de la nota final. Aún mas importante, las pruebas van a resultar fundamentales para lograr no solamente una implementación correcta, si no también una experiencia de desarrollo menos turbulenta.

CONSIDERACIONES PARA LA IMPLEMENTACIÓN
Recuerda que en un hash abierto las colisiones se encadenan.

IMPORTANTE: dos claves idénticas no colisionan.
Tené en cuenta que una inserción con clave repetida produce que un elemento de la tabla se sobreescriba (actualización).

A medida que la tabla se va llenando, la cantidad de colisiones aumenta. Esto produce una degradación en el rendimiento de las operaciones sobre la tabla, sin importar si es abierta o cerrada. Para evitar que esto suceda, tenes que decidir un criterio para decidir en qué momento se debe producir una reorganización y redimensionamiento de la tabla.

Por último, las pruebas de Chanutron't hace pruebas de rendimiento insertando/borrando/consultando muchos elementos en la tabla. Si bien se brinda un tiempo de ejecución máximo generoso, es posible que si la implementación es demasiado ineficiente, no pase todas las pruebas.

CONSEJOS PARA LA ELABORACIÓN DEL TRABAJO
Intente comprender primero el funcionamiento de la tabla y del mecanismo de resolución de colisiones. Utilice lápiz y papel para dibujar algunas tablas y realice varias operaciones de inserción, eliminación y búsqueda. Asegúrese de entender bien cómo se relacionan las operaciones y cómo los datos se almacenan en la tabla antes de comenzar la implementación.

Y como siempre, las recomendaciones generales que no pueden faltar: recuerde que al escribir pruebas no se busca en el código de pruebas la encapsulación ni simplificación de las mismas. No es incorrecto tener pruebas con código repetitivo. Las pruebas son una especificación del comportamiento deseado de las primitivas. Como tal, deben ser fáciles de leer y entender su objetivo.

En general para todo el código: utilice nombres claros de variables y funciones auxiliares. Nombres claros facilitan la comprensión de la implementación (tanto por el implementador como por el corrector). Respete las convenciones de estilo propuestas por la cátedra.

NO escribas código a lo loco sin compilar cada tanto. Implementá la solución de a poco y compilando a cada paso. Dejar la compilación para el final es uno de los peores errores que podés cometer. Para la compilación del trabajo se provee un Makefile. Utilizá el comando make frecuentemente para compilar y correr el programa.

NO avances en la implementación si quedan errores sin resolver en alguna prueba. Cada vez que escribas una prueba implementá toda la funcionalidad necesaria para que funcione correctamente. Esto incluye liberar memoria y accesos inválidos a la misma. Solamente una vez que hayas logrado que la prueba pase exitosamente es que podés comenzar a escribir la próxima prueba para continuar el trabajo.

NO está permitido modificar los archivos .h. Se pueden hacer modificaciones al makefile, pero recordá que el trabajo será compilado por el sistema de entregas con las cabeceras y el makefile original.

ENTREGA
La entrega deberá contar con todos los archivos que se adjuntan (todo lo necesario para compilar y correr correctamente) y las pruebas que demuestran que su implementación funciona. Dichos archivos deberán formar parte de un único archivo .zip el cual será entregado a través de la plataforma de corrección automática Chanutron't.

El archivo comprimido deberá contar, además de los archivos del TDA, con un informe que contenga la siguiente información:

Explicá teóricamente (y por favor usando diagramas):
Qué es un diccionario
Qué es una función de hash y qué características debe tener
Qué es una tabla de Hash y los diferentes métodos de resolución de colisiones vistos (encadenamiento, probing, zona de desborde)
CRITERIOS MÍNIMOS DE CORRECCIÓN
GENERAL
 Cada malloc tiene su verificación
 Libera(cierra) memoria(archivos) en los casos de error
 Reallocs sobre punteros auxiliares
 No hay fragmentos de código comentado sin usar
 No hay printfs donde no es necesario
 Los entregables compilan y corren sin error
Si se entrega makefile, debe funcionar correctamente.
Si no se entrega makefile, debe especificarse cómo compilar y correr.
 Verifica los punteros recibidos en las funciones públicas
 No hay variables globales
 No reserva memoria cuando no es necesario
 Usa constantes y tienen sentido.
ESTILO
 El estilo es el apropiado
 Los nombres de función me dicen lo que hacen
 No hay variables con nombre confuso
PRUEBAS
 Corren sin error y pasan
 Son fáciles de leer y entender qué hacen
 Cantidad razonable
Si prueba lo necesario no importa que sean pocas
Si son excesivas sin motivo no es bueno
 No hace printf para verificar el resultado visualmente
HASH
 Se inicializa la capacidad como pide el enunciado.
 Se implementa el rehash.
 Al hacer rehash se aumenta el tamaño de la tabla a no mas del doble.
 La función de hash es independiente del tamaño de la tabla.
LISTA DE VERIFICACIÓN DE PRUEBAS DE HASH RECOMENDADAS POR ABRIL
2.1 CREACIÓN
 Se prueba crear el hash con una capacidad inicial mayor a 3
 Se prueba crear el hash con una capacidad inicial menor a 3
2.2 INSERCIÓN
 Se prueba insertar en un hash nulo
 Se prueba insertar una clave nula en un hash válido
 Se prueba insertar un elemento nulo con clave válida en un hash válido
 Se prueba insertar un elemento con clave válida en un hash válido
 Se prueba insertar varios elementos
 Se prueba insertar varios elementos y causar un rehash
 Se prueba actualizar un elemento y guardar su valor anterior en anterior
 Se prueba actualizar un elemento, enviando NULL en anterior
2.3 ELIMINACIÓN
 Se prueba quitar de un hash nulo
 Se prueba quitar una clave nula
 Se prueba quitar un elemento que no existía
 Se prueba quitar un elemento que sí existía
 Se prueba quitar un elemento que sí existía, y luego quitarlo de nuevo
2.4 OBTENCIÓN
 Se prueba obtener de un hash nulo
 Se prueba obtener una clave nula
 Se prueba obtener una clave que no se encuentra en el hash
 Se prueba obtener una clave que sí se encuentra en el hash
 Se prueba obtener una calve que sí se encuentra en el hash, quitarla, y luego verificar que ya no se encuentra
2.5 CANTIDAD
 Se prueba obtener la cantidad de elementos de un hash nulo
 Se prueba obtener la cantidad de elementos de un hash vacío
 Se prueba obtener la cantidad de elementos de un hash con elementos
2.6 CONTENER
 Se prueba verificar si un hash nulo contiene la clave pasada
 Se prueba verificar si un hash vacío contiene la clave pasada
 Se prueba verificar si un hash con elementos contiene una clave que se encuentra en el hash
 Se prueba verificar si un hash con elementos contiene una clave que no se encuentra en el hash
 Se prueba verificar si un hash con elementos contiene una clave nula
2.7 ITERADOR INTERNO
 Se prueba iterar un hash nulo
 Se prueba iterar un hash vacío
 Se prueba iterar un hash con elementos con una función nula
 Se prueba iterar un hash con elementos con un auxiliar nulo
 Se prueba iterar un hash con elementos en su totalidad
 Se prueba iterar un hash deteniéndose antes de terminar de visitar todos los elementos
