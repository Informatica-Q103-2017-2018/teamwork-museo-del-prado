#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int codigo; //debe tener una longitud de ocho digitos solo numeros 
	char nombreobra[30];
	char autor[30];
	char tipo; //escultura o pintura 
	int creacion;
	int adquisicion;
} datosobra;

typedef struct
{
	char usuario[25];
	char clave[20];
} contrasena;

void menu ();
int existeUsuario(contrasena usuarioValido[], char nombre[], char clave[]);

int main()
{
	//Primeras llamadas 
	int i, j;
	int opcion;
	datosobra *obra; //puntero para introducir los datos de las obras, esto ira en un archivo 		
	int buscar;
	char repetir[2];
	char buscarnombre[20], buscarautor[20]; 
	FILE *pf;
	
	//int num = 100;
	//obra = (datosobra *) malloc(num * sizeof(datosobra));
	
	//Contrase�a para entrar
	contrasena autorizado [5], acceso;
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
	
	do
	{	
	i=0;
	menu();//llamamos a la opcion menu 
	//empezamos el switch para el menu
	scanf(" %d", &opcion);
	
		switch(opcion)
		{
			case 1: //registrar obra se puede hacer mas de una a la vez 
				system ("cls");
				printf("Ha seleccionado la opcion Registrar Obras\n");
								
				pf = fopen("registrodeobras.txt","r");	
				while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
													&obra[i].creacion, &obra[i].adquisicion)!=EOF)
					i++;
				fclose(pf);
			
				pf = fopen("registrodeobras.txt","a");			
				
				do
				{
					obra[i].codigo += obra[i].codigo+1;
					printf("Nombre de la obra: \n");
					scanf(" %s[^\n]", obra[i].nombreobra);
					printf("Autor de la obra: \n");	
					scanf(" %s[^\n]", obra[i].autor);
					printf("e -> Escultura \np -> Pintura \n"); //Tiene que introducirse solo una de las opciones  
					scanf(" %c", &obra[i].tipo);
					printf("Fecha de creacion: \n");
					scanf(" %d", &obra[i].creacion); 
					printf("Fecha de adquisicion: \n");
					scanf(" %d", &obra[i].adquisicion);	
		
					fprintf(pf, "%d %s %s %c %d %d\n", obra[i].codigo, obra[i].nombreobra,obra[i].autor, obra[i].tipo, 
														obra[i].creacion, obra[i].adquisicion);
												
					printf("Desea introducir otra obra? -> s/n: \n");
					scanf(" %c", &repetir);
					
				} while (repetir == 's');
				
				fclose(pf);
				break;
			
			case 2: //Buscar las obras tanto por autor como por nombre
				system ("cls");
				printf("Ha seleccionado la opcion buscar obra\n");
				printf("Indique si desea buscar por nombre (1) o por autor (2): \n");
				scanf(" %d", &buscar);
				pf= fopen("registrodeobras.txt", "r");
				
				switch(buscar)
				{
					case 1: //Buscador por nombre 
					printf("Introduzca el nombre de la obra: \n");
					scanf(" %s[^\n]", buscarnombre);
					while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
												&obra[i].creacion, &obra[i].adquisicion)!=EOF)
					{								
						if(strcmp(buscarnombre, obra[i].nombreobra))
						{
							printf("%d %s %s %c %d %d\n", obra[i].codigo, obra[i].nombreobra, obra[i].autor, obra[i].tipo, 
														obra[i].creacion, obra[i].adquisicion);	
						}
						i++;
					}
					fclose(pf);
					break;
							
					case 2: //Buscador por autor		
					printf("Introduzca el autor de la obra: \n");
					scanf(" %s[^\n]", buscarautor);
					while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
															&obra[i].creacion, &obra[i].adquisicion)!=EOF)
					{									
						if(strcmp(buscarautor,obra[i].autor))
						{
							printf("%d %s %s %c %d %d\n", obra[i].codigo, obra[i].nombreobra, obra[i].autor, obra[i].tipo, 
														obra[i].creacion, obra[i].adquisicion);				
						}
						i++;
					}
					fclose(pf);
					break;	
				}
				fclose(pf);
				break;
							
			case 3: //Eliminar obra por nombre de la obra
				system ("cls");
				printf("Ha elegido la opcion Retirar Obra\n");
				char retirar[30];
				printf("Indique el nombre de la obra que desea retirar: \n");
				scanf(" %s[^\n]", retirar);
				
				pf = fopen ("registrodeobras.txt","r"); //Solo leer� los datos para guardarlos en el vector de estructura 
				
				while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
													&obra[i].creacion, &obra[i].adquisicion)!=EOF)
				{									
					if(strcmp(retirar, obra[i].nombreobra))
					{
						obra[i].codigo = -1; //Es un entero por lo que hay que asignarle un numero
					}
					i++;
				}
				
				fclose(pf);
				pf = fopen ("registrodeobra.txt", "w");//Se recrea el archivo asi que hay que volver a guardarlo todo pero 
				//sin los datos borrados hasta el momento
			
				while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
													&obra[i].creacion, &obra[i].adquisicion)!=EOF)
				{
					if(obra[i].codigo > 0)
						fprintf(pf, "%d %s %s %c %d %d", obra[i].codigo, obra[i].nombreobra, obra[i].autor, obra[i].tipo, 
													obra[i].creacion, obra[i].adquisicion);			
					i++;					
				}
				printf("Se ha retirado correctamente la obra. \n");
				fclose(pf);
				break;
			
			case 4: //listado de obras 
				//mostrar de dos formas:
				//1. orden cronologico por orden de antiguedad
				//2.orden cronologico por orden de adquisicion 
				system ("cls");		
				printf("Ha elegido la opcion Listado de obras\n Indique por que orden: \n");
				int opcionlistado;
				int mayor;
				printf("1. Orden cronologico por antiguedad\n");
				printf("2. Orden cronologico por adquisicion\n");
				scanf(" %d", &opcionlistado);
				
				pf = fopen("registrodeobras.txt", "r");
				
				if(opcionlistado==1)
				{
					while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
															&obra[i].creacion, &obra[i].adquisicion)!=EOF)
					{							
					//metodo burbuja para ordenar los a�os
						for(j=0; j<100-1; j++) //Con este se repetir� la comparacion hasta que finalice 
						{
							for (i=0; i<100-1;i++)	
							{
								if (obra[i].creacion > obra[i+1].creacion)
								{
									mayor = obra[i].creacion;
									obra[i].creacion = obra[i+1].creacion;
									obra[i+1].creacion = mayor;
								}
							}
						}
						i++;				
					}
					for(i=0; i<100; i++)
						printf("%d %s %s %c %d %d", obra[i].codigo, obra[i].nombreobra, obra[i].autor, obra[i].tipo, 
													obra[i].creacion, obra[i].adquisicion);
				}
				
				if(opcionlistado==2)
				{
					while (fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
															& obra[i].creacion, &obra[i].adquisicion)!=EOF)
					{						
						//metodo burbuja para ordenar los a�os
						for(j=0; j<100-1; j++) //Con este se repetir� la comparacion hasta que finalice 
						{
							for (i=0; i<100-1;i++)	
							{
								if (obra[i].adquisicion > obra[i+1].adquisicion)
								{
									mayor = obra[i].adquisicion;
									obra[i].creacion = obra[i+1].adquisicion;
									obra[i+1].adquisicion = mayor;
								}
							}
						}
						i++;
					}
					for(i=0; i<100; i++)
						printf("%d %s %s %c %d %d", obra[i].codigo, obra[i].nombreobra, obra[i].autor, obra[i].tipo, 
													obra[i].creacion, obra[i].adquisicion);
				}
				fclose(pf);
				break;
				
			case 5: //almac�n 
				system("cls");
				printf ("La opcion elegida es ver la cantidad de esculturas y pinturas en el almacen.\n");
				int totalpinturas = 0;
				int totalesculturas = 0;
	
				pf = fopen("registrodeobras.txt", "r");
				
				while (fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
															&obra[i].creacion, &obra[i].adquisicion)!=EOF)
				{
					if(obra[i].tipo== 'p')
						totalpinturas++;
	        		if(obra[i].tipo== 'e')
						totalesculturas++;
					i++;
				}	
				printf("El total de pinturas es %d \n", totalpinturas);
				printf("El total de esculturas es %d \n", totalesculturas);
				printf("El total de obras es %d \n", totalpinturas+totalesculturas);
				
				fclose(pf);
				break;
					
			case 6:
				return; //Buscar numero para salir del programa 	
				
			default: 
				system("cls");
				printf("Opcion incorrecta\n");	
				break;	
		}
	} while(1); 

	system("pause");
	return 0;	
}

int existeUsuario(contrasena usuarioValido[], char nombre[], char clave[])
{
	int valido, i;
	for (i = 0; i < 5; i++)
		{
			valido = strcmp (usuarioValido[i].usuario, nombre) || strcmp (usuarioValido[i].clave, clave); 
			if (valido == 0) break;
		}
	return valido;
}

void menu ()
{
	system ("cls");
	printf("Bienvenido al MENU DE OPCIONES del Museo del Prado.\n ");
	printf ("Por favor seleccione una de las siguientes opciones: \n");
	printf("1. Registrar obra\n");
	printf("2. Buscar obra\n");
	printf("3. Retirar obra\n");
	printf("4. Listado de obras\n");
	printf("5. Almacen\n");
	printf("6. Salir\n");
	//default printf("Opcion incorrecta");
}
