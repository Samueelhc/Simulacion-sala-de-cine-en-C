/*
    =============================================================
        SIMULACION DE RESERVA DE ASIENTOS EN UNA SALA DE CINE
    =============================================================
    Este programa de consola permite:

    - Visualizar el estado actual de la sala de cine.
    - Reservar asientos (marcados con 'X').
    - Cancelar reservas de asientos (volver a 'O').

    Ademas valida exhaustivamente las entradas del usuario para evitar errores como letras donde deben ir numeros, rangos fuera de los permitidos, o mas de un caracter cuando solo debe introducirse uno.
    
	=============================================================
	Realizado por: Samuel Hernández Cavada
	Fecha: 15/11/2024
	=============================================================
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
#include<signal.h>

// Cantidad total de filas de la sala
#define FILAS 25
// Cantidad de columnas (A, B, C, D)
#define COLUMNAS 4

// Prototipos de las funciones de validacion de entrada
int validarenteroP1(char num[10]);     // Valida opcion de menu (1 a 4)
int validarenteroP2(char num[10]);     // Valida numero de fila (1 a 25)
int validarcaracterLETRAS(char caracter[1]);   // Valida letras A-D para columnas
int validarcaracterLETRAS2(char caracter[1]);  // Valida letra S (volver al menu)
int validarcaracterLETRAS3(char caracter[1]);  // Valida letras S o N (si/no)


// Muestra por pantalla la sala de cine con sus asientos
void imprimirsala();

// Matriz global que representa los asientos de la sala
// 'O' = asiento libre, 'X' = asiento reservado
char asientos[FILAS][COLUMNAS];

// Funcion principal del programa
main(){
	
	int no; // Variable de control para validaciones
	
	// Variables para las diferentes entradas del usuario
	char opcion[10],columna[3],volver[3],fila[10];
	int vacio=0,j,numop,fila_e,columnae,opcion_e=0;
	char cuantos[2],seguir[3];
	
	// Ignorar la interrupcion por teclado (CTRL + C)
	signal(SIGINT, SIG_IGN);
	
	// Inicializar todos los asientos como disponibles ('O')
	for(int i=0; i<FILAS;++i){

		for(int j=0; j<COLUMNAS; ++j){
					
			asientos[i][j] = 'O';
			vacio=0; // Indica que la sala comienza vacia
			
		}
	}
	

	
		// Bucle principal del programa (menu)
		do{
		
		// Bucle para pedir y validar la opcion del menu
		do{	
			//imprimirsala();
			//no=0;
			fflush(stdin);
			system("cls");
			printf("\n\n\t\t\t************* BIENVENIDO A CINEX *************\n\n");
			
			printf("\n\n\t--- MENU DE OPCIONES ---\n\n");
			
			printf("\t1. VER SALA \n");
			printf("\t2. RESERVAR \n");
			printf("\t3. CANCELAR \n");
			printf("\t4. SALIR \n\n");
			printf("\tOPCION: ");
			fgets(opcion,sizeof(opcion),stdin);
			no=validarenteroP1(opcion);
			
			if(no==0){
				
			printf("\nEntrada invalida recuerde que solo puede ingresar numeros entre 1 y 4.\n\n");
			system("pause");				
			}
			
			if(atoi(opcion) == 3 && vacio == 0){
				
			printf("\nLa sala esta vacia, no puede cancelar ningun asiento\n\n");
			system("pause");
			no=0;		
			}
				
		}while(no == 0);
		
	
		// Convertir la opcion valida a entero
		numop = atoi(opcion);
		
	// Segun la opcion elegida se ejecuta un caso del menu
	switch(numop){
		
		case 1:
		
		// VER SALA
		do{
		fflush(stdin);
		system("cls");
		imprimirsala();
		printf("Presione S para volver al menu: ");
		fgets(volver,sizeof(volver),stdin);
		
		no=validarcaracterLETRAS2(volver);
			
		if(no==0){
				
			printf("\nEntrada invalida recuerde que solo puede ingresar letra 'S'.\n\n");
			system("pause");				
			}
			
		}while(no==0);
		
	
		break;
		
		case 2:
		
			// RESERVAR ASIENTOS
			do{
			//fila=0;
			columna[0]=' ';
			volver[0]=' ';
			seguir[0]=' ';
			
			do{
				fflush(stdin);
			system("cls");
			imprimirsala();
			
			printf("Elija el asiento que desea reservar");	
			printf("\n\nIngrese la columna (A-D): ");
			fgets(columna,sizeof(columna),stdin);
			no = validarcaracterLETRAS(columna);
			
			if(no==0){
				
			printf("\nEntrada invalida solo puede ingresar letras A, B, C, D.\n\n");
			system("pause");				
			}
			
			
			}while(no==0);
			
			do{
				fflush(stdin);
			system("cls");
			imprimirsala();
				
			printf("\nIngrese la la fila (1-25): ");
			fgets(fila,sizeof(fila),stdin);
			no=validarenteroP2(fila);
			
			if(no==0){
				
			printf("\nEntrada invalida solo puede ingresar numeros del 1 al 25.\n\n");
			system("pause");				
			}
				
			}while(no==0);
		
			
			
			
			fila_e = atoi(fila);
			
			
			if(columna[0] == 'A'|| columna[0] == 'a')
			columnae = 0;
			
			if(columna[0] == 'B'|| columna[0] == 'b')
			columnae = 1;
			
			if(columna[0] == 'C'|| columna[0] == 'c')
			columnae = 2;
			
			if(columna[0] == 'D'|| columna[0] == 'd')
			columnae = 3;
			
			
			// Solo se reserva si el asiento esta libre
			if (asientos[fila_e-1][columnae] == 'O') {
                    asientos[fila_e-1][columnae] = 'X';
                    vacio=1;
                    printf("\n\t\t[Asiento reservado con exito]\n\n");
                    system("pause");
                } 
				
				else {
                    printf("\n\t\tDisculpe, el asiento ya esta reservado.\n\n");
                    system("pause");
                }
			
			
			
			
			
			do{
			fflush(stdin);	
			system("cls");
			imprimirsala();
			printf("Desea reservar otro asiento? S/N: ");
			fgets(seguir,sizeof(seguir),stdin);
			no=validarcaracterLETRAS3(seguir);
			
			if(no==0){
				
			printf("\nEntrada invalida solo puede ingresar 'S' o 'N'.\n\n");
			system("pause");				
			}
				
			}while(no==0);
			
			
			
		
			
			}while(seguir[0] =='s'|| seguir[0] =='S');
			
			if(seguir[0] =='n'|| seguir[0] =='N'){
				volver[0] ='s';	
			}
	
			break;
			
			
			
		case 3:
			
			// CANCELAR RESERVA DE ASIENTOS
			do{
			fila_e=0;
			columna[0]=' ';
			seguir[0]=' ';
			volver[0]=' ';
			
				imprimirsala();
			
			do{
			fflush(stdin);
			system("cls");
			imprimirsala();
			
			printf("Elija el asiento que desea cancelar");	
			printf("\n\nIngrese la columna (A-D): ");
			fgets(columna,sizeof(columna),stdin);
			no = validarcaracterLETRAS(columna);
			
			if(no==0){
				
			printf("\nEntrada invalida solo puede ingresar letras A, B, C, D.\n\n");
			system("pause");				
			}
			
			}while(no==0);
			
			do{
			fflush(stdin);
			system("cls");
			imprimirsala();
				
			printf("\nIngrese la la fila (1-25): ");
			fgets(fila,sizeof(fila),stdin);
			no=validarenteroP2(fila);
				
			if(no==0){
				
			printf("\nEntrada invalida solo puede ingresar numeros del 1 al 25.\n\n");
			system("pause");				
			}	
				
			}while(no==0);
			
		
			fila_e = atoi(fila);

			if(columna[0] == 'A'|| columna[0] == 'a')
			columnae = 0;
			
			if(columna[0] == 'B'|| columna[0] == 'b')
			columnae = 1;
			
			if(columna[0] == 'C'|| columna[0] == 'c')
			columnae = 2;
			
			if(columna[0] == 'D'|| columna[0] == 'd')
			columnae = 3;
			
			
			// Solo se puede cancelar si el asiento esta actualmente reservado
			if (asientos[fila_e-1][columnae] == 'X') {
                 asientos[fila_e-1][columnae] = 'O';
                 printf("\n\t\t[Asiento cancelado con exito]\n\n");
                 system("pause");
                 
				 // Verificar si luego de la cancelacion la sala quedo totalmente vacia
                for(int i=0; i<FILAS;++i){

					for(int j=0; j<COLUMNAS; ++j){
					
					if(asientos[i][j] != 'O'){
						
					vacio=1;
					break;	
					}
					
					else{
						vacio=0;
					}
				
					}
					
				}
                 
                 
            } 
				
			else {
               printf("\n\t\t[El asiento NO esta reservado, no puede cancelarlo]\n\n");
               system("pause");
            }
			
			do{
				fflush(stdin);
			system("cls");
			imprimirsala();
			
			if(vacio==1){
			printf("Desea cancelar otro asiento? S/N: ");
			fgets(seguir,sizeof(seguir),stdin);
			no=validarcaracterLETRAS3(seguir);	
			}
			else{
				
			printf("\nLa sala quedo vacia, no puede cancelar mas asientos.\n");
			system("pause");
			no=1;
			volver[0] ='s';
			
			}
			
			
			if(no==0){
				
			printf("\nEntrada invalida solo puede ingresar 'S' o 'N'.\n\n");
			system("pause");
					
			}
				
			}while(no==0);
			
			
			}while(seguir[0] =='s'|| seguir[0] =='S');
			
			if(seguir[0] =='n'|| seguir[0] =='N'){
				volver[0] ='s';	
			}
			break;
			
		default:
			
			// Opcion 4: salir del programa
			printf("\n\nUSTED A SALIDO DEL PROGRAMA.");
			printf("\nGRACIAS POR USAR NUESTRO SERVICIO.");
			volver[0]='n';
			
			
	}
		
	
	}while(volver[0] =='s'||volver[0] =='S');
	
	
	
	
	getche();
}



void imprimirsala(){
	
	
	printf("-------- ASIENTOS --------\n\n");
			printf("  Disponibles = O\n");
			printf("     Ocupados = X\n\n");
			
			
			printf("\n\t\t\t------------- PANTALLA -------------\n\n");
			for(int i=0; i<FILAS;++i){
				
				printf("\t\t\t\t");
				
				if(i<9){
					printf(" %d   ",i+1);
					
				}
				
				else{
				printf("%d   ",i+1);	
				}

				for(int j=0; j<COLUMNAS; ++j){
									
					printf("[%c] ",asientos[i][j]);
	
				}
				
				printf("\n");

			}
			printf("\t\t\t\t      A   B   C   D\n\n");
	

}

//FUNCIONES DE VALIDACION DE ENTRADA

int validarenteroP1(char num[20]){
	
	int s,nume;	
	
	//Eliminar el caracter de salto de la ultima linea que coloca fgets por un caracter vacio, para que la validacion funcione
	
		for (int s = 0; s < sizeof(num); ++s) 
    	{
       	 if (num[s] == '\n') 
       	 {
            num[s] = '\0';
        	}
    	}
		//En caso de que la cadena contenga letras o simbolos
		for(s=0;s < strlen(num);++s){
		
			if(!(isdigit(num[s]))){
			fflush(stdin);
			return 0;
			
			}
		}
		
		nume= atoi(num);
		//Evitar enter, ceros al principio, y evitar numeros muy grandes
		if(num[0] == '\0'|| num[0] =='0' || strlen(num)>1 || nume>4){
											//Estos 2 condicionales debo cambiarlos segun el requerimiento del programa
			fflush(stdin);
			return 0;
		}
	
		return 1;	
}

int validarenteroP2(char num[20]){
	
	int s,nume;	
	
	//Eliminar el caracter de salto de la ultima linea que coloca fgets por un caracter vacio, para que la validacion funcione
	
		for (int s = 0; s < sizeof(num); ++s) 
    	{
       	 if (num[s] == '\n') 
       	 {
            num[s] = '\0';
        	}
    	}
		//En caso de que la cadena contenga letras o simbolos
		for(s=0;s < strlen(num);++s){
		
			if(!(isdigit(num[s]))){
			fflush(stdin);
			return 0;
			
			}
		}
		
		nume= atoi(num);
		//Evitar enter, ceros al principio, y evitar numeros muy grandes
		if(num[0] == '\0'|| num[0] =='0' || strlen(num)>2 || nume>25){
											//Estos 2 condicionales debo cambiarlos segun el requerimiento del programa
			fflush(stdin);
			return 0;
		}
	
		return 1;	
}

int validarcaracterLETRAS(char caracter[1]){
	
/*Si la posicion 1 es diferente al salto de linea proporcionado por 
fgets repito, porque quiere decir que hay mas de un caracter*/
		if(caracter[1] != '\n'){
			
		fflush(stdin);
		return 0;
			
		}
		
		//Permite todas las letras incluyendo acentos, �, y dieresis mayus y minus
		if((caracter[0] == 'A'|| caracter[0] == 'a') || (caracter[0] == 'B'|| caracter[0] == 'b') ||(caracter[0] == 'C'|| caracter[0] == 'c') ||
		(caracter[0] == 'D'|| caracter[0] == 'd')){
		
			return 1;	
	

		}
		
		//Evita espacios y enter al principio ademas evita que se ingresen numeros y simbolos
		else{
			
			fflush(stdin);
			return 0;
			
		}
		

	/*if(caracter[0] == '\0'|| caracter[0] ==' ' || caracter[1] != '\n' || !(isalpha(caracter[0])) ){
			fflush(stdin);
			return 0;
		}*/
}

int validarcaracterLETRAS2(char caracter[1]){
	
/*Si la posicion 1 es diferente al salto de linea proporcionado por 
fgets repito, porque quiere decir que hay mas de un caracter*/
		if(caracter[1] != '\n'){
			
		fflush(stdin);
		return 0;
			
		}
		
		//Permite todas las letras incluyendo acentos, �, y dieresis mayus y minus
		if(caracter[0] == 'S' || caracter[0] == 's'){
		
			return 1;	

		}
		
		//Evita espacios y enter al principio ademas evita que se ingresen numeros y simbolos
		else{
			
			fflush(stdin);
			return 0;
			
		}
		

	/*if(caracter[0] == '\0'|| caracter[0] ==' ' || caracter[1] != '\n' || !(isalpha(caracter[0])) ){
			fflush(stdin);
			return 0;
		}*/
}

int validarcaracterLETRAS3(char caracter[1]){
	
/*Si la posicion 1 es diferente al salto de linea proporcionado por 
fgets repito, porque quiere decir que hay mas de un caracter*/
		if(caracter[1] != '\n'){
			
		fflush(stdin);
		return 0;
			
		}
		
		//Permite todas las letras incluyendo acentos, �, y dieresis mayus y minus
		if(caracter[0] == 'S' || caracter[0] == 's' || caracter[0] == 'N' || caracter[0] == 'n'){
		
			return 1;	

		}
		
		//Evita espacios y enter al principio ademas evita que se ingresen numeros y simbolos
		else{
			
			fflush(stdin);
			return 0;
			
		}
		

	/*if(caracter[0] == '\0'|| caracter[0] ==' ' || caracter[1] != '\n' || !(isalpha(caracter[0])) ){
			fflush(stdin);
			return 0;
		}*/
}
