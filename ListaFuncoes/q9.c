#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define bool _Bool 
#define true 1
#define false 0

#define quantMaxClientes 3

#define TAM_CPF 16
#define TAM_NAC 12
#define TAM_NOME 20
#define TAM_MAT 13

struct Cad_Clientes{
    char cpf[TAM_CPF],
         nascimento[TAM_NAC],
         nome[TAM_NOME],
         sexo;
}clientes[quantMaxClientes];
typedef struct Cad_Clientes Clientes;

int clientesCadastrados = 0;

void limpaTexto( char* );
void padronizaNome( char* );

void limpaTexto( char *texto ){
    for( int caracter = 0; texto[caracter] != '\0'; caracter++ ){
        if( texto[caracter+1] == '\0' )
            texto[caracter] = '\0';}
}
void padronizaNome( char nome[] ){
    strcpy( nome, caixaBaixa( nome ) );
    nome[0] = aumentaLetra(nome[0]); 
    for( int caracter = 0; nome[caracter] != '\0'; caracter++ ){
        if( nome[caracter-1] == ' ' ){
            nome[caracter] = aumentaLetra(nome[caracter]); }}
}
bool validaCpf( char *cpf );
bool validaSexo( char sexo );
bool validaNascimento( char *data );
bool validaNome( char *nome );
bool ehNumero( char );
bool ehLetra ( char );
bool verificaCpf( int, char * );
  
int main( ){
    int menuInicial(  );
    bool cadastrarCliente( ); 

	char resposta = '\0';
    enum MENU{ Cadastrar_Cliente = '1', Encerrar_Programa = '0'};
    
    do{ 	
        resposta = menuInicial( );
        switch( resposta ){
            case Cadastrar_Cliente : cadastrarCliente( ); break;
            case Encerrar_Programa: printf ("Programa Encerrado\n"); break;}
    }while( resposta != Encerrar_Programa );

    return 1;
}

int menuPrincipal( ){
    char resposta[3];
    enum MENU { Cadastrar = '1', Encerrar_Programa = '0'};
    
    do{
        printf( "=====================================\n"
                "             MENU CADASTRO           \n"
                "=====================================\n"
                "CADASTRAR: \n"	
                "[1] | Cliente\n"
                "[0] | Encerrar\n\n-> ");
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == Cadastrar) && !(resposta[0] == Encerrar_Programa) ){
            puts( "   ^ Valor inserido inválido! \n" );
        }else putchar('\n');
      }while( !(resposta[0] == Cadastrar) && !(resposta[0] == Encerrar_Programa) );    
    
    return resposta[0];
}

bool cadastrarCliente( ){
    bool solicitaNomeCliente( );
    bool solicitaNascimentoCliente( );
    bool solicitaCpfCliente( );
    bool solicitaSexoCliente( );
    clientesCadastrados++;
            if( solicitaNomeCliente( ) ) 
                if( solicitaNascimentoCliente( ) )
                    if( solicitaCpfCliente( ) )
                        if( solicitaSexoCliente( ) )
                            return true;
        clientesCadastrados--; 
        return false; 
  }

bool solicitaNomeCliente( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = clientesCadastrados - 1;
    
    do{
        printf("Digite o nome do professor:\n");
        fgets(clientes[posicao].nome, TAM_NOME, stdin);
        limpaTexto(clientes[posicao].nome);
        
            DADO = validaNome( clientes[posicao].nome );
    }while( DADO == INVALIDO );
    
    padronizaNome( clientes[posicao].nome );
    return true;
}

bool solicitaNascimentoCliente( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = clientesCadastrados - 1;
    
    do{
        printf("Digite a data de nascimento:\n");
        fgets(clientes[posicao].nascimento, TAM_NAC, stdin);
        limpaTexto(clientes[posicao].nascimento);
      
        DADO = validaNascimento ( clientes[posicao].nascimento );
    }while( DADO == INVALIDO );
    
    return true;
}

bool solicitaCpfCliente(){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = clientesCadastrados - 1;
    
    do{
        printf("Digite o CPF:\n");
        fgets(clientes[posicao].cpf, TAM_CPF, stdin);
        
            limpaTexto(clientes[posicao].cpf);
            DADO = validaCpf ( clientes[posicao].cpf );            
            if( DADO == VALIDO && ( verificaCpf( 1, clientes[posicao].cpf )
                || verificaCpf( 0, clientes[posicao].cpf ) ) ){
                puts( "CPF repetido");
                DADO = INVALIDO;}
    }while( DADO == INVALIDO );
    
    return true;
}

bool solicitaSexoCliente( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = clientesCadastrados - 1;
    char TesteSaida[4]; 
    
    do{
        printf("Digite o sexo:\n");
        fgets( TesteSaida, 4, stdin);

            clientes[posicao].sexo = TesteSaida[0];
            DADO = validaSexo(clientes[posicao].sexo);
    }while( DADO == INVALIDO );
    if( clientes[posicao].sexo == 'f' || clientes[posicao].sexo == 'm' ||   clientes[posicao].sexo == 'o'  ){
      clientes[posicao].sexo = clientes[posicao].sexo - 32;
      return true;
    }
    else { 
      return true;} 
}
bool validaNome(char *nome){ 
    for(int i = 0; nome[i] != '\0'; i++){
        if(!(ehLetra(nome[i])) && !(nome[i] == ' ')){
            puts( " Caractere inválido" );
            return false;}}
    return true;
}
bool validaNascimento( char *data ){    
    char *mensagensDeErro[3] = { };
    int erro = 0;
  
    if ( !tamanhoCerto(TAM_NAC, data) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";}  

    for(int i = 0; data[i] != '\0'; i++){
        if( !ehNumero(data[i]) && !(data[i] == '/')){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
    mensagensDeErro[erro] = NULL;
    
    for( int caracter = 0; data[caracter] != '\0'; caracter++ ){
        if( !ehNumero(data[caracter]) && caracter != 2 && caracter != 5 ){
            puts( "  Formato invalido" );
            return false;}}

    int dia = (charParaInt(data[0])*10)+charParaInt(data[1]),
        mes = (charParaInt(data[3])*10)+charParaInt(data[4]),
        ano = (charParaInt(data[6])*1000)+charParaInt(data[7])*100+charParaInt(data[8]*10)+charParaInt(data[9]);

    if(  dia <= 31 &&  mes <= 12 && ano >= 1899  && ano <= 2003){
        if( ( mes == 4 || mes == 6 || mes == 9 || mes == 11 ) && dia > 30  ){ 
            puts(" Data invalida");
            return false;
        }else if( mes == 2 && dia > 29 ){
            puts(" Data invalida");
            return false;}
            
    }else{
        puts(" Data invalida");
        return false;}
    
    if( mensagensDeErro[0] == NULL ){
        return true;
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
}
bool validaCpf (char *cpf){ 
    char *mensagensDeErro[3] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_CPF, cpf) ){
        mensagensDeErro[erro++] = "  Tamanho inválido"; }  
  
    for(int i = 0; cpf[i] != '\0'; i++){
        if( !ehNumero(cpf[i]) && !(cpf[i] == '.') && !(cpf[i] == '-') ){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
  
    mensagensDeErro[erro] = NULL;
  
    for( int caracter = 0; cpf[caracter] != '\0'; caracter++ ){
        if( !ehNumero(cpf[caracter]) && caracter != 3 && caracter != 7 && caracter != 11 ){
            puts( "  Formato invalido" );
            return false;}}
  
    if( mensagensDeErro[0] != NULL ){
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
    
    return true;
 }
bool validaSexo( char sexo ){ 
    if (!(sexo == 'm') && !(sexo == 'M') && !(sexo == 'F') && !(sexo == 'f') && !(sexo == 'o') && !(sexo == 'O')){
        puts( " Opção inválida" );
        return false;
    }else{  
      return true;}
}
bool ehNumero( char digito ){
    if( digito < '0' || digito > '9'){
    	return false;}
    return true;
}
bool ehLetra(char caracter){
    char caracteresEspeciais[] = "àèìòùÀÈÌÒÙáéíóúýÁÉÍÓÚÝâêîôûÂÊÎÔÛãñõÃÑÕäëïöüÿÄËÏÖÜŸçÇ";
    
    if( (caracter >= 'A' && caracter <= 'Z') ||
	       ( caracter >= 'a' && caracter <= 'z' ) ){
        return true;}
  
    for(int i = 0; caracteresEspeciais[i] != '\0'; i++){
      if( caracter == caracteresEspeciais[i] ){
          return true;}
    }
    return false;     
}
bool verificaCpf( int filtro, char *cpf  ){
    
      switch( filtro ){ 
        case 0:
            if( clientesCadastrados > 0 ){ 
                for( int cadastrado = 0; cadastrado < clientesCadastrados; cadastrado++){
                    if( (strcmp( cpf, clientes[cadastrado].cpf)) == 0 ){ 
                        return true; } }
                }break;
        case 1:
            if( clientesCadastrados > 1 ){ 
                for( int cadastrado = 0; cadastrado < (clientesCadastrados - 1); cadastrado++){
                    if( (strcmp( cpf, clientes[cadastrado].cpf)) == 0 ){ 
                        return true;}}
                 }break;
        default: puts( "Filtro invalido\n" ); 
    }
    return false;
 }