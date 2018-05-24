typedef struct //Estructuras anidadas, primero hay que poner la que vas a usar despues para que se lea 
{
	int dia; 
	char mes;
	int año; 
} fecha;
 
typedef struct 
{
	int codigo[8]; //debe tener una longitud de ocho digitos solo numeros 
	char nombreobra[30];
	char autor[30];
	char tipo[10]; //escultura o pintura 
	fecha creacion;
	fecha adquisicion;
} datosobra;

typedef struct //para comprobar si es valido el usuario 
{
	char usuario[30];
	char clave[20];
} contraseña;
