
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALMACEN 10

typedef struct //Estructuras anidadas, primero hay que poner la que vas a usar despues para que se lea 
{
	int dia; 
	int mes;
	int ano; 
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
} contrasena;

char menu (char opcion);
void buscarobra (char buscarnombre[20], char buscarcodigo[20]);

int main()
{
	//Primeras llamadas 
	int i;
	int opcion;
	int num; //numero de obras a registrar
	datosobra *obra; //puntero para introducir los datos de las obras, esto ira en un archivo 
					//Futura modificación 
	int buscar;
	char buscarnombre[20], buscarcodigo[8]; 
	
	
	opcion = menu(opcion);//llamamos a la opcion menu 
	//empezamos el switch para el menu

	do
	{	
		switch(opcion)
		{
			case 1: //registrar obra se puede hacer mas de una a la vez 
				printf("Ha seleccionado la opcion Registrar Obras\n");
				
				printf("Introduzca el numero de obras que desea registrar: ");
				scanf("%d", &num);
					
				obra = (datosobra *) malloc(num * sizeof(datosobra));
				
				for(i=0; i<num; i++)
				{
					fflush(stdin);
					printf("Nombre de la %d obra: \n", i+1);
					gets(obra[i].nombreobra);
					printf("Autor de la %d obra: \n", i+1);	
					gets(obra[i].autor);
					printf("e -> Escultura \n p -> Pintura \n"); //Tiene que introducirse solo una de las opciones  
					scanf("%c", &obra[i].tipo);
					printf("Fecha de creacion: \n");
					scanf("%d %d %d", &obra[i].creacion.dia, &obra[i].creacion.mes, &obra[i].creacion.ano); 
					printf("Fecha de adquisición: \n");
					scanf("%d %d %d", &obra[i].adquisicion.dia, &obra[i].adquisicion.mes, &obra[i].adquisicion.ano);
					//El programa debe registrar el codigo
					/*obra[i].codigo = i+1; No sirve */
					
				}//Hay que meter todos estos datos en el archivo registrodeobras.txt
				
				if(num==1)	printf("Su obra ha sido registrada correctamente\n");
				
				else  // No hay espacio disponible
				printf ("No hay espacio disponible para esta obra\n");
			
			
			case 2: //Buscar las obras tanto por codigo como por nombre
				printf("Ha seleccionado la opcion buscar obra\n");
				printf("Indique si desea buscar por nombre (1) o por codigo (2): \n");
				scanf("%d", &buscar);
				
				if(buscar == 1) //Buscador por nombre
				{
					printf("Introduzca el nombre de la obra: \n");
					gets(buscarnombre);
					buscarobra (buscarnombre, buscarcodigo); //Llamar a la funcion buscar 
				} 
				
				if(buscar == 2) //Buscador por codigo
				{
					printf("Introduzca el codigo de la obra: \n");
					gets(buscarcodigo);
					buscarobra (buscarnombre, buscarcodigo); //llamar a la funcion buscar
					
				}
				
				else 
				{
					printf("Opcion incorrecta");
					return 1; //Buscar el numero para volver al menu
				}
				
			case 3: //Eliminar obra indicando si es prestamo o vendido
			/*Si la obra ha sido prestada puede guardarse como prestamo, pero si se h avendido 
			eliminar totalmente del registro*/
			
			//Abrir archivo solo modificacion 
			
			printf("Ha elegido la opcion Retirar Obra\n");
			printf("Indique si desea eliminar(1) o prestar(2) la obra: \n");
			scanf("%d", &retirar);
			
			if(retirar==1)
			{
				printf("Indique el codigo de la obra que desea eliminar: \n"); //Se eliminará del archivo
				scanf("%d", &obra.codigo);
				if()//Buscar si existe el archivo
				{
					
				}
				else
					printf("La obra seleccionada no existe\n");
			}
		
			if(retirar==2)
			{
				printf("Indique el codigo de la obra que desea prestar: \n");
				scanf("%d", &obra.codigo);
				if()//Buscar si existe el archivo
				{
					//Modificar entre parentesis al lado del nombre (PRESTAMO)
				}
				else
					printf("La obra seleccionada no existe\n");
			}
			
			return 1;
			
			case 4: //listado de obras 
			/*mostrar de dos formas:
			1. orden cronologico por orden de antiguedad
			2.orden cronologico por orden de adquisicion */
			int opcionlistado;
			
			printf("Ha elegido la opcion Listado de obras\n Indique el orden: \n");
			pritnf("1. Orden cronologico por antiguedad\n");
			printf("2. Orden cronologico por adquisicion\n");
			scanf("%d", &opcionlistado);
			
			if(opcionlistado==1)
			{
				
			}
			
			if(opcionlistado==2)
			{
				
			}
				
			return 1;
				
			case 5://almacen 
			/*Muestra el total de elementos puedes elegir tres opciones: 
			1. si quieres que te enseñe todo sin diferenciar p o e pero que lo indique
			2. si quieres solo las p
			3. si quieres solo las e */
			printf("Ha elegido la opcion ver almacen\n Indique que desea ver:\n");
			
			int opcionalmacen;
			
			printf("1. Mostrar todas las obras\n");
			printf("2. Mostrar todas las pinturas\n");
			printf("3. Mostrar todas las esculturas\n");
			scanf("%d", %opcionalmacen);
			
			if(opcionalmacen==1)
			{
				prinf("Estas son las obras que se encuentran disponibles en nuestro almacen:\n");
				for(i=0; i<ALMACEN; i++)
				{
					printf("Nombre: &s", obra[i].nombreobra);
					printf("Codigo: %d", obra[i].codigo);
					printf("Tipo: e -> escultura, p -> pintura: %c", obra[i].tipo);
				}
			}
			
			if(opcionalmacen==2)
			{
				printf("Estas son las pinturas que disponemos en el almacen:\n");
				while ()//solo tipo p
			}
			
			if(opcionalmacen==3)
			{
				printf("Estas son las esculturas que disponemos en el almacen:\n");
				while ()//solo tipo e
			}
			return 1;
				
			case 6:
				return 0; //Buscar numero para salir del programa 	
				
			default printf("Opcion incorrecta\n");	
			
		}
	} while(1);

	system("pause");
	return 0;
	
}

char menu (char opcion)
{
	printf("Bienvenido al MENU DE OPCIONES del Museo del Prado.\n ");
	printf ("Por favor seleccione una de las siguientes opciones: \n");
	printf("1. Registrar obra\n");
	printf("2. Buscar obra\n");
	printf("3. Retirar obra\n");
	printf("4. Listado de obras\n");
	printf("5. Almacén\n");
	printf("6. Salir\n");
	//default printf("Opcion incorrecta");
	scanf ("%c", &opcion);
	while (getchar() != '\n');
	return opcion;	
}

