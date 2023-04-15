#include "src/hash.h"
#include "pa2m.h"
#include <string.h>

unsigned long prueba_funcion_hash(const char *string){

	if(!string)
		return 0;

	unsigned long resultado_hash = 5381;
	int c;

	while((c = *(string++))){
		resultado_hash = ((resultado_hash << 5) + resultado_hash + (unsigned long)c);
	}
	return resultado_hash;
}

bool funcion(const char *algo, void *valor, void *aux){
	return true;
}

bool comparar(const char *algo, void *valor, void *aux){
	if(strcmp(algo, "Matias") == 0)
		return false;
	return true;
}

bool mostrar_clave(const char *clave, void *valor, void *aux){
	if (!clave)
	return false;
	
	aux = aux;
	
	return true;
	}

void proxima_clave(char *c){

	c[0]++;
	if (c[0] == 'z' + 1) {
		c[0] = '0';
		proxima_clave(c + 1);
	}
}

void crear_un_hash(){
	
	hash_t *hash = hash_crear(0);

	pa2m_afirmar(hash != NULL, "Puedo crear un hash enviandole capacidad MENOR al minimo(3)");
	pa2m_afirmar(hash_cantidad(hash) == 0, "Creo un hash y está vacío");

	hash_destruir(hash);

	hash = hash_crear(5);
	pa2m_afirmar(hash != NULL, "Puedo crear un hash enviandole una capacidad MAYOR al minimo(3)");
	
	hash_destruir(hash);
	}
	
void insertar_elementos(){
	
	hash_t *hash = hash_crear(3);
	void *anterior = NULL;

	pa2m_afirmar(hash_insertar(NULL, "Algo", "Otro algo", &anterior) == NULL, "No es posible insertar elementos en un hash nulo");
	pa2m_afirmar(hash_insertar(hash, NULL, "Otro algo", &anterior) == NULL, "No es posible insertar elementos con una clave nula");

	pa2m_afirmar(hash_insertar(hash, "AC123BD", "Auto de Mariano", &anterior) != NULL, "Inserto un elemento correctamente.");
	pa2m_afirmar(hash_cantidad(hash) == 1, "El hash tiene un elemento.");
	
	pa2m_afirmar(hash_insertar(hash, "OPQ976", "Auto de Lucas", &anterior) != NULL, "Inserto un segundo elemento correctamente.");
	pa2m_afirmar(hash_cantidad(hash) == 2, "El hash tiene dos elementos.");
	
	pa2m_afirmar(hash_insertar(hash, "A421ACB", "Moto de Manu", &anterior) != NULL, "Inserto un tercer elemento correctamente.");
	pa2m_afirmar(hash_cantidad(hash) == 3, "El hash tiene tres elementos.");
	
	pa2m_afirmar(hash_insertar(hash, "AA442CD", "Auto de Guido", &anterior) != NULL, "Inserto un cuarto elemento correctamente.");
	pa2m_afirmar(hash_cantidad(hash) == 4, "El hash tiene cuatro elementos.");
	
	pa2m_afirmar(hash_contiene(hash, "AC123BD") == true, "Busco un elemento por su clave y lo encuentro.");
	
	pa2m_afirmar(hash_contiene(hash, "OPQ976") == true, "Busco un segundo elemento por su clave y lo encuentro.");
	
	pa2m_afirmar(hash_contiene(hash, "A421ACB") == true, "Busco un tercer elemento por su clave y lo encuentro.");
	
	pa2m_afirmar(hash_contiene(hash, "AA442CD") == true, "Busco un cuarto elemento por su clave y lo encuentro.");
	
	pa2m_afirmar(hash_insertar(hash, "AC123BD", "Auto de Mariano", &anterior) != NULL, "Inserto un elemento con clave repetida correctamente.");
	pa2m_afirmar(strcmp(anterior, "Auto de Mariano") == 0 , "Se guarda en anterior el valor anterior del elemento reemplazado");
	pa2m_afirmar(hash_cantidad(hash) == 4, "El hash sigue teniendo la misma cantidad de elementos.");

	pa2m_afirmar(hash_insertar(hash, "AC152AD", "Auto de Agustina", &anterior) != NULL, "Inserto un elemento con clave repetida correctamente.");
	pa2m_afirmar(hash_cantidad(hash) == 5, "El hash sigue teniendo la misma cantidad de elementos.");
	pa2m_afirmar(hash_contiene(hash, "AC152AD"), "Busco el elemento por su clave y lo encuentro.");

	pa2m_afirmar(hash_insertar(hash, "AC152AD", "Auto de Agustina", NULL) != NULL && anterior == NULL, 
		"Al insertar una clave repetida con un anterior nulo, se puede insertar el elemento pero no se guarda el valor anterior");
	
	hash_destruir_todo(hash, NULL);
}

void insertar_multiples_elementos(){

	hash_t *hash = hash_crear(3);

	char clave[4] = {'1','1','1', 0};

	for( int i = 0; i < 5000; i++){
		hash_insertar(hash, clave, (void*)i, NULL);
		proxima_clave(clave);
	}

	pa2m_afirmar(hash_cantidad(hash) == 5000, "Se insertan 5000 elementos correctamente (sin repetir)");

	for( int i = 0; i < 5000; i++){
		hash_insertar(hash, "CLAVE IDENTICA", (void*)i, NULL);
		proxima_clave(clave);
	}

	pa2m_afirmar(hash_cantidad(hash) == 5001, "Se insertan otros 5000 elementos con claves iguales entre si y el tamaño solo aumenta en uno");
	pa2m_afirmar(hash_con_cada_clave(hash, funcion, NULL) == hash_cantidad(hash), "El iterador aplica la funcion a todos los elementos");

	hash_destruir( hash);
}

void quitar_elementos(){

	hash_t *hash = hash_crear(3);
	void *anterior = NULL;

	pa2m_afirmar(hash_quitar(NULL, "AC123BD") == NULL, "No puedo quitar un elemento de un hash inexistente");
	pa2m_afirmar(hash_quitar(hash, NULL) == NULL, "No puedo quitar un elemento si la clave es nula");

	hash_insertar(hash, "AC123BD", "Auto de Mariano", &anterior);
	hash_insertar(hash, "OPQ976", "Auto de Lucas", &anterior);
	hash_insertar(hash, "A421ACB", "Moto de Manu", &anterior);
	
	pa2m_afirmar( strcmp(hash_quitar(hash, "AC123BD"),"Auto de Mariano") == 0 && hash_cantidad(hash) == 2, "Al eliminar un elemento, la cantidad de elementos ocupados se reduce en uno");
	pa2m_afirmar( hash_cantidad(hash) == 2, "Al eliminar un elemento, la cantidad de elementos ocupados se reduce en uno");

	pa2m_afirmar( hash_quitar(hash, "AC123BD") == NULL && hash_cantidad(hash) == 2, "No puedo eliminar un elemento que ya fue eliminado");
	pa2m_afirmar( hash_quitar(hash, "Alguna palabra") == NULL && hash_cantidad(hash) == 2, "No puedo eliminar un elemento que no existe");

	hash_quitar(hash, "OPQ976");
	hash_quitar(hash, "A421ACB");
	pa2m_afirmar( hash_cantidad(hash) == 0, "Al eliminar todos los elementos, la cantidad de elementos ocupados es cero");
	pa2m_afirmar(hash_quitar(hash, "OPQ976") == NULL, "Al eliminar un elemento que no existe, la funcion quitar devuelve NULL");

	hash_destruir(hash);
}

void iterador_interno(){

	hash_t *hash = hash_crear(3);
	void *anterior = NULL;

	pa2m_afirmar(hash_con_cada_clave(NULL,funcion,anterior) == 0, "No puedo recorrer un hash inexistente");
	pa2m_afirmar(hash_con_cada_clave(hash,funcion,anterior) == 0, "No puedo recorrer una tabla vacia");
	pa2m_afirmar(hash_con_cada_clave(hash, NULL, anterior) == 0, "No puedo aplicar una funcion NULA a los elementos");

	hash_insertar(hash, "AC123BD", "Auto de Mariano", &anterior);
	hash_insertar(hash, "OPQ976", "Auto de Lucas", &anterior);
	hash_insertar(hash, "A421ACB", "Moto de Manu", &anterior);
	hash_insertar(hash, "AA442CD", "Auto de Guido", &anterior);
	hash_insertar(hash, "AC152AD", "Auto de Agustina", &anterior);

	pa2m_afirmar(hash_con_cada_clave(hash, funcion, anterior) == hash_cantidad(hash), "Se invoca a la funcion la cantidad de claves esperadas");

	hash_destruir(hash);
}

void cantidad_elementos(){

	hash_t *hash = hash_crear(3);
	void *anterior = NULL;

	pa2m_afirmar( hash_cantidad(NULL) == 0 ,"La cantidad de elementos en un hash nulo es cero");
	pa2m_afirmar( hash_cantidad(hash) == 0,"La cantidad de elementos en un hash vacio es cero");

	hash_insertar(hash, "AC123BD", "Auto de Mariano", &anterior);
	hash_insertar(hash, "OPQ976", "Auto de Lucas", &anterior);
	hash_insertar(hash, "A421ACB", "Moto de Manu", &anterior);
	hash_insertar(hash, "AA442CD", "Auto de Guido", &anterior);
	hash_insertar(hash, "AC152AD", "Auto de Agustina", &anterior);

	pa2m_afirmar( hash_cantidad(hash) == 5,"La cantidad de elementos es la correcta");

	hash_destruir(hash);
}

void obtener_elementos(){

	hash_t *hash = hash_crear(3);
	void *anterior = NULL;

	pa2m_afirmar( hash_obtener(NULL, "Algo") == NULL,"No puedo buscar elementos en un hash inexistente");
	pa2m_afirmar( hash_obtener(hash, "Algo") == NULL,"No puedo buscar elementos en un hash vacio");

	hash_insertar(hash, "AC123BD", "Auto de Mariano", &anterior);
	hash_insertar(hash, "OPQ976", "Auto de Lucas", &anterior);
	hash_insertar(hash, "A421ACB", "Moto de Manu", &anterior);
	hash_insertar(hash, "AA442CD", "Auto de Guido", &anterior);
	hash_insertar(hash, "AC152AD", "Auto de Agustina", &anterior);

	pa2m_afirmar( strcmp(hash_obtener(hash, "AC123BD"), "Auto de Mariano") == 0 , "Si la clave existe, la funcion devuelve el elemento correspondiente");
	pa2m_afirmar( hash_obtener(hash, "Algo") == 0 , "Si la clave no existe, la funcion devuelve NULL");

	hash_destruir(hash);
}

void contener_elementos(){

	hash_t *hash = hash_crear(3);
	void *anterior = NULL;

	pa2m_afirmar( hash_contiene(NULL, "Algo") == false,"No puedo buscar elementos en un hash inexistente");
	pa2m_afirmar( hash_contiene(hash, "Algo") == false,"No puedo buscar elementos en un hash vacio");

	hash_insertar(hash, "AC123BD", "Auto de Mariano", &anterior);
	hash_insertar(hash, "OPQ976", "Auto de Lucas", &anterior);
	hash_insertar(hash, "A421ACB", "Moto de Manu", &anterior);
	hash_insertar(hash, "AA442CD", "Auto de Guido", &anterior);
	hash_insertar(hash, "AC152AD", "Auto de Agustina", &anterior);

	pa2m_afirmar( hash_contiene(hash, "Algo") == false, "Si la clave NO se encuentra, la funcion devuelve false");
	pa2m_afirmar( hash_contiene(hash, "AC123BD") == true, "Si la clave se encuentra, la funcion devuelve true");

	hash_destruir(hash);
}

int main(){
	
	pa2m_nuevo_grupo("Pruebas de creacion de hash");
	crear_un_hash();
	
	pa2m_nuevo_grupo("Pruebas de insertar");
	insertar_elementos();

	pa2m_nuevo_grupo("Pruebas de insertar MUCHOS elementos");
	insertar_multiples_elementos();

	pa2m_nuevo_grupo("Pruebas de quitar elementos");
	quitar_elementos();

	pa2m_nuevo_grupo("Pruebas de iterador interno");
	iterador_interno();

	pa2m_nuevo_grupo("Pruebas de funcion contener");
	contener_elementos();

	pa2m_nuevo_grupo("Pruebas de funcion obtener");
	obtener_elementos();

	pa2m_nuevo_grupo("Pruebas de funcion cantidad");
	cantidad_elementos();
	
	return pa2m_mostrar_reporte();
}