
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALMACEN 12

typedef struct 
{
	int codigo[8]; //debe tener una longitud de ocho digitos solo numeros 
	char nombreobra[30];
	char autor[30];
	char tipo[10]; //escultura o pintura 
	int creacion;
	int adquisicion;
} datosobra;

typedef struct
{
	char usuario[25];
	char clave[20];
}	contrasena;

char menu ();
int existeUsuario(contrasena usuarioValido[], char nombre[], char clave[]);


int main()
{
	//Primeras llamadas 
	int i;
	int opcion;
	int num; //numero de obras a registrar
	datosobra *obra; //puntero para introducir los datos de las obras, esto ira en un archivo 
					//Futura modificación 
	int buscar;
	char buscarnombre[20], buscarautor[20]; 
	FILE *pf;
	
	//Contraseña para entrar
	contrasena autorizado [3], acceso;
	int contador = 0;
	int valido;
	strcpy (autorizado[0].usuario, "Adela"); 	strcpy (autorizado[0].clave, "53531");
	strcpy (autorizado[1].usuario, "Idoya"); 	strcpy (autorizado[1].clave, "53632");
	strcpy (autorizado[2].usuario, "Claudia"); 	strcpy (autorizado[2].clave, "53382");
	strcpy (autorizado[3].usuario, "Patricia"); strcpy (autorizado[3].clave, "53370");
	strcpy (autorizado[4].usuario, "Elvira"); 	strcpy (autorizado[4].clave, "53576");
	
	do
	{
		if (contador == 3) return 666;
		printf ("\nIndique su nombre de usuario y su contrasena:  ");
		scanf ("%s %s", acceso.usuario, acceso.clave);
		while (getchar() != '\n');

		valido = existeUsuario(autorizado, acceso.usuario, acceso.clave);

		contador++;
	}	while (valido != 0);
	
	
	opcion = menu();//llamamos a la opcion menu 
	//empezamos el switch para el menu

	do
	{	
		switch(opcion)
		{
			case 1: //registrar obra se puede hacer mas de una a la vez 
				system ("cls");
				printf("Ha seleccionado la opcion Registrar Obras\n");
				
				printf("Introduzca el numero de obras que desea registrar: ");
				scanf("%d", &num);
					
				obra = (datosobra *) malloc(num * sizeof(datosobra));
				pf=fopen ("registrodeobras.txt","a+");
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
					scanf("%d", &obra[i].creacion); 
					printf("Fecha de aquisición: \n");
					scanf("%d",  &obra[i].adquisicion);					
				}
				while (fscanf(pf, "%d", &obra[i].codigo)!=EOF)
				{
					fprinf("%d %s %s %c %d %d", obra[i].codigo, obra[i].nombreobra,obra[i].autor, obra[i].tipo, 
												obra[i].creacion, obra[i].adquisicion);
				}
				fclose(pf);
				
				if(num==1)	printf("Su obra ha sido registrada correctamente\n");
				else		printf("Sus obras han sido registradas correctamente\n");
				
		//	if () // No hay espacio disponible
		//		printf ("No hay espacio disponible para esta obra\n");
			
			
			case 2: //Buscar las obras tanto por autor como por nombre
				system ("cls");
				printf("Ha seleccionado la opcion buscar obra\n");
				printf("Indique si desea buscar por nombre (1) o por autor (2): \n");
				scanf("%d", &buscar);
				
				pf= fopen("registrodeobras.txt", "r");
				
				if(buscar == 1) //Buscador por nombre
				{
					printf("Introduzca el nombre de la obra: \n");
					gets(buscarnombre);
					while(fscanf(pf, "%d %s %s %c %d %d", &obra->codigo, obra->nombreobra, obra->autor, obra->tipo, 
												&obra->creacion, &obra->adquisicion)!=EOF)
					{									
						if(buscarnombre==obra->nombreobra)
						{
							printf("");
							fclose(pf);
							return;
						}
						else
							printf("No se ha encontrado la obra\n");
							fclose(pf);
							return;
					}
				
				if(buscar == 2) //Buscador por autor
				{
					printf("Introduzca el autor de la obra: \n");
					gets(buscarautor);
					while(fscanf(pf, "%d %s %s %c %d %d", &obra->codigo, obra->nombreobra, obra->autor, obra->tipo, 
														&obra->creacion, &obra->adquisicion)!=EOF)
					{									
						if(buscarautor==obra->autor)
						{
							printf("");
							fclose(pf);
							return;
						}
						else
							printf("No se ha encontrado la obra\n");
							fclose(pf);
							return;
					}
					
				}
							
			case 3: //Eliminar obra por nombre de la obra
			system ("cls");
			printf("Ha elegido la opcion Retirar Obra\n");
			int retirar;
			printf("Indique el nombre de la obra que desea retirar: \n");
			scanf("%d", &retirar);
			
			pf=fopen ("registrodeobras.txt","w"); //Se recrea el archivo asi que hay que volver a guardarlo todo pero 
			//sin los datos borrados hasta el momento
			
			while(fscanf(pf, "%d %s %s %c %d %d", &obra->codigo, obra->nombreobra, obra->autor, obra->tipo, 
														&obra->creacion, &obra->adquisicion)!=EOF)
			{									
				if(retirar==obra->nombreobra)
				{
					//Borrar la obra, como?? -> probar guardar espacios donde antes habia letras 
					printf("Se ha retirado correctamente la obra.\n");
					fclose(pf);
					return;
				}
				else
					printf("No se ha encontrado la obra\n");
					fclose(pf);
					return;
			}	
			
			case 4: //listado de obras 
			//mostrar de dos formas:
			//1. orden cronologico por orden de antiguedad
			//2.orden cronologico por orden de adquisicion 
			system ("cls");		
			printf("Ha elegido la opcion Listado de obras\n Indique el orden: \n");
			int opcionlistado;
			pritnf("1. Orden cronologico por antiguedad\n");
			printf("2. Orden cronologico por adquisicion\n");
			scanf("%d", &opcionlistado);
			
			pf = fopen("registrodeobras.txt", "r");
			
			if(opcionlistado==1)
			{
			//metodo burbuja para ordenar los años
			
		
			}
			
			if(opcionlistado==2)
			{
			//metodo burbuja para ordenar los años 
			
	
			}
			
				
			case 5://almacén 
			system ("cls");
			printf ("La opcion elegida es ver la cantidad de esculturas y pinturas en el almacen.\n");
			totalpinturas = 0;
			totalesculturas = 0;

				
			case 6:
				return 0; //Buscar numero para salir del programa 	
				
			default printf("Opcion incorrecta\n");	
			
		}
	} while(1); 

	system("pause");
	return 0;
	
}
int existeUsuario(contrasena usuarioValido[], char nombre[], char clave[])
{
	int valido, i;
	for (i = 0; i < 3; i++)
		{
			valido = strcmp (usuarioValido[i].usuario, nombre) ||
									strcmp (usuarioValido[i].clave, clave); 
			if (valido == 0) break;
		}
	return valido;
}

char menu ()
{
	char opcion;
	system ("cls");
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


